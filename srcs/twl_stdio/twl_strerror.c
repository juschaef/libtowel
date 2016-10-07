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

#define ENTRY(value, name, msg) { value, name, msg }

static const t_error_info	g_error_table[] =
{
#if defined (EPERM)

	ENTRY(EPERM, "EPERM", "Operation not permitted"),
#endif

#if defined (ENOENT)

	ENTRY(ENOENT, "ENOENT", "No such file or directory"),
#endif

#if defined (ESRCH)

	ENTRY(ESRCH, "ESRCH", "No such process"),
#endif

#if defined (EINTR)

	ENTRY(EINTR, "EINTR", "Interrupted system call"),
#endif

#if defined (EIO)

	ENTRY(EIO, "EIO", "Input/output error"),
#endif

#if defined (ENXIO)

	ENTRY(ENXIO, "ENXIO", "Device not configured"),
#endif

#if defined (E2BIG)

	ENTRY(E2BIG, "E2BIG", "Argument list too long"),
#endif

#if defined (ENOEXEC)

	ENTRY(ENOEXEC, "ENOEXEC", "Exec format error"),
#endif

#if defined (EBADF)

	ENTRY(EBADF, "EBADF", "Bad file descriptor"),
#endif

#if defined (ECHILD)

	ENTRY(ECHILD, "ECHILD", "No child processes"),
#endif

#if defined (EWOULDBLOCK)

	ENTRY(EWOULDBLOCK, "EWOULDBLOCK", "Operation would block"),
#endif

#if defined (EAGAIN)

	ENTRY(EAGAIN, "EAGAIN", "No more processes"),
#endif

#if defined (ENOMEM)

	ENTRY(ENOMEM, "ENOMEM", "Not enough space"),
#endif

#if defined (EACCES)

	ENTRY(EACCES, "EACCES", "Permission denied"),
#endif

#if defined (EFAULT)

	ENTRY(EFAULT, "EFAULT", "Bad address"),
#endif

#if defined (ENOTBLK)

	ENTRY(ENOTBLK, "ENOTBLK", "Block device required"),
#endif

#if defined (EBUSY)

	ENTRY(EBUSY, "EBUSY", "Device busy"),
#endif

#if defined (EEXIST)

	ENTRY(EEXIST, "EEXIST", "File exists"),
#endif

#if defined (EXDEV)

	ENTRY(EXDEV, "EXDEV", "Cross-device link"),
#endif

#if defined (ENODEV)

	ENTRY(ENODEV, "ENODEV", "No such device"),
#endif

#if defined (ENOTDIR)

	ENTRY(ENOTDIR, "ENOTDIR", "Not a directory"),
#endif

#if defined (EISDIR)

	ENTRY(EISDIR, "EISDIR", "Is a directory"),
#endif

#if defined (EINVAL)

	ENTRY(EINVAL, "EINVAL", "Invalid argument"),
#endif

#if defined (ENFILE)

	ENTRY(ENFILE, "ENFILE", "File table overflow"),
#endif

#if defined (EMFILE)

	ENTRY(EMFILE, "EMFILE", "Too many open files"),
#endif

#if defined (ENOTTY)

	ENTRY(ENOTTY, "ENOTTY", "Not a typewriter"),
#endif

#if defined (ETXTBSY)

	ENTRY(ETXTBSY, "ETXTBSY", "Text file busy"),
#endif

#if defined (EFBIG)

	ENTRY(EFBIG, "EFBIG", "File too large"),
#endif

#if defined (ENOSPC)

	ENTRY(ENOSPC, "ENOSPC", "No space left on device"),
#endif

#if defined (ESPIPE)

	ENTRY(ESPIPE, "ESPIPE", "Illegal seek"),
#endif

#if defined (EROFS)

	ENTRY(EROFS, "EROFS", "Read-only file system"),
#endif

#if defined (EMLINK)

	ENTRY(EMLINK, "EMLINK", "Too many links"),
#endif

#if defined (EPIPE)

	ENTRY(EPIPE, "EPIPE", "Broken pipe"),
#endif

#if defined (EDOM)

	ENTRY(EDOM, "EDOM", "Math argument out of domain of func"),
#endif

#if defined (ERANGE)

	ENTRY(ERANGE, "ERANGE", "Math result not representable"),
#endif

#if defined (ENOMSG)

	ENTRY(ENOMSG, "ENOMSG", "No message of desired type"),
#endif

#if defined (EIDRM)

	ENTRY(EIDRM, "EIDRM", "Identifier removed"),
#endif

#if defined (ECHRNG)

	ENTRY(ECHRNG, "ECHRNG", "Channel number out of range"),
#endif

#if defined (EL2NSYNC)

	ENTRY(EL2NSYNC, "EL2NSYNC", "Level 2 not synchronized"),
#endif

#if defined (EL3HLT)

	ENTRY(EL3HLT, "EL3HLT", "Level 3 halted"),
#endif

#if defined (EL3RST)

	ENTRY(EL3RST, "EL3RST", "Level 3 reset"),
#endif

#if defined (ELNRNG)

	ENTRY(ELNRNG, "ELNRNG", "Link number out of range"),
#endif

#if defined (EUNATCH)

	ENTRY(EUNATCH, "EUNATCH", "Protocol driver not attached"),
#endif

#if defined (ENOCSI)

	ENTRY(ENOCSI, "ENOCSI", "No CSI structure available"),
#endif

#if defined (EL2HLT)

	ENTRY(EL2HLT, "EL2HLT", "Level 2 halted"),
#endif

#if defined (EDEADLK)

	ENTRY(EDEADLK, "EDEADLK", "Deadlock condition"),
#endif

#if defined (ENOLCK)

	ENTRY(ENOLCK, "ENOLCK", "No record locks available"),
#endif

#if defined (EBADE)

	ENTRY(EBADE, "EBADE", "Invalid exchange"),
#endif

#if defined (EBADR)

	ENTRY(EBADR, "EBADR", "Invalid request descriptor"),
#endif

#if defined (EXFULL)

	ENTRY(EXFULL, "EXFULL", "Exchange full"),
#endif

#if defined (ENOANO)

	ENTRY(ENOANO, "ENOANO", "No anode"),
#endif

#if defined (EBADRQC)

	ENTRY(EBADRQC, "EBADRQC", "Invalid request code"),
#endif

#if defined (EBADSLT)

	ENTRY(EBADSLT, "EBADSLT", "Invalid slot"),
#endif

#if defined (EDEADLOCK)

	ENTRY(EDEADLOCK, "EDEADLOCK", "File locking deadlock error"),
#endif

#if defined (EBFONT)

	ENTRY(EBFONT, "EBFONT", "Bad font file format"),
#endif

#if defined (ENOSTR)

	ENTRY(ENOSTR, "ENOSTR", "Device not a stream"),
#endif

#if defined (ENODATA)

	ENTRY(ENODATA, "ENODATA", "No data available"),
#endif

#if defined (ETIME)

	ENTRY(ETIME, "ETIME", "Timer expired"),
#endif

#if defined (ENOSR)

	ENTRY(ENOSR, "ENOSR", "Out of streams resources"),
#endif

#if defined (ENONET)

	ENTRY(ENONET, "ENONET", "Machine is not on the network"),
#endif

#if defined (ENOPKG)

	ENTRY(ENOPKG, "ENOPKG", "Package not installed"),
#endif

#if defined (EREMOTE)

	ENTRY(EREMOTE, "EREMOTE", "Object is remote"),
#endif

#if defined (ENOLINK)

	ENTRY(ENOLINK, "ENOLINK", "Link has been severed"),
#endif

#if defined (EADV)

	ENTRY(EADV, "EADV", "Advertise error"),
#endif

#if defined (ESRMNT)

	ENTRY(ESRMNT, "ESRMNT", "Srmount error"),
#endif

#if defined (ECOMM)

	ENTRY(ECOMM, "ECOMM", "Communication error on send"),
#endif

#if defined (EPROTO)

	ENTRY(EPROTO, "EPROTO", "Protocol error"),
#endif

#if defined (EMULTIHOP)

	ENTRY(EMULTIHOP, "EMULTIHOP", "Multihop attempted"),
#endif

#if defined (EDOTDOT)

	ENTRY(EDOTDOT, "EDOTDOT", "RFS specific error"),
#endif

#if defined (EBADMSG)

	ENTRY(EBADMSG, "EBADMSG", "Not a data message"),
#endif

#if defined (ENAMETOOLONG)

	ENTRY(ENAMETOOLONG, "ENAMETOOLONG", "File name too long"),
#endif

#if defined (EOVERFLOW)

	ENTRY(EOVERFLOW, "EOVERFLOW", "Value too large for defined data type"),
#endif

#if defined (ENOTUNIQ)

	ENTRY(ENOTUNIQ, "ENOTUNIQ", "Name not unique on network"),
#endif

#if defined (EBADFD)

	ENTRY(EBADFD, "EBADFD", "File descriptor in bad state"),
#endif

#if defined (EREMCHG)

	ENTRY(EREMCHG, "EREMCHG", "Remote address changed"),
#endif

#if defined (ELIBACC)

	ENTRY(ELIBACC, "ELIBACC", "Can not access a needed shared library"),
#endif

#if defined (ELIBBAD)

	ENTRY(ELIBBAD, "ELIBBAD", "Accessing a corrupted shared library"),
#endif

#if defined (ELIBSCN)

	ENTRY(ELIBSCN, "ELIBSCN", ".lib section in a.out corrupted"),
#endif

#if defined (ELIBMAX)

	ENTRY(ELIBMAX, "ELIBMAX",
			"Attempting to link in too many shared libraries"),
#endif

#if defined (ELIBEXEC)

	ENTRY(ELIBEXEC, "ELIBEXEC", "Cannot exec a shared library directly"),
#endif

#if defined (EILSEQ)

	ENTRY(EILSEQ, "EILSEQ", "Illegal byte sequence"),
#endif

#if defined (ENOSYS)

	ENTRY(ENOSYS, "ENOSYS", "Operation not applicable"),
#endif

#if defined (ELOOP)

	ENTRY(ELOOP, "ELOOP", "Too many symbolic links encountered"),
#endif

#if defined (ERESTART)

	ENTRY(ERESTART, "ERESTART", "Interrupted system call should be restarted"),
#endif

#if defined (ESTRPIPE)

	ENTRY(ESTRPIPE, "ESTRPIPE", "Streams pipe error"),
#endif

#if defined (ENOTEMPTY)

	ENTRY(ENOTEMPTY, "ENOTEMPTY", "Directory not empty"),
#endif

#if defined (EUSERS)

	ENTRY(EUSERS, "EUSERS", "Too many users"),
#endif

#if defined (ENOTSOCK)

	ENTRY(ENOTSOCK, "ENOTSOCK", "Socket operation on non-socket"),
#endif

#if defined (EDESTADDRREQ)

	ENTRY(EDESTADDRREQ, "EDESTADDRREQ", "Destination address required"),
#endif

#if defined (EMSGSIZE)

	ENTRY(EMSGSIZE, "EMSGSIZE", "Message too long"),
#endif

#if defined (EPROTOTYPE)

	ENTRY(EPROTOTYPE, "EPROTOTYPE", "Protocol wrong type for socket"),
#endif

#if defined (ENOPROTOOPT)

	ENTRY(ENOPROTOOPT, "ENOPROTOOPT", "Protocol not available"),
#endif

#if defined (EPROTONOSUPPORT)

	ENTRY(EPROTONOSUPPORT, "EPROTONOSUPPORT", "Protocol not supported"),
#endif

#if defined (ESOCKTNOSUPPORT)

	ENTRY(ESOCKTNOSUPPORT, "ESOCKTNOSUPPORT", "Socket type not supported"),
#endif

#if defined (EOPNOTSUPP)

	ENTRY(EOPNOTSUPP, "EOPNOTSUPP",
			"Operation not supported on transport endpoint"),
#endif

#if defined (EPFNOSUPPORT)

	ENTRY(EPFNOSUPPORT, "EPFNOSUPPORT", "Protocol family not supported"),
#endif

#if defined (EAFNOSUPPORT)

	ENTRY(EAFNOSUPPORT, "EAFNOSUPPORT",
			"Address family not supported by protocol"),
#endif

#if defined (EADDRINUSE)

	ENTRY(EADDRINUSE, "EADDRINUSE", "Address already in use"),
#endif

#if defined (EADDRNOTAVAIL)

	ENTRY(EADDRNOTAVAIL, "EADDRNOTAVAIL", "Cannot assign requested address"),
#endif

#if defined (ENETDOWN)

	ENTRY(ENETDOWN, "ENETDOWN", "Network is down"),
#endif

#if defined (ENETUNREACH)

	ENTRY(ENETUNREACH, "ENETUNREACH", "Network is unreachable"),
#endif

#if defined (ENETRESET)

	ENTRY(ENETRESET, "ENETRESET",
			"Network dropped connection because of reset"),
#endif

#if defined (ECONNABORTED)

	ENTRY(ECONNABORTED, "ECONNABORTED", "Software caused connection abort"),
#endif

#if defined (ECONNRESET)

	ENTRY(ECONNRESET, "ECONNRESET", "Connection reset by peer"),
#endif

#if defined (ENOBUFS)

	ENTRY(ENOBUFS, "ENOBUFS", "No buffer space available"),
#endif

#if defined (EISCONN)

	ENTRY(EISCONN, "EISCONN", "Transport endpoint is already connected"),
#endif

#if defined (ENOTCONN)

	ENTRY(ENOTCONN, "ENOTCONN", "Transport endpoint is not connected"),
#endif

#if defined (ESHUTDOWN)

	ENTRY(ESHUTDOWN, "ESHUTDOWN",
			"Cannot send after transport endpoint shutdown"),
#endif

#if defined (ETOOMANYREFS)

	ENTRY(ETOOMANYREFS, "ETOOMANYREFS", "Too many references: cannot splice"),
#endif

#if defined (ETIMEDOUT)

	ENTRY(ETIMEDOUT, "ETIMEDOUT", "Connection timed out"),
#endif

#if defined (ECONNREFUSED)

	ENTRY(ECONNREFUSED, "ECONNREFUSED", "Connection refused"),
#endif

#if defined (EHOSTDOWN)

	ENTRY(EHOSTDOWN, "EHOSTDOWN", "Host is down"),
#endif

#if defined (EHOSTUNREACH)

	ENTRY(EHOSTUNREACH, "EHOSTUNREACH", "No route to host"),
#endif

#if defined (EALREADY)

	ENTRY(EALREADY, "EALREADY", "Operation already in progress"),
#endif

#if defined (EINPROGRESS)

	ENTRY(EINPROGRESS, "EINPROGRESS", "Operation now in progress"),
#endif

#if defined (ESTALE)

	ENTRY(ESTALE, "ESTALE", "Stale NFS file handle"),
#endif

#if defined (EUCLEAN)

	ENTRY(EUCLEAN, "EUCLEAN", "Structure needs cleaning"),
#endif

#if defined (ENOTNAM)

	ENTRY(ENOTNAM, "ENOTNAM", "Not a XENIX named type file"),
#endif

#if defined (ENAVAIL)

	ENTRY(ENAVAIL, "ENAVAIL", "No XENIX semaphores available"),
#endif

#if defined (EISNAM)

	ENTRY(EISNAM, "EISNAM", "Is a named type file"),
#endif

#if defined (EREMOTEIO)

	ENTRY(EREMOTEIO, "EREMOTEIO", "Remote I/O error"),
#endif

	ENTRY(0, NULL, NULL)
};

char			*twl_strerror(int errnum)
{
	size_t			index;
	t_error_info	info;

	index = 0;
	while (true)
	{
		info = g_error_table[index];
		if (info.name == NULL)
			return ("error not found");
		if (info.value == errnum)
			break ;
		index += 1;
	}
	return (info.msg);
}
