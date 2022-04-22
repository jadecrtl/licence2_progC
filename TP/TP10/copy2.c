#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    FILE *fic1 = fopen(argv[1], "r");
    if (fic1 != NULL) {
        printf("ouvert en lecture\n");
    }
    else {
        printf("impossible d'ouvrir en lecture\n");
        exit(1);
    }
    FILE *fic2 = fopen(argv[2], "w");
    if (fic2 != NULL) {
        printf("ouvert en écriture\n");
    }
    else {        
        printf("impossible d'ouvrir en écriture\n");
        exit(1);
    }
    /*ALGO
    fseek qui se met à la fin du fichier
    ftell qui donne le numéro du dernier octet du fichier (par ex 1000)
    je crée une chaine de caractère qui est de la taille de ftell + 1 (pour \0)
    fread qui va lire tout le fic1 et va mettre chaque élément dans la chaine de charactère
    fwrite qui va mettre chaque caractère de la chaine en indiquant la taille du fichier dans fic2 

    */
    fseek(fic1, 0, SEEK_END);
    int taille = ftell(fic1);
    char *tmp = malloc(sizeof(char) * taille + 1 );
    if (tmp == NULL) {
        perror("failed du malloc de tmp");
        exit(1);
    }
    tmp[taille] = '\0';
    rewind(fic1);
    fread(tmp, sizeof(char), taille, fic1);
    fwrite(tmp, sizeof(char), taille, fic2);
    free(tmp);
    fclose(fic1);
    fclose(fic2);
    return 0;
}