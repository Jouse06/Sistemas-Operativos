# Low level I/O & Syscalls

- **File Descriptors:** 
  - An integer tracking open files. By default, every UNIX process opens with `0` (stdin), `1` (stdout), and `2` (stderr).

- **Syscalls:**
  - `creat(name,mode)`: Creates a file. Returns a file descriptor or `-1` if it fails.
  - `open(name,flags,mode)`: Opens a file. Returns a file descriptor or `-1` if it fails.
  - `close(fd)`: Closes a file descriptor. Returns `0` on success or `-1` if it fails.
  - `read(fd,buf,count)`: Reads data from a file descriptor. Returns the number of bytes read or `-1` if it fails.
  - `write(fd,buf,count)`: Writes data to a file descriptor. Returns the number of bytes written or `-1` if it fails.
  - `lseek(fd,offset,origin)`: Changes the file offset. Returns the new offset or `-1` if it fails.

- **Error Handling:**
  - When a syscall fails, it sets a global integer called `errno`. You can use `strerror(errno)` to get a human-readable error message.
