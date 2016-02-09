import java.util.concurrent.locks.*;

public class FairDiningPhilosophers implements DiningPhilosophers {

	public Runnable make(
		int numPhilosophers,
		long eatTime ) {
		return new Runnable() {
			public void run() {
				ForkAndLock [] forks = new ForkAndLock[numPhilosophers];
				for(int i = 0; i < numPhilosophers; i++) {
					forks[i] = new ForkAndLock(i);
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
					threads[i] = new Thread( new FairPhilosopher(i, eatTime, forks[lowFork], forks[highFork]));
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

class ForkAndLock { 
	final int id;
 	final ReentrantLock lock = new ReentrantLock(true); // true ensures it's fair

	public ForkAndLock(int id) {
		this.id=id;
	}
}

class FairPhilosopher implements Runnable {
	int id;
	long eatTime;
	ForkAndLock lowFork;
	ForkAndLock highFork;

	public FairPhilosopher(int id, long eatTime, ForkAndLock lowFork, ForkAndLock highFork) {
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

			lowFork.lock.lock();
		 	try {
				highFork.lock.lock();
				try {
					System.out.println(id + " ate and starved for " + (System.currentTimeMillis() - lastAteTime));
					Thread.sleep(eatTime);
					lastAteTime = System.currentTimeMillis();
				} finally {
					highFork.lock.unlock();
				}
			} catch (InterruptedException e) {
				System.exit(0);
			} finally {
				lowFork.lock.unlock();
			}
		}
	}
}
