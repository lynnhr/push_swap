*This project has been created as part of the 42 curriculum by atchelde.*

## Description

This project is a reimplementation of the 'printf' function of the `stdio` library in C. All functionality is written almost entirely from scratch, except from some basic functions, such as `write`. 
The goal of this project is to reproduce the core behavior of `printf` while gaining a deep understanding of variadic functions, format parsing, and low-level output handling in C.

Supported Format Specifiers
- `%c` : character
- `%s` : string
- `%d` / `%i` : signed decimal integer
- `%u` : unsigned decimal integer
- `%x` : hexadecimal (lowercase)
- `%X` : hexadecimal (uppercase)
- `%p` : pointer address
- `%%` : literal percent sign

## Algorithm and Data Structure Explanation

### Overall Algorithm

1. Initialize variadic arguments using va_start.
2. Iterate through the format string character by character.
3. When a `%` is encountered:
   - Read the next character to determine the conversion specifier.
   - Call the appropriate helper function.
4. Each helper function:
   - Converts the value to the correct representation.
   - Writes output using the `write` system call.
   - Returns the number of characters printed.
5. Accumulate the total number of printed characters.
6. Clean up variadic arguments using va_end.
7. Return the total output length.

### Data Structures Used

- Variadic argument list (va_list): Used to retrieve an unknown number of arguments at runtime.

- Primitive data types only: No dynamic containers (arrays, structs, linked lists) are used. This keeps the implementation lightweight and close to system-level behavior.

## Instructions

### Compilation

From the root of the repository, run:

```
make
```

This command compiles all source files and generates the static library `libftprintf.a`.

To clean these source files, run:

```
make clean
make fclean
make re
```

## Usage

Include the library header in your source file:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```
cc {filename}.c libftprintf.a
```

Then run the executable:

```
./a.out
```

## Resources

- GNU C Library Documentation
- `man` pages (`man printf`, `man write`, etc.)
- 42 documentation and subject PDF

### Use of AI

AI tools were used strictly as a learning and assistance aid, specifically for:
- clarifying the behavior of certain printf format specifiers
- improving code readability and documentation wording

## Additional Notes

- This project does not fully replicate the original `printf` with all its features (flags, width, precision, etc.).
- All output is written using the `write` system call.
