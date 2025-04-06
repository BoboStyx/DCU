import java.util.*;

public class Taxi{

    public static void main(String[] args){
        DispatchCenter dispatchCenter = new DispatchCenter();

        Passenger alice = new Passenger("Alice");
        Passenger bob = new Passenger("Bob");

        Taxi2 taxi1 = new Taxi2("Taxi-01");
        Taxi2 taxi2 = new Taxi2("Taxi-02");
        Taxi2 taxi3 = new Taxi2("Taxi-03");

        dispatchCenter.registerTaxi(taxi1);
        dispatchCenter.registerTaxi(taxi2);
        dispatchCenter.registerTaxi(taxi3);

        alice.requestRide("Airport", dispatchCenter);
        bob.requestRide("Downtown", dispatchCenter);

        taxi1.setAvailable(true);
        taxi2.setAvailable(true);
        taxi3.setAvailable(true);

        taxi1.respondToRide(true); // Accept the ride
        taxi2.respondToRide(false); // Reject the ride
        taxi3.respondToRide(true); // Accept the rejected ride
    }
}
	class Passenger{
		private String passenger;
		private String destination;

		public Passenger(String passenger){
			this.passenger = passenger;
		}

		public String getName(){
			return passenger;
		}

		public String getDestination(){
			return destination;
		}

		public void requestRide(String destination, DispatchCenter dispatchcenter){
			this.destination = destination;
			System.out.println("Passenger " + passenger + " requested a ride to " + destination + ".");
			dispatchcenter.addPassenger(this);
		}
	}

	class Taxi2{
		private String taxi;
		private DispatchCenter dispatchcenter;
		private Passenger passenger;

		public Taxi2(String taxi){
			this.taxi = taxi;
		}

		public String getId(){
			return taxi;
		}

		public void setDispatchCenter(DispatchCenter dispatchcenter){
			this.dispatchcenter = dispatchcenter;
		}

		public void setAvailable(boolean availability){
			if (availability){
				System.out.println("Taxi " + taxi + " is now available.");
				dispatchcenter.registerAvailableTaxi(this);
			}
		}

		public void assignPassenger(Passenger passenger){
			this.passenger = passenger;
			System.out.println("Dispatch assigned Taxi " + taxi + " to passnger " + passenger.getName() + ".");
		}

		public void respondToRide(boolean response){
			if (passenger == null){
				return;
			}

			String destination = passenger.getDestination();

			if (response){
				System.out.println("Taxi "+ taxi + " accepted ride to " + destination + ".");
				passenger = null;
			}
			else {
				System.out.println("Taxi " + taxi + " rejected ride to " + destination + ". Searching for another taxi...");
				dispatchcenter.reassignPassenger(this, passenger);
			}
		}
	}

	class DispatchCenter{

	private Queue<Passenger> passengerQueue = new LinkedList<>();
	private Queue<Taxi2> taxiQueue = new LinkedList<>();

		public void addPassenger(Passenger passenger){
			passengerQueue.add(passenger);
		}

		public void registerTaxi(Taxi2 taxi){
			taxi.setDispatchCenter(this);
		}

		public void registerAvailableTaxi(Taxi2 taxi){
			taxiQueue.add(taxi);
			assignRides();
		}

		private void assignRides(){
			while (!passengerQueue.isEmpty() && !taxiQueue.isEmpty()){
				Passenger passenger = passengerQueue.poll();
				Taxi2 taxi = taxiQueue.poll();
				taxi.assignPassenger(passenger);
			}
		}

		public void reassignPassenger(Taxi2 taxi, Passenger passenger){
			if (!taxiQueue.isEmpty()){
				Taxi2 newTaxi = taxiQueue.poll();
				newTaxi.assignPassenger(passenger);
			}
			else{
				passengerQueue.add(passenger);
			}
			taxiQueue.add(taxi);
		}
	}
