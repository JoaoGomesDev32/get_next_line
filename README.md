*This project has been created as part of the 42 curriculum by joagomes.*

## Description

Get Next Line is a C function that reads and returns one line at a time
from a file descriptor. Repeated calls allow reading an entire file
line by line. The function works with files, standard input, and any
valid file descriptor.

The project introduces the concept of static variables in C —
a variable that persists its value between function calls.

## Instructions

### Compilation
\```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c \
get_next_line_utils.c -o program
\```

### Usage
\```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
\```

### Return Value
- Returns the next line read from the file descriptor, including `\n`
- Returns `NULL` when there is nothing left to read or an error occurs
- The caller is responsible for freeing the returned string

## Algorithm

### Static Variable

The function uses a static variable called leftover to store data that
was read from the file descriptor but not yet returned as a complete line.

Because static variables preserve their value between function calls,
leftover allows the function to continue reading exactly where the
previous call stopped.

### Reading Loop

The function reads the file descriptor using a temporary buffer of size
BUFFER_SIZE.

Each read operation appends the new content to leftover using
ft_strjoin().

The loop stops when:

- a newline character (\n) is found
- the end of file is reached
- or an error occurs during read()

### Function Breakdown

read_collect_leftover()
- Reads data from the file descriptor
- Stores everything inside leftover
- Stops reading when a newline is found

extract_line()
- Extracts the next complete line from leftover
- Includes the newline character if it exists

update_leftover()
- Removes the extracted line from leftover
- Keeps only the remaining unread content

get_next_line()
- Main function
- Coordinates reading, extracting, and updating
- Returns one line per function call

### Why the Buffer is Allocated on the Heap

The buffer is allocated with malloc() instead of a local array because
large BUFFER_SIZE values (ex: 9999999) would exceed the stack limit
and cause a segmentation fault. Heap allocation has no such restriction.

## Resources

- `man read` — system call used to read from file descriptors
- `man open` — system call used to open files  
- `man malloc` / `man free` — memory management
- [42 Docs](https://harm-smits.github.io/42docs/projects/get_next_line)

### AI Usage

AI tools were used only as learning support during the development of
this project.

They helped explain concepts such as:

- static variables
- memory management
- file descriptors
- dynamic allocation
- debugging logic errors

All code was written, tested, and understood by me.

AI was not used to blindly copy complete solutions.