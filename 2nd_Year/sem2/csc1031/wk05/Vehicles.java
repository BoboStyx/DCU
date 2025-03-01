import java.util.*;

interface Vehicle {
    void start();
    void stop();
}

class Car implements Vehicle {
    @Override
    public void start() {
        System.out.println("Car is starting...");
    }

    @Override
    public void stop() {
        System.out.println("Car is stopping...");
    }
}

class Bicycle implements Vehicle {
	@Override
	public void start(){
		System.out.println("Bicycle is starting...");
	}

	public void stop(){
		System.out.println("Bicycle is stopping...");
	}
}
