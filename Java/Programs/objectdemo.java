class objectdemo
{
public static void main(String args[])
{
student s1=new student(10,"Ram");
student s2=new student(11,"Sia");
System.out.println(s1.getClass());// class student
System.out.println(s1.hashCode());
System.out.println(s1.equals(s2));
System.out.println(s1==s2);
}

}
class student
{
int id;
String name;

student(int id,String name)
{
this.id=id;
this.name=name;
}
void display()
{
System.out.println("id="+id);
System.out.println("name="+name);
}
}


