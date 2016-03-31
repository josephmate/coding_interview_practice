import java.util.*;

public class RotateMatrix {
	
	/**
	 * Rotates the 2D matrix in play by 90 degrees clockwise
	 *
	 * 1 2
	 * 3 4
	 *
	 * becomes
	 *
	 * 3 1
	 * 4 2
	 *
	 *  1  2  3  4  5  6  7
	 *  8  9 10 11 12 13 14
	 * 15 16 17 18 19 20 21
	 * 22 23 24 25 26 27 28
	 * 29 30 31 32 33 34 35
	 * 36 37 38 39 40 41 42
	 * 43 44 45 46 47 48 49
	 *
	 * As you can see from the example above we have |_n/2_| shells to rotate
	 *
	 * The rotation of the first shell goes from 0th to n-2th offset
	 * 43 36 29 22 15  8  1
	 * 44  9 10 11 12 13  2
	 * 45 16 17 18 19 20  3
	 * 46 23 24 25 26 27  4
	 * 47 30 31 32 33 34  5
	 * 48 37 38 39 40 41  6
	 * 49 42 35 28 21 14  7
	 *
	 * The rotation of the second shell goes from the 1st to n-3th offset
	 */
	public static void rotateMatrix(int [][] matrix) {
		int n = matrix.length;

		for(int shell = 0; shell < n/2; shell++) {
			rotateShell(matrix, shell, n);
		}

	}

	private static void rotateShell(int[][] matrix, int shell, int n) {
		for(int offset = shell; offset <= n-2-shell; offset++) {
			//top left  matrix[shell         ][shell+offset]
			//top right matrix[shell+offset  ][n-1-shell]
			//bot right matrix[n-1-shell       ][n-1-shell-offset]
			//bot left  matrix[n-1-offset-shell][shell]
			
			// top left into tmp
			int tmp = matrix[shell         ][shell+offset];
			// bot left into top right
			matrix[shell         ][shell+offset]    = matrix[n-1-offset-shell][shell];
			// bot right into bot left
			matrix[n-1-offset-shell][shell]         = matrix[n-1-shell       ][n-1-shell-offset];
			// top right into bot right
			matrix[n-1-shell       ][n-1-shell-offset] = matrix[shell+offset  ][n-1-shell];
			// top left (tmp) into top right
			matrix[shell+offset  ][n-1-shell]       = tmp;
		}
	}

}
