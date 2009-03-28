SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
CC = g++
CFLAGS=-Wall -pedantic
LDFLAGS=
EXEC=main

all : $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC) : $(LIBDIR)/main.o  
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR)

clean :
	rm $(LIBDIR)/*
	rm $(BINDIR)/$(EXEC)
