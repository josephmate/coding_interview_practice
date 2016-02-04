

Explain the term "busy waiting" and how it can be avoided.

== Busy Waiting ==

You have busy waiting When one thread, waits for a result from another thread in a NOOP/empty loop:

Thread thread2 = new Thread(new SomeRunnable());
thread2.start();

while( waitingForThread2() ) {
	// empty loop
}

You want to avoid this pattern because it wastes CPU cycles: 

1. Other threads you have running could of made use of those cycles
2. Other processes sharing the same machine could have also used those cycles
3. If the machine only has one CPU, thread2 could have made use of those cycles

== Poor Solution: Sleep ==
while( waitingForThread2() ) {
	Thread.sleep(1000); // Sleep for 1 second
}

This is an improvement over busy waiting as we're now using less cycles. However
there are still some draw backs to this pattern:

1. You're still wasting cycles. It may seem like you're wasting one cycle every
	 second. However, every time the thread wakes up, takes many cycles because
   you have reload the threads stack, registers, etc.
2. What do you set as the sleep duration?
  1. Set it too long, and there is a long delay between thread 2 finishing and
		 the main recognizing that it's done
  2. Set it too short, and you increase the amount of wasted cycles

== Better but Still Poor Solution: Exponential Backoff ==

To take away a bit of the tuning, we can add an exponential backoff. To describe
the process, imagine that your plane gets delayed for some unknown period of
time. What do you do? Well first you might go to the washroom for a few minutes.
Then you might get something to eat for half an hour. Then you might play a game
on your cellphone for an hour. Finally, you'll read a book for the next couple
of hours. Your waiting tasks become progressively larger as you wait more.
That's the idea behind exponential backoff.

private static final int MAX_BACKOFF=1000*60*60; // 1 hour
private static final int INITIAL_BACKOFF=100; // 100ms 
int backOff=INITIAL_BACKOFF;
while( waitingForThread2() ) {
	Thread.sleep(backOff); // Sleep for 1 second
	backOff=backOff<<2; //bit shift to the left to multiply by 2
	if(backOff > MAX_BACKOFF) {
		backOff = MAX_BACKOFF;
	}
}
