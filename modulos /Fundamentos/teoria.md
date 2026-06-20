# Theory and Concepts

1. List the 4 stages of a `.c`file goes through to become executable and describe the role of the linker.
  - Source code -> Compiler -> Object code -> Linker -> Executable
  - The linker adds the libraries needed by the executable.

2. Explain the difference between local variables(allocated in the stack) and global variables(allocated at compile time).
  - Local variables are created and destroyed with each function call, while global variables are created and destroyed with the program.
  - It is also important to note that global variables are shared across all functions, while local variables are not.

3. What does a `&` operator do, and what does the `*` operator do when placed in front of a variable?
  - The `&` operator returns the memory address of a variable, while the `*` operator dereferences a pointer and returns the value it points to.

4. Compare passing by value and passing by reference. Why must you pass by reference if you want to a function to modify the original variable?
  - Passing by reference allows the function to modify the original variable directly, while passing by value creates a copy of the variable that the function can modify without affecting the original variable.

5. What is the difference between static array declaration and dynamic array declaration using `malloc()`?
  - Static array declaration allocates memory at compile time, while dynamic array declaration allocates memory at runtime.

6. What is a macro and at what stage of the compilation cycle are they processed?
  - A macro is a preprocessor directive that replaces a macro name with a value before the compiler processes the code.
  - Macros are processed before the compiler processes the code.

7. If `malloc()` succesfully reserves memory, what does it return? What must you do with that memory when you are done?
  - If `malloc()` successfully reserves memory, it returns a pointer to the allocated memory.
  - You must free the memory using `free()` when you are done with it to avoid memory leaks.
