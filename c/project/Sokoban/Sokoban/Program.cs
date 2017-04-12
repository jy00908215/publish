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
        public const int boxNumber = 9;
        public const int mapHigt = 12, mapWidth = 13;
    }
    public class Map
    {
        public static int[,] now = new int[Const.mapHigt, Const.mapWidth]
        {
            {0,0,0,0,0,1,1,1,1,1,1,1,0},
            {0,0,0,0,0,1,0,0,1,0,0,1,0},
            {0,0,0,0,0,1,0,0,2,2,0,1,0},
            {1,1,1,1,1,1,0,2,1,0,0,1,0},
            {1,4,4,4,1,1,1,0,1,0,0,1,1},
            {1,4,0,0,1,0,0,2,0,1,0,0,1},
            {1,4,0,0,0,0,2,0,2,0,2,0,1},
            {1,4,0,0,1,0,0,2,0,1,0,0,1},
            {1,4,4,4,1,1,1,0,1,0,0,1,1},
            {1,1,1,1,1,1,0,2,0,0,0,1,0},
            {0,0,0,0,0,1,0,3,1,0,0,1,0},
            {0,0,0,0,0,1,1,1,1,1,1,1,0}
        };
        public static int[,] original = new int[Const.mapHigt, Const.mapWidth]
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
    }
    public class Object
    {
        public static Pos rolePlayer;
        public static Pos[] box = new Pos[Const.boxNumber];
    }
    public class MovePos
    {
        public static Pos nextPos;
        public static Pos gotoPos;
    }
    public class Function
        {
        public static void NextPosIs(string input,Pos objPos) //根据移动方向获得下一个点的函数
        {
            if ("UpArrow" == input)
            {
                MovePos.nextPos.y = objPos.y - 1;
                MovePos.nextPos.x = objPos.x;
            }
            if ("DownArrow" == input)
            {
                MovePos.nextPos.y = objPos.y + 1;
                MovePos.nextPos.x = objPos.x;
            }
            if ("LeftArrow" == input)
            {
                MovePos.nextPos.y = objPos.y;
                MovePos.nextPos.x = objPos.x - 1;
            }
            if ("RightArrow" == input)
            {
                MovePos.nextPos.y = objPos.y;
                MovePos.nextPos.x = objPos.x + 1;
            }
        }
        public static void Move_Obj(string input,Pos objPos) //移动角色坐标的函数
        {
            if ("UpArrow" == input)
            {
                objPos.y--;
            }
            if ("DownArrow" == input)
            {
                objPos.y++;
            }
            if ("LeftArrow" == input)
            {
                objPos.x--;
            }
            if ("RightArrow" == input)
            {
                objPos.x++;
            }
        }
        public static bool GridCanEnter(int[] nextPos)
        {
            return (0 <= MovePos.nextPos.y && Const.mapHigt >= MovePos.nextPos.y &&
                0 <= MovePos.nextPos.x && Const.mapWidth >= MovePos.nextPos.x &&
                Const.wall != Map.original[MovePos.nextPos.y, MovePos.nextPos.x]);
        }
        public static int FindBoxNumber(Pos pos)
        {
            for (int i = 0; Const.boxNumber > i; i++)
            {
                if (Object.box[i].y == pos.y && Object.box[i].x == pos.x)
                    return i;
            }
            return -1;
        }

        public static void Move() //移动函数
        {
            Function.Move_Direction();
            if (Const.nothing == Map.now[(MovePos.Next[0]),(MovePos.Next[1])] || //如果下一个位置是空地或者目标
                Const.target == Map.now[(MovePos.Next[0]), (MovePos.Next[1])])
            {
                Map.now[(MovePos.Next[0]), (MovePos.Next[1])] = Const.role;
                if (Const.target == Map.original[RolePos.y, RolePos.x])
                {
                    Map.now[RolePos.y, RolePos.x] = Const.target;
                }
                else
                {
                    Map.now[RolePos.y, RolePos.x] = Const.nothing;
                }
                Function.Move_Role();
            }
            else if(Const.wall == Map.now[(MovePos.Next[0]), (MovePos.Next[1])]) //如果下一个位置是墙
            {
                return ;
            }
            else if (Const.box == Map.now[(MovePos.Next[0]), (MovePos.Next[1])] || //如果下一个位置是箱子或者已得分的箱子
                Const.goal == Map.now[(MovePos.Next[0]), (MovePos.Next[1])])
            {
                if (Const.wall == Map.now[(MovePos.BoxNext[0]), (MovePos.BoxNext[1])] || //如果箱子后面是墙或者箱子等
                    Const.box == Map.now[(MovePos.BoxNext[0]), (MovePos.BoxNext[1])]  ||
                    Const.goal == Map.now[(MovePos.BoxNext[0]), (MovePos.BoxNext[1])])
                {
                    return;
                }
                else if (Const.nothing == Map.now[(MovePos.BoxNext[0]), (MovePos.BoxNext[1])] ||
                    Const.target == Map.now[(MovePos.BoxNext[0]), (MovePos.BoxNext[1])]) //如果箱子后面是空地或者目标点
                {
                    if (Const.nothing == Map.now[(MovePos.BoxNext[0]), (MovePos.BoxNext[1])])
                    {
                        Map.now[(MovePos.BoxNext[0]), (MovePos.BoxNext[1])] = 2;
                    }

                    else
                    {
                        Map.now[(MovePos.BoxNext[0]), (MovePos.BoxNext[1])] = 5;
                    }

                    Map.now[(MovePos.Next[0]), (MovePos.Next[1])] = 3;
                    if (Const.target == Map.original[RolePos.y, RolePos.x])
                    {
                        Map.now[RolePos.y, RolePos.x] = 4;
                    }
                    else
                    {
                        Map.now[RolePos.y, RolePos.x] = 0;
                    }
                    Function.Move_Role();
                }
            }
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
            Object.box[1].y = 2;
            Object.box[1].x = 9;
            Object.box[2].y = 3;
            Object.box[2].x = 7;
            Object.box[3].y = 5;
            Object.box[3].x = 7;
            Object.box[4].y = 6;
            Object.box[4].x = 6;
            Object.box[5].y = 6;
            Object.box[5].x = 8;
            Object.box[6].y = 6;
            Object.box[6].x = 10;
            Object.box[7].y = 7;
            Object.box[7].x = 7;
            Object.box[8].y = 9;
            Object.box[8].x = 7;
            for (;;)
            {
                //打印新地图
                for (int i = 0; i < 12; i++)
                {
                    for (int j = 0; j < 13; j++)
                    {
                        if (Map.now[i, j] == Const.nothing)
                        {
                            Console.Write("　");
                        }
                        if (Map.now[i, j] == Const.wall)
                        {
                            Console.Write("■");
                        }
                        if (Map.now[i, j] == Const.box)
                        {
                            Console.Write("□");
                        }
                        if (Map.now[i, j] == Const.role)
                        {
                            Console.Write("♀");
                        }
                        if (Map.now[i, j] == Const.target)
                        {
                            Console.Write("☆");
                        }
                        if (Map.now[i, j] == Const.goal)
                        {
                            Console.Write("★");
                        }
                    }
                    Console.WriteLine();
                }
                ConsoleKeyInfo aj = Console.ReadKey();
                Console.Clear();
                string input = "";
                input = aj.Key.ToString();
            }
            Console.ReadLine();
        }
    }
}
