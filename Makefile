# Adjustable config variables
# ---------------------------
# Main source and header file (creates binary of same name)
PROJECT:=all-in-c
# C Compiler
CC:=gcc
# Source file directory
SRCDIR:=./src

# **NOTE: THESE DIRECTORIES ARE AUTOMATICALLY GENERATED **DO NOT ALTER OR ADD CONTENTS**
#		  BOTH GET **PERMANENTLY** DELETED ON `$ make clean`
# Object file directory (object files built here)
OBJDIR:=./obj
# Compiled binary directory (binary built here)
BINDIR:=./bin
# ---------------------------


BIN:=$(BINDIR)/$(PROJECT)

# Find all source sources file paths and generate corrosponding object paths
SRCS:=$(wildcard $(SRCDIR)/*.c)
OBJS:=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

TARGET=
MEMBERS=
CFLAGS=

# Default target on `$ make`
default: build

# Validate header file and build binary 
build: $(BIN)

# Permanently remove build directories and their contents
clean:
	rm -r $(OBJDIR) $(BINDIR)

# Create binary by compiling main source and linking with other object files
$(BIN): $(PROJECT).c $(PROJECT).h $(OBJS)
	$(CC) -o $@ $^

# Create object files if they do not exist or if their source has been altered
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $^

# Make build directories if they do not exist
$(OBJS): | $(OBJDIR)
$(BIN): | $(BINDIR)
$(OBJDIR) $(BINDIR):
	mkdir $@