class paramdemo {
    public static void main(String a[]) {
        test t = new test(10, 20);
        t.display();
        t.testmethod(t);
        t.display();
    }
}

class test {
    int i;
    int j;

    test(int i, int j) {
        this.i = i;
        this.j = j;
    }

    test(test p) {
        this.i = p.i;
        this.j = p.j;
    }

    /*
     * void testmethod(test t1)
     * {
     * test t2=new test(t1);
     * t2.i++;
     * t2.j++;
     * }
     */
    void testmethod(test t1) {
        t1.i++;
        t1.j++;
    }

    void display() {
        System.out.println("i=" + i + "j=" + j);
    }
}
