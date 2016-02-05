import java.util.*;
import java.util.concurrent.*;

public class ProducerConsumerWithConcurencyLibrary implements ProducerConsumerModel {

	public Runnable make(
		int bufferSize,
		int numProducers, 
		int numItemsPerProducer, 
		int produceTime, 
		int numConsumers, 
		int consumeTime)  {
		return new Runnable() {
			public void run() {
				ExecutorService executor = Executors.newFixedThreadPool(numProducers + numConsumers);
				BlockingDeque<Integer> deque = new LinkedBlockingDeque<Integer>(bufferSize);

				// create producers
				List<Future<?>> producers = new ArrayList<>(numProducers);
				for(int i = 0; i < numProducers; i++) {
					producers.add(executor.submit(new ConcLibProducer(i, numItemsPerProducer, produceTime, deque)));
				}

				// create consumers
				List<Future<?>> consumers = new ArrayList<>();
				for(int i = 0; i < numConsumers; i++) {
					consumers.add(executor.submit(new ConcLibConsumer(i, consumeTime, deque)));
				}
				
				for(int i = 0; i < numProducers; i++) {
					try {
						System.out.println("waiting on producer " + i);
						producers.get(i).get();
						System.out.println("done wait for producer " + i);
					} catch(InterruptedException|ExecutionException e) {
						return;
					}
				}
				
				// let the consumers know that there is no more work to do
				for(int i = 0; i < numConsumers; i++) {
					try {
						deque.put(-1);
					} catch(InterruptedException e) {
						return;
					}
				}

				for(int i = 0; i < numConsumers; i++) {
					try {
						System.out.println("waiting on consumer " + i);
						consumers.get(i).get();
						System.out.println("done wait for consumer " + i);
					} catch(InterruptedException|ExecutionException e) {
						return;
					}
				}

				executor.shutdown();
			}
		};
	}
}

class ConcLibProducer implements Runnable {

	int id;
	int items;
	int produceTime;
	BlockingDeque<Integer> deque;

	ConcLibProducer(int id, int items, int produceTime, BlockingDeque<Integer> deque) {
		this.id = id;
		this.items = items;
		this.produceTime = produceTime;
		this.deque = deque;
	}

	public void run() {
		for(int i = 0; i < items; i++) {
			System.out.println("producer " + id + " sleeping for " + produceTime + " ms");
			try {
				Thread.sleep(produceTime);
			} catch(InterruptedException e) {
				return;
			}
			System.out.println("producer " + id + " trying to add task");
			try {
				deque.put(id);
			} catch(InterruptedException e) {
				return;
			}
			System.out.println("producer " + id + " done adding task");
		}
		
		System.out.println("producer " + id + " done");
	}

}

class ConcLibConsumer implements Runnable {

	int id;
	int items;
	int consumeTime;
	BlockingDeque<Integer> deque;

	ConcLibConsumer(int id, int consumeTime, BlockingDeque<Integer> deque) {
		this.id = id;
		this.consumeTime = consumeTime;
		this.deque = deque;
	}

	public void run() {
		int taskid;
		while(true) {

			System.out.println("consumer " + id + " trying to get task");
			try {
				taskid = deque.take();
			} catch(InterruptedException e) {
				return;
			}
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
	}
}
