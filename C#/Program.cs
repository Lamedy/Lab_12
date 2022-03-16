using System;

namespace Lab_12
{
    internal class Program
    {
        public class A
        {
            public int x; 
            public int y;
            public A() { x = 1; y = 2; }
            protected void print()
            {
                System.Console.Write("X = " + x + "\tY = " + y);
            }
        };
        class B : A
        {
            public int z;
            public B() { z = 3; }

            public B(int a)
            {
                z = a;
            }

            public B(int a, int b, int c)
            {
                x = a; y = b; z = c;
            }
            public void write() {
            print();
            System.Console.WriteLine("\tZ = " + z);
            }

            public B Clone()
            {
                B p = (B)this.MemberwiseClone();
                return p;
            }
        }
        abstract class weapon : IShowInfo
        {
            public abstract void use();
        };
        class gun : weapon {
            public override void use() {
            System.Console.WriteLine("BANG");
            }
        };
        class player
        {
            public void use(IShowInfo weapon)
            {
                weapon.use();
            }
        };
        interface IShowInfo
        {
            void use();
        }

        static void Main(string[] args)
        {
            B point = new B(10);
            point.write();

            B clone = point.Clone();
            clone.write();

            gun one = new gun();
            player man = new player();
            man.use(one);

            Console.ReadLine();
        }
    }
};