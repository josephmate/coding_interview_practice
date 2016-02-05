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
			public void run() {
				// TODO
			}
		};
	}
	
}
