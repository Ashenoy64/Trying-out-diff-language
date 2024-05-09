interface Shape{
	int d1 = 10,d2 = 20;   // final,static and public
	void find_area(); // abstract, public
	void hellomethod();
}
class Rectangle implements Shape{
	int d1,d2;
	Rectangle(){}
	Rectangle(int d1,int d2)
	{
		this.d1 = d1;
		this.d2 = d2;
	}
	public void find_area(){System.out.println("in rectangle");}
	public void hellomethod(){System.out.println("in hello rectangle");}
	
}
/*
class Triangle extends Shape{
	int d1,d2,d3;
	Triangle(){}
	Triangle(int d1,int d2, int d3)
	{
		this.d1 = d1;
		this.d2 = d2;
		this.d3 = d3;
	}
	void find_area(){System.out.println("in triangle");}
	
}

class Circle extends Shape{
	void find_area(){System.out.println("in circle");}
}

*/
class interfacedemo2{
	public static void main(String[] args)
	{
		//Shape s = new Shape(); // CT error
		
		Shape s1 = new Rectangle();
		// s1.find_area();
		//s1.hellomethod();
		//System.out.println(s1.d1); // 10
		//s1.d1 = 100;  error
		//System.out.println(s1.d1);
		
		
		Rectangle r = new Rectangle(5,6);
		r.d1 = 100;
		System.out.println(s1.d1+" "+r.d1);

		
		// Rectangle r = new Rectangle(5,6);
		// s1 = r;
		// r.d1 = 500;
		// System.out.println(s1.d1);     //10
		
		
	}
}