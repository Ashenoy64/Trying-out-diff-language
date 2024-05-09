class Person {
    private String name;
    private int age;

    // Default constructor
    public Person() {
        // Default values
        this.name = "John Doe";
        this.age = 30;
    }

    // Parameterized constructor
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Copy constructor
    public Person(Person otherPerson) {
        this.name = otherPerson.name;
        this.age = otherPerson.age;
    }

    // Getter methods
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}
public class Constructor{

    public static void main(String[] args) {
        // Creating an object using the default constructor
        Person person1 = new Person();

        // Displaying details of the first person
        System.out.println("Person 1 - Name: " + person1.getName() + ", Age: " + person1.getAge());

        // Creating an object using the parameterized constructor
        Person person2 = new Person("Alice", 25);

        // Displaying details of the second person
        System.out.println("Person 2 - Name: " + person2.getName() + ", Age: " + person2.getAge());

        // Creating an object using the copy constructor
        Person person3 = new Person(person2);

        // Displaying details of the third person
        System.out.println("Person 3 (Copy of Person 2) - Name: " + person3.getName() + ", Age: " + person3.getAge());
    }
}

