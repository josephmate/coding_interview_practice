import java.util.*;

public class ProducerConsumerWithMonitor implements ProducerConsumerModel {

	public Runnable make(
		int bufferSize,
		int numProducers, 
		int numItemsPerProducer, 
		int produceTime, 
		int numConsumers, 
		int consumeTime)  {
		return new Runnable() {

			public boolean producersNotDone(List<Producer> producers) {
				Iterator<Producer> pIterator = producers.iterator();
				while(pIterator.hasNext()) {
					if(pIterator.next().done) {
						pIterator.remove();
					}
				}
				return !producers.isEmpty();
			}

			public boolean consumersNotDone(List<Consumer> consumers) {
				Iterator<Consumer> cIterator = consumers.iterator();
				while(cIterator.hasNext()) {
					if(cIterator.next().done) {
						cIterator.remove();
					}
				}
				return !consumers.isEmpty();
			}

			public void run() {
				Object lock = new Object();
				synchronized(lock) {

					// shared data
					Buffer buffer = new Buffer(bufferSize);
					
					// create producers
					List<Producer> producers = new ArrayList<>(numProducers);
					List<Thread> producerThreads = new ArrayList<>(numProducers);
					for(int i = 0; i < numProducers; i++) {
						Producer producer = new Producer(i, numItemsPerProducer, produceTime, buffer, lock);
						Thread producerThread = new Thread(producer);
						producers.add(producer);
						producerThreads.add(producerThread);
					}
					
					// create consumers
					List<Consumer> consumers = new ArrayList<>();
					List<Thread> consumerThreads = new ArrayList<>(numProducers);
					for(int i = 0; i < numConsumers; i++) {
						Consumer consumer = new Consumer(i, consumeTime, buffer, lock);
						Thread consumerThread = new Thread(consumer);
						consumers.add(consumer);
						consumerThreads.add(consumerThread);
					}
					
					// start the threads
					for(Thread consumerThread : consumerThreads) {
						consumerThread.start();
					}
					for(Thread producerThread : producerThreads) {
						producerThread.start();
					}
					
					// wait for everything to finish
					while( producersNotDone(producers) ) {
						try {
							lock.wait();
						} catch(InterruptedException e) {
							return;
						}
					}
					
					// let the consumers know that there is no more work to do
					buffer.done();
					while( consumersNotDone(consumers) ) {
						try {
							lock.wait();
						} catch(InterruptedException e) {
							return;
						}
					}

				}
			}
		};
	}
	
}

class Buffer {
	
	int [] buffer;
	int lastIdxAdded;
	boolean done;

	Buffer(int bufferSize) {
		buffer = new int[bufferSize];
		lastIdxAdded = -1;
	}
	
	public synchronized void done() {
		done = true;
		notifyAll();
	}

	public synchronized int removeTask() {
		if(done) {
			return -1;
		}
		// wait until producer adds something
		while(lastIdxAdded < 0) {
			try {
				wait();
			} catch(InterruptedException e) {
				return -1;
			}
			if(done) {
				return -1;
			}
		}

		// if we get out of the loop, there is at least one item, and it's
		// guarenteed to be untouched because we're the only one in the critical
		// section
		
		int ret = buffer[lastIdxAdded];
		lastIdxAdded--;
		notify();
		return ret;
	}

	public synchronized void addTask(int id) {
		while(lastIdxAdded+1 >= buffer.length) {
			try {
				wait();
			} catch(InterruptedException e) {
				return;
			}
		}

		lastIdxAdded++;
		buffer[lastIdxAdded] = id;
		notify();
	}
}

class Producer implements Runnable {

	int id;
	int items;
	int produceTime;
	Buffer buffer;
	Object toNotify;
	boolean done = false;

	Producer(int id, int items, int produceTime, Buffer buffer, Object toNotify) {
		this.id = id;
		this.items = items;
		this.produceTime = produceTime;
		this.buffer = buffer;
		this.toNotify = toNotify;
	}

	public void run() {
		for(int i = 0; i < items; i++) {
			try {
				Thread.sleep(produceTime);
			} catch(InterruptedException e) {
				return;
			}
			System.out.println("producer " + id + " trying to add task");
			buffer.addTask(i);
			System.out.println("producer " + id + " done adding task");
		}
		
		System.out.println("producer " + id + " done");

		// let the main thread know we're done
		synchronized(toNotify) {
			done = true;
			toNotify.notify();
		}
	}

}

class Consumer implements Runnable {

	int id;
	int items;
	int consumeTime;
	Buffer buffer;
	Object toNotify;
	boolean done = false;

	Consumer(int id, int consumeTime, Buffer buffer, Object toNotify) {
		this.id = id;
		this.consumeTime = consumeTime;
		this.buffer = buffer;
		this.toNotify = toNotify;
	}

	public void run() {
		int taskid;
		while(true) {

			System.out.println("consumer " + id + " trying to get task");
			taskid = buffer.removeTask();
			if(taskid == -1) {
				break;
			}

			System.out.println("consumer " + id + " taking task from producer " + taskid);
			try {
				Thread.sleep(consumeTime);
			} catch(InterruptedException e) {
				return;
			}
		}

		System.out.println("consumer " + id + " done");

		// let the main thread know we're done
		synchronized(toNotify) {
			done = true;
			toNotify.notify();
		}
	}
}
