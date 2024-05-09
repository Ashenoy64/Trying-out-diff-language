class Box
{
	double width=12.45;
	double height=45.67;
	double depth=32.56;
	void disp()
	{
	System.out.println("width: "+width);
	System.out.println("height: "+height);
	System.out.println("depth: "+depth);
	}
	
	public static void main(String[] args)
	{
	Box mybox = new Box();
	mybox.disp();
	}		
}
