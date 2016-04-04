import java.util.*;

public class Main {

	public static void main(String []args) {
		if(args.length != 2) {
			throw new IllegalArgumentException(
					"This program needs exactly two argument arguments: the two strings to determine if they are rotations of each other");
		}
		int arg = 0;
		String a = args[arg++];
		String b = args[arg++];
		
		System.out.println("a:      " + a);
		System.out.println("b:      " + b);
		System.out.println("result: " + IsRotation.isRotation(a,b));
		
	}

}
