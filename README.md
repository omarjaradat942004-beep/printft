*This activity has been created as part of the 42 curriculum by omajarad.*

# ft_printf

## Description

The goal of this activity is to recreate the standard C library function printf() by implementing a custom function called ft_printf().

The project provides an opportunity to understand how variadic functions work in C and how different types of arguments can be processed using va_list, va_start, va_arg, and va_end.

The function implemented in this project has the following prototype:

int ft_printf(const char *, ...);


The implementation does not reproduce the internal buffer management of the original printf(). Instead, it writes the output directly using the write() function.

The following conversions are supported:

%c — Prints a single character.

%s — Prints a string.

%p — Prints a pointer address in hexadecimal format.

%d — Prints a decimal number.

%i — Prints an integer in base 10.

%u — Prints an unsigned decimal number.

%x — Prints a hexadecimal number using lowercase letters.

%X — Prints a hexadecimal number using uppercase letters.

%% — Prints a percent sign.

The final library is called libftprintf.a.

## Instructions

### Compilation

The project is compiled using the provided Makefile.

To compile the library, run:

make


This creates:

libftprintf.a


at the root of the repository.

The Makefile also provides the following required rules:

make all
make clean
make fclean
make re


make / make all compiles the project and creates the library.

make clean removes object files.

make fclean removes object files and the compiled library.

make re performs a complete recompilation.

### Using the library

To use ft_printf() in another C program, include the project's header:

#include "ft_printf.h"


Then compile the program together with the library:

cc main.c -L. -lftprintf


For example:

#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    return (0);
}


The program can then be compiled with:

cc main.c -L. -lftprintf

### Creating the library

The project uses the ar command to create the static library, as required by the activity.

The libtool command is not used.

## Algorithm and Data Structures

### General algorithm

The main algorithm used by ft_printf() is a sequential scan of the format string.

The function starts at the first character of the format string and processes each character from left to right.

When the current character is not %, it is written directly to standard output.

When % is encountered, the next character is interpreted as a conversion specifier.

For example:

"Hello %s!"
       ^
       |
   conversion


The character after % determines which function should process the corresponding argument.

The general process is:

Start at the beginning of the format string.

Read one character at a time.

If the character is not %, write it directly.

If the character is %, read the following character.

Select the appropriate conversion function.

Retrieve the corresponding argument using va_arg().

Print the argument.

Add the number of printed characters to the total counter.

Continue until the end of the format string.

Return the total number of characters printed.

### Conversion dispatch

The conversion handling is separated from the main function.

The conversion character is checked and the appropriate helper function is called.

For example:

if (ptr[index] == 'c')
    (*counter) += ft_printf_char(va_arg(list, int));
else if (ptr[index] == 's')
    (*counter) += ft_printf_str(va_arg(list, char *));
else if (ptr[index] == 'd' || ptr[index] == 'i')
    (*counter) += ft_printf_decimal(va_arg(list, int));


This keeps the main ft_printf() function relatively simple and allows each conversion to have its own implementation.

### Number conversion algorithm

Decimal and hexadecimal numbers are converted recursively or iteratively by repeatedly dividing the number by its base.

For decimal numbers, the base is:

10


For hexadecimal numbers, the base is:

16


The hexadecimal digit table is used to select the correct character:

0123456789abcdef


for %x, and:

0123456789ABCDEF


for %X.

For example, the decimal number 255 is converted to hexadecimal as:

255 / 16 = 15 remainder 15
15  / 16 = 0  remainder 15


The remainders correspond to:

15 = f
15 = f


giving:

ff

### Pointer conversion

The %p conversion receives a void * argument.

The pointer value is converted to an unsigned integer representation and printed in hexadecimal format.

A pointer is displayed with the hexadecimal prefix:

0x


followed by the hexadecimal representation of the address.

### Data structures

The implementation does not require complex data structures.

The main data structures used are:

const char * for the format string.

va_list for managing the variable arguments.

Integer types such as int and unsigned int for numeric conversions.

void * for pointer arguments.

The format string is processed directly without copying it into another data structure. This keeps the implementation simple and avoids unnecessary memory allocation.

No dynamic memory allocation is required for the core implementation.

### Variadic Functions

One of the main concepts studied in this project is variadic functions.

ft_printf() accepts a variable number of arguments:

int ft_printf(const char *, ...);


The ... allows the function to receive different numbers and types of arguments.

The following macros are used:

va_list
va_start
va_arg
va_end


va_start() initializes the argument list.

va_arg() retrieves the next argument with the expected type.

For example:

va_arg(list, int)


retrieves an integer argument.

Finally, va_end() releases the resources associated with the variable argument list.

### Return Value

Like the original printf(), ft_printf() returns the number of characters written.

For example:

int count;

count = ft_printf("Hello");


The value of count is:

5


Each conversion function therefore returns the number of characters it printed, allowing the main function to maintain a total counter.

For example:

(*counter) += ft_printf_str(...);


This makes it possible for the final return value to represent the total number of characters printed.

### Error and Edge-Case Testing

The implementation should be compared with the original printf() using different combinations of conversions.

Examples include:

printf("%d\n", 42);
ft_printf("%d\n", 42);

printf("%s %d %x\n", "hello", 42, 255);
ft_printf("%s %d %x\n", "hello", 42, 255);

printf("%c %c %c\n", 'A', 'B', 'C');
ft_printf("%c %c %c\n", 'A', 'B', 'C');

printf("%u\n", 4294967295u);
ft_printf("%u\n", 4294967295u);


Special values should also be tested, including:

0

negative integers

INT_MIN

INT_MAX

UINT_MAX

NULL strings

NULL pointers

zero pointers

multiple conversions in one format string

consecutive conversions

%%

The return value of ft_printf() should also be compared with the return value of printf().

### Project Structure

The actual project structure is:

```
.
├── Makefile
├── README.md
├── ft_printf.h
├── libft.h
├── ft_printf.c
├── ft_printf_char.c
├── ft_printf_str.c
├── ft_printf_decimal.c
├── ft_printf_unint.c
├── ft_printf_lower.c
├── ft_printf_upper.c
├── ft_printf_ptr.c
└── ft_itoa.c
```

The header file `ft_printf.h` contains the prototype of `ft_printf()` and the declarations of the helper conversion functions.

`libft.h` declares `ft_itoa()`, which is implemented in `ft_itoa.c` and used by `ft_printf_decimal.c` to convert signed integers to strings. The rest of the standard libft function prototypes are declared in `libft.h` for reference but are not implemented or used in this project.

### Allowed Functions

The following external functions are authorized for this activity:

malloc
free
write
va_start
va_arg
va_copy
va_end


Libft is also authorized.

The project does not use the original printf() internally to perform any conversion.

## Resources

The following resources were useful for understanding the concepts involved in this activity:

C language documentation for variadic functions and stdarg.h.

The printf() manual page (man 3 printf).

The write() manual page (man 2 write).

The ar manual page (man 1 ar).

The C standard library documentation for integer and pointer types.

42 course material and peer discussions about variadic functions and formatted output.

The existing Libft project and its utility functions.

### AI Usage

AI was used as a learning and debugging assistant during the activity.

It was used to:

Explain the requirements of the ft_printf activity.

Clarify how variadic functions and va_list work.

Suggest edge cases for testing.

Help identify potential problems in the implementation.

Explain the behavior expected from different conversion specifiers.

Review individual helper functions and provide debugging hints.

The implementation itself was developed as part of the activity. AI was used to understand concepts, review code, and guide debugging rather than to replace the learning process or the implementation work.

## Conclusion

The ft_printf activity provides practical experience with variadic functions, formatted output, integer representation, hexadecimal conversion, pointers, and static libraries.

The project also reinforces important C programming concepts such as function decomposition, type handling, return-value management, and low-level output using write().

The final result is a custom ft_printf() implementation packaged into libftprintf.a, capable of handling the required cspdiuxX% conversions.
