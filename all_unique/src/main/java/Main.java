import java.util.*;

public class Main {

	private static enum Impl {
		DataStruct,
		NoDataStruct
	}

	public static void main(String []args) {
		if(args.length != 2) {
			throw new IllegalArgumentException(
					"This program needs exactly two arguments: [DataStruct|NoDataStruct] <the string to check>");
		}
		int arg = 0;
		Impl impl = Impl.valueOf(args[arg++]);
		String str = args[arg++];
		
		System.out.println("impl:         " + impl);
		System.out.println("input string: " + str);
		
		AllUniqueChars solver;
		switch(impl){
			case DataStruct:
				solver = new DataStructAllUniqueChars();
				break;
			case NoDataStruct:
				solver = new NoDataStructAllUniqueChars();
				break;
			default:
				throw new IllegalArgumentException(impl + " not implemented yet");
		}

		if(solver.allUniqueChars(str.toCharArray())) {
			System.out.println("all chars unique");
		} else {
			System.out.println("not all chars unique");
		}

	}

}
