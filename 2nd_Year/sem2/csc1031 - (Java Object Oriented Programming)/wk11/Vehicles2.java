public class Vehicles2{

    public static void main(String[] args) {
        Engine carEngine = new Engine(150);
        Car myCar = new Car("Toyota", 4, carEngine);
        myCar.startEngine();

        Engine bikeEngine = new Engine(20);
        Bike myBike = new Bike("Yamaha", true, bikeEngine);
        myBike.startEngine();

        Engine electricCarEngine = new Engine(200);
        ElectricCar tesla = new ElectricCar("Tesla", 4, 75, electricCarEngine);
        tesla.startEngine();
    }
}


	abstract class Vehicle{
		String brand;

		public Vehicle(String brand){
			this.brand = brand;
		}

		public abstract void startEngine();
	}


	class Engine{
		int horsePower;

		public Engine(int horsePower){
			this.horsePower = horsePower;
		}

		public int getHorsePower(){
			return horsePower;
		}
	}

	class Car extends Vehicle{
		int numDoors;
		Engine engine;

		public Car(String brand, int numDoors, Engine engine){
			super(brand);
			this.numDoors = numDoors;
			this.engine = engine;
		}

		@Override
		public void startEngine(){
			System.out.println("Starting car with " + engine.getHorsePower() +  " horsepowers");
		}
	}

	class Bike extends Vehicle{
		boolean hasCarrier;
		Engine engine;

		public Bike(String brand, boolean hasCarrier, Engine engine){
			super(brand);
			this.hasCarrier = hasCarrier;
			this.engine = engine;
		}

		@Override
		public void startEngine(){
			System.out.println("Starting bike with " + engine.getHorsePower() +  " horsepowers");
		}
	}

	class ElectricCar extends Car{
		int batteryCapacity;

		public ElectricCar(String brand, int numDoors, int batteryCapacity, Engine engine){
			super(brand, numDoors, engine);
			this.batteryCapacity = batteryCapacity;
		}

		@Override
		public void startEngine(){
			System.out.println("Starting eletric car silently  with " + engine.getHorsePower() +  " horsepowers");
		}
	}
