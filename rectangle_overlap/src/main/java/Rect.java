
public class Rect {
	public Point ul;
	public Point lr;

	public Rect( Point ul, Point lr ){
		if(lr.y <= ul.y) {
			throw new IllegalArgumentException("ul must be up and to the left of lr. lr: " + lr + ", ul: " + ul);
		}
		if(lr.x >= ul.x) {
			throw new IllegalArgumentException("ul must be up and to the left of lr. lr: " + lr + ", ul: " + ul);
		}
		this.ul = ul;
		this.lr = lr;
	}

	public static boolean overlapping(Rect r1, Rect r2) {
		return false;
	}

	@Override
	public String toString() {
		return "[" + lr + ", " + ul + "]";
	}
}

