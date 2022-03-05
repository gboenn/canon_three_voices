SRCS = pitch_work.cpp
HDRS = /usr/local/include/chunking/Modul.h
OBJS = canon_3.o
CC = g++
CFLAGS = -std=c++17 -g -O0 -Wall 
#-Wextra -Wconversion
INCLUDES = /usr/local/include/chunking/
TARGETS = sketch
LIBCHUNKING = /usr/local/lib/libchunking.dylib
LIBRHYLANG = /usr/local/lib/librhylang.dylib

sketch: $(OBJS)
	$(CC) $(OBJS) $(LIBRHYLANG) $(LIBCHUNKING) -o sketch

canon_3.o: canon_3.cpp
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $(@:.o=.cpp)

clean:
	rm -f $(TARGETS) $(OBJS)
