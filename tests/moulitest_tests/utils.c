#include "twl_string.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include "twl_unistd.h"
#include "twl_arr.h"
#include "twl_string.h"
#include "twl_xstring.h"

void	it_test(char *c)
{
	*c = *c + 1;
}

void	iti_test(unsigned int i, char *c)
{
	*c = *c + i;
}

char	map_test(char c)
{
	return (c + 1);
}

char	mapi_test(unsigned int i, char c)
{
	return (c + i);
}

int		____diddel;

#ifdef BONUS
void	del_test(void *data, size_t i)
{
	(void)data;
	(void)i;
	____diddel++;
}

void	lstiter_test(t_list *ppp)
{
	ppp->content_size = 42;
}

t_list	*lstmap_test(t_list *list)
{
	t_list	*l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = malloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}



#endif


char			*get_opt_testable_result(
	int (getopt_fn)(int argc, char * const argv[], const char *optstring),
	int				*optind_ptr,
	int				*optopt_ptr,
	char			**optarg_ptr,
	char *argv_str, char *optstring)
{
	char			**argv;
	char			**remain;
	int				argc;
	char			getopt_c;
	char			*result;
	char			*tmp;

	argv = twl_strsplit(argv_str, ' ');
	argc = twl_arr_len(argv) - 1;
	result = twl_strdup(argv[0]);
	*optopt_ptr = 0;
	while ((getopt_c = getopt_fn(argc, argv, optstring)) != -1)
	{
		tmp = result;
		asprintf(&result, "%s   %c%c(ind=%d)", tmp, g_twl_optsign, getopt_c, *optind_ptr);
		free(tmp);
		tmp = result;
		asprintf(&result, "%s(opt=%c)", tmp, *optopt_ptr);
		free(tmp);
		if (*optarg_ptr && getopt_c != '?')
		{
			tmp = result;
			asprintf(&result, "%s(arg=%s)", tmp, *optarg_ptr);
			free(tmp);
		}
	}
	remain = argv + *optind_ptr;
	while (*remain)
	{
		tmp = result;
		asprintf(&result, "%s   %s", tmp, *remain);
		free(tmp);
		remain++;
	}
	twl_arr_del(argv, free);
	return (result);
}
