

public class BargingDiningPhilosophers implements DiningPhilosophers {

	public Runnable make(
		int numPhilosophers,
		long eatTime ) {
		return new Runnable() {
			public void run() {
				Fork [] forks = new Fork[numPhilosophers];
				for(int i = 0; i < numPhilosophers; i++) {
					forks[i] = new Fork(i);
				}
				
				Thread [] threads = new Thread[numPhilosophers];
				for(int i = 0; i < numPhilosophers; i++) {
					int fork1 = i;
					int fork2 = (i+1) % numPhilosophers;
					int highFork;
					int lowFork;
					if(fork1 > fork2) {
						lowFork = fork2;
						highFork = fork1;
					} else {
						lowFork = fork1;
						highFork = fork2;
					}
					threads[i] = new Thread( new Philosopher(i, eatTime, forks[lowFork], forks[highFork]));
					System.out.println("philosopher " + i + " using forks " + forks[lowFork].id + " and " + forks[highFork].id);
				}

				for(int i = 0; i < numPhilosophers; i++) {
					threads[i].start();
				}

				for(int i = 0; i < numPhilosophers; i++) {
					try{
						threads[i].join();
					} catch (InterruptedException e) {
						System.exit(0);
					}
				}
			}
		};
	}
}

class Fork { 
	int id;

	public Fork(int id) {
		this.id=id;
	}
}

class Philosopher implements Runnable {
	int id;
	long eatTime;
	Fork lowFork;
	Fork highFork;

	public Philosopher(int id, long eatTime, Fork lowFork, Fork highFork) {
		this.id = id;
		this.eatTime = eatTime;
		this.lowFork = lowFork;
		this.highFork = highFork;
	}

	public void run() {
		long lastAteTime = System.currentTimeMillis();
		while(true) {
			// to prevent deadlocks, we use the resource heiarchy strategy:
			// 1) apply acyclic heiarchy to resources
			// 2) grab lower resource to high resource always

			synchronized(lowFork) {
				synchronized(highFork) {
					System.out.println(id + " ate and starved for " + (System.currentTimeMillis() - lastAteTime));
					try{
						if(eatTime > 0 ) {
							Thread.sleep(eatTime);
						}
					} catch (InterruptedException e) {
						System.exit(0);
					}
					lastAteTime = System.currentTimeMillis();
				}
			}

		}
	}
}
