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
	write(fd, "aa\0bb\0cc\n", 9);
	close(p[1]);
	dup2(out, fd);
	mt_assert(twl_gnl(p[0], &line, &remainder) == GNL_ERR_BINARY_FILE);
	free(line);
	free(remainder);
}

void	suite_gnl_zero(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
