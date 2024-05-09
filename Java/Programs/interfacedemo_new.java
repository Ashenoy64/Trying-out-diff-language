interface output {
    int y = 20;

    void disp();

    default void disphello() {
        System.out.println("hello");
    }
}

interface display {
    void disp();
}

class sample implements output, display {
    int x = 10;

    public void disp() {
        System.out.println("imple of disp");
        System.out.println(y);
    }

    public void disphello() {
        System.out.println("hello-overriden");
    }

    // instance method
    void print() {
        System.out.println("instance method");
    }
}

class interfacedemo_new {
    public static void main(String args[]) {
        sample s = new sample();
        s.disp();// interface method
        s.print();// instance method
        System.out.println(s.y);// instance var
        System.out.println(sample.y);
        s.disp();
        System.out.println(output.y);// to show y is public+static
        // System.out.println(output.y++);// to show y is final---error: cannot assign a
        // value to final variable y
        // display.disp();
        // output.disp();
        s.disphello();
        output obj = s;// to show interface ref can hold obj of class that imple it
        obj.disp();
    }
}
// if pubic is not added to method implementation--attempting to assign weaker
// privilege.
// print is an instance method
// if y not initi-- error: = expected
// y can be directly used in class sample

// if a class implements interfaces having same method--one imple is enough
// default methods can be overridden
