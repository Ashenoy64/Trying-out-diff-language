class Main2{
  public static void main(String[] args) {
    Person myObj = new Person();
    myObj.name = "John"; 			 // error
    System.out.println(myObj.name); 	// error 
  }
}
class Person {
  private String name; 	// private = restricted access
  
  public String getName() {			 // Getter
    return name;
  }
    public void setName(String newName) {	 // Setter
    this.name = newName;
  }
}

