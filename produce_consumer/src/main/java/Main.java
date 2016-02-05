import java.util.*;

public class Main {
	
	public static enum Implementation {
		MONITOR,
		CONCURRENT_LIBRARY
	}

	public static void main(String []args) {
		if(args.length != 7) {
			throw new IllegalArgumentException(
					"./runjar.sh [MONITOR|CONCURRENT_LIBRARY] <buffer_size> <num_producers> <num_items_producer_per_consumer> <producer_time_msec> <num_consumers> <consumer_time_msec>");
		}
		int argCounter = 0;
		Implementation impl = Implementation.valueOf(args[argCounter++]);
		int bufferSize = Integer.parseInt(args[argCounter++]);
		int numProducers = Integer.parseInt(args[argCounter++]);
		int numItemsPerProducer = Integer.parseInt(args[argCounter++]);
		int produceTime = Integer.parseInt(args[argCounter++]);
		int numConsumers = Integer.parseInt(args[argCounter++]);
		int consumeTime = Integer.parseInt(args[argCounter++]);
		
		ProducerConsumerModel model;
		switch(impl){
			case MONITOR:
				model = new ProducerConsumerWithMonitor();
				break;
			case CONCURRENT_LIBRARY:
				model = new ProducerConsumerWithConcurencyLibrary();
				break;
			default:
				throw new IllegalArgumentException(impl + " not implemented yet");
		}
		Runnable runner = model.make(
					bufferSize, 
					numProducers, 
					numItemsPerProducer, 
					produceTime, 
					numConsumers, 
					consumeTime 
		);
		runner.run();
	}

}
