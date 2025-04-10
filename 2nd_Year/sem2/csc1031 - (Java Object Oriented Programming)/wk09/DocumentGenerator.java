import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

interface Reader{
    Scanner scanner = new Scanner(System.in);
}

abstract class Document implements Reader {
    protected List<String> content = new ArrayList<>();

    public final void generateDocument() {
        createHeader();
        createBody();
        createFooter();
        printDocument();
    }

    private void createHeader() {
        System.out.print("Enter company name: ");
        String companyName = scanner.nextLine();
        if (companyName.isEmpty()) throw new IllegalArgumentException("Error: Company name cannot be empty.");

        System.out.print("Enter date (DD/MM/YYYY): ");
        String date = scanner.nextLine();
        if (date.isEmpty()) throw new IllegalArgumentException("Date cannot be empty.");

        content.add("Company: " + companyName);
        content.add("Date: " + date);
	}

	public void printDocument(){
		for (String info: content){
			System.out.println(info);
		}
	}

    protected abstract void createBody();
	protected abstract void createFooter();
}

class Invoice extends Document {
    @Override
    protected void createBody() {
        System.out.print("Enter total amount: ");
		if (!scanner.hasNextDouble()) {
			throw new IllegalArgumentException("Error: Total amount must be numeric.");
		}
        double totalAmount = scanner.nextDouble();
        if (totalAmount <= 0) throw new IllegalArgumentException("Error: Total amount must be positive.");
		System.out.print("\n");
        content.add("Total Due: €" + totalAmount);
		System.out.println("=== Printing Document ===");
		System.out.println("=== INVOICE ===");
    }

    @Override
    protected void createFooter() {
        content.add("Prepared by: AutoDoc System");
        content.add("Document Type: INVOICE");
    }
}

class Report extends Document {
    @Override
    protected void createBody() {
        System.out.print("Enter report summary: ");
        String summary = scanner.nextLine();
        if (summary.isEmpty()) {
            System.out.println("Warning: Summary is empty.");
        }
        content.add("Report Summary: " + summary);
		System.out.print("\n");
		System.out.println("=== Printing Document ===");
		System.out.println("=== REPORT ===");
    }

    @Override
    protected void createFooter() {
        content.add("Reviewed by: Management Department");
    }
}

class Receipt extends Document {
    @Override
    protected void createBody() {

        System.out.print("Enter amount paid: ");
        double amountPaid = scanner.nextDouble();
        if (amountPaid <= 0) throw new IllegalArgumentException("Error: Amount paid must be positive.");
        content.add("Total Paid: €" + amountPaid);

        System.out.print("Enter number of items: ");
        int itemsCount = scanner.nextInt();
        if (itemsCount <= 0) throw new IllegalArgumentException("Error: Items count must be positive.");
		if (itemsCount == 0) throw new ArithmeticException("Cannot divide by zero.");

        double pricePerItem = amountPaid / itemsCount;
        content.add("Items Purchased: " + itemsCount);
        content.add("Price per Item: €" + pricePerItem);
		System.out.print("\n");
		System.out.println("=== Printing Document ===");
		System.out.println("=== RECEIPT ===");
    }

    @Override
    protected void createFooter() {
        content.add("Prepared by: AutoDoc System");
        content.add("Document Type: RECEIPT");
    }
}

public class DocumentGenerator implements Reader{
    public static void main(String[] args) {
        try {
            System.out.println("Choose document type: (INV) Invoice, (REP) Report, (REC) Receipt");
            String choice = scanner.nextLine();
            Document document;
            switch (choice) {
                case "INV":
                    document = new Invoice();
                    break;
                case "REP":
					document = new Report();
					break;
				case "REC":
					document = new Receipt();
					break;
				default:
					throw new IllegalArgumentException("Invalid choice. Exiting.");
			}

		document.generateDocument();;

		System.out.println("=========================");
		}
		catch (IllegalArgumentException e){
            System.out.println(e.getMessage());
		}
		catch (ArithmeticException e){
            System.out.println(e.getMessage());
		}
	}
}
