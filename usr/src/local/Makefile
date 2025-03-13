#
# 	#(@)Makefile	2.0 (2.11BSD) 2025/2/23
#
DESTDIR=
CFLAGS=	-O
SEPFLAG= -i

# Programs that live in subdirectories, and have makefiles of their own.
SUBDIR= afio cxref ddd less mkovmake mp mtools welcome qterm zmodem

# C source that lives in the current directory
SRCS= decompr16.c trace.c

# C programs that live in the current directory and do not need
# explicit make lines.
STD= decompr16 trace 

# Manpage directory
MANDIR= ${DESTDIR}/usr/local/man

all:	${SUBDIR} ${STD}

${SUBDIR}: FRC
	cd $@; make ${MFLAGS} SEPFLAG=${SEPFLAG}

FRC:

${STD}:
	cc ${CFLAGS} ${SEPFLAG} -o $@ $@.c

install: ${STD}
	-mkdir ${MANDIR}
	-chmod a+r ${MANDIR}
	-for i in 1 2 3 4 5 6 7 8; do \
		(mkdir ${MANDIR}/cat$$i; chmod a+r ${MANDIR}/cat$$i); done
	-for i in ${SUBDIR}; do \
		(cd $$i; make ${MFLAGS} DESTDIR=${DESTDIR} install); done
	-install -s -o bin -g bin  decompr16 ${DESTDIR}/usr/local/decompr16
	-install -s -o bin -g kmem -m 2755 trace ${DESTDIR}/usr/local/trace
	-sh /usr/sbin/makewhatis ${MANDIR}

clean:
	rm -f a.out core *.s *.o ${STD}
	for i in ${SUBDIR}; do (cd $$i; make ${MFLAGS} clean); done

depend:
	-chmod +w Makefile
	mkdep -p ${CFLAGS} ${SRCS}

# DO NOT DELETE THIS LINE -- make depend uses it

# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
