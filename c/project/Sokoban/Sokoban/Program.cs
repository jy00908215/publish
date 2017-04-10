using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace Sokoban
{
    public class Const
    {
        public const int nothing = 0, wall = 1, box = 2, role = 3, target = 4, goal = 5;
        public const int up = 0, down = 1, left = 2, right = 3;
    }
    public class Map
    {
        public static int[,] now = new int[12, 13]
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
        public static int[,] original = new int[12, 13]
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
    public class RolePos
    {
        public static int y = 10;
        public static int x = 7;
    }
    public class MovePos
    {
        public static int direction = 0;
        public static int[] Next= new int[2] { 0, 0 };
        public static int[] BoxNext = new int[2] { 0, 0 };
    }
    public class Function
        {
        public static void Move_Direction() //根据移动方向获得下一个点的函数
        {
            if (Const.up == MovePos.direction)
            {
                MovePos.Next[0] = RolePos.y - 1;
                MovePos.Next[1] = RolePos.x;
                MovePos.BoxNext[0] = RolePos.y - 2;
                MovePos.BoxNext[1] = RolePos.x;
            }
            if (Const.down == MovePos.direction)
            {
                MovePos.Next[0] = RolePos.y + 1;
                MovePos.Next[1] = RolePos.x;
                MovePos.BoxNext[0] = RolePos.y + 2;
                MovePos.BoxNext[1] = RolePos.x;
            }
            if (Const.left == MovePos.direction)
            {
                MovePos.Next[0] = RolePos.y;
                MovePos.Next[1] = RolePos.x - 1;
                MovePos.BoxNext[0] = RolePos.y;
                MovePos.BoxNext[1] = RolePos.x - 2;
            }
            if (Const.right == MovePos.direction)
            {
                MovePos.Next[0] = RolePos.y;
                MovePos.Next[1] = RolePos.x + 1;
                MovePos.BoxNext[0] = RolePos.y;
                MovePos.BoxNext[1] = RolePos.x + 2;
            }
        }
        public static void Move_Role() //移动角色坐标的函数
        {
            if (Const.up == MovePos.direction)
            {
                RolePos.y--;
            }
            if (Const.down == MovePos.direction)
            {
                RolePos.y++;
            }
            if (Const.left == MovePos.direction)
            {
                RolePos.x--;
            }
            if (Const.right == MovePos.direction)
            {
                RolePos.x++;
            }
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
                if ("UpArrow" == aj.Key.ToString())
                {
                    MovePos.direction = Const.up;
                    Function.Move();
                }
                if ("DownArrow" == aj.Key.ToString())
                {
                    MovePos.direction = Const.down;
                    Function.Move();
                }
                if ("LeftArrow" == aj.Key.ToString())
                {
                    MovePos.direction = Const.left;
                    Function.Move();
                }
                if ("RightArrow" == aj.Key.ToString())
                {
                    MovePos.direction = Const.right;
                    Function.Move();
                }
            }
            Console.ReadLine();
        }
    }
}
