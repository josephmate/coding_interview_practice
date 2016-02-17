import java.util.*;

public class Main {

	public static void main(String []args) {
		if(args.length != 8) {
			throw new IllegalArgumentException(
					"./runjar.sh r1x1 r1y1 r1x2 r1y2 r2x1 r2y1 r2x2 r2y2" + "\n" +
					"            |__ul___| |_lr____| |___ul__| |__lr___|"
					);
		}
		int argCount = 0;
		int r1x1 = Integer.parseInt(args[argCount++]);
	 	int r1y1 = Integer.parseInt(args[argCount++]);
	 	int r1x2 = Integer.parseInt(args[argCount++]);
	 	int r1y2 = Integer.parseInt(args[argCount++]);
	 	int r2x1 = Integer.parseInt(args[argCount++]);
	 	int r2y1 = Integer.parseInt(args[argCount++]);
	 	int r2x2 = Integer.parseInt(args[argCount++]);
	 	int r2y2 = Integer.parseInt(args[argCount++]);
		
		Rect r1 = new Rect(new Point(r1x1, r1y1), new Point(r1x2, r1y2));
		Rect r2 = new Rect(new Point(r2x1, r2y1), new Point(r2x2, r2y2));

		System.out.println("rectangle 1: " + r1);
		System.out.println("rectangle 2: " + r2);

		if(Rect.overlapping(r1, r2)) {
			System.out.println("rectangle 1 and 2 overlap");
		} else {
			System.out.println("rectangle 1 and 2 do not overlap");
		}
	}

}
