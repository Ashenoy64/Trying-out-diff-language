abstract class Shape{
	
	abstract void find_area();
	void hellomethod()
	{
		System.out.println("in hellomethod");
	}
}
class Rectangle extends Shape{
	int d1,d2;
	Rectangle(){}
	Rectangle(int d1,int d2)
	{
		this.d1 = d1;
		this.d2 = d2;
	}
	void find_area(){System.out.println("in rectangle");}
	
}
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
class abstractdemo
{
	public static void main(String[] args)
	{
		/*Rectangle r = new Rectangle();
		r.find_area();
		Triangle t = new Triangle();
		t.find_area();
		
		*/
		/*
		Shape s = new Rectangle();
		s.find_area();
		
		Shape s2 = new Triangle();
		s2.find_area();
		
		*/
		
		
	/*	Shape s1 = new Rectangle();
		s1.find_area();
		
		Shape s2 = new Triangle();
		s2.find_area();
		
		*/
		
		
		
		Shape s1 = new Rectangle(10,20);
		s1.find_area();
		
		Shape s2 = new Triangle(100, 200,300);
		s2.find_area();
		
		Shape s3 = new Circle();
		s3.find_area();
		
		/*Rectangle r;
		s1.d1 = 30;
		//r = s1; // error
		System.out.println(r.d1);
		
		*/
		
	/*	Rectangle r = new Rectangle(500,600);
		s1 = r;
		System.out.println(s1.d1);
		s1.hellomethod();
		*/
		
		
		
		
		
		
		
		
		
		
		
		//Shape s = new Shape();  // CT  error
		//s.find_area();
	}
}