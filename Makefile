SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
CC = g++
CFLAGS=-Wall -pedantic 
LDFLAGS=
EXEC=main
EXECTEST=maintest

all : $(BINDIR)/$(EXEC) $(BINDIR)/$(EXECTEST)

main : $(BINDIR)/$(EXEC)

test : $(BINDIR)/$(EXECTEST)

$(BINDIR)/$(EXECTEST) : $(LIBDIR)/mainTest.o $(LIBDIR)/cube.o $(LIBDIR)/ecoAgent.o $(LIBDIR)/ecoAgentID.o $(LIBDIR)/etat.o  $(LIBDIR)/plateformeEcoResolution.o  $(LIBDIR)/plateformeMondeDesCubes.o  $(LIBDIR)/regle.o  $(LIBDIR)/singleton.o $(LIBDIR)/table.o $(LIBDIR)/reliesATable.o $(LIBDIR)/aucuneSurcharge.o $(LIBDIR)/plateformeEcoResolutionTest.o $(LIBDIR)/plateformeMondeDesCubesTest.o $(LIBDIR)/aucuneSurchargeTest.o $(LIBDIR)/cubeTest.o $(LIBDIR)/ecoAgentIDTest.o $(LIBDIR)/ecoAgentTest.o $(LIBDIR)/regleTest.o $(LIBDIR)/reliesATableTest.o $(LIBDIR)/singletonTest.o $(LIBDIR)/tableTest.o
	$(CC) $(LDFLAGS) -o $@ $^ -lcppunit

$(BINDIR)/$(EXEC) : $(LIBDIR)/main.o $(LIBDIR)/cube.o $(LIBDIR)/ecoAgent.o $(LIBDIR)/ecoAgentID.o $(LIBDIR)/etat.o  $(LIBDIR)/plateformeEcoResolution.o  $(LIBDIR)/plateformeMondeDesCubes.o  $(LIBDIR)/regle.o  $(LIBDIR)/singleton.o $(LIBDIR)/table.o $(LIBDIR)/reliesATable.o $(LIBDIR)/aucuneSurcharge.o
	$(CC) $(LDFLAGS) -o $@ $^ -lcppunit

$(LIBDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR) -lcppunit

clean :
	rm $(LIBDIR)/*
	rm $(BINDIR)/$(EXEC)
	rm $(BINDIR)/$(EXECTEST)
