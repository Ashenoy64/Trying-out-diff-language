class Main3 {
  public static void main(String[] args) {   
    Ninja NinjaCar = new Ninja();
    NinjaCar.setColour("Orange");
    NinjaCar.setMaxiSpeed(180);
    NinjaCar.carDetails();
    NinjaCar.NinjaOil();
  }
}
class CarOil {
  public void FillOil() {
    System.out.println("The fuel is full in the car");
  }
  public void EmptyOil() {
    System.out.println("The car has low oil");
  } } 
class Car {
  private String colour;
  private int maxi_Speed;
  public void carDetails(){
    System.out.println("Car Colour= "+colour + ", Maximum Speed= " + maxi_Speed);
  }
    public void setColour(String colour) {		 //Setting colour of the car
    this.colour = colour;
  }
   public void setMaxiSpeed(int maxi_Speed) {		//Setting maximum car Speed

    this.maxi_Speed = maxi_Speed;
  } 
} 
class Ninja extends Car {
  private CarOil Ninja_Oil;       //composition
  public void NinjaOil() {
    Ninja_Oil = new CarOil(); 	//composition
    Ninja_Oil.FillOil();
  }
} 

