CC = g++
CFLAGS = -Wall -g
EXECUTABLE = f
INSTALL_DIR = ~/lab 

all: $(EXECUTABLE)

$(EXECUTABLE): lab2.cpp Threads.cpp Threads.h
	$(CC) $(CFLAGS) lab2.cpp Threads.cpp -o $(EXECUTABLE)

install: $(EXECUTABLE)
	mkdir -p $(INSTALL_DIR)
	cp $(EXECUTABLE) $(INSTALL_DIR)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all install clean
