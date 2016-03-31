import java.util.*;

public class Main {

	public static void main(String []args) {
		if(args.length != 1) {
			throw new IllegalArgumentException(
					"This program needs exactly argument arguments: the string to be encoded");
		}
		int arg = 0;
		String input = args[arg++];
		
		System.out.println("input:   " + input);
		System.out.println("encoded: " + new String(EncodeSpace.encodeSpace(input.toCharArray())));
		
	}

}
