CC=gcc
CFLAGS= -g -Wall
OBJS = lab01.o main.o
DEPS = lab01.h
TARGET = lab01

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm -f $(OBJS) $(TARGET)

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS)


