import java.util.Scanner;
import java.util.ArrayList;
import java.util.Random;

public class Main{
    public static void main(String[] args)
    {
        arrays();
    }

    public static void typeJava()
    {
        int x = 123;
        long y =99999999999999L;

        float f = 3.14f;
        double d=3.14159;

        boolean b= true;
        char symbol = '@';

        String name = "Send Help";

        System.out.println("My number is "+x);
        System.out.println("What the hell  "+y);
        System.out.println("Please send help "+f+" "+d+" "+b+" "+symbol+" "+name);
    }

    public static void swap()
    {   
        String x = "water";
        String y ="Kool-Aid";

        String temp = x;
        x = y;
        y = temp; 

        System.out.println("X = "+x);
        System.out.println("Y = "+y);
    }

    public static void input()
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("What is your name bosss?");
        String name =sc.nextLine();

        // sc.nextInt();
        System.out.println("Hello "+name);
        sc.close();

    }

    public static void hypotenuese()
    {   
        Scanner sc = new Scanner(System.in);
        System.out.println("Side 1 : ");
        double x = sc.nextDouble();
        sc.nextLine();

        System.out.println("Side 2:");
        double y = sc.nextDouble();
        sc.nextLine();

        System.out.println("Hypotenuse is = " + Math.sqrt(x*x+y*y));
        sc.close();

        
    }

    public static void randome()
    {
        Random random = new Random();

        random.nextInt();

        random.nextInt(6); //0-5
        // random.nextInt(6)+1; //1-6


    }

    public static void arrays()
    {
            String[] cars = {"Camaro","Bugatti","Tesla"};

            System.out.println(cars[new Random().nextInt(3)]);

            String[] new_cars = new String[3];

            new_cars[0] = "Hello";

            System.out.println(new_cars.length); 
    }
    public static void string_methode()
    {
        String name="Bro";    

        name.equals("Bro");
        name.equalsIgnoreCase("Bro");

        name.length();

        name.charAt(0);

        name.indexOf("B");

        name.isEmpty();

        name.toLowerCase(null);

        name.trim();

        name.replace("what", "to what");


    }

    public static void wrapper()
    {
        // Boolean a = true;
        // Character b='@';
        // Integer c= 123;
        // Double d = 1.233;
        // String l= "bdcjbdj";

    }

    public static void list(){
        ArrayList<String> food = new ArrayList<String>();

        food.add("pizza");
        food.add("C");

        food.set(1,"Cake");

        food.remove(1);

        food.clear();

        
        for(int i=0;i<food.size();++i){
            System.out.println(food.get(i));
        }
    }

    public static void java_one()
    {
        
    }

    
}