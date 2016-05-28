#include <project.h>
#include <fcntl.h>
#include "twl_gnl.h"
#include "twl_xstring.h"

#define test_fn(testname, input, expected, debug) \
static void testname(t_test *test) \
{ \
	char 	*line; \
	char 	*remainder = NULL; \
	int		out; \
	int		fd; \
	int		p[2]; \
	char	*joined; \
	out = dup(1); \
	pipe(p); \
	fd = 1; \
	dup2(p[1], fd); \
	write(fd, input, twl_strlen(input)); \
	close(p[1]); \
	dup2(out, fd); \
	joined = strdup(""); \
	while (twl_gnl(p[0], &line, &remainder)) \
	{ \
		joined = twl_strjoinfree(joined, line, 'b'); \
		joined = twl_strjoinfree(joined, "\n", 'l'); \
	} \
	if (debug) \
	{ \
		printf("========= case =========\n"); \
		printf("input    {%s}\n", input); \
		printf("actual   {%s}\n", joined); \
		printf("expected {%s}\n", expected); \
	} \
	mt_assert(strcmp(joined, expected) == 0); \
	free(joined); \
	free(line); \
	free(remainder); \
}

test_fn(simple_string, "aa\nbb\ncc\n", "aa\nbb\ncc\n", false);
test_fn(without_ending_newline, "aabbcc", "aabbcc\n", false);
test_fn(empty_line, "", "", false);
test_fn(one_newline, "\n", "\n", false);
test_fn(two_newline, "\n\n", "\n\n", false);
test_fn(ten_newline, "\n\n\n\n\n\n\n\n\n\n", "\n\n\n\n\n\n\n\n\n\n", false);

void	suite_gnl_30_test_multi_lines(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
	SUITE_ADD_TEST(suite, without_ending_newline);
	SUITE_ADD_TEST(suite, empty_line);
	SUITE_ADD_TEST(suite, one_newline);
	SUITE_ADD_TEST(suite, two_newline);
	SUITE_ADD_TEST(suite, ten_newline);
}
