import java.util.ArrayList;
import java.util.List;

public class Fridge {
    private List<String> foodItems;
    private int balance;
    public Fridge(int initialBalance) {
       if (initialBalance < 0){
	System.out.println("Error");
	this.balance = 0;
	}
	else{
	this.balance = initialBalance;
	}
	this.foodItems = new ArrayList<>();
	}
    public void addFood(String item, int cost) {
        if (item == null || item.isEmpty() || cost < 0){
		System.out.println("Error");
		return;
	}
	if (cost > balance){
		System.out.println("Error");
		return;
	}
	foodItems.add(item);
	balance -= cost;
	System.out.println("Item " + item + " has been added to the fridge.");
    }
    public void getFood(String item) {
       if (item == null || item.isEmpty() || !foodItems.contains(item)){
		System.out.println("Error");
		return;
	}
	foodItems.remove(item);
	System.out.println("Item " + item + " has been removed from the fridge.");
    }

    public void checkStatus() {
	System.out.println("Food items:");
	if (foodItems.isEmpty()) {
		System.out.println("(none)");
	} else {
		for (String item : foodItems) {
			System.out.println(item);
		}
        }
	System.out.println("Balance: €" + balance);
    }
}

