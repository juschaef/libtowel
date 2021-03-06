#include <project.h>
#include <fcntl.h>
#include "twl_gnl.h"

static void test01(t_test *test)
{
	char *line;
	int fd;
	int fd2;
	int fd3;
	char *remainder = NULL;
	int	diff_file_size;
	char buff[100];

    system("mkdir -p sandbox");
	system("openssl rand -out sandbox/large_file.txt -base64 $((50 * 1000 * 3/4)) 2> /dev/null");

	fd = open("sandbox/large_file.txt", O_RDONLY);
	fd2 = open("sandbox/large_file.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (twl_gnl(fd, &line, &remainder) == 1)
	{
	    write(fd2, line, strlen(line));
	    write(fd2, "\n", 1);
	    free(line);
	}

	close(fd);
	close(fd2);

	system("diff sandbox/large_file.txt sandbox/large_file.txt.mine > sandbox/large_file.diff");
	fd3 = open("sandbox/large_file.diff", O_RDONLY);
	diff_file_size = read(fd3, buff, 10);
	close(fd3);

	mt_assert(diff_file_size == 0);
	free(remainder);
}

void	suite_gnl_41_hard_test_large_file(t_suite *suite)
{
	SUITE_ADD_TEST_TIMEOUT(suite, test01, 5 * 1000000);
}
