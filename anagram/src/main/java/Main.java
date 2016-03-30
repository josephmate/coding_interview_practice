import java.util.*;

public class Main {

	private static SortedMap<String, Anagram> impls = new TreeMap<>();

	public static void main(String []args) {
		if(args.length != 2) {
			throw new IllegalArgumentException(
					"This program needs exactly two arguments: stringA stringB");
		}
		int arg = 0;
		String a = args[arg++];
		String b = args[arg++];
		
		System.out.println("a: " + a);
		System.out.println("b: " + b);
		
		for(Map.Entry<String,Anagram> e : impls.entrySet()) {
			System.out.println(e.getKey() + ": " + e.getValue().anagram(a.toCharArray(),b.toCharArray()));
		}
		
	}

}
