SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
CC = g++
CFLAGS=-Wall -pedantic
LDFLAGS=
EXEC=main

all : $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC) : $(LIBDIR)/main.o $(LIBDIR)/cube.o $(LIBDIR)/ecoAgent.o $(LIBDIR)/ecoAgentID.o $(LIBDIR)/etat.o  $(LIBDIR)/plateformeEcoResolution.o  $(LIBDIR)/plateformeMondeDesCubes.o  $(LIBDIR)/regle.o  $(LIBDIR)/singleton.o $(LIBDIR)/table.o $(LIBDIR)/reliesATable.o $(LIBDIR)/aucuneSurcharge.o
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR)

clean :
	rm $(LIBDIR)/*
	rm $(BINDIR)/$(EXEC)
