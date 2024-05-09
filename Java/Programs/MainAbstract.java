class Main1{
  public static void main(String[] args) {
    Dog mydog = new Dog(); // Create a Dog object
    mydog.animalSound();
    mydog.sleep();
  }
}
abstract class Animal {		// Abstract class
    public abstract void animalSound();   	 // Abstract method (does not have a body) 
    public void sleep() {			// Regular method
    System.out.println("Zzz");
  }
}
class Dog extends Animal {		// Subclass (inherit from Animal)
  public void animalSound() {
    System.out.println("The Dog says: bow bow "); 	// The body of animalSound() is provided here
  }
}
