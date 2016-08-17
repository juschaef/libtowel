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
  int   ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "efghijklmnop\nabc456789", 22);
	close(p[1]);
	dup2(out, fd);
	ret = twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "efghijklmnop") == 0);
  mt_assert(ret == 1);
	ret = twl_gnl(p[0], &line, &remainder);
	mt_assert(strcmp(line, "abc456789") == 0);
	ret = twl_gnl(p[0], &line, &remainder);
  mt_assert(ret == 0);
	free(line);
	free(remainder);
}

void	suite_gnl_19_test_multi_line_without_nl(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
