# CHAPITRE 1 : BUT FINAL

but : projet

# CHAPITRE 2 : VARIABLES

OFILES = menu.o \
         jeux.o \
         jun.o \
         jdeux.o \
         affiche.o \
         main.o 

CC = gcc

CFLAGS = -Wall -pedantic -g

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

menu.o : menu.h 

jun.o : jun.h

jdeux.o : jdeux.h

jeux.o : jeux.h jun.h jdeux.h

affiche.o : affiche.h

main.o : menu.h jeux.h affiche.h

#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES

projet: $(OFILES)
	$(CC) $(CFLAGS) -o projet $(OFILES) -lgraph

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) projet

run :
	./projet

#CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean