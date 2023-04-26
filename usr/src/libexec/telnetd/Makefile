#
#	@(#)Makefile	2.0 (2.11BSD) 2023/4/26
#
CFLAGS=	 -O
SEPFLAG= -i
SRCS=	telnetd.c gettytab.c subr.c init.c
OBJS=	telnetd.o gettytab.o subr.o init.o
MAN=	telnetd.0
MANSRC=	telnetd.8

all: telnetd telnetd.0

telnetd: ${OBJS}
	${CC} ${CFLAGS} ${SEPFLAG} -o $@ ${OBJS}

telnetd.0: ${MANSRC}
	/usr/man/manroff ${MANSRC} > ${MAN}

clean:
	rm -f ${OBJS} ${MAN} telnetd tags 

depend: ${SRCS}
	mkdep ${CFLAGS} ${SRCS}

install: telnetd ${MAN}
	install -c -o bin -g bin -m 444 ${MAN} ${DESTDIR}/usr/man/cat8
	install -c -s -o root -g bin -m 755 telnetd ${DESTDIR}/usr/libexec/telnetd

lint: ${SRCS}
	lint -hax ${SRCS}

tags: ${SRCS}
	ctags ${SRCS}
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
