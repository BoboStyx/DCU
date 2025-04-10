import java.util.Base64;

interface EncryptionStrategy{
	String encrypt(String text);
}

class CaesarCipherEncryption implements EncryptionStrategy{
    private final int shift;

    public CaesarCipherEncryption(int shift){
        this.shift = shift;
    }

	@Override
	public String encrypt(String text){
		StringBuilder result = new StringBuilder();
		for (char ch : text.toCharArray()) {
			if (Character.isLetter(ch)) {
				char base = Character.isUpperCase(ch) ? 'A' : 'a';
				result.append((char) ((ch - base + shift) % 26 + base));
            }
			else{
            	result.append(ch);
			}
		}
		return result.toString();
	}
}

class Base64Encryption implements EncryptionStrategy{
	@Override
	public String encrypt(String text){
		return Base64.getEncoder().encodeToString(text.getBytes());
	}
}

class XOREncryption implements EncryptionStrategy{
	private final char key;

	public XOREncryption(char key){
		this.key = key;
	}

	@Override
	public String encrypt(String text){
    StringBuilder result = new StringBuilder();
            for (char ch : text.toCharArray()) {
                result.append((char) (ch ^ key));
            }
            return result.toString();
	}
}

class ReverseStringEncryption implements EncryptionStrategy{

	@Override
	public String encrypt(String text){
		StringBuilder result = new StringBuilder(text).reverse();
		return result.toString();
	}
}

class DuplicateCharacterEncryption implements EncryptionStrategy{

	@Override
	public String encrypt(String text){
	StringBuilder result = new StringBuilder();
		for (char ch : text.toCharArray()){
			result.append(ch).append(ch);
		}
		return result.toString();
	}
}

public class EncryptionService{
	public EncryptionStrategy strategy;

	public void setEncryptionStrategy(EncryptionStrategy strategy){
		this.strategy = strategy;
	}

	public String encrypt(String text){
		return strategy.encrypt(text);
	}
}

