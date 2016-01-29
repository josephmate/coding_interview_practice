

public class Main {

	public static void main(String []args) {
		if(args.length != 2) {
			System.err.println("You need exactly two arguments\n"
					+ "1) the original string\n"
					+ "2) the string of characters to be removed from the original string"
			);
			System.exit(-1);
		}
		System.out.println("The original string:                " + args[0]);
		System.out.println("Characters to be removed:           " + args[1]);
		System.out.println("The string with characters removed: " + RemoveChars.removeChars(args[0],args[1]));
	}

}
