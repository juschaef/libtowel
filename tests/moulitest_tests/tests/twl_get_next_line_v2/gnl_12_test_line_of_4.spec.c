#include <project.h>
#include <fcntl.h>
#include "twl_get_next_line.h"

static void simple_string(t_test *test)
{
	char 	*line;
	char 	*remainder = NULL;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	close(p[1]);
	dup2(out, fd);
	twl_get_next_line_v2(p[0], &line, &remainder);
	mt_assert(strcmp(line, "abcd") == 0);
	ret = twl_get_next_line_v2(p[0], &line, &remainder);
	mt_assert(ret == 0);
}

void	suite_gnl_12_test_line_of_4(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
