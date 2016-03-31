import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public class TestRotateMatrix {
	
	private static void check(int [][] expected, int[][] actual) {
		assertEquals(expected.length, actual.length);

		for(int i = 0; i < expected.length; i++) {
			assertArrayEquals(expected[i], actual[i]);
		}
	}

	@Test
	public void test() {
		int [][] n0input = {};
		int [][] n0output = {};
		RotateMatrix.rotateMatrix(n0input);
		check(n0output, n0input);

		int [][] n1input = {{1}};
		int [][] n1output = {{1}};
		RotateMatrix.rotateMatrix(n1input);
		check(n1output, n1input);


		int [][] n2input = {
			{1,2},
			{3,4}
		};
		int [][] n2output = {
			{3,1},
			{4,2}
		};
		RotateMatrix.rotateMatrix(n2input);
		check(n2output, n2input);
		
		int [][] n3input = {
			{1,2,3},
			{4,5,6},
			{7,8,9},
		};
		int [][] n3output = {
			{7,4,1},
			{8,5,2},
			{9,6,3},
		};
		RotateMatrix.rotateMatrix(n3input);
		check(n3output, n3input);
		
		int [][] n4input = {
			{ 1, 2, 3, 4},
			{ 5, 6, 7, 8},
			{ 9,10,11,12},
			{13,14,15,16},
		};
		int [][] n4output = {
			{13, 9, 5, 1},
			{14,10, 6, 2},
			{15,11, 7, 3},
			{16,12, 8, 4},
		};
		RotateMatrix.rotateMatrix(n4input);
		check(n4output, n4input);
	}


}
