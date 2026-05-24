
CC = gcc

CFLAGS = -Wall -Wextra -std=c99

LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt

TARGET = build/main

SRC = *.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
