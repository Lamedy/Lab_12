package com.company;

public class B extends A {
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
        System.out.print("\tZ = " + z);
    }
}
