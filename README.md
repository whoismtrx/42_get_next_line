# Get_next_line

## Overview

The aim of this project is to make you code a function like getline() in C. but with some diferences. The prject is a part of the 42 curriculum, written in C language.

## Key Features

The project contains 2 parts: `Manadatory` and `Bonus`.

• `Mandatory` part is to code a function that returns a line ending with a newline, read from a file descriptor. and sould be able to memorize the reading position to read from the same file descriptor on the next call.

• `Bonus` part is to code a function that can read from multiple file descriptors without losing the reading position.

## Getting Started

to compile the project you need to clone the repository first, to that run the following command:

```bash
git clone https://github.com/whoismtrx/42_get_next_line.git get_next_line
cd get_next_line/src
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1337 get_next_line.c get_next_line_utils.c main.c
```

## Usage

to use the function you need to include the header file in your project and call the get_next_line function with the file descriptor you want to read from.

```c
// example.c
#include "get_next_line.h"
char *line = get_next_line(fd);
```

## Implementation

The function is implemented using a static variable to store the reading position and a buffer to store the read data. the function reads the data from the file descriptor and stores it in the buffer, then it searches for a newline character in the buffer, if it finds one it returns the line ending with the newline character, if not it reads more data from the file descriptor and appends it to the buffer and repeats the process. if the function reaches the end of the file it returns the last line without a newline character. lastly, the function frees the buffer and returns the line. this process is repeated on every call to the function.

## Project Structure

```
get_next_line/
├── src/
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   ├── get_next_line.h
│   ├── get_next_line_bonus.c
│   ├── get_next_line_utils_bonus.c
│   └── get_next_line_bonus.h
└── README.md
```

## Resources

• this is a great article about [static variables](https://www.scaler.com/topics/static-variables-in-c/).

• if you want to know more about [read](https://man7.org/linux/man-pages/man2/read.2.html) and how to use it.

• you can also read about [file descriptors](https://www.ibm.com/docs/en/aix/7.1?topic=volumes-using-file-descriptors) and how to manage them.


## Disclaimer

This repository is for educational purposes only, documenting my work on the 42 curriculum. These solutions are intended as a reference for students who have already completed or are actively working on the project.
