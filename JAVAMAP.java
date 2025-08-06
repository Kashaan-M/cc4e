import java.util.Map;
import java.util.TreeMap;

// A Map is an interface, A TreeMap is an implementation
// Trees are a great way to store key-value data, but they
// take more memory then linked lists.
// A Tree map is an ordered key value store
// a hash map is a simpler tree implementation but it doesn't
// keep things in order

public class JAVAMAP {
    public static void main(String[] args) {
        Map<String, Integer> mp = new TreeMap<String, Integer> ();

        System.out.printf("Testing map class\n");
        mp.put("z",0);
        mp.put("z",1);
        mp.put("y",2);
        mp.put("b",3);
        mp.put("a",4);
        System.out.println("z=" + mp.getOrDefault("z", 42));
        System.out.println("x=" + mp.getOrDefault("x", 42));

        System.out.printf("\nIterate\n");
        for (Map.Entry<String,Integer> entry : mp.entrySet()) {
            System.out.println("Key = " + entry.getKey() + ", value = " + entry.getValue());
        }
    }
}