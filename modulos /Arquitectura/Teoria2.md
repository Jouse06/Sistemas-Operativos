# Basic concepts of OS architecture and mock questions

- **What is an OS?** It is the core software acting as an intermediary between user applications and the hardware. Its primary goals are user comfort, hardware efficiency, and evolution capacity.

- **Operation Modes**: * Kernel/Supervisor Mode: The OS has complete, unrestricted access to all hardware and root instructions.
   - User Mode: Restricted access. User processes must rely on System Calls to request services (like I/O) from the OS.

- **UNIX Architecture**: Built in concentric layers: Hardware  Kernel  System Call Interface  UNIX Commands/Libraries  User Applications.

- **File Abstraction in UNIX**: UNIX treats almost everything as a file.
   - Regular Files: Data and programs.
   - Directories: Hierarchical nodes linking names to files.
   - Special Files: Input/Output devices (found in /dev), categorized as block (addressable) or character (sequential) devices.
- **i-nodes (nodos-i)**: A crucial data structure storing a file's metadata (permissions, owner, size, timestamps, data block links). Notably, the i-node does not store the file's name; the directory associates the name with the i-node.
- **Links**: Hard links associate a new name directly with the existing i-node. Symbolic links (symlinks) point to the original file path. If the original is deleted, the hard link survives, but the symlink breaks.

## Mock Multiple Choice Questions

1. Which of the following is NOT stored ina a UNIX file's i-node?
   A. The file's name   B. Permissions   C. Creation date   D. File size

2. What happens if you delete a file that has a symbolic link attached to it?
   A. The symbolic link becomes a regular file.   B. The symbolic link breaks and becomes unusable.   C. The file is not actually deleted until the symbolic link is removed.   D. The symbolic link is not deleted and the original file remains.

## Mock Theory Questions
1. What are the three primary objectives of an operating system?
   - *Comfort:* To make the computer easier to use. It provides a comfortable and user-friendly environment for users to run programs. solve problems, and access resources without needing to understand the underlying hardware complexities.
   - *Efficiency:* To optimize resource usage and system performance. It manages hardware resources, schedules processes, and provides efficient memory management.
   - *Evolution capacity:* To adapt to changing hardware and software requirements. It provides mechanisms for updating and extending the system's functionality without requiring a complete re-installation.

2. Explain the difference between Kerner(Supervisor) and user mode. Why are certain instructions restricted in user mode?
   - In user mode, certain instructions are restricted because they require higher privileges than user mode. These instructions are executed by the kernel (supervisor) to manage system resources and provide system-level functionality.
   - Also the supervisor can handle the hardware and software resources, while user mode is limited to user-level operations.

3. List the concentric layers of UNIX starting from the Hardware and ending at User Applications.
   - Hardware -> Kernel -> System Call interface -> UNIX Commands/Libraries -> User Applications

4. Explain the UNIX philosophy that treats hardware devices, directories, and texts as files. Where are hardware devices located?
   - Hardware devices are treated as files in UNIX, located in the `/dev` directory.
   - Regular files are located in the `/home` directory, while system files are located in the `/etc` directory.
   - Directories are used to organize files and provide a hierarchical structure for the system.

5. What is an i-node? List at least 4 pieces of metadata stored inside an i-node. 
   - An i-node (index node) is a data structure that stores metadata about a file or directory in UNIX.
   - It stores permissions, ownership, size, timestamps, and data block links.

6. Does an i-node store the name of the file? If not, how does the OS know the file's name?
   - The OS knows the file's name through the directory structure, where the i-node is associated with the file's name.
   - The i-node does not store the file's name directly; it is stored in the directory entry that points to the i-node.

7. Explain the difference between a Hard Link and a Symbolic Link (symlink). What happens to a symlink if the original file is deleted?
   - A hard link is a direct reference to the i-node of a file, while a symbolic link is a pointer to the file's name in the directory structure.
   - If the original file is deleted, the hard link will still point to the i-node, while the symbolic link will become invalid.

8. Is the shell part of the kernel or a user space process?
   - The shell is a user space process that provides an interface for interacting with the kernel.
   - But it is not part of the kernel; it is a separate process that communicates with the kernel via system calls.

9. What is a background process (daemon) and how do you execute a command in the background via the terminal?
   - A background process (daemon) is a process that runs in the background, independently of the terminal session.
   - To execute a command in the background, you can use the `&` operator at the end of the command.
