/* ******************j******************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 22:13:37 by frodrig2          #+#    #+#             */
/*   Updated: 2026/04/23 18:34:16 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

static int	tested = 0;
static int	passed = 0;
static int	failed = 0;

/* ================= PRINTERS ================= */

static void	print_header(const char *title)
{
	printf("\n");
	printf("==================================================\n");
	printf("  TESTING: " ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET "\n", title);
	printf("==================================================\n");
}

static void	print_call(const char *test)
{
	printf("  %s\n", test);
}

static void	print_test(const char *test, int pass)
{
	tested++;
	if (pass)
	{
		passed++;
		printf(ANSI_COLOR_GREEN "  [OK]  " ANSI_COLOR_RESET "%s\n", test);
	}
	else
	{
		failed++;
		printf(ANSI_COLOR_RED " [FAIL] %s\n" ANSI_COLOR_RESET, test);
	}
}

static void	print_summary(void)
{
	printf("\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("  SUMMARY:\n");
	printf("\n");
	printf("  Passed	" ANSI_COLOR_GREEN "%d" ANSI_COLOR_RESET "/%d	tests\n", passed, tested);
	printf("  Failed	" ANSI_COLOR_RED "%d" ANSI_COLOR_RESET "/%d	tests\n", failed, tested);
	printf("\n");
	if (failed == 0)
	{
		printf(ANSI_COLOR_GREEN "  Passed all tests! :3" ANSI_COLOR_RESET "\n\n");
	}
	else
	{
		printf(ANSI_COLOR_RED "  Failed some tests :(" ANSI_COLOR_RESET "\n\n");
	}
}

/* ============ AUXILIARY FUNCTIONS =========== */

static int	getsign(int n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}

/* ============== LIBC FUNCTIONS ============== */

static void	test_ft_isalpha(void)
{
	int	prefailed = failed;

	print_header("ft_isalpha");
	print_test("ft_isalpha('0') ? 0", ft_isalpha('0') == 0);
	print_test("ft_isalpha('@') ? 0", ft_isalpha('@') == 0);
	print_test("ft_isalpha('A') ? 1", ft_isalpha('A') == 1);
	print_test("ft_isalpha('[') ? 0", ft_isalpha('[') == 0);
	print_test("ft_isalpha('`') ? 0", ft_isalpha('`') == 0);
	print_test("ft_isalpha('z') ? 1", ft_isalpha('z') == 1);
	print_test("ft_isalpha('{') ? 0", ft_isalpha('{') == 0);
	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_isdigit(void)
{
	int	prefailed = failed;

	print_header("ft_isdigit");
	print_test("ft_isdigit('/') ? 0", ft_isdigit('/') == 0);
	print_test("ft_isdigit('0') ? 1", ft_isdigit('0') == 1);
	print_test("ft_isdigit('9') ? 1", ft_isdigit('9') == 1);
	print_test("ft_isdigit(':') ? 0", ft_isdigit(':') == 0);
	print_test("ft_isdigit('a') ? 0", ft_isdigit('a') == 0);
	print_test("ft_isdigit('{') ? 0", ft_isdigit('{') == 0);
	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_isalnum(void)
{
	int	prefailed = failed;

	print_header("ft_isalnum");
	print_test("ft_isalnum('/') ? 0", ft_isalnum('/') == 0);
	print_test("ft_isalnum('0') ? 1", ft_isalnum('0') == 1);
	print_test("ft_isalnum('9') ? 1", ft_isalnum('9') == 1);
	print_test("ft_isalnum(':') ? 0", ft_isalnum(':') == 0);
	print_test("ft_isalnum('@') ? 0", ft_isalnum('@') == 0);
	print_test("ft_isalnum('A') ? 1", ft_isalnum('A') == 1);
	print_test("ft_isalnum('Z') ? 1", ft_isalnum('Z') == 1);
	print_test("ft_isalnum('[') ? 0", ft_isalnum('[') == 0);
	print_test("ft_isalnum('`') ? 0", ft_isalnum('`') == 0);
	print_test("ft_isalnum('a') ? 1", ft_isalnum('a') == 1);
	print_test("ft_isalnum('z') ? 1", ft_isalnum('z') == 1);
	print_test("ft_isalnum('{') ? 0", ft_isalnum('{') == 0);
	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_isascii(void)
{
	int	prefailed = failed;

	print_header("ft_isascii");
	print_test("ft_isascii(-1) ? 0", ft_isascii(-1) == 0);
	print_test("ft_isascii(0) ? 1", ft_isascii(0) == 1);
	print_test("ft_isascii('/') ? 1", ft_isascii('/') == 1);
	print_test("ft_isascii('0') ? 1", ft_isascii('0') == 1);
	print_test("ft_isascii('@') ? 1", ft_isascii('@') == 1);
	print_test("ft_isascii('Z') ? 1", ft_isascii('Z') == 1);
	print_test("ft_isascii('`') ? 1", ft_isascii('`') == 1);
	print_test("ft_isascii('a') ? 1", ft_isascii('a') == 1);
	print_test("ft_isascii('{') ? 1", ft_isascii('{') == 1);
	print_test("ft_isascii(127) ? 1", ft_isascii(127) == 1);
	print_test("ft_isascii(128) ? 0", ft_isascii(128) == 0);
	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_isprint(void)
{
	int	prefailed = failed;

	print_header("ft_isprint");
	print_test("ft_isprint(-1) ? 0", ft_isprint(-1) == 0);
	print_test("ft_isprint(0) ? 0", ft_isprint(0) == 0);
	print_test("ft_isprint(31) ? 0", ft_isprint(31) == 0);
	print_test("ft_isprint(' ') ? 1", ft_isprint(' ') == 1);
	print_test("ft_isprint('/') ? 1", ft_isprint('/') == 1);
	print_test("ft_isprint('0') ? 1", ft_isprint('0') == 1);
	print_test("ft_isprint(':') ? 1", ft_isprint(':') == 1);
	print_test("ft_isprint('Z') ? 1", ft_isprint('Z') == 1);
	print_test("ft_isprint('a') ? 1", ft_isprint('a') == 1);
	print_test("ft_isprint('~') ? 1", ft_isprint('~') == 1);
	print_test("ft_isprint(127) ? 0", ft_isprint(127) == 0);
	print_test("ft_isprint(128) ? 0", ft_isprint(128) == 0);
	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_strlen(void)
{
	int	prefailed = failed;

	print_header("ft_strlen");
	print_test("ft_strlen(\"\") ? 0", ft_strlen("") == 0);
	print_test("ft_strlen(\"42\") ? 2", ft_strlen("42") == 2);
	print_test("ft_strlen(\"hello friend\") ? 12", ft_strlen("hello friend") == 12);
	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_memset(void)
{
	int		prefailed = failed;
	char	str[10];

	print_header("ft_memset");
	// test 1
	str[5] = '\0';
	ft_memset(str, 'x', 5);
	print_test("ft_memset(str, 'x', 5) ? \"xxxxx\"", strcmp(str, "xxxxx") == 0);
	// test 2
	str[8] = '\0';
	ft_memset(str, '0', 8);
	print_test("ft_memset(str, '0', 8) ? \"00000000\"", strcmp(str, "00000000") == 0);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_bzero(void)
{
	int		prefailed = failed;
	char	str[4];

	print_header("ft_bzero");
	// test
	memset(str, 'x', 4);
	ft_bzero(str, 4);
	print_test("ft_bzero(str, 4) ? zeroes 4 bytes", str[0] == 0
			&& str[1] == 0 && str[2] == 0 && str[3] == 0);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_memcpy(void)
{
	int		prefailed = failed;
	char	dest[10];

	print_header("ft_memcpy");
	ft_memcpy(dest, "testing", 7);
	print_call("	ft_memcpy(dest, \"testing\", 7)");
	print_test("  ? copy \"testing\" to dest",
			strcmp(dest, "testing") == 0);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_memmove(void)
{
	int		prefailed = failed;
	char	src[10] = "testing";

	print_header("ft_memmove");
	ft_memmove(src + 3, src, 7);
	print_call("	ft_memmove(src + 3, src, 7)");
	print_test("  ? copy \"testing\" from src to src+3",
			strcmp(src + 3, "testing") == 0);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_strlcpy(void)
{
	int		prefailed = failed;
	char	dst[5];
	int		len;

	print_header("ft_strlcpy");
	// test 1
	len = ft_strlcpy(dst, "test", sizeof(dst));
	print_call("	ft_strlcpy(dst, \"test\", sizeof(dst))");
	print_test("  ? copy \"test\" to dst",
		strcmp(dst, "test") == 0);
	print_test("  ? return lenght of source (4)",
		len == 4);
	// test 2
	len = ft_strlcpy(dst, "testing", sizeof(dst));
	print_call("	ft_strlcpy(dst, \"testing\", sizeof(dst))");
	print_test("  ? copy only \"test\" to dst",
		strcmp(dst, "test") == 0);
	print_test("  ? return lenght of source (7)",
		len == 7);
	// test 3
	len = ft_strlcpy(dst, "test", 4);
	print_call("	ft_strlcpy(dst, \"test\", 4)");
	print_test("  ? copy \"tes\" to dst (5 bytes)",
		strcmp(dst, "tes") == 0);
	print_test("  ? truncate dst with '\\0'",
		dst[3] == 0);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_strlcat(void)
{
	int		prefailed = failed;
	char	dst[10] = "test";
	int		len;

	print_header("ft_strlcat");
	// test 1
	len = ft_strlcat(dst, "ing", sizeof(dst));
	print_call("	ft_strlcat(dst, \"ing\", sizeof(dst))");
	print_test("  ? append \"ing\" to the end of dst (\"test\")",
			strcmp(dst, "testing") == 0);
	print_test("  ? return length of \"testing\" (7)",
			len == 7);
	// test 2
	memcpy(dst, "test\0", 5);
	len = ft_strlcat(dst, "ing", 7);
	print_call("	ft_strlcat(dst, \"ing\", 7)");
	print_test("  ? append \"in\" to dst and NUL-terminate",
			strcmp(dst, "testin") == 0);
	print_test("  ? return length of \"testing\" (7)",
			len == 7);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void test_ft_toupper(void)
{
	int prefailed = failed;

	print_header("ft_toupper");
	print_test("  ft_toupper('f') ? 'F'", ft_toupper('f') == 'F');
	print_test("  ft_toupper('T') ? 'T'", ft_toupper('T') == 'T');
	print_test("  ft_toupper('6') ? '6'", ft_toupper('6') == '6');
	print_test("  ft_toupper(21) ? 21", ft_toupper(21) == 21);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void test_ft_tolower(void)
{
	int prefailed = failed;

	print_header("ft_tolower");

	print_test("  ft_tolower('F') ? 'f'", ft_tolower('F') == 'f');
	print_test("  ft_tolower('t') ? 't'", ft_tolower('t') == 't');
	print_test("  ft_tolower('6') ? '6'", ft_tolower('6') == '6');
	print_test("  ft_tolower(21) ? 21", ft_tolower(21) == 21);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_strchr(void)
{
	int prefailed = failed;
	char	*s = "finding 42";

	print_header("ft_strchr");

	print_call("        s[] = \"finding 42\"");
	print_test("  ft_strchr(s, 'f') ? s", ft_strchr(s, 'f') == s);
	print_test("  ft_strchr(s, 'i') ? &s[1]", ft_strchr(s, 'i') == &s[1]);
	print_test("  ft_strchr(s, '4') ? &s[8]", ft_strchr(s, '4') == &s[8]);
	print_test("  ft_strchr(s, '\\0') ? &s[10]", ft_strchr(s, '\0') == &s[10]);
	print_test("  ft_strchr(s, 't') ? NULL", ft_strchr(s, 't') == NULL);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_strrchr(void)
{
	int prefailed = failed;
	char	*s = "finding 42";

	print_header("ft_strrchr");

	print_call("        s[] = \"finding 42\"");
	print_test("  ft_strrchr(s, 'f') ? s", ft_strrchr(s, 'f') == s);
	print_test("  ft_strrchr(s, 'i') ? &s[4]", ft_strrchr(s, 'i') == &s[4]);
	print_test("  ft_strrchr(s, '4') ? &s[8]", ft_strrchr(s, '4') == &s[8]);
	print_test("  ft_strrchr(s, '\\0') ? &s[10]", ft_strrchr(s, '\0') == &s[10]);
	print_test("  ft_strrchr(s, 't') ? NULL", ft_strrchr(s, 't') == NULL);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_strncmp(void)
{
	int prefailed = failed;

	print_header("ft_strncmp");

	print_test("  ft_strncmp(\"test\", \"test\", 4)",
			getsign(ft_strncmp("test", "test", 4)) == getsign(strncmp("test", "test", 4)));
	print_test("  ft_strncmp(\"test\", \"testing\", 4)",
			getsign(ft_strncmp("test", "testing", 4)) == getsign(strncmp("test", "testing", 4)));
	print_test("  ft_strncmp(\"test\", \"testing\", 7)",
			getsign(ft_strncmp("test", "testing", 7)) == getsign(strncmp("test", "testing", 7)));

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_memchr(void)
{
	int prefailed = failed;

	print_header("ft_memchr");

	// tests
	print_test("  ft_memchr(\"abcde\", 'c', 5)",
			ft_memchr("abcde", 'c', 5) == memchr("abcde", 'c', 5));
	print_test("  ft_memchr(\"abcde\", 'a', 1)",
			ft_memchr("abcde", 'a', 1) == memchr("abcde", 'a', 1));
	print_test("  ft_memchr(\"abcde\", 'a', 0)",
			ft_memchr("abcde", 'a', 0) == memchr("abcde", 'a', 0));
	print_test("  ft_memchr(\"abcde\", '\\0', 5)",
			ft_memchr("abcde", '\0', 5) == memchr("abcde", '\0', 5));
	print_test("  ft_memchr(\"abcde\", '\\0', 6)",
			ft_memchr("abcde", '\0', 6) == memchr("abcde", '\0', 6));

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_memcmp(void)
{
	int prefailed = failed;

	print_header("ft_memcmp");

	// tests
	print_test("  ft_memcmp(\"abcde\", \"abcdx\", 5)",
			getsign(ft_memcmp("abcde", "abcdx", 5)) == getsign(memcmp("abcde", "abcdx", 5)));
	print_test("  ft_memcmp(\"abcde\", \"abcdx\", 4)",
			getsign(ft_memcmp("abcde", "abcdx", 4)) == getsign(memcmp("abcde", "abcdx", 4)));
	print_test("  ft_memcmp(\"abcde\", \"xxxxx\", 0)",
			getsign(ft_memcmp("abcde", "xxxxx", 0)) == getsign(memcmp("abcde", "xxxxx", 0)));
	print_test("  ft_memcmp(\"xxxxx\", \"abcde\", 1)",
			getsign(ft_memcmp("xxxxx", "abcde", 1)) == getsign(memcmp("xxxxx", "abcde", 1)));

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_strnstr(void)
{
	int		prefailed = failed;
	char	s[10];

	print_header("ft_strnstr");

	// test 1
	ft_strlcpy(s, "abc", sizeof(s));
	print_test("  ft_strnstr(\"abc\", \"xyz\", 0)",
			ft_strnstr(s, "xyz", 0) == NULL);
	// test 2
	ft_strlcpy(s, "abc", sizeof(s));
	print_test("  ft_strnstr(\"abc\", \"xyz\", 1)",
			ft_strnstr(s, "xyz", 1) == NULL);
	// test 3
	ft_strlcpy(s, "", sizeof(s));
	print_test("  ft_strnstr(\"\", \"\", 0)",
			ft_strnstr(s, "", 0) == &s[0]);
	// test 4
	ft_strlcpy(s, "", sizeof(s));
	print_test("  ft_strnstr(\"\", \"\", 1)",
			ft_strnstr(s, "", 1) == &s[0]);
	// test 5
	ft_strlcpy(s, "", sizeof(s));
	print_test("  ft_strnstr(\"\", \"test\", 0)",
			ft_strnstr(s, "test", 0) == NULL);
	// test 6
	ft_strlcpy(s, "", sizeof(s));
	print_test("  ft_strnstr(\"\", \"test\", 4)",
			ft_strnstr(s, "test", 4) == NULL);
	//	test 7
	ft_strlcpy(s, "test", sizeof(s));
	print_test("  ft_strnstr(\"test\", \"\", 0)",
			ft_strnstr(s, "", 0) == &s[0]);
	//	test 8
	ft_strlcpy(s, "test", sizeof(s));
	print_test("  ft_strnstr(\"test\", \"\", 2)",
			ft_strnstr(s, "", 2) == &s[0]);
	//	test 9
	ft_strlcpy(s, "xxabcdef", sizeof(s));
	print_test("  ft_strnstr(\"xxabcdef\", \"abc\", 2)",
			ft_strnstr(s, "abc", 2) == NULL);
	//	test 14
	ft_strlcpy(s, "xxabcdef", sizeof(s));
	print_test("  ft_strnstr(\"xxabcdef\", \"abc\", 4)",
			ft_strnstr(s, "abc", 4) == NULL);

	//	test 11
	ft_strlcpy(s, "abc", sizeof(s));
	print_test("  ft_strnstr(\"abc\", \"abcdef\", 3)",
			ft_strnstr(s, "abcdef", 3) == NULL);

	//	test 12
	ft_strlcpy(s, "aaxx", sizeof(s));
	print_test("  ft_strnstr(\"aaxx\", \"xx\", 2)",
			ft_strnstr(s, "xx", 2) == NULL);

	//	test 13
	ft_strlcpy(s, "aaxx", sizeof(s));
	print_test("  ft_strnstr(\"aaxx\", \"xx\", 3)",
			ft_strnstr(s, "xx", 3) == NULL);

	//	test 14
	ft_strlcpy(s, "aaxx", sizeof(s));
	print_test("  ft_strnstr(\"aaxx\", \"xx\", 4)",
			ft_strnstr(s, "xx", 4) == &s[2]);

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

static void	test_ft_atoi(void)
{
	int prefailed = failed;

	print_header("ft_atoi");

	// test 1
	print_test("ft_atoi(\" \\t\\v\\n\\r\\f123\")",
			ft_atoi(" \t\v\n\r\f123") == atoi(" \t\v\n\r\f123"));
	// test 2
	print_test("ft_atoi(\"0\")",
			ft_atoi("0") == atoi("0"));
	// test 3
	print_test("ft_atoi(\"-1000043\")",
			ft_atoi("-1000043") == atoi("-1000043"));
	// test 4
	print_test("ft_atoi(\"+00000000000000123\")",
			ft_atoi("+00000000000000123") == atoi("+00000000000000123"));
	// test 5
	print_test("ft_atoi(\"    123\")",
			ft_atoi("    123") == atoi("    123"));
	// test 6
	print_test("ft_atoi(\"--123\")",
			ft_atoi("--123") == atoi("--123"));
	// test 7
	print_test("ft_atoi(\"-+123\")",
			ft_atoi("-+123") == atoi("-+123"));
	// test 8
	print_test("ft_atoi(\"+-123\")",
			ft_atoi("+-123") == atoi("+-123"));
	// test 9
	print_test("ft_atoi(\"++123\")",
			ft_atoi("++123") == atoi("++123"));
	// test 10
	print_test("ft_atoi(\"- 123\")",
			ft_atoi("- 123") == atoi("- 123"));
	// test 11
	print_test("ft_atoi(\"+ 123\")",
			ft_atoi("+ 123") == atoi("+ 123"));
	// test 12
	print_test("ft_atoi(\"+\\n123\")",
			ft_atoi("+\n123") == atoi("+\n123"));
	// test 13
	print_test("ft_atoi(\"1209\")",
			ft_atoi("1209") == atoi("1209"));
	// test 14
	print_test("ft_atoi(\"12/3\")",
			ft_atoi("12/3") == atoi("12/3"));
	// test 15
	print_test("ft_atoi(\"12;3\")",
			ft_atoi("12;3") == atoi("12;3"));

	if (failed == prefailed)
		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
	else
		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
}

// static void	test_ft_NAME(void)
// {
// 	int prefailed = failed;
// 
// 	print_header("ft_NAME");
// 
// 	// tests
// 
// 	if (failed == prefailed)
// 		printf("\n " ANSI_COLOR_GREEN ">>> SUCCESS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ANSI_COLOR_RESET "\n");
// 	else
// 		printf("\n " ANSI_COLOR_RED "<<< FAILURE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" ANSI_COLOR_RESET "\n");
// }

/* =================== MAIN ==================== */

int	main(void)
{
	printf(ANSI_COLOR_MAGENTA);
	printf("\n");
	printf(ANSI_COLOR_CYAN "///" ANSI_COLOR_MAGENTA "-============================================-" ANSI_COLOR_CYAN "/" ANSI_COLOR_MAGENTA "\n");
	printf(ANSI_COLOR_CYAN "//            ARIACORE: LIBFT TESTER            //" ANSI_COLOR_MAGENTA "\n");
	printf(ANSI_COLOR_CYAN "/" ANSI_COLOR_MAGENTA "-============================================-" ANSI_COLOR_CYAN "///" ANSI_COLOR_MAGENTA "\n");
	printf(ANSI_COLOR_RESET);

	// LIBC FUNCTIONS:
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
	test_ft_atoi();
	// SUMMARY:
	print_summary();
	return (0);
}
