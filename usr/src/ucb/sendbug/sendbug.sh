#!/bin/sh -
#
# Copyright (c) 1983 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	@(#)sendbug.sh	6.3 (2.11BSD) 2025/3/7
#
# Create a bug report and mail to bugs@2bsd.com
#

TEMP=/tmp/bug$$
FORMAT=/usr/share/misc/bugformat

: ${BUGADDR=bugs@2BSD.COM}
: ${EDITOR=/usr/ucb/vi}

trap '/bin/rm -f $TEMP ; exit 1' 1 2 3 13 15

/bin/cp $FORMAT $TEMP
if $EDITOR $TEMP
then
	if cmp -s $FORMAT $TEMP
	then
		echo "File not changed, no bug report submitted."
		exit
	fi
	case "$#" in
	0) /usr/sbin/sendmail -t -oi $BUGADDR  < $TEMP ;;
	*) /usr/sbin/sendmail -t -oi "$@" < $TEMP ;;
	esac
fi

/bin/rm -f $TEMP
