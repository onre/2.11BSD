#
# Copyright (c) 1983 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)Makefile	5.8 (2.11BSD) 2025/3/7
#
# Bug report processor and associated programs
#

BUGS_NAME = bugs
BUGS_HOME = @2BSD.COM
DEFS = -DBUGS_NAME='"$(BUGS_NAME)"' -DBUGS_HOME='"$(BUGS_HOME)"'
CFLAGS = -O -DUNIXCOMP $(DEFS)
DESTDIR=

all: bugfiler unixtomh

bugfiler: bugfiler.c
	${CC} ${CFLAGS} ${SEPFLAG} -DUNIXTOMH='"/usr/libexec/unixtomh"' -o bugfiler bugfiler.c

unixtomh: unixtomh.c
	${CC} ${SEPFLAG} ${CFLAGS} -o unixtomh unixtomh.c

install: bugfiler sendbug.sh bugformat unixtomh
	install -s bugfiler ${DESTDIR}/usr/libexec/bugfiler
	install -c -m 555 sendbug.sh ${DESTDIR}/usr/ucb/sendbug
	install -s unixtomh ${DESTDIR}/usr/libexec/unixtomh
	install -c -m 644 bugformat ${DESTDIR}/usr/share/misc/bugformat

clean:
	rm -f *.o bugfiler unixtomh
