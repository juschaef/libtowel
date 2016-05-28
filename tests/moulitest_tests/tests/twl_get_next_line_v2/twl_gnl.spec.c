#include <project.h>
#include <fcntl.h>
#include "twl_gnl.h"

static void simple_test(t_test *test)
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
	remainder = NULL;
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "aaa") == 0);
	free(line);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "bbb") == 0);
	free(line);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "ccc") == 0);
	free(line);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "ddd") == 0);
	free(line);
	free(remainder);
}

void	suite_twl_gnl(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_test);
}
