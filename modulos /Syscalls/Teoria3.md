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


## Mock Theory Questions

1. **System Calls vs. Libraries:** What is the functional difference between printf() (a C library function) and write() (a system call)?
  - The printf() function is a C library function that prints formatted output to the standard output stream (stdout).
  - The write() function is a system call that writes data to a file descriptor.

2. **File Descriptors (FD):** What are the default file descriptors assigned to 0, 1, and 2?
  - `0` is the standard input (stdin), `1` is the standard output (stdout), and `2` is the standard error (stderr).

3. **Return Values:** If open() fails, what integer does it return?
  - `-1` is returned on failure, and `errno` is set to indicate the specific error.

4. **Read/Write Pointers:** What happens to the internal file pointer automatically when you successfully read() 10 bytes from a file?
  - The internal file pointer is automatically advanced by the number of bytes read.

5. **Error Handling:** What is the errno variable? How do you convert it into a human-readable string?
  - The `errno` variable is set by system calls to indicate the specific error that occurred. You can use `strerror(errno)` to get a human-readable error message.

## Code analysis and tracing

6. **Flags:** Explain the difference between `O_RDONLY`, `O_WRONLY`, and `O_CREAT`. Can they be combined?
   - `O_RDONLY` opens a file for reading only.
   - `O_WRONLY` opens a file for writing only.
   - `O_CREAT` creates a new file if it does not exist.
   - These flags can be combined using bitwise OR (`|`). For example, `O_RDONLY | O_CREAT` opens a file for reading and creates it if it does not exist.

7. **Permissions:** In the call `creat("archivo.txt", 0666);`, what does the `0666` mean?
   - `0666` is a permission mask that allows read and write access to the file for all users.

8. **Tracing I/O Error:** Look at this code: `int fd = 20; read(fd, buffer, 100);`. If file descriptor 20 was never opened, what will `errno` be set to?
   - `errno` will be set to `EBADF` (Bad file descriptor) if the file descriptor is invalid.
