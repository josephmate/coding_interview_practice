import java.util.*;

public class Main {
	
	public static void main(String []args) {
		if(args.length != 1) {
			throw new IllegalArgumentException(
					"./runjar.sh <num_disks>");
		}
		int argCounter = 0;
		int numDisks = Integer.parseInt(args[argCounter++]);

		solve(numDisks);

	}

	public static void solve(int numDisks) {
		List<Stack<Integer>> stacks = new ArrayList<>(3);
		for(int i = 0; i < 3; i++) {
			stacks.add(new Stack<>());
		}
		for(int i = numDisks; i>=1; i--){
			stacks.get(0).push(i);
		}

		solveRecurse(stacks, numDisks, 0, 2, 1);


		System.out.println("final stacks look like:");
		for(int i = 0; i < 3; i++) {
			System.out.println("stack " + i);
			while(!stacks.get(i).empty()) {
				System.out.println(stacks.get(i).pop());
			}
		}
	}

	public static void solveRecurse(List<Stack<Integer>> stacks, int numDisks, int fromStack, int toStack, int bufferStack) {
		if(numDisks == 1) {
			int disk = stacks.get(fromStack).pop();
			stacks.get(toStack).push(disk);
			System.out.println("moved " + disk + " from " + fromStack + " to " + toStack);
		} else {
			solveRecurse(stacks, numDisks-1, fromStack, bufferStack, toStack);
			solveRecurse(stacks,          1, fromStack, toStack, bufferStack);
			solveRecurse(stacks, numDisks-1, bufferStack, toStack, fromStack);
		}
	}


}

