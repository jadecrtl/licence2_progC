#include <stdio.h>

int main() {
    char a[100];//taille maximale de la sequence ordonnee de char dans un tableau de 100 char

    gets(a);//lit l'entree sous la forme d'une sequence ordonnee de char, egalement appelee string

    printf("You entered: %s", a);

    //au lieu d'utiliser gets() on peut utiliser
    //char* fgets(char *string, int length, FILE * stream);
    
    //exemple de code qui utilise fgets
    /*
    #include <errno.h>
    #include <stdio.h>
    #include <stdlib.h>

    #define MAX_LENGTH 10

    int main( int argc, char * argv[] ) {
    
        argc--;   argv++;
    
        if ( argc == 0 ) {
            printf( "Usage: sample filename\n" );
            exit( 0 );
        }
    
        FILE * inputFile = fopen( argv[0], "r" );
        if ( inputFile == NULL ) {
            printf( "Cannot open file %s\n", argv[0] );
            exit( -1 );
        }
    
        char * buffer = (char *) malloc( MAX_LENGTH );
        while ( ! feof( inputFile ) ) {
            fgets( buffer, MAX_LENGTH, inputFile );
            if ( ferror( inputFile ) ) {
                fprintf( stderr, "Reading error with code %d\n", errno );
                break;
            }
        
            puts( buffer );        
        }

        free( buffer );
        fclose( inputFile );
        
        return 0;
    }    
    */
    
    return 0;
}