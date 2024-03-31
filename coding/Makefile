# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRC_MAIN = main.c
SRC_MENU = menu.c
SRC_BILLING = billing.c

# Object files
OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJ_MENU = $(SRC_MENU:.c=.o)
OBJ_BILLING = $(SRC_BILLING:.c=.o)

# Header files
HEADERS = menu.h billing.h

# Executable name
TARGET = myprogram

# Phony targets
.PHONY: all clean

# Default target
all: $(TARGET)

# Compile main object file
$(OBJ_MAIN): $(SRC_MAIN) $(HEADERS)
    $(CC) $(CFLAGS) -c $(SRC_MAIN) -o $(OBJ_MAIN)

# Compile menu object file
$(OBJ_MENU): $(SRC_MENU) $(HEADERS)
    $(CC) $(CFLAGS) -c $(SRC_MENU) -o $(OBJ_MENU)

# Compile billing object file
$(OBJ_BILLING): $(SRC_BILLING) $(HEADERS)
    $(CC) $(CFLAGS) -c $(SRC_BILLING) -o $(OBJ_BILLING)

# Link object files into executable
$(TARGET): $(OBJ_MAIN) $(OBJ_MENU) $(OBJ_BILLING)
    $(CC) $(OBJ_MAIN) $(OBJ_MENU) $(OBJ_BILLING) -o $(TARGET)

# Clean up object files and executable
clean:
    rm -f $(OBJ_MAIN) $(OBJ_MENU) $(OBJ_BILLING) $(TARGET)
