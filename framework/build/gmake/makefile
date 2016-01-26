#****************************************************************************
# Makefile for lplugin_hq_leavelone
#****************************************************************************

# DEBUG can be set to YES to include debugging info, or NO otherwise
#DEBUG          := NO

# PROFILE can be set to YES to include profiling info, or NO otherwise
PROFILE        := NO

# WLCOMM_USE_STL can be used to turn on STL support. NO, then STL
# will not be used. YES will include the STL files.
WLCOMM_USE_STL := NO

#****************************************************************************

TLIBNAME := liblplugin_hq_szgw.so

# setting
# sourcecode path
BASESRCDIR  :=  .
# working path
BASEWRKDIR  := .
#comm path  D:\KMDS\src
COMMPATH    := .
#output path

TOUTPUTDIR   := .

#****************************************************************************
# Source files
#****************************************************************************
SRCS  = ${BASESRCDIR}src/main.cpp
SRCS += ${BASESRCDIR}src/wsocket.cpp

CC     := gcc
CXX    := g++ 
LD     := g++
AR     := ar cr
RANLIB := ranlib

#ADDDEF := -D_VSS_TEST_
ADDDEF :=
DEBUG_CFLAGS     := -fPIC -Wall -Wno-format  -D_TEST_ ${ADDDEF}
RELEASE_CFLAGS   := -fPIC -Wall -Wno-unknown-pragmas -Wno-format -O3 ${ADDDEF}

LIBS		 :=

DEBUG_CXXFLAGS   := ${DEBUG_CFLAGS}
RELEASE_CXXFLAGS := ${RELEASE_CFLAGS}

DEBUG_LDFLAGS    := 
RELEASE_LDFLAGS  :=

ifeq (YES, ${LDEBUG})
   CFLAGS       := ${DEBUG_CFLAGS}
   CXXFLAGS     := ${DEBUG_CXXFLAGS}
   LDFLAGS      := ${DEBUG_LDFLAGS}
   EXTRA_LIBS:= 
   OUTPUTDIR    := ${TOUTPUTDIR}
else
   CFLAGS       := ${RELEASE_CFLAGS}
   CXXFLAGS     := ${RELEASE_CXXFLAGS}
   LDFLAGS      := ${RELEASE_LDFLAGS}
   EXTRA_LIBS:= 
   OUTPUTDIR    := ${TOUTPUTDIR}
endif

ifeq (YES, ${PROFILE})
   CFLAGS   := ${CFLAGS} -pg -O3
   CXXFLAGS := ${CXXFLAGS} -pg -O3
   LDFLAGS  := ${LDFLAGS} -pg
endif

DEFS := -D_LINUX_

BASE_LIBS := -lpthread -ldl

INCS := -I${BASESRCDIR} \
        -I${BASEWRKDIR} \
        -I${COMMPATH} \
        -I${COMMPATH} \
        -I${COMMPATH} \
        -I${COMMPATH} \
        -I${COMMPATH} \
        -I${COMMPATH}

#****************************************************************************
# Makefile code common to all platforms
#****************************************************************************

CFLAGS   := ${CFLAGS}   ${DEFS}
CXXFLAGS := ${CXXFLAGS} ${DEFS}

#****************************************************************************
# Targets of the build
#****************************************************************************

LIBNAME      := ${TLIBNAME}

LIB := ${LIBNAME}

all: ${LIB}


# Add on the sources for libraries
SRCS := ${SRCS}

LIBOBJS := $(addsuffix .o,$(basename ${SRCS}))

#****************************************************************************
# Output
#****************************************************************************
${LIB}: ${LIBOBJS}
	$(CXX) -o $@ -shared ${LIBOBJS} ${BASE_LIBS} ${EXTRA_LIBS}
	#cp -f ${LIB} ${OUTPUTDIR}${LIB}
	#rm -f $@
	#cp -f ${LIB} /home/kmds/szkingdom/all_server/kdhqtrans_szgw_test1213/plugins/${LIB}
#****************************************************************************
# common rules
#****************************************************************************

# Rules for compiling source files to object files
%.o : %.cpp
	${CXX} -c ${CXXFLAGS} ${INCS} $< -o $@

%.o : %.c
	${CC} -c ${CFLAGS} ${INCS} $< -o $@

dist:
	bash makedistlinux

clean:
	rm -f ${LIBOBJS} ${LIB}

cleanobjs:
	-rm -f core ${LIBOBJS}

auto:
	make clean
	make all
	make cleanobjs
