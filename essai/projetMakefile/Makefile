#url du lien web pour faire des makefile : https://gl.developpez.com/tutoriel/outil/makefile/
COMPILATEUR=gcc
CFLAGS=-W -Wall -ansi -pedantic

# $@ Le nom de la cible
# $< Le nom de la première dépendance
# $^ La liste des dépendances
# $? La liste des dépendances plus récentes que la cible
# $* Le nom du fichier sans suffixe

#Makefile permet également de créer des règles génériques (par exemple construire un .o à partir d'un .c) qui se verront appelées par défaut.
#Une telle règle se présente sous la forme suivante : 
#%.o: %.c
#	commandes

all: hello

hello: hello.o main.o
	$(COMPILATEUR) -o $@ $^

hello.o: hello.c
	$(COMPILATEUR) -o $@ -c $^ $(CFLAGS)

main.o: hello.h

%.o: %.c
	$(COMPILATEUR) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf hello	

integral: mrproper all