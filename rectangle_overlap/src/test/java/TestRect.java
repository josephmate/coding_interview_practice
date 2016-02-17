import org.junit.Test;
import java.util.*;
import static org.junit.Assert.*;

public class TestRect {
	
	public Rect rect(int ulx, int uly, int lrx, int lry) {
		return new Rect(new Point(ulx,uly), new Point(lrx,lry));
	}

	// r2 above r1
	// r2 below r1
	// r2 left of r1
	// r2 right of r1
	//
	// r2 inside r1
	// r2 through r1
	// one corner of r2 in r1
	// two corners of r2 in r1
	@Test
	public void testRect() {
		// r2 above r1
		assertFalse(Rect.overlapping(rect(0,100,100,0), rect(0,201,100,101)));
		// r2 below r1
		assertFalse(Rect.overlapping(rect(0,100,100,0), rect(0,-1,100,-101)));
		// r2 left of r1
		assertFalse(Rect.overlapping(rect(0,100,100,0), rect(-101,100,-1,0)));
		// r2 right of r1
		//
		//     0,100            101,100
		//       *--------------*--------------
		//       |             ||             |
		//       |             ||             |
		//       |             ||             |
		//       --------------*--------------*
		//                  (100,0)          (201,0)
		//
		assertFalse(Rect.overlapping(rect(0,100,100,0), rect(101,100,201,0)));

		// r2 inside r1
		assertTrue(Rect.overlapping(rect(0,100,100,0), rect(10,60,60,10)));
		// r2 is r1
		assertTrue(Rect.overlapping(rect(0,100,100,0), rect(0,100,100,0)));
		// r2 through r1
		assertTrue(Rect.overlapping(rect(0,100,100,0), rect(20,120,80,-10)));
		// one corner of r2 in r1
		assertTrue(Rect.overlapping(rect(0,100,100,0), rect(50,150,150,50)));
		// two corners of r2 in r1
		assertTrue(Rect.overlapping(rect(0,100,100,0), rect(50,150,70,50)));
	}

}
