
public interface ProducerConsumerModel {
	
	/**
	 * Produces a runnable that implements the Producer-Consumer Model
	 *
	 * The run() of the runnable should return only once all the producers have
	 * finished generating all the tasks and the consumers have finishing
	 * processing all the tasks
	 */
	public Runnable make(
		int bufferSize,
		int numProducers, 
		int numItemsPerProducer, 
		int produceTime, 
		int numConsumers, 
		int consumeTime)  ;

}
