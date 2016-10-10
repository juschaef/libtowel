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

#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "twl_stdio.h"
#include "twl_string.h"

static const int	g_error_table_size = 107;
static const char	*g_error_table[] =
{
	"Undefined error: 0",
	"Operation not permitted",
	"No such file or directory",
	"No such process",
	"Interrupted system call",
	"Input/output error",
	"Device not configured",
	"Argument list too long",
	"Exec format error",
	"Bad file descriptor",
	"No child processes",
	"Resource deadlock avoided",
	"Cannot allocate memory",
	"Permission denied",
	"Bad address",
	"Block device required",
	"Resource busy",
	"File exists",
	"Cross-device link",
	"Operation not supported by device",
	"Not a directory",
	"Is a directory",
	"Invalid argument",
	"Too many open files in system",
	"Too many open files",
	"Inappropriate ioctl for device",
	"Text file busy",
	"File too large",
	"No space left on device",
	"Illegal seek",
	"Read-only file system",
	"Too many links",
	"Broken pipe",
	"Numerical argument out of domain",
	"Result too large",
	"Resource temporarily unavailable",
	"Operation now in progress",
	"Operation already in progress",
	"Socket operation on non-socket",
	"Destination address required",
	"Message too long",
	"Protocol wrong type for socket",
	"Protocol not available",
	"Protocol not supported",
	"Socket type not supported",
	"Operation not supported",
	"Protocol family not supported",
	"Address family not supported by protocol family",
	"Address already in use",
	"Can't assign requested address",
	"Network is down",
	"Network is unreachable",
	"Network dropped connection on reset",
	"Software caused connection abort",
	"Connection reset by peer",
	"No buffer space available",
	"Socket is already connected",
	"Socket is not connected",
	"Can't send after socket shutdown",
	"Too many references: can't splice",
	"Operation timed out",
	"Connection refused",
	"Too many levels of symbolic links",
	"File name too long",
	"Host is down",
	"No route to host",
	"Directory not empty",
	"Too many processes",
	"Too many users",
	"Disc quota exceeded",
	"Stale NFS file handle",
	"Too many levels of remote in path",
	"RPC struct is bad",
	"RPC version wrong",
	"RPC prog. not avail",
	"Program version wrong",
	"Bad procedure for program",
	"No locks available",
	"Function not implemented",
	"Inappropriate file type or format",
	"Authentication error",
	"Need authenticator",
	"Device power is off",
	"Device error",
	"Value too large to be stored in data type",
	"Bad executable (or shared library)",
	"Bad CPU type in executable",
	"Shared library version mismatch",
	"Malformed Mach-o file",
	"Operation canceled",
	"Identifier removed",
	"No message of desired type",
	"Illegal byte sequence",
	"Attribute not found",
	"Bad message",
	"EMULTIHOP (Reserved)",
	"No message available on STREAM",
	"ENOLINK (Reserved)",
	"No STREAM resources",
	"Not a STREAM",
	"Protocol error",
	"STREAM ioctl timeout",
	"Operation not supported on socket",
	"Policy not found",
	"State not recoverable",
	"Previous owner died",
	"Interface output queue is full",
	NULL
};
static char			g_twl_strerror_msg[1024];

char			*twl_strerror(int errnum)
{
	if (errnum < 0 || errnum > g_error_table_size || !g_error_table[errnum])
	{
		twl_sprintf(g_twl_strerror_msg, "Unknown error %i", errnum);
	}
	else
	{
		twl_strcpy(g_twl_strerror_msg, g_error_table[errnum]);
	}
	return (g_twl_strerror_msg);
}
