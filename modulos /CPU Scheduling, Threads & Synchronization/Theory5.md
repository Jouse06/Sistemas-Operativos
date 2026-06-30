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
