import java.util.*;

public class Main {

	public static void main(String []args) {
		if(args.length < 1) {
			throw new IllegalArgumentException(
					"This program need exactly one argument: the telephone number to generate words for");
		}
		int telephone = Integer.parseInt(args[0]);
		
		System.out.println("telephone number: " + telephone);

		System.out.println("telephone words:");
		for(String word : TelephoneWords.telephoneWords(telephone)) {
			System.out.println(word);
		}

	}

}
