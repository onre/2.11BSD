#@(#)@(#)Makefile	2.6.1 1996/11/27

DESTDIR		=
CSRCS		=	pop_dele.c pop_dropcopy.c pop_dropinfo.c \
			pop_get_command.c pop_get_subcommand.c pop_init.c \
			pop_last.c pop_list.c pop_log.c pop_lower.c \
			pop_msg.c pop_parse.c pop_pass.c pop_quit.c \
			pop_rset.c pop_send.c pop_stat.c pop_updt.c \
			pop_user.c pop_xtnd.c pop_xmit.c popper.c
OBJS		=	pop_dele.o pop_dropcopy.o pop_dropinfo.o \
			pop_get_command.o pop_get_subcommand.o pop_init.o \
			pop_last.o pop_list.o pop_log.o pop_lower.o \
			pop_msg.o pop_parse.o pop_pass.o pop_quit.o \
			pop_rset.o pop_send.o pop_stat.o pop_updt.o \
			pop_user.o pop_xtnd.o pop_xmit.o popper.o
DOCS		=	README pop3.rfc1081 pop3e.rfc1082 popper.8
INCLUDES	=	popper.h version.h
SRCS		=	${CSRCS} ${INCLUDES}
SCCS		=	/usr/ucb/sccs
REL		=
MAKEFILE	=	Makefile

#               Options are:
#               BIND43          -	If you are using BSD 4.3 domain 
#					name service.
#		DEBUG		-	Include the debugging code.  Note:  You
#					still have to use the -d or -t flag to
#					enable debugging.
#               HAVE_VSPRINTF   -	If the vsprintf functions are available 
#					on your system.
#               SYSLOG42        -	For BSD 4.2 syslog (default is BSD 4.3 
#					syslog).
#               STRNCASECMP     -	If you do not have strncasecmp()

CFLAGS		=	-O -DBIND43
TARGET		=	popper
TAR		=	${TARGET}.tar
INSTALLDIR	=	${DESTDIR}/usr/libexec
MANPAGE		=	popper.8
CATPAGE		=	popper.0
MANDIR		=	${DESTDIR}/usr/man/cat8

all: ${TARGET} ${CATPAGE}

${TARGET}: ${OBJS}
	cc  -i ${OBJS} -o ${TARGET}

tar: ${SRCS} ${DOCS} ${MAKEFILE}
	rm -f ${TAR} *.Z*
	tar -cvf ${TAR} ${SRCS} ${DOCS} ${MAKEFILE}
	compress ${TAR}
	uuencode ${TAR}.Z ${TAR}.Z > ${TAR}.Z.uuencoded
	split -300 ${TAR}.Z.uuencoded
	mv xaa ${TAR}.Z.uuencoded.xaa
	mv xab ${TAR}.Z.uuencoded.xab
	mv xac ${TAR}.Z.uuencoded.xac
	mv xad ${TAR}.Z.uuencoded.xad
	mv xae ${TAR}.Z.uuencoded.xae

clean:
	rm -f core *.o *.Z* ${CATPAGE} ${TARGET}

install: ${TARGET} ${CATPAGE}
	install -c -m 700 -o root -g staff ${TARGET} ${INSTALLDIR}
	install -c -o bin -g bin -m 444 ${CATPAGE} ${MANDIR}

${CATPAGE}:	${MANPAGE}
	nroff -h -man ${MANPAGE} > ${CATPAGE}

edit:
	${SCCS} edit ${REL} ${SRCS}

admin:
	${SCCS} admin -ft"Copyright (c) 1990 Regents of the University of California.\nAll rights reserved.\n" ${SRCS}

sources: ${SRCS}

${SRCS}:
	${SCCS} get ${REL} $@ -p | expand -4 > $@

${DOCS}:
	${SCCS} get README -p | expand -4 > README
	${SCCS} get popper.8 -p | expand -4 > popper.8
	
${OBJS}:    popper.h version.h
