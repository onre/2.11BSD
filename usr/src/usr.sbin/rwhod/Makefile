#
# Public Domain.  1996/11/16 - Steven Schultz
#
#	@(#)Makefile	1.1 (2.11BSD) 2024/9/26
#
CFLAGS=	 -O
SEPFLAG= -i
SRCS=	rwhod.c
OBJS=	rwhod.o
MAN=	rwhod.0
MANSRC=	rwhod.8

all: rwhod rwhod.0

rwhod: ${OBJS}
	${CC} ${CFLAGS} ${SEPFLAG} -o $@ ${OBJS}

rwhod.0: ${MANSRC}
	/usr/man/manroff ${MANSRC} > ${MAN}

clean:
	rm -f ${OBJS} ${MAN} rwhod tags 

depend: ${SRCS}
	mkdep ${CFLAGS} ${SRCS}

install: rwhod rwhod.0
	install -c -o bin -g bin -m 444 ${MAN} ${DESTDIR}/usr/man/cat8
	install -s -o root -g bin -m 755 rwhod ${DESTDIR}/usr/sbin/rwhod

lint: ${SRCS}
	lint -hax ${SRCS}

tags: ${SRCS}
	ctags ${SRCS}
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
