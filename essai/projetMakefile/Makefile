COMPILATEUR=gcc
CFLAGS=-W -Wall -ansi -pedantic

# $@ Le nom de la cible
# $< Le nom de la première dépendance
# $^ La liste des dépendances
# $? La liste des dépendances plus récentes que la cible
# $* Le nom du fichier sans suffixe


all: hello

hello: hello.o main.o
	$(COMPILATEUR) -o $@ $^

hello.o: hello.c
	$(COMPILATEUR) -o $@ -c $^ $(CFLAGS)

main.o: main.c hello.h
	$(COMPILATEUR) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf hello	

integral: mrproper all