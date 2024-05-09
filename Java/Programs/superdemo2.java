class base {
	int i;

	base() {
	}

	base(int i) {
		System.out.println("base class param ctt");
		this.i = i;
	}

}

class child extends base {
	int j;

	child(int i, int j) {
		super(i);
		this.j = j;
		System.out.println("child class param ctt");
	}
}

class superdemo2 {
	public static void main(String args[]) {
		child cobj = new child(10, 20);

	}

}
