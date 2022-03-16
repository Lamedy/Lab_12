package com.company;

public class Main {

    public static void main(String[] args) {
        B point = new B(10);
        point.write();

        gun one = new gun();
        player man = new player();
        man.use(one);
    }
}
