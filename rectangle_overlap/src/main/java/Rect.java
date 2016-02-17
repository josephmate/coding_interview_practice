
public class Rect {
	public Point ul;
	public Point lr;

	public Rect( Point ul, Point lr ){
		if(lr.y >= ul.y) {
			throw new IllegalArgumentException("ul must be up and to the left of lr. lr: " + lr + ", ul: " + ul);
		}
		if(lr.x <= ul.x) {
			throw new IllegalArgumentException("ul must be up and to the left of lr. lr: " + lr + ", ul: " + ul);
		}
		this.ul = ul;
		this.lr = lr;
	}

	/**
	 * Computing if two overlap has so many cases:
	 * - at least one corner is inside
	 * - completely inside
	 * - no corners inside
	 * and each of these have multiple comparisons.
	 *
	 * It's easier to compute if two rectangles do not overlap.
	 * not(
	 *    r1.ul.y < r2.lr.y // r2 is above r1
	 * or r1.lr.y > r2.ul.y // r2 is below r1
	 * or r1.ul.x > r2.lr.x // r2 is to the left of r1
	 * or r1.lr.x < r2.ul.x // r2 is to the right of r1
	 * )
	 * <=>
	 *     r1.ul.y >= r2.lr.y // r2 is above r1
	 * and r1.lr.y <= r2.ul.y // r2 is below r1
	 * and r1.ul.x <= r2.lr.x // r2 is to the left of r1
	 * and r1.lr.x >= r2.ul.x // r2 is to the right of r1
	 */
	public static boolean overlapping(Rect r1, Rect r2) {
		return 
			r1.ul.y >= r2.lr.y      // r2 is above r1
			&& r1.lr.y <= r2.ul.y   // r2 is below r1
			&& r1.ul.x <= r2.lr.x   // r2 is to the left of r1
			&& r1.lr.x >= r2.ul.x;  // r2 is to the right of r1
	}

	@Override
	public String toString() {
		return "[" + lr + ", " + ul + "]";
	}
}

