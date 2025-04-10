import java.util.ArrayList;
import java.util.List;

public class Product{
	private String productName;
	private long price;
	private boolean inStock;
	private List<String> tags;
	public Product(){
		this.productName = "Unknown";
		this.price = 0;
		this.inStock = false;
		this.tags = new ArrayList<>();
	}

	public Product(String productName){
		this.productName = productName != null ? productName : "Unknown";
		this.price = 0;
		this.inStock = false;
		this.tags = new ArrayList<>();
	}

    	public Product(String productName, long price) {
        	this.productName = productName != null ? productName : "Unknown";
       		this.price = price >= 0 ? price : 0;
        	this.inStock = false;
        	this.tags = new ArrayList<>();
    	}


	public Product(String productName, long price, boolean inStock){
		this.productName = productName != null ? productName : "Unknown";
		this.price = price >= 0 ? price : 0;
		this.inStock = inStock;
		this.tags = new ArrayList<>();
	}

    	public Product(String productName, long price, List<String> tags) {
        	this.productName = productName != null ? productName : "Unknown";
        	this.price = price >= 0 ? price : 0;
        	this.inStock = false;
       		this.tags = (tags != null) ? new ArrayList<>(tags) : new ArrayList<>();
    	}

	public Product(String productName, long price, boolean inStock, List<String> tags) {
        	this.productName = productName != null ? productName : "Unknown";
        	this.price = price >= 0 ? price : 0;
        	this.inStock = inStock;
        	this.tags = (tags != null) ? new ArrayList<>(tags) : new ArrayList<>();
    	}

    	public Product(Product other) {
        	this.productName = other.productName;
        	this.price = other.price;
        	this.inStock = other.inStock;
        	this.tags = new ArrayList<>(other.tags);
    	}

    	public List<String> getTags() {
        	return new ArrayList<>(tags);
    	}

    	public void setTags(List<String> tags) {
        	this.tags = (tags != null) ? new ArrayList<>(tags) : new ArrayList<>();
    	}

    	public void addTag(String tag) {
        	if (tag != null && !tag.isEmpty()) {
            	this.tags.add(tag);
        	}
    	}

    	@Override
    	public String toString() {
        	return "Product{" +
                	"productName='" + productName + '\'' +
                	", price=" + price +
                	", inStock=" + inStock +
                	", tags=" + tags +
                	'}';
    	}
}
