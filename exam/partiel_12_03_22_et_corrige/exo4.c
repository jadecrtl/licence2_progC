#include <stdio.h>

enum color { BLUE, RED, YELLOW, GREEN };
struct article{
unsigned int id;
  enum color c;
  unsigned int poids;
};

int main(void){
  struct article a = { .poids=54, .id=12, .c = YELLOW };
  struct article tab[]= {  { .poids=11, .id=12, .c = BLUE },
			   { .poids=22, .id=23, .c = RED } };
}
  


  
  
  
    
