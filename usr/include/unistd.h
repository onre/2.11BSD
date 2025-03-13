/*-
 * Copyright (c) 1991, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)unistd.h	8.12 (2.11BSD) 2025/2/22
 */

#ifndef _UNISTD_H_
#define	_UNISTD_H_

#include <sys/types.h>
#include <stdint.h>

#define	 STDIN_FILENO	0	/* standard input file descriptor */
#define	STDOUT_FILENO	1	/* standard output file descriptor */
#define	STDERR_FILENO	2	/* standard error file descriptor */

#ifndef NULL
#define	NULL		0	/* null pointer constant */
#endif

/* for lseek() */
#define	SEEK_SET	0
#define	SEEK_CUR	1
#define	SEEK_END	2

/* for access() */
#define F_OK	0	/* test for presence of file */
#define X_OK	1	/* test for execute (search) permission */
#define W_OK	2	/* test for write permission */
#define R_OK	4	/* test for read permission */

int	 access(const char *, int);
unsigned alarm(unsigned);
char	*brk(void *addr);
int	 chdir(const char *);
int	 chown(const char *, uid_t, gid_t);
int	 close(int);
char	*crypt(const char *, const char *);
int	 dup(int);
void	_exit(int);
void	 encrypt(char [64], int);
void	 endusershell(void);
int	 execl(const char *, const char *, ...);
int	 execle(const char *, const char *, ...);
int	 execlp(const char *, const char *, ...);
int	 execv(const char *, char *const []);
int	 execve(const char *, char *const [], char *const []);
int	 execvp(const char *, char *const []);
int	 fchdir(int);
int	 fchown(int, uid_t, gid_t);
int	 fchownat(int, const char *, uid_t, gid_t, int);
pid_t	 fork(void);
int	 fsync(int);
int	 ftruncate(int, off_t);
/* char	*getcwd(char *, size_t); */
char	*getwd(char *buf);
gid_t	 getegid(void);
uid_t	 geteuid(void);
gid_t	 getgid(void);
int	 getgroups(int, gid_t []);
long	 gethostid(void);
int	 gethostname(char *, size_t);
char	*getlogin(void);
int	 getopt(int, char * const [], const char *);
char	*getpass(const char *prompt);
/* pid_t getpgid(pid_t); */
pid_t	 getpgrp(void);
pid_t	 getpid(void);
pid_t	 getppid(void);
uid_t	 getuid(void);
char	*getusershell(void);
int	 isatty(int);
int	 link(const char *, const char *);
off_t	 lseek(int, off_t, int);
int	 nice(int);
int	 pause(void);
int	 pipe(int [2]);
ssize_t	 read(int, void *, size_t);
int	 rmdir(const char *);
char	*sbrk(intptr_t incr);
int	 setegid(gid_t);
int	 seteuid(uid_t);
int	 setgid(gid_t);
int	 sethostid(long);
int	 setpgrp(); /* XXX FIXME not correct */
int	 setregid(gid_t, gid_t);
int	 setreuid(uid_t, uid_t);
int	 setuid(uid_t);
void	 setusershell(void);
unsigned sleep(unsigned);
void	 swab(const void *restrict, void *restrict, ssize_t);
int	 symlink(const char *, const char *);
void	 sync(void);
int	 truncate(const char *, off_t);
char	*ttyname(int);
unsigned ualarm(unsigned, unsigned);
int	 unlink(const char *);
void	 usleep(unsigned);
pid_t	 vfork(void);
ssize_t	 write(int, const void *, size_t);

extern	char	*optarg;		/* getopt(3) external variables */
extern	int	opterr, optind, optopt;

#endif /* !_UNISTD_H_ */
