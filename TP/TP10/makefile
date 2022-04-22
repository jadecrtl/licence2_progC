#url du lien web pour faire des makefile : https://gl.developpez.com/tutoriel/outil/makefile/
COMPILATEUR=gcc
CFLAGS=-Wall 
EXEC=copy copy2

# $@ Le nom de la cible
# $< Le nom de la première dépendance
# $^ La liste des dépendances
# $? La liste des dépendances plus récentes que la cible
# $* Le nom du fichier sans suffixe

#Makefile permet également de créer des règles génériques (par exemple construire un .o à partir d'un .c) qui se verront appelées par défaut.
#Une telle règle se présente sous la forme suivante : 
#%.o: %.c
#	commandes

#cible: dependance
#	commandes

all : $(EXEC)

copy: copy.o
	$(COMPILATEUR) -o $@ $^

copy2: copy2.o
	$(COMPILATEUR) -o $@ $^

%.o: %.c
	$(COMPILATEUR) $(CFLAGS) -o $@ -c $< 

clean :
	rm -f *.o
	rm -f copy
	rm -f copy2	