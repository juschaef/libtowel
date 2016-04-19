#include <project.h>
#include <fcntl.h>
#include "twl_gnl.h"

static void simple_string(t_test *test)
{
	char 	*line;
	char 	*remainder = NULL;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefgh\n", 9);
	write(fd, "ijklmnop\n", 9);
	write(fd, "qrstuvwx\n", 9);
	write(fd, "yzabcdef\n", 9);
	write(fd, "ghijklmn\n", 9);
	write(fd, "opqrstuv\n", 9);
	write(fd, "wxyzabcd\n", 9);
	close(p[1]);
	dup2(out, fd);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "abcdefgh") == 0);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "ijklmnop") == 0);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "qrstuvwx") == 0);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "yzabcdef") == 0);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "ghijklmn") == 0);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "opqrstuv") == 0);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "wxyzabcd") == 0);
}

void	suite_gnl_08_test_few_lines_of_08(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
