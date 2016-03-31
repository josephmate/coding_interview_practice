import java.util.*;

public class Main {

	public static void main(String []args) {
		if(args.length != 1) {
			throw new IllegalArgumentException(
					"This program needs exactly argument arguments: the size of the array");
		}
		int arg = 0;
		int n = Integer.parseInt(args[arg++]);
		
		int [][] input = new int[n][n];

		int c = 1;
		for(int i = 0; i < n; i++) {
			for (int j =0; j<n; j++) {
				input[i][j] = c;
				c++;
			}
		}
		
		System.out.println("input:");
		printMatrix(input);

		RotateMatrix.rotateMatrix(input);
		System.out.println("output:");
		printMatrix(input);
	}

	private static void printMatrix(int [][] matrix) {
		for(int i = 0; i < matrix.length; i++) {
			for (int j =0; j<matrix[i].length; j++) {
				System.out.print(matrix[i][j] + "\t");
			}
			System.out.println();
		}
	}

}
