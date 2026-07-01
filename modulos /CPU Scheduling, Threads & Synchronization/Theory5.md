# Concepts 

- **CPU Scheduling:** The OS determines who uses the CPU. Algorithms like Round-Robin use a _quantum_ (a set time limit based on clock interrupts). Context switching "wastes" CPU time to load/unload PCBs.
    
- **Threads (pthreads):** Unlike processes (which have isolated memory), sibling threads within a process share the same global variables, open files, and address space. However, **each thread has its own private stack** (for local variables) and registers.
    
- **Critical Sections & Race Conditions:** When threads/processes share memory, simultaneous writes cause non-serializable race conditions. To fix this, we protect "Critical Sections".
    
- **Correctness Criteria:** To properly protect a critical section, three rules must apply:
    
    1. _Mutual Exclusion_ (only one inside at a time)
        
    2. _Progress_ (no deadlocks)
        
    3. _Bounded Waiting_ (no starvation).


## Comprehensive Review

1. Create 3 threads. Thread 1 prints A, Thread 2 prints B, Thread 3 prints C. Execute them so the interleaving is A-B-C-A-B-C-etc. (i.e., the threads alternate in printing their letters).

```c
#include <pthread.h>
#include <stdio.h>

void *print_letter(void *letter) {
    char *l = (char *)letter;
    while (1) {
        printf("%c", *l);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    char a = 'A', b = 'B', c = 'C';

    pthread_create(&t1, NULL, print_letter, &a);
    pthread_create(&t2, NULL, print_letter, &b);
    pthread_create(&t3, NULL, print_letter, &c);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
```

## Mock Multiple choice questions

**Q1 (Multiple Choice):** Which of the following is NOT shared among sibling threads belonging to the same process?

A) Global Variables

B) Open File Descriptors

C) Program Code

D) Local Stack Variables

## Theory Questions

1. ***Explain Round-Robin scheduling and the concept of a "quantum".***
  - Each thread is assigned a time slice (quantum) to execute.
  - The scheduler cycles through the threads, giving each one a turn to execute for its quantum.
  - When a thread's quantum expires, the scheduler moves on to the next thread in the queue.
  - This continues until all threads have had a chance to execute.

2. ***What memory segments do sibling threads share? What memory segments do they keep private?***
  - Global variables and program code are shared among sibling threads.
  - Local stack variables and open file descriptors are kept private to each thread.

3. ***Define a "Race Condition" and explain why a Critical Section needs protection.***
  - A race condition occurs when multiple threads access shared data concurrently, leading to unpredictable behavior.
  - A critical section is a section of code that must be executed atomically, without interruption by other threads.
  - Protection is needed to prevent race conditions by synchronizing access to critical sections.

4. ***List and explain the three rules for a valid critical section solution (Mutual Exclusion, Progress, Bounded Waiting).***
  - Mutual Exclusion: Only one thread can be in the critical section at a time.
  - Progress: If no thread is currently in the critical section, a waiting thread can enter.
  - Bounded Waiting: A waiting thread is guaranteed to eventually enter the critical section.
  - No Starvation: No thread is indefinitely prevented from entering the critical section.
  - No Deadlock: The system does not deadlock, meaning all threads eventually enter the critical section.
  - No Priority Inversion: No thread is temporarily given a higher priority than it should have, preventing lower-priority threads from executing.
  
5. ***What is the difference between a Mutex (Binary) Semaphore and a Counting Semaphore?***
  - A Mutex (Binary) Semaphore is a binary semaphore that allows only one thread to access a critical section at a time.
  - A Counting Semaphore is a semaphore that allows multiple threads to access a critical section simultaneously, up to a specified limit.

6. ***How does a deadlock occur in terms of semaphore queues?***
  - A deadlock occurs when two or more threads are waiting for each other to release a semaphore, resulting in a circular wait and no progress.

7. ***Explain the Producer-Consumer Problem and the shared variables required to solve it(mutex,gaps,items)***
  - The Producer-Consumer Problem is a classic synchronization problem where a producer thread produces items and a consumer thread consumes them.
  - The shared variables required to solve it are a mutex, a gap, and an item count.
  - The mutex is used to protect the shared variables, the gap is used to indicate the number of empty slots in the buffer, and the item count is used to indicate the number of items in the buffer.

## Code Analysis & Tracing

8. ***If Thread A modifies a global variable, will Thread B see the change? What if Thread A modifies a local variable inside its execution function?***
  - Yes, Thread B will see the change if the variable is global. If the variable is local, Thread B will not see the change.

9. ***Calculate the completion time of three processes under Round-Robin (quantum=2) given arbitrary arrival times and CPU bursts.***


**Time Quantum (Q):** 2
**P1:** Arrival Time = 0, Burst Time = 5
**P2:** Arrival Time = 1, Burst Time = 3
**P3:** Arrival Time = 2, Burst Time = 4


**Time = 0**

**Arrivals:** P1 arrives.
**Ready Queue:** `[P1]`
**Action:** P1 gets the CPU.
**Remaining time:** P1 needs 5 units. It will run for 2 (its quantum).

**Time = 1**

**Arrivals:** P2 arrives.
**Ready Queue:** `[P2]` (P1 is currently in the CPU).

**Time = 2**

**Arrivals:** P3 arrives. Ready Queue becomes `[P2, P3]`.
**Action:** P1 finishes its 2-unit quantum. It still needs 3 units (5 - 2 = 3), so it is placed at the *back* of the queue.
**Ready Queue:** `[P2, P3, P1]`
**Action:** The OS takes the next process in line (P2) and gives it the CPU.
**Remaining time:** P2 needs 3 units. It will run for 2.

**Time = 4**

**Action:** P2 finishes its quantum. It still needs 1 unit (3 - 2 = 1), so it goes to the back of the queue.
**Ready Queue:** `[P3, P1, P2]`
**Action:** P3 gets the CPU.
**Remaining time:** P3 needs 4 units. It will run for 2.

**Time = 6**

**Action:** P3 finishes its quantum. It still needs 2 units (4 - 2 = 2), so it goes to the back.
**Ready Queue:** `[P1, P2, P3]`
**Action:** P1 gets the CPU.
**Remaining time:** P1 needs 3 units. It will run for 2.

**Time = 8**

**Action:** P1 finishes its quantum. It still needs 1 unit (3 - 2 = 1), so it goes to the back.
**Ready Queue:** `[P2, P3, P1]`
**Action:** P2 gets the CPU.
**Remaining time:** P2 needs 1 unit. Since 1 is less than the quantum (2), it will just run for 1 unit and then terminate.

**Time = 9**

**Action:** **P2 finishes its execution.** -> **Completion Time for P2 is 9.**
**Ready Queue:** `[P3, P1]`
**Action:** P3 gets the CPU.
**Remaining time:** P3 needs 2 units. It will run for 2.

**Time = 11**

**Action:** **P3 finishes its execution.** -> **Completion Time for P3 is 11.**
**Ready Queue:** `[P1]`
**Action:** P1 gets the CPU.
**Remaining time:** P1 needs 1 unit. It runs for 1.

**Time = 12**

**Action:** **P1 finishes its execution.** -> **Completion Time for P1 is 12.**
**Ready Queue:** `[]` (Empty, all processes finished).

**Averages:**

**Average Turnaround Time:** (12 + 8 + 9) / 3 = **9.67**
**Average Waiting Time:** (7 + 5 + 5) / 3 = **5.67**

10. ***In the Readers-Writers problem (priority to readers), what happens to a waiting Writer if readers continuously arrive one after another?***
  - if readers arrive continuously in the Priority to Readers variant (Variant 1) of the Readers-Writers problem, the waiting writer will suffer from starvation (inanición).
  - Because any new reader that arrives is given preference to join the active readers in the database, the waiting writer will be indefinitely locked out and will never get the exclusive access it needs to execute as long as the stream of readers never fully empties. 

## Code examples

### Basic Thread Creation

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 8

// The function that each thread will execute
void* print_message(void *thread_id) {
    // Cast the void pointer back to an integer pointer, then dereference it
    int tid = *((int*)thread_id); 
    
    printf("I am thread %d\n", tid);
    
    // Safely terminate the thread
    pthread_exit(NULL); 
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS]; 
    
    // 1. Create the 8 threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i; // Store the ID in a distinct memory location
        
        if (pthread_create(&threads[i], NULL, print_message, &thread_args[i]) != 0) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    // 2. Wait for all threads to finish execution
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
```

### Joining Threads
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 8

// The function that each thread will execute
void* print_message(void *thread_id) {
    int tid = *((int*)thread_id); 
    
    printf("I am thread %d\n", tid);
    
    // Safely terminate the thread
    pthread_exit(NULL); 
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS]; 
    
    // 1. Create the 8 threads
    printf("Main: Creating threads...\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i; 
        
        if (pthread_create(&threads[i], NULL, print_message, &thread_args[i]) != 0) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    // 2. Wait for all threads to finish execution using pthread_join()
    printf("Main: Waiting for threads to finish...\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        // The main thread blocks (waits) here until threads[i] finishes
        pthread_join(threads[i], NULL); 
        printf("Main: Thread %d has joined.\n", i);
    }

    printf("Main: All 8 threads have finished. Exiting program.\n");
    return 0;
}
```
### Thread Arguments
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The function the thread will execute
void* print_message(void *args) {
    // Cast the generic void pointer back to a character pointer (string)
    char *message = (char *)args;
    
    // Print the message
    printf("%s\n", message);
    
    // Safely exit the thread
    pthread_exit(NULL);
}

int main(void) {
    pthread_t my_thread;
    char *my_string = "Hello World";

    // Create the thread:
    // 1st arg: pointer to thread ID
    // 2nd arg: thread attributes (NULL for default)
    // 3rd arg: function to execute
    // 4th arg: parameter to pass to the function (our string)
    if (pthread_create(&my_thread, NULL, print_message, (void *)my_string) != 0) {
        printf("Error creating thread\n");
        exit(-1);
    }

    // Wait for the thread to finish so the main program doesn't exit prematurely
    pthread_join(my_thread, NULL);

    return 0;
}
```
### Interleaved threads
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // Required for the sleep() function

// The function each thread will execute
void* print_letter(void *arg) {
    // Cast the argument back to a string (char pointer)
    char *letter = (char *)arg; 
    
    // Loop to print the letter multiple times
    for (int i = 0; i < 5; i++) {
        printf("%s\n", letter);
        sleep(1); // Pause execution of THIS thread for 1 second
    }
    
    // Safely exit the thread
    pthread_exit(NULL); 
}

int main(void) {
    pthread_t threadA, threadB, threadC;

    // 1. Create the 3 threads
    // We pass "A", "B", and "C" as the 4th argument to pthread_create
    if (pthread_create(&threadA, NULL, print_letter, "A") != 0) {
        printf("Error creating thread A\n");
        exit(-1);
    }
    if (pthread_create(&threadB, NULL, print_letter, "B") != 0) {
        printf("Error creating thread B\n");
        exit(-1);
    }
    if (pthread_create(&threadC, NULL, print_letter, "C") != 0) {
        printf("Error creating thread C\n");
        exit(-1);
    }

    // 2. Wait for all 3 threads to finish
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    printf("Main: All threads have finished executing.\n");
    return 0;
}
```

### Sequential Threads
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // Required for the sleep() function

// The function each thread will execute
void* print_letter(void *arg) {
    // Cast the argument back to a string (char pointer)
    char *letter = (char *)arg; 
    
    // Loop to print the letter multiple times
    for (int i = 0; i < 5; i++) {
        printf("%s\n", letter);
        sleep(1); // Pause execution of THIS thread for 1 second
    }
    
    // Safely exit the thread
    pthread_exit(NULL); 
}

int main(void) {
    pthread_t threadA, threadB, threadC;

    // 1. Create the 3 threads
    // We pass "A", "B", and "C" as the 4th argument to pthread_create
    if (pthread_create(&threadA, NULL, print_letter, "A") != 0) {
        printf("Error creating thread A\n");
        exit(-1);
    }
    if (pthread_create(&threadB, NULL, print_letter, "B") != 0) {
        printf("Error creating thread B\n");
        exit(-1);
    }
    if (pthread_create(&threadC, NULL, print_letter, "C") != 0) {
        printf("Error creating thread C\n");
        exit(-1);
    }

    // 2. Wait for all 3 threads to finish
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    printf("Main: All threads have finished executing.\n");
    return 0;
}
```

### Array Summation
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10

// Global variables shared by all threads
int array[NUM_THREADS];
int global_sum = 0;

// Mutex to protect the critical section (global_sum)
pthread_mutex_t mutex;

// The function each thread will execute
void* add_to_sum(void* arg) {
    // 1. Extract the index passed to the thread
    int index = *((int*)arg);
    
    // 2. Get the value from the array
    int value_to_add = array[index];

    // 3. CRITICAL SECTION: Lock the mutex before modifying the shared variable
    pthread_mutex_lock(&mutex);
    
    global_sum += value_to_add;
    printf("Thread %d added %d. Current Sum: %d\n", index, value_to_add, global_sum);
    
    // 4. Unlock the mutex so other threads can use it
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    // Initialize the mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Populate the array with random numbers (0 to 99) and calculate the expected sum
    int expected_sum = 0;
    printf("Array values: ");
    for (int i = 0; i < NUM_THREADS; i++) {
        array[i] = rand() % 100; 
        expected_sum += array[i];
        printf("%d ", array[i]);
    }
    printf("\nExpected sum should be: %d\n\n", expected_sum);

    // Create the 10 threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i; // Assign the array index to the thread
        if (pthread_create(&threads[i], NULL, add_to_sum, &thread_args[i]) != 0) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final result
    printf("\nFinal calculated global sum is: %d\n", global_sum);

    // Destroy the mutex to free resources
    pthread_mutex_destroy(&mutex);

    return 0;
}
```

### Mutex Protection
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10

// Shared resources
int array[NUM_THREADS];
int global_sum = 0;

// Mutex declaration
pthread_mutex_t sum_mutex;

void* add_to_sum(void* arg) {
    int index = *((int*)arg);
    int value_to_add = array[index];

    // --- Critical Section ---
    // Acquire the lock: only one thread can proceed past here at a time
    pthread_mutex_lock(&sum_mutex);
    
    global_sum += value_to_add;
    printf("Thread %d added %d. Global sum is now: %d\n", index, value_to_add, global_sum);
    
    // Release the lock: allow other threads to access the sum
    pthread_mutex_unlock(&sum_mutex);
    // --- End of Critical Section ---

    pthread_exit(NULL);
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    // Initialize the mutex
    if (pthread_mutex_init(&sum_mutex, NULL) != 0) {
        perror("Mutex init failed");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < NUM_THREADS; i++) {
        array[i] = rand() % 100;
        thread_args[i] = i;
        
        if (pthread_create(&threads[i], NULL, add_to_sum, &thread_args[i]) != 0) {
            perror("Thread creation failed");
            return 1;
        }
    }

    // Join all threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nFinal total sum: %d\n", global_sum);

    // Clean up the mutex
    pthread_mutex_destroy(&sum_mutex);

    return 0;
}
```
### Barbershop Simulation
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define TOTAL_CLIENTS 50
#define NUM_BARBERS 3
#define SHOP_CAPACITY 20
#define SOFA_CAPACITY 4
#define BARBER_CHAIRS 3

sem_t shop_sem, sofa_sem, barber_chair_sem, barber_wakeup, customer_ready;

void* barber(void* arg) {
    int id = *((int*)arg);
    while (1) {
        sem_wait(&customer_ready); // Sleep until a customer arrives
        sem_wait(&barber_chair_sem); // Grab a chair
        printf("Barber %d is cutting hair.\n", id);
        sleep(2); // Simulate haircut time
        sem_post(&barber_chair_sem); // Release chair
        printf("Barber %d finished cutting.\n", id);
    }
}

void* customer(void* arg) {
    int id = *((int*)arg);
    if (sem_trywait(&shop_sem) != 0) {
        printf("Customer %d: Shop full, leaving.\n", id);
        pthread_exit(NULL);
    }
    
    printf("Customer %d entered shop.\n", id);
    sem_wait(&sofa_sem); // Sit on sofa
    printf("Customer %d sitting on sofa.\n", id);
    
    sem_post(&customer_ready); // Wake up a barber
    sem_wait(&barber_chair_sem); // Move to barber chair
    sem_post(&sofa_sem); // Leave sofa space
    
    // Haircut happens here
    sem_post(&barber_chair_sem); // Leave shop
    sem_post(&shop_sem);
    printf("Customer %d left shop.\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t barbers[NUM_BARBERS], clients[TOTAL_CLIENTS];
    int barber_ids[NUM_BARBERS], client_ids[TOTAL_CLIENTS];

    sem_init(&shop_sem, 0, SHOP_CAPACITY);
    sem_init(&sofa_sem, 0, SOFA_CAPACITY);
    sem_init(&barber_chair_sem, 0, BARBER_CHAIRS);
    sem_init(&barber_wakeup, 0, 0);
    sem_init(&customer_ready, 0, 0);

    for (int i = 0; i < NUM_BARBERS; i++) {
        barber_ids[i] = i;
        pthread_create(&barbers[i], NULL, barber, &barber_ids[i]);
    }

    for (int i = 0; i < TOTAL_CLIENTS; i++) {
        client_ids[i] = i;
        pthread_create(&clients[i], NULL, customer, &client_ids[i]);
        sleep(1); // Customers arrive every second
    }

    for (int i = 0; i < TOTAL_CLIENTS; i++) pthread_join(clients[i], NULL);
    return 0;
}
```
### Producer-Consumer
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 3

sem_t empty, full, mutex;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void* producer(void* arg) {
    int id = *((int*)arg);
    while (1) {
        
    }
}

void* consumer(void* arg) {
    int id = *((int*)arg);
    while (1) {
        
    }
}

int main() {
    pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS];
    int producer_ids[NUM_PRODUCERS], consumer_ids[NUM_CONSUMERS];

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producer_ids[i] = i;
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        consumer_ids[i] = i;
        pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++) pthread_join(producers[i], NULL);
    for (int i = 0; i < NUM_CONSUMERS; i++) pthread_join(consumers[i], NULL);
    return 0;
}
```

### Thread Return Values
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function that runs in the thread
void* calculate_square(void* arg) {
    // Cast argument to integer
    int num = *((int*)arg);
    
    // Allocate memory for the result on the heap.
    // We cannot return the address of a local variable (it's on the stack and will be destroyed).
    int* result = malloc(sizeof(int));
    *result = num * num;
    
    // Terminate thread and return the pointer to the result
    pthread_exit((void*)result);
}

int main(void) {
    pthread_t thread;
    int number = 5;
    void* status; // Pointer to receive the exit status
    
    // Create thread, passing address of 'number'
    if (pthread_create(&thread, NULL, calculate_square, &number) != 0) {
        printf("Error creating thread\n");
        return 1;
    }
    
    // Wait for the thread to finish and capture the returned pointer
    pthread_join(thread, &status);
    
    // Cast the returned void pointer back to an int pointer
    int* result = (int*)status;
    
    printf("The square of %d is %d\n", number, *result);
    
    // Free the memory allocated inside the thread
    free(result);
    
    return 0;
}
```