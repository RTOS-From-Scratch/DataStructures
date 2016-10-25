# CC=arm-none-eabi-gcc
TARGET = linkedlist
DEPS = linkedlist.h
CC = gcc
CFLAGS = -Wall -g -c
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

valg: all
	valgrind --leak-check=full ./$(TARGET)

run: all
	./$(TARGET)
    
clean:
	rm *.o $(TARGET)