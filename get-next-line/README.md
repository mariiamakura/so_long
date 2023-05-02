# get-next-line
This project is about programming a function that returns a line read from a file descriptor

## open() function in c

int open(const char *pathname, int flags);

The open() system call opens the file specified by pathname. If the specified file does not exist, it may optionally (if O_CREAT is specified in flags) be created by open().

On success, open(), openat(), and creat() return the new file descriptor (a nonnegative integer). On error, -1 is returned and errno is set to indicate the error.

## read() function in c

ssize_t read(int fd, void *buf, size_t count);

read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf. On success, the number of bytes read is returned (zero indicates end of file), and the file position is advanced by this number. It is not an error if this number is smaller than the number of bytes requested; this may happen for example because fewer bytes are actually available right now (maybe because we were close to end-of-file, or because we are reading from a pipe, or from a terminal), or because read() was interrupted by a signal. See also NOTES.

On error, -1 is returned, and errno is set to indicate the error. In this case, it is left unspecified whether the file position (if any) changes.
static variable

In computer programming, a static variable is a variable that has been allocated "statically", meaning that its lifetime (or "extent") is the entire run of the program.

## static vs conctant variables

Cnst means that you're not changing the value after it has been initialised. static inside a function means the variable will exist before and after the function has executed. static outside of a function means that the scope of the symbol marked static is limited to that . c file and cannot be seen outside of it.

## macros

A macro is a piece of code in a program that is replaced by the value of the macro. Macro is defined by #define directive. Whenever a macro name is encountered by the compiler, it replaces the name with the definition of the macro. Macro definitions need not be terminated by a semi-colon(;).

```
// C program to illustrate macros
#include <stdio.h>

// Macro definition
#define LIMIT 5

// Driver Code
int main()
{
    // Print the value of macro defined
    printf("The value of LIMIT"
           " is %d",
           LIMIT);

    return 0;
}

The value of LIMIT is 5
```

## Buffer

is a generic term that refers to a block of memory that serves as a temporary placeholder. In computer programming, data can be placed in a software buffer before it is processed. Because writing data to a buffer is much faster than a direct operation, using a buffer while programming in C and C++ makes a lot of sense and speeds up the calculation process. Buffers come in handy when a difference exists between the rate data is received and the rate it is processed.
Buffer vs. Cache

A buffer is temporary storage of data that is on its way to other media or storage of data that can be modified non-sequentially before it is read sequentially. It attempts to reduce the difference between input speed and output speed. A cache also acts as a buffer, but it stores data that is expected to be read several times to reduce the need to access slower storage.
