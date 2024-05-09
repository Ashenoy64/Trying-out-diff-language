class Sample1
{  
 public static void main(String args[])  
 {   
   A obj=new A();  
   System.out.println(obj.data);    //Compile Time Error  
   obj.msg();                       //Compile Time Error  
 }  
} 
class A
{  
	private int data=10;
	private void msg()
	{
		data++; //no error
		System.out.println("Welcome to OOAD with Java class");
	}  
}
 
