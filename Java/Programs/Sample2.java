class Sample
{  
	public static void main(String args[])  
	{   
		A obj=new A();  
		System.out.println(obj.data);       //no error
		obj.msg();                          //no error
    }  
}
class A
{  
	public int data=10;
	public void msg()
	{
		data++; //no error
		System.out.println("Welcome to OOAD with Java class");
	}  
}
