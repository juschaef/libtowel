/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_string.h"
#include "twl_stdio.h"

static const int	g_signal_table_size = 32;
static const char	*g_signal_table[] =
{
	NULL,
	"Hangup: 1",
	"Interrupt: 2",
	"Quit: 3",
	"Illegal instruction: 4",
	"Trace/BPT trap: 5",
	"Abort trap: 6",
	"EMT trap: 7",
	"Floating point exception: 8",
	"Killed: 9",
	"Bus error: 10",
	"Segmentation fault: 11",
	"Bad system call: 12",
	"Broken pipe: 13",
	"Alarm clock: 14",
	"Terminated: 15",
	"Urgent I/O condition: 16",
	"Suspended (signal): 17",
	"Suspended: 18",
	"Continued: 19",
	"Child exited: 20",
	"Stopped (tty input): 21",
	"Stopped (tty output): 22",
	"I/O possible: 23",
	"Cputime limit exceeded: 24",
	"Filesize limit exceeded: 25",
	"Virtual timer expired: 26",
	"Profiling timer expired: 27",
	"Window size changes: 28",
	"Information request: 29",
	"User defined signal 1: 30",
	"User defined signal 2: 31",
	NULL
};
static char			g_twl_strsignal_msg[1024];

char			*twl_strsignal(int signum)
{
	if (signum < 0 || signum > g_signal_table_size || !g_signal_table[signum])
	{
		twl_sprintf(g_twl_strsignal_msg, "Unknown signal: %i%c", signum, 0);
	}
	else
	{
		twl_strcpy(g_twl_strsignal_msg, g_signal_table[signum]);
	}
	return (g_twl_strsignal_msg);
}
