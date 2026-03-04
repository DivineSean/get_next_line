# get_next_line

A function that reads a file descriptor line by line, returning one line per call. Each call picks up exactly where the last one stopped — no repeated reads, no missed content.

## how it works

`get_next_line` uses `static char *stock[OPEN_MAX]` to hold leftover data between calls, one slot per file descriptor. Every time you call it, it reads from the fd until it hits a newline or EOF, returns that line, and saves whatever came after for next time. Multiple fds work independently.

## project structure

```
gnl/
├── include/
│   └── get_next_line_bonus.h
├── src/
│   ├── get_next_line_bonus.c
│   └── get_next_line_utils_bonus.c
├── lib/
│   └── libgnl.a          (built by make)
├── obj/                  (built by make)
├── main.c
└── Makefile
```

## build

```bash
make          # builds lib/libgnl.a and compiles main.c into program
make clean    # removes obj/
make fclean   # removes obj/, lib/ and program
make re       # fclean + all
```

## run the demo

After `make`, a `program` binary is ready. Pass any file you want to read line by line:

```bash
./program somefile.txt
./program main.c
```

## use the library in your own project

Build the library first:

```bash
make
```

Then link it when compiling your project:

```bash
cc yourfile.c -I include -L lib -lgnl -o yourprogram
```

And in your code just include the header and call it:

```c
#include "get_next_line_bonus.h"

char *line = get_next_line(fd);
while (line)
{
    // do something with line
    free(line);
    line = get_next_line(fd);
}
```

Supports multiple file descriptors at the same time — each fd has its own slot in `stock[OPEN_MAX]`, so they don't interfere with each other.

## functions

| file | what it does |
|------|--------------|
| `get_next_line_bonus.c` | main function + internal read/parse helpers |
| `get_next_line_utils_bonus.c` | ft_strlen, ft_strcpy, ft_strdup, ft_strcat, ft_strjoin |

## buffer size

Default `BUFFER_SIZE` is 42. Override it at compile time:

```bash
cc -D BUFFER_SIZE=1024 yourfile.c -I include -L lib -lgnl -o yourprogram
```

Each returned line includes the `\n` at the end (if there is one). The last line won't have one if the file doesn't end with a newline — handle accordingly.
