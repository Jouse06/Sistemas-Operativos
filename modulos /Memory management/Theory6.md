# Concepts

- **Memory Structure:** Memory is organized hierarchically: CPU Registers $\rightarrow$ Cache $\rightarrow$ RAM $\rightarrow$ Disk (Swap/Virtual Memory). This is a trade-off between speed and capacity.
    
- **Process Memory Mapping:** A process in RAM is divided into segments: Code (executable instructions), Data (global variables), Heap (dynamic memory), and Stack (local function variables). You can map these regions on Linux using `/proc/[pid]/maps`.
    
- **Paging:** Virtual memory is divided into fixed-size **Pages**. Physical RAM is divided into identical **Frames**. The OS maintains a _Page Table_ to translate Logical Addresses into Physical Addresses.
    
- **Page Replacement Algorithms:** When RAM is full, the OS must swap a page out.
    
    - _FIFO (First-In, First-Out):_ Easiest to implement but uses a flawed premise (assumes the oldest page is useless).
        
    - _LRU (Least Recently Used):_ Highly accurate but very costly to implement (requires hardware timestamping).
        
    - _NRU (Not Recently Used):_ Categorizes pages into 4 tiers based on combinations of the Reference Bit and Modification Bit.


## **6.2 Comprehensive Exercises**

**Exercise 1: Tracing Memory Calls**

> How do you trace which system calls a memory program makes during execution?

### **6.3 End-of-Module Mock Test**

**Q1 (Multiple Choice):** Which page replacement algorithm ranks pages based on combinations of a Reference Bit and a Modification Bit?

A) FIFO

B) LRU

C) NRU

D) Round-Robin


**Q2 (Multiple Choice):** If the size of a page is exactly $2^n$ bytes, what is true about the logical address?

A) It perfectly matches the relative address because the lower $n$ bits represent the offset.

B) The page table does not need to exist.

C) Swapping is no longer necessary.

## Theory Questions

1. **Memory Hierarchy:** Order the following by speed and capacity: RAM, Disk/Swap, L1 Cache, CPU Registers.
    
2. **Process Memory Map:** Explain the difference between the Text (Code), Data, Heap, and Stack segments of a process.
    
3. **Paging:** What is the difference between a Virtual Page and a Physical Frame?
    
4. **Page Table:** What is the purpose of the Page Table?
    
5. **Replacement Algorithms:** Explain how FIFO, LRU (Least Recently Used), and NRU (Not Recently Used) decide which page to swap out.
    
6. **Reference/Modification Bits:** In the NRU algorithm, how are the reference and modification bits used to create 4 tiers of page evictions?
    
7. **Fragmentation:** What is the difference between Internal and External Fragmentation? Which one applies to Paged memory systems?
    

## Code Analysis and Tracing 

8. **Mathematical Translation:** If a logical address is 32 bits, and the page size is 4KB ($2^{12}$), how many bits represent the Page Number, and how many represent the Offset?

9. **Page Table Sizing:** Calculate the size of a page table for a 32-bit address space with 4KB pages, assuming each entry takes 4 bytes.

10. **FIFO Tracing:** Given the page reference string: `[0, 1, 2, 3, 0, 1, 4]`, and 3 RAM frames, trace the page faults using the FIFO algorithm.

11. **LRU Tracing:** Trace the same reference string `[0, 1, 2, 3, 0, 1, 4]` using the LRU algorithm. Compare the page fault count.

12. **Fragmentation Math:** A process needs 31,566 bytes. Pages are 2,048 bytes. How many pages does it need? What is the internal fragmentation (wasted space in the last page)?
