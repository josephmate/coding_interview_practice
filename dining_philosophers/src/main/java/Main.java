import java.util.*;

public class Main {
	
	public static enum Implementation {
		BARGING,
		FAIR
	}

	public static void main(String []args) {
		if(args.length != 3) {
			throw new IllegalArgumentException(
					"./runjar.sh [BARGING|FAIR] <num_philosphers> <philosopher_eat_time_msec>");
		}
		int argCounter = 0;
		Implementation impl = Implementation.valueOf(args[argCounter++]);
		int numPhilosophers = Integer.parseInt(args[argCounter++]);
		long eatTime = Long.parseLong(args[argCounter++]);

    DiningPhilosophers model;
		switch(impl){
			case BARGING:
				model = new BargingDiningPhilosophers();
				break;
			case FAIR:
				model = new FairDiningPhilosophers();
				break;
			default:
				throw new IllegalArgumentException(impl + " not implemented yet");
		}
		model.make(numPhilosophers, eatTime).run();
	}


}

