# Compiler and compiler flags
CC := gcc
CFLAGS := -Wall -Wextra -Iinclude -lm -O3
LDFLAGS := -lm

DEBUGFLAGS := -g

# Source and object file directories
SRCDIR := src
OBJDIR := obj

# List of source files
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Output binary
TARGET := $(notdir $(CURDIR))

# Default target
all: $(TARGET)

# Compile source files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Build with debug flag for gdb
debug: CFLAGS += $(DEBUGFLAGS)
debug: clean $(TARGET)

# Clean build artifacts
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean debug
