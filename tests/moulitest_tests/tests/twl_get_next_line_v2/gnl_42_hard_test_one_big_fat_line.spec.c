#include <project.h>
#include <fcntl.h>
#include "twl_gnl.h"

static void test01(t_test *test)
{
	test->timeout = 1;

	char *line;
	char *remainder = NULL;
	int fd;
	int fd2;
	int fd3;
	int	diff_file_size;
	char buff[100];

    system("mkdir -p sandbox");
	system("openssl rand -base64 $((30 * 100 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
	system("echo '\n' >> sandbox/one_big_fat_line.txt");

	fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (twl_gnl(fd, &line, &remainder) == 1)
	{
	    write(fd2, line, strlen(line));
	    write(fd2, "\n", 1);
	    free(line);
	}
	if (line)
		write(fd2, line, strlen(line));
	close(fd);
	close(fd2);

	system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
	fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	diff_file_size = read(fd3, buff, 10);
	close(fd3);

	mt_assert(diff_file_size == 0);
	free(remainder);
}

void	suite_gnl_42_hard_test_one_big_fat_line(t_suite *suite)
{
	SUITE_ADD_TEST_TIMEOUT(suite, test01, 5 * 1000000);
}
