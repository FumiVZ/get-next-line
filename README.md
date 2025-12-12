# get_next_line

![42 Lyon](https://img.shields.io/badge/42-Lyon-blue)
![Score](https://img.shields.io/badge/Score-105%2F100-brightgreen)
![Language](https://img.shields.io/badge/Language-C-lightgrey)

## Description

**get_next_line** is a project from the 42 school curriculum that challenges students to implement a function capable of reading a single line from a file descriptor. The function can be called repeatedly to read an entire file line by line, making it an essential utility for parsing text files, reading user input, or processing data streams.

The main challenge lies in handling the buffer efficiently, managing memory correctly, and preserving the reading state between function calls using a static variable.

## Features

### Mandatory Part
- Reads and returns one line at a time from a file descriptor
- Works with any file descriptor (files, stdin, network sockets, etc.)
- Handles lines of any length
- Uses a static variable to preserve data between consecutive calls
- Properly handles end-of-file (EOF)
- Returns `NULL` when there is nothing more to read or in case of error
- The returned line includes the terminating `\n` character (except for EOF without newline)
- Customizable buffer size at compile time via the `BUFFER_SIZE` macro

### Bonus Part
- Manages multiple file descriptors simultaneously
- Each file descriptor maintains its own reading state
- Allows alternating reads between different files without losing track of position

## Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters
| Parameter | Description |
|-----------|-------------|
| `fd` | The file descriptor to read from |

### Return Value
| Value | Description |
|-------|-------------|
| `char *` | The line that was read (including `\n` if present) |
| `NULL` | Nothing more to read, or an error occurred |

## Compilation

The project can be compiled with any C compiler. The `BUFFER_SIZE` can be defined at compile time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

For the bonus version with multiple file descriptor support:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Buffer Size

The default `BUFFER_SIZE` is set to `1024` bytes. You can modify this value at compile time using the `-D` flag. Different buffer sizes can affect performance:

| Buffer Size | Behavior |
|-------------|----------|
| Small (1-10) | More system calls, slower but uses less memory |
| Medium (42-1024) | Good balance between performance and memory |
| Large (10000+) | Fewer system calls, faster but uses more memory |

## Files

### Mandatory
| File | Description |
|------|-------------|
| `get_next_line.c` | Main function implementation |
| `get_next_line_utils.c` | Helper functions (ft_strlen, ft_strchr, ft_strjoin_n, etc.) |
| `get_next_line.h` | Header file with function prototypes and includes |

### Bonus
| File | Description |
|------|-------------|
| `get_next_line_bonus.c` | Main function with multiple fd support |
| `get_next_line_utils_bonus.c` | Helper functions for bonus |
| `get_next_line_bonus.h` | Header file for bonus |

## How It Works

1. **Reading**: The function reads `BUFFER_SIZE` bytes from the file descriptor into a static buffer (stash)
2. **Processing**: It searches for a newline character (`\n`) in the accumulated data
3. **Extraction**: Once a newline is found (or EOF is reached), it extracts the complete line
4. **Preservation**: Any remaining data after the newline is kept in the static buffer for the next call
5. **Return**: The extracted line is returned to the caller (who is responsible for freeing it)

## Memory Management

- Each call to `get_next_line` returns a newly allocated string
- The caller is responsible for freeing the returned string
- The static buffer is automatically managed by the function
- In case of error, all allocated memory is properly freed

## Error Handling

The function handles the following error cases:
- Invalid file descriptor (negative fd)
- Read errors (returns `NULL` and cleans up)
- Memory allocation failures (returns `NULL`)
- Empty files (returns `NULL`)

## Author

**vzuccare** - 42 Lyon

---

*This project is part of the 42 school common core curriculum.*
