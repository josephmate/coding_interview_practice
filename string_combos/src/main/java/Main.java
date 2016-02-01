import java.util.*;

public class Main {

	public static void main(String []args) {
		if(args.length < 1) {
			throw new IllegalArgumentException(
					"This program need exactly one argument: the string to find combinations for");
		}
		String strToCombo = args[0];
		
		System.out.println("the string to find combinations for: " + strToCombo);

		System.out.println("combinations:");
		for(String combo : StringCombos.stringCombos(strToCombo)) {
			System.out.println(combo);
		}

	}

}
