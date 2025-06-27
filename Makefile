# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2 `sdl2-config --cflags`

# File paths
SRC = $(wildcard src/*.c)
BIN = bin/app

# Default build
all: $(BIN)

# Build rule
$(BIN): $(SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Clean build artifacts
clean:
	rm -rf build

.PHONY: all clean
