public class Person {
    String name;
    int age;
    String address;

    public Person(String name, int age, String address) {
        System.out.println("Person constructor");
        this.name = name;
        this.age = age;
        this.address = address;
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Address: " + address);
    }
    public static void main(String[] args) {
        Worker worker = new Worker("John", 30, "123 Main St", "W123");
        worker.displayInfo();

        worker.updateWorkerInfo("456 Elm St");
        worker.displayInfo();

        worker.updateWorkerInfo(35);
        worker.displayInfo();

        worker.fire();
        worker.displayInfo();
    }
}

interface SpecialFunctionality {
    void fire();
}

class Worker extends Person implements SpecialFunctionality{
	String workerid;
	public Worker(String name, int age, String address, String workerid){
		super(name, age, address);
		this.workerid = workerid;
	}

	public void updateWorkerInfo(String address){
		this.address = address;
	}

	public void updateWorkerInfo(int age){
		this.age = age;
	}

	@Override
	public void fire(){
		this.address = "Fired";
		System.out.println("Worker " + this.workerid + " has been fired!");
	}
}
