import org.junit.Test;
import static org.junit.Assert.*;

public class TestHeap {

	/**
	 *              ______________0_____________________
	 *             |                                    |
	 *        _____1__________                __________2______
	 *        |               |               |                |
	 *    ____3____       ____4___        ____5___          ___6___
	 *    |       |       |       |       |       |         |      |
	 *    7       8       9      10      11       12       13      14
	 *  15 16   17 18   19 20  21  22  23  24   25  26   27  28  29  30
	 */
	@Test
	public void testGetIdxOfParent() {
		assertEquals("By my defn, the parent of the root is the root", 0, Heap.getIdxOfParent(0));
		assertEquals(0, Heap.getIdxOfParent(1));
		assertEquals(0, Heap.getIdxOfParent(2));
		assertEquals(1, Heap.getIdxOfParent(3));
		assertEquals(1, Heap.getIdxOfParent(4));
		assertEquals(2, Heap.getIdxOfParent(5));
		assertEquals(2, Heap.getIdxOfParent(6));
		assertEquals(13, Heap.getIdxOfParent(27));
	}

	@Test
	public void testGetIdxOfChild() {
		assertEquals(1, Heap.getIdxOfChild(0, true));
		assertEquals(2, Heap.getIdxOfChild(0, false));
		assertEquals(3, Heap.getIdxOfChild(1, true));
		assertEquals(4, Heap.getIdxOfChild(1, false));
		assertEquals(27, Heap.getIdxOfChild(13, true));
		assertEquals(28, Heap.getIdxOfChild(13, false));
	}
	
	/**
	* no element test
	*/
	
	@Test(expected=IllegalArgumentException.class)
	public void testNoElements() {
		Heap heap = new Heap();
		heap.max();
	}

	@Test
	public void testHeap() {
		Heap heap = new Heap();

		// size 1 heap
		heap.add(12);
		assertEquals(12, heap.deleteMax());
		
		// size 2 heap
		heap.add(12);
		heap.add(42);
		assertEquals(42, heap.deleteMax());
		assertEquals(12, heap.deleteMax());

		// size 3 heap promote left
		heap.add(42);
		heap.add(32);
		heap.add(12);
		assertEquals(42, heap.deleteMax());
		assertEquals(32, heap.deleteMax());
		assertEquals(12, heap.deleteMax());

		// size 3 heap promote right 
		heap.add(42);
		heap.add(12);
		heap.add(32);
		assertEquals(42, heap.deleteMax());
		assertEquals(32, heap.deleteMax());
		assertEquals(12, heap.deleteMax());

		// size 4 heap promote right 
		heap.add(42);
		heap.add(12);
		heap.add(32);
		heap.add(9);
		assertEquals(42, heap.deleteMax());
		assertEquals(32, heap.deleteMax());
		assertEquals(12, heap.deleteMax());
		assertEquals(9, heap.deleteMax());

		// size 4 heap promote left 
		heap.add(42);
		heap.add(32);
		heap.add(12);
		heap.add(9);
		assertEquals(42, heap.deleteMax());
		assertEquals(32, heap.deleteMax());
		assertEquals(12, heap.deleteMax());
		assertEquals(9, heap.deleteMax());

		// size 5
		heap.add(42);
		heap.add(99);
		heap.add(32);
		heap.add(12);
		heap.add(9);
		assertEquals(99, heap.deleteMax());
		assertEquals(42, heap.deleteMax());
		assertEquals(32, heap.deleteMax());
		assertEquals(12, heap.deleteMax());
		assertEquals(9, heap.deleteMax());

	}
}
