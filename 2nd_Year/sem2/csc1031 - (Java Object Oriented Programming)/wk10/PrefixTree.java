import java.util.HashMap;

class TrieNode {
    char value;
    HashMap<Character, TrieNode> children;
    boolean isEndOfWord;

    public TrieNode(char value) {
        this.value = value;
        this.children = new HashMap<>();
        this.isEndOfWord = false;
    }

    public void markAsLeaf() {
        this.isEndOfWord = true;
    }
}

public class PrefixTree {
    private TrieNode root;

    public PrefixTree() {
        root = new TrieNode('\0');
    }

    public void insert(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            current.children.putIfAbsent(ch, new TrieNode(ch));
            current = current.children.get(ch);
        }
        current.markAsLeaf();
    }

    public boolean search(String word) {
        TrieNode node = getNode(word);
        return node != null && node.isEndOfWord;
    }

    public boolean startsWith(String prefix) {
        return getNode(prefix) != null;
    }

    private TrieNode getNode(String str) {
        TrieNode current = root;
        for (char ch : str.toCharArray()) {
            if (!current.children.containsKey(ch)) {
                return null;
            }
            current = current.children.get(ch);
        }
        return current;
    }

    public void traverse() {
        traverseHelper(root, "", "");
    }

    private void traverseHelper(TrieNode node, String prefix, String indent) {
        if (node != root) {
            System.out.println(indent + "└── " + node.value + (node.isEndOfWord ? " (end)" : ""));
        }
        for (TrieNode child : node.children.values()) {
            traverseHelper(child, prefix + child.value, indent + "  ");
        }
    }
}
