#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files


APPSWU_ROOT = /home/kirk/repo/Planthouse/application/applBlock/appSwu/src

# define the C compiler to use
#CC =arm-linux-gnueabihf-g++
#C = arm-linux-gnueabihf-gcc
#CC=g++
#C=gcc
#/PATH_TO_THE_RPI_TOOLS/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-gcc
CC=/home/kirk/repo/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-g++
C=/home/kirk/repo/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-gcc

#CC=/home/kirk/repo/tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/bin/arm-linux-gnueabihf-g++
#C=/home/kirk/repo/tools/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc
# define any compile-time flags
CPPFLAGS = -c -std=c++11 -pthread 
#-Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s
CFLAGS = -Wall -c 
# define any directories containing header files other than /usr/include
#
INCLUDES  := -I/home/kirk/repo/Planthouse/application/applBlock/appSwu/export/ \
	-I/home/kirk/repo/Planthouse/application/applBlock/appSwu/inc \
	-I/usr/include/mysql \
	-I/usr/local/include



# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
CPPLFLAGS := -L/usr/local/lib \
	     -L/usr/lib 
		
#LFLAGS =
# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lpthread -lwiringPi -lmysqlclient -lz

#-Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s

# define the CPP source files
SRCS = Planthouse.cpp DbHandler.cpp TempMoistSensor.cpp PumpRelay.cpp
CSRCS = 
# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS := $(CSRCS:%.c=%.o) $(SRCS:%.cpp=%.o)

# define the executable file 
MAIN = Planthouse.exe

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean cleanest

all:    $(MAIN) 

$(MAIN):$(OBJS) 
	@echo "$(OBJS)"
	$(CC) -o $@ $^ $(CPPLFLAGS)  $(LIBS) 
# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)


%.o: $(APPSWU_ROOT)/%.c
	$(C) $(CFLAGS)  $<  -o $@ 

%.o: $(APPSWU_ROOT)/%.cpp
	$(CC) $(CPPFLAGS) $(INCLUDES)  $<  -o  $@ 
clean: 
	rm *.o 

cleanest: clean
	rm Planthouse.exe

depend: $(SRCS) makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

