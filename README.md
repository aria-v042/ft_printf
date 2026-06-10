*This project has been created as part of the 42 curriculum by frodrig2.*

# ft_printf

## Description

ft_printf is a project in the 42 curriculum. The goal is to reimplement the standard C library's `printf()` function from scratch, handling a defined subset of conversion specifiers using variadic functions.

The function is implemented as a static archive, `libftprintf.a`, which includes the `libft` archive.

The core challenge isn't the individual conversions themselves: most of them are straightforward once you have solid output primitives in place. The real exercise is in the architecture. A naive approach — one big switch with ad hoc formatting logic per specifier — technically works but becomes difficult to extend and harder to reason about. The project pushes you toward building something clean: a format string parser that identifies specifiers, and a dispatcher that routes each one to a dedicated handler.

The project's code was written in accordance with [The Norm v4.1](https://github.com/42school/norminette/blob/master/pdf/en.norm.pdf).

---

## Instructions

### Compilation

Clone the repository and run `make` at its root:

```sh
git clone https://gitlab.com/aria-v042/ft_printf.git ft_printf-aria-v042
cd ft_printf-aria-v042
make
```

This produces `libftprintf.a` at the root of the repository.

### Linking

To use the library in your own project, include the header and link against the archive:

```sh
cc your_file.c -Llibrary_dir -l libftprintf -Iheader_dir -o your_program
```

### Makefile rules

| Rule | Effect |
|---|---|
| `make` / `make all` | Compile `libftprintf.a`, including the `libft` library |
| `make clean` | Remove object files |
| `make fclean` | Remove object and archive files |
| `make re` | Run `fclean` then `all` |

#### Extra Makefile rules

These rules were not included in the official project submission, but are available in the `extras/` folder `Makefile`, allowing users to easily test and debug their code.

| Rule | Effect |
|---|---|
| `make test <optional_file.c>` | Compile `test` from `test.c` or given source file |
| `make tclean` | Remove object files, archive files, and `test` |

---

## Conversion specifiers

`ft_printf()` handles the following conversion specifiers:

| Specifier | Output |
|---|---|
| `%c` | Single character |
| `%s` | String (null-terminated, C convention) |
| `%p` | Pointer address in hexadecimal (`0x...`) |
| `%d`, `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned integer in lowercase hexadecimal |
| `%X` | Unsigned integer in uppercase hexadecimal |
| `%%` | Literal percent sign |

The function returns the total number of characters written, matching the behavior of the original `printf()`.

---

## Algorithms and data structure

### Format string parsing

The function's core loop iterates through the format string character by character, copying ordinary characters (not %) as-is to the output stream using the `write()` function. When a % character is found, the format string pointer advances to the next position and is passed to the `parse_specifier()` function.

### Conversion specification parsing

`parse_specifier()` takes the conversion specification and the address of the `va_list` of args, and routes the latter to the appropriate handler. It is implemented as a series of conditionals mapping each valid specifier to the dedicated conversion function. Unknown or unsupported specifiers are silently ignored.

### Conversion handling

Each specifier type is handled by a corresponding function responsible for correctly converting the next argument in the `va_list` and writing it to the standard output stream.

The numeric specifiers that require a base conversion share a common utility function `ft_putnbr_base`, that also updates the variable containing the length of the converted number through its address.

Pointer printing (`%p`) is treated as a special case of hex output: the address is cast to `uintptr_t` and printed with the `0x` prefix prepended. The data type used is `uintptr_t` rather than `unsigned long` or `unsigned int` for compatibility with pointer width variation across architectures.

---

## Resources

### Reference material

- `man 3 printf` — primary reference for conversion specifier behavior ([https://www.man7.org/linux/man-pages/man3/printf.3.html](https://www.man7.org/linux/man-pages/man3/printf.3.html))

### Learning resources

- CodeVault — [*Variadic functions in C (part 1)*](https://youtu.be/oDC208zvsdg) and [*Variadic functions in C (part 2)*](https://youtu.be/Hb2m7htiKWM) — understanding variadic functions and `va_list` mechanics.
- Jacob Sorber — [*Makefiles: the best way to manage your project builds*](https://youtu.be/DtGrdB8wQ_8) — correctly integrating `libft` as a subproject dependency in the Makefile.

### Use of AI

AI was not used during the implementation of this project.
