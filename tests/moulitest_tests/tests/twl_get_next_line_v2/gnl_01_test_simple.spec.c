#include <project.h>
#include <fcntl.h>
#include <fcntl.h>
#include "twl_get_next_line.h"

static void simple_string(t_test *test)
{
	char 	*line;
char 	*remainder = NULL;
	int		out;
	int		p[2];
	int		fd;

	fd = 1;
	out = dup(fd);
	pipe(p);

	dup2(p[1], fd);
	write(fd, "aaa\nbbb\nccc\nddd\n", 16);
	dup2(out, fd);
	close(p[1]);
	twl_get_next_line_v2(p[0], &line, &remainder);
	mt_assert(strcmp(line, "aaa") == 0);
	twl_get_next_line_v2(p[0], &line, &remainder);
	mt_assert(strcmp(line, "bbb") == 0);
	twl_get_next_line_v2(p[0], &line, &remainder);
	mt_assert(strcmp(line, "ccc") == 0);
	twl_get_next_line_v2(p[0], &line, &remainder);
	mt_assert(strcmp(line, "ddd") == 0);
}

void	suite_gnl_01_test_simple(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
