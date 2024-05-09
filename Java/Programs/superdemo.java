class base
{int i=100;
}
class child extends base
{int i=200;
void display()
{
		System.out.println(super.i);
		System.out.println(i);
}
}
class superdemo
{
	public static void main(String args[])
	{
		child cobj=new child();
		cobj.display();
		
	}
	
}
