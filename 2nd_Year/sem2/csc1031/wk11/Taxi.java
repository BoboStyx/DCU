import java.util.*

public class Taxi{
	class Passenger{
		String passenger;

		public Passenger(String passenger){
			this.passenger = passenger;
		}

		public void requestRide(String destination, DispatchCenter dispatchcenter){
			this.destination = destination;
			dispatchcenter.addPassenger(this);
		}
	}

	class Taxi{
		String taxi;

		public Taxi(String taxi){
			this.taxi = taxi;
		}

		public void setAvailable(boolean availability){
			this.availability = availability;
		}

		public void respondToRide(boolean response){
		}
	}

	class DispatchCenter{

		public void addPassenger(Passenger passenger){
			passengerQueue.add(passenger);
		}

		public void registerTaxi(Taxi taxi){
			taxiQueue.add(taxi);
		}
	}

	Queue<Passenger> passengerQueue = new LinkedList<>();
	Queue<Taxi> taxiQueue = new LinkedList<>();

    public static void main(String[] args){
        DispatchCenter dispatchCenter = new DispatchCenter();

        Passenger alice = new Passenger("Alice");
        Passenger bob = new Passenger("Bob");

        Taxi taxi1 = new Taxi("Taxi-01");
        Taxi taxi2 = new Taxi("Taxi-02");
        Taxi taxi3 = new Taxi("Taxi-03");

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
