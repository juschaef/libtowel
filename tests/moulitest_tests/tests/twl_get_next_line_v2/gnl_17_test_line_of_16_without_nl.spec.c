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
	write(fd, "mnopqrstuvwxyzab", 16);
	close(p[1]);
	dup2(out, fd);
	twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "mnopqrstuvwxyzab") == 0);
	free(line);
	free(remainder);
}

void	suite_gnl_17_test_line_of_16_without_nl(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
