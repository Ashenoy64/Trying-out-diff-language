/*In Java, instanceof is a keyword used for checking if a reference variable contains a given type of object reference or not. Following is a Java program to show different behaviors of instanceof. Henceforth it is known as a comparison operator where the instance is getting compared to type returning boolean true or false as in Java we do not have 0 and 1 boolean return types.
*/

class A{}
class B extends A{}
class C extends B{}
class D extends A{}
class multileveldemo

{
	public static void main(String[] args)
	{
		A a1 = new C();
		System.out.println(a1 instanceof A);
		System.out.println(a1 instanceof B);
		System.out.println(a1 instanceof D);
	}
}