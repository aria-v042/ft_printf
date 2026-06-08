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

`ft_printf` handles the following conversion specifiers:

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

The function's core loop iterates through the format string character by character, copying ordinary characters (not %) as-is to the output stream using the `write` function. When a % character is found, it advances to the next position, and passes the 

    When it encounters a `%`, it advances one position and passes the next character to a specifier dispatcher (`parse_specifier`). All other characters are written directly to stdout as-is, and the character count is incremented accordingly.

This two-phase structure — scan, then dispatch — keeps the main loop simple and makes it easy to add specifiers without modifying the parsing logic.

### Dispatcher

`parse_specifier` takes the specifier character and the `va_list`, and routes to the appropriate handler. It is implemented as a series of conditionals (or a comparable structure) mapping each valid specifier to a dedicated output function. Unknown or unsupported specifiers are handled gracefully rather than silently ignored.

### Output layer

Each specifier has a corresponding function responsible for extracting its argument from the `va_list` and printing it. The numeric specifiers (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) share a common base-conversion utility (`util_putnbr_base`) that handles arbitrary bases and character sets, avoiding duplicated logic across handlers.

Pointer printing (`%p`) is treated as a special case of hex output: the address is cast to `uintptr_t` (an unsigned integer wide enough to hold a pointer on the target platform) and printed with the `0x` prefix prepended. Using `uintptr_t` rather than `unsigned long` or `unsigned int` is the correct approach, as pointer width varies across architectures.

Unsigned types (`%u`, `%x`, `%X`) use `unsigned int` when extracting from `va_list`, while `%p` uses `unsigned long long` (via `uintptr_t`) to accommodate 64-bit addresses. Signed types (`%d`, `%i`) use `int`. Mixing these up is a common source of bugs, particularly when testing with `UINT_MAX` or printing null pointers.

### Justification

The dispatcher-plus-handler architecture was chosen because it directly reflects the structure of the problem: each specifier is independent, and the logic for handling one shouldn't be entangled with the logic for another. It also makes the code straightforward to audit — checking that `%u` is correctly handled means reading one function, not tracing through a nested block.

The decision to build a shared `util_putnbr_base` function rather than writing separate conversion routines for decimal, hex-lower, and hex-upper means that the base-conversion logic is tested once and reused consistently. The only variation between `%x` and `%X` is the digit character set passed to the utility.

---

## Resources

### Reference material

- `man 3 printf` — primary reference for conversion specifier behavior: [https://www.man7.org/linux/man-pages/man3/printf.3.html](https://www.man7.org/linux/man-pages/man3/printf.3.html)

### Learning resources

- Codevaultyt — [*Variadic functions in C (part 1)*](https://youtu.be/oDC208zvsdg) and [*Variadic functions in C (part 2)*](https://youtu.be/Hb2m7htiKWM) — understanding variadic functions and `va_list` mechanics.
- Jacob Sorber — [*Makefiles: the best way to manage your project builds*](https://youtu.be/DtGrdB8wQ_8) — correctly integrating `libft` as a subproject dependency in the Makefile.

### Use of AI

AI was not used during the implementation of this project. The man page, the referenced videos, and existing knowledge from Libft were sufficient throughout. As with Libft, I preferred to keep my thought process free of external influence while still in the foundational phase of the curriculum.
