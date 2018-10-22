#
# File          : Makefile
# Description   : Build file for CSE543 optional project 1, applied cryptography
#                 diffie-hellman (hughes) and RSA
# Last Modified : Sun Sep 16 08:42:48 EST 2007
# By            : Trent Jaeger

# Environment Setup
LIBDIRS=-L. -L/opt/local/lib
INCLUDES=-I. -I/opt/local/include
CC=gcc 
CFLAGS=-c $(INCLUDES) -g
LINK=gcc -g
LDFLAGS=$(LIBDIRS)
AR=ar rc
RANLIB=ranlib

# Suffix rules
.c.o :
	${CC} ${CFLAGS} $< -o $@

#
# Setup builds

TARGETS=cse543-p1
ACRYPTLIB=cse543-appcrypto
ACRYPYOBJS=cse543-appcrypto.o

UTILLIB=cse543-util
UTILOBJS=cse543-util.o

#
# Project Protections

p2 : cse543-p1

cse543-p1 : cse543-p1.o lib$(ACRYPTLIB).a lib$(UTILLIB).a
	$(LINK) $(LDFLAGS) cse543-p1.o -l$(ACRYPTLIB) -l$(UTILLIB) -lgmp -o $@

lib$(ACRYPTLIB).a : $(ACRYPYOBJS)
	$(AR) $@ $(ACRYPYOBJS)
	$(RANLIB) $@

lib$(UTILLIB).a : $(UTILOBJS)
	$(AR) $@ $(UTILOBJS)
	$(RANLIB) $@

clean:
	rm -f *.o *~ $(TARGETS) $(LIBOBJS) lib$(ACRYPTLIB).a 

BASENAME=p1-appcrypto
tar: 
	tar cvfz $(BASENAME).tgz -C ..\
	    $(BASENAME)/Makefile \
            $(BASENAME)/cse543-appcrypto.c \
	    $(BASENAME)/cse543-p1.c \
	    $(BASENAME)/cse543-util.c \
            $(BASENAME)/cse543-appcrypto.h \
	    $(BASENAME)/cse543-util.h 
