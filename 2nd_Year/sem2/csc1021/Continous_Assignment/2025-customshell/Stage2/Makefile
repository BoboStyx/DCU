#Name: Oluwaseyi Favour Adu
#Student Number: 23378686
#I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.
#I have read and understood the DCU Academic Integrity and Plagiarism Policy. I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.

# Compiler
GCC = gcc
FLAGS = -Wall -Wextra -g

# Directories
START_DIR = ./src
END_DIR = ./bin

# C and header files
SRCS = $(START_DIR)/customshell.c $(START_DIR)/init.c $(START_DIR)/utility.c $(START_DIR)/execution.c
HEADERS = $(START_DIR)/customshell.h

# Output executable
TARGET = $(END_DIR)/customshell

# Default target
all: $(TARGET)

# Compile everything in one step
$(TARGET): $(SRCS) $(HEADERS)
	$(GCC) $(FLAGS) $(SRCS) -o $(TARGET)

# Clean compiled files
clean:
	rm -f $(TARGET)
