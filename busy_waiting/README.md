

Explain the term "busy waiting" and how it can be avoided.

## Busy Waiting

You have busy waiting When one thread, waits for a result from another thread in a NOOP/empty loop. 
We will explore waiting for a result from two threads.

```
Thread thread1 = new Thread(new SomeRunnable());
Thread thread2 = new Thread(new SomeRunnable());
thread1.start();
thread2.start();

while( waitinigForThread1() && waitingForThread2() ) {
	// empty loop
}
// do something with result from thread1 and thread2
```

You want to avoid this pattern because it wastes CPU cycles: 

1. Other threads you have running could of made use of those cycles
2. Other processes sharing the same machine could have also used those cycles
3. If the machine only has one CPU, thread2 could have made use of those cycles

## BPoor Solution: Sleep
```
while( waitinigForThread1() && waitingForThread2() ) {
	Thread.sleep(1000); // Sleep for 1 second
}
```

This is an improvement over busy waiting as we're now using less cycles. However
there are still some draw backs to this pattern:

1. You're still wasting cycles. It may seem like you're wasting one cycle every
	 second. However, every time the thread wakes up, takes many cycles because
   you have reload the threads stack, registers, etc.
2. What do you set as the sleep duration?
  1. Set it too long, and there is a long delay between thread 2 finishing and
		 the main recognizing that it's done
  2. Set it too short, and you increase the amount of wasted cycles

## Better but Still Poor Solution: Exponential Backoff

To take away a bit of the tuning, we can add an exponential backoff. To describe
the process, imagine that your plane gets delayed for some unknown period of
time. What do you do? Well first you might go to the washroom for a few minutes.
Then you might get something to eat for half an hour. Then you might play a game
on your cellphone for an hour. Finally, you'll read a book for the next couple
of hours. Your waiting tasks become progressively larger as you wait more.
That's the idea behind exponential backoff.
```
private static final int MAX_BACKOFF=1000*60*60; // 1 hour
private static final int INITIAL_BACKOFF=100; // 100ms 
int backOff=INITIAL_BACKOFF;
while( waitinigForThread1() && waitingForThread2() ) {
	Thread.sleep(backOff); // Sleep for 1 second
	backOff=backOff<<2; //bit shift to the left to multiply by 2
	if(backOff > MAX_BACKOFF) {
		backOff = MAX_BACKOFF;
	}
}
```

## Decent Solution: Locking or Monitors

You can setup up some locks to ensure that the main thread has successfully
'waited' on the lock. Then the two threads 'notify' when they have finished.
Each 'notify' wakes the main thread and the main thread check to see if both
threads finished. 

This method uses the least possible cycles, but it is error prone. If not coded
properly, you can end up with race conditions or deadlocks.

## Good Solution: Futures and Other Concurrency Libraries

Instead of trying to carefully code this pattern every time, you can use
libraries that have already correctly implemented these patterns for us. In our
example where we're waiting for two results from two threads we can apply
Futures.

```
ExecutorService executor = ...
// Runs in separate thread
Future<String> future1 = executor.submit( new Callable<String>() { /* do work for first result here */ } ); 
// Runs in separate thread
Future<String> future2 = executor.submit( new Callable<String>() { /* do work for second result here */ } ); 
String result1 = future1.get();
String result2 = future2.get();
```
From the example we can immediately see that it's the most elegant solution, and less bug prone. 
But more importantly, we still using the least possible cycles as execution of the main thread only resumes when one of the futures completes.

Here we were looking at an example waiting on two sub tasks to complete.
However, there are many other very different waiting scenarios and the stanard
libraries of C# and Java provide many concurrency facilities to make developer's
lives easier. Before trying to code up your own monitor or locking, see if you
problem has been solved before.

