using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace Sokoban
{
    public struct Pos
    {
        public int y;
        public int x;
    };
    public class Const
    {
        public const int nothing = 0, wall = 1, box = 2, role = 3, target = 4, goal = 5;
        public const int up = 0, down = 1, left = 2, right = 3;
        public const int boxNumber = 1;
        public const int mapHigt = 12, mapWidth = 13;
    }
    public class Output
    {
        public static int[,] canvas = new int[Const.mapHigt, Const.mapWidth];
    }
    public class Input
    {
        public static string key = "";
    }
    public class Object
    {
        public static int [,] map= new int[Const.mapHigt, Const.mapWidth]
        {
            {0,0,0,0,0,1,1,1,1,1,1,1,0},
            {0,0,0,0,0,1,0,0,1,0,0,1,0},
            {0,0,0,0,0,1,0,0,0,0,0,1,0},
            {1,1,1,1,1,1,0,0,1,0,0,1,0},
            {1,4,4,4,1,1,1,0,1,0,0,1,1},
            {1,4,0,0,1,0,0,0,0,1,0,0,1},
            {1,4,0,0,0,0,0,0,0,0,0,0,1},
            {1,4,0,0,1,0,0,0,0,1,0,0,1},
            {1,4,4,4,1,1,1,0,1,0,0,1,1},
            {1,1,1,1,1,1,0,0,0,0,0,1,0},
            {0,0,0,0,0,1,0,0,1,0,0,1,0},
            {0,0,0,0,0,1,1,1,1,1,1,1,0}
        };
        public static Pos rolePlayer;
        public static Pos[] box = new Pos[Const.boxNumber];
    }
    public class MovePos
    {
        public static Pos roleNextPos;
        public static Pos boxNextPos;
    }
    public class Function
    {
        public static bool CheckWin()
        {
            int n = 0;
            for (int i = 0; Const.boxNumber > i; i++)
            {
                if (Output.canvas[Object.box[i].y, Object.box[i].x] != Const.target)
                {
                    return false;
                }
            }
            return true;
        }
        public static Pos NextPosIs(string input,Pos objPos) //根据移动方向获得下一个点的函数
        {
            Pos objNextPos;
            objNextPos.x = -1;
            objNextPos.y = -1;
            if ("UpArrow" == input)
            {
                objNextPos.y = objPos.y - 1;
                objNextPos.x = objPos.x;
            }
            if ("DownArrow" == input)
            {
                objNextPos.y = objPos.y + 1;
                objNextPos.x = objPos.x;
            }
            if ("LeftArrow" == input)
            {
                objNextPos.y = objPos.y;
                objNextPos.x = objPos.x - 1;
            }
            if ("RightArrow" == input)
            {
                objNextPos.y = objPos.y;
                objNextPos.x = objPos.x + 1;
            }
            return objNextPos;
        }
        public static bool GridCanEnter(Pos pos)
        {
            return (0 <= pos.y && Const.mapHigt >= pos.y &&
                0 <= pos.x && Const.mapWidth >= pos.x &&
                Const.wall != Object.map[pos.y, pos.x]);
        }
        public static int FindBox(Pos pos)
        {
            for (int i = 0; Const.boxNumber > i; i++)
            {
                if (Object.box[i].y == pos.y && Object.box[i].x == pos.x)
                    return i;
            }
            return -1;
        }
        public static void PrintOutput()
        {
            for (int i = 0; Const.mapHigt > i; i++)
            {
                for (int j = 0; Const.mapWidth > j; j++)
                {
                    Output.canvas[i, j] = Object.map[i, j];
                }
            }
            Output.canvas[Object.rolePlayer.y, Object.rolePlayer.x] = Const.role;
            for (int i = 0; Const.boxNumber > i; i++)
            {
                if (Output.canvas[Object.box[i].y, Object.box[i].x] == Const.target)
                {
                    Output.canvas[Object.box[i].y, Object.box[i].x] = Const.goal;
                }
                else
                {
                    Output.canvas[Object.box[i].y, Object.box[i].x] = Const.box;
                }
            }
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 13; j++)
                {
                    if (Output.canvas[i, j] == Const.nothing)
                    {
                        Console.Write("　");
                    }
                    if (Output.canvas[i, j] == Const.wall)
                    {
                        Console.Write("■");
                    }
                    if (Output.canvas[i, j] == Const.box)
                    {
                        Console.Write("□");
                    }
                    if (Output.canvas[i, j] == Const.role)
                    {
                        Console.Write("♀");
                    }
                    if (Output.canvas[i, j] == Const.target)
                    {
                        Console.Write("☆");
                    }
                    if (Output.canvas[i, j] == Const.goal)
                    {
                        Console.Write("★");
                    }
                }
                Console.WriteLine();
            }
        }
        public static void Move() //移动函数
        {
            MovePos.roleNextPos = Function.NextPosIs(Input.key, Object.rolePlayer);
            if (Function.GridCanEnter(MovePos.roleNextPos) && Function.FindBox(MovePos.roleNextPos) == -1)
            {
                Object.rolePlayer = MovePos.roleNextPos;
            }
            else if (Function.GridCanEnter(MovePos.roleNextPos) && Function.FindBox(MovePos.roleNextPos)!=-1)
            {
                MovePos.boxNextPos = Function.NextPosIs(Input.key, MovePos.roleNextPos);
                if(Function.GridCanEnter(MovePos.boxNextPos) && Function.FindBox(MovePos.boxNextPos) == -1)
                {
                    Object.rolePlayer = MovePos.roleNextPos;
                    Object.box[FindBox(MovePos.roleNextPos)] = MovePos.boxNextPos;
                }
            }
            return;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Object.rolePlayer.y = 10;
            Object.rolePlayer.x = 7;
            Object.box[0].y = 2;
            Object.box[0].x = 8;
            while(!Function.CheckWin())
            {
                Function.PrintOutput();
                ConsoleKeyInfo aj = Console.ReadKey();
                Console.Clear();
                Input.key = aj.Key.ToString();
                Function.Move();
            }
            Console.Clear();
            Console.Write("Congratulations!!!");
            Console.ReadLine();

        }
    }
}
