import java.util.*;

public class Main {

	public static void main(String []args) {
		if(args.length < 1) {
			throw new IllegalArgumentException(
					"This program need exactly one argument: the string to permute");
		}
		String strToPermute = args[0];
		
		System.out.println("the string to permute: " + strToPermute);

		System.out.println("permutations:");
		for(String permutation : PermuteString.permuteString(strToPermute)) {
			System.out.println(permutation);
		}

	}

}
