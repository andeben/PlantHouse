#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files


APPSWU_ROOT = /home/kirk/repo/Planthouse/application/applBlock/appSwu/src

# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -std=c++11 -pthread 

# define any directories containing header files other than /usr/include
#
INCLUDES  := -I/home/kirk/repo/Planthouse/application/applBlock/appSwu/export/ \
	-I/home/kirk/repo/Planthouse/application/applBlock/appSwu/inc \
	-I/usr/include/mysql

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = -L/usr/lib/x86_64-linux_gnu
#LFLAGS =
# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lpthread -lmysqlclient

# define the C source files
SRCS = Planthouse.cpp

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.cpp=.o)
#OBJS=$(subst .cpp,.o,$(SRCS))

# define the executable file 
MAIN = Planthouse.exe

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean cleanest

all:    $(MAIN) 

$(MAIN): $(OBJS) 
	@echo "$(OBJS)"
	$(CC) -o $@ $^ $(LFLAGS) $(LIBS)	

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
%.o: $(APPSWU_ROOT)/%.cpp
	$(CC) -c $(CFLAGS) $(INCLUDES)  $<  -o $@ 
clean: 
	rm *.o 

cleanest: clean
	rm Planthouse.exe

depend: $(SRCS) makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

