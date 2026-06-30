# Rundown of concepts 

- **Program vs. Process:** A program is a passive entity on disk. A process is an active entity executing in memory.
- **Process States:** A process moves between states: New, Ready, Running, Blocked (waiting for I/O), and Terminated. Advanced models include Suspended states, meaning the OS has swapped the blocked process out of RAM and onto the disk to save space.
- **Process Control Block (PCB):** A data structure storing context, process ID (PID), parent ID (PPID), priority, and register states required for context switching.
- **Creation (fork()):** Creates an exact clone of the parent. They have distinct memory maps. fork() returns 0 inside the child process, and returns the child's actual PID to the parent.
- **Replacement (exec()):** Replaces the current process's memory space and instructions entirely with a new executable (e.g., `execl("/bin/ls", "ls", "-l", NULL)`).
- **Synchronization (wait()):** Parents use wait() to pause execution until their children terminate, avoiding "Zombie" or "Orphan" processes.

## End of module mock multiple choice questions

***If fork() executes successfully, what value does it return to the newly created child process?***

- A) The Parent's PID
- B) 0
- C) -1
- D) Its own PID

## End of module Exercises

1. Program vs Process: Define the passive and active nature of programs and processes.
  - A program is a passive entity that resides on disk, while a process is an active entity that is loaded into memory and executed by the OS.

2. PCB: What is the Process Control Block? List 4 items stored inside it.
  - A PCB stores context, process ID (PID), parent ID (PPID), priority, and register states required for context switching.

3. State Models: Draw or describe the 5-state process model (New, Ready, Running, Blocked, Terminated).
  - 

4. Suspension: What is the "Suspended" state in the 7-state model? Why does the OS swap processes to disk?
  - The "Suspended" state is used to save memory by swapping out blocked processes to disk.
  
5. Context Switch: Why does a context switch incur "overhead" (wasted CPU time)?
  - A context switch involves saving and restoring register states, which can be time-consuming.
    
6. Fork Return Values: What are the three possible return values of fork() and what do they signify?
  - fork() returns 0 to the child process and the child's PID to the parent process. 
  - fork() returns -1 on failure. 
      
7. Exec: How does the exec() family of functions differ from fork()? Does exec() create a new PID?
  - exec() replaces the current process with a new one, while fork() creates a new process that is a copy of the parent.
