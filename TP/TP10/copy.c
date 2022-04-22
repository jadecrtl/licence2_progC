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
    int c;
    while( ( c = fgetc(fic1) ) != EOF ){
        if( fputc(c,fic2) == EOF ){
            printf("Vous n'avez très certainement pas les droits d'écriture sur le fichier!!\n");
            break;
        }
    }    
    fclose(fic1);
    fclose(fic2);
    return 0;
}