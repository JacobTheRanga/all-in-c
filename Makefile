CC := gcc
SRCDIR := src
OBJDIR := obj
BINDIR := bin
PROJECT := all-in-c

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
BIN := $(BINDIR)/$(PROJECT)

TARGET =
MEMBERS =
CFLAGS =

all: $(PROJECT).h $(BIN)

clean:
	rm -r $(OBJDIR)/ $(BINDIR)/

$(BIN): $(PROJECT).c $(OBJS)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $^

$(OBJS): | $(OBJDIR)
$(BIN): | $(BINDIR)

$(OBJDIR) $(BINDIR):
	mkdir $@