#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
        int c;
	float  probabilidares;
	
	if ((argc >= 2)) {
          fprintf(stderr, "No se aceptan argumentos");
          exit(1);
        }	
	
	while ((c=getc(stdin)) != EOF) {
	    if(c ==  '0' || c == '1' || c == '2'|| c == '3' || c == '4' || c == '5' ){
	        float numero = c - '0';
	        probabilidares = numero/5;
	        fprintf(stdout,"%.1f\n",probabilidares);
	        }
	    else if(c != '\n' && c != ' ')
	      fprintf(stderr, "Numero o letra incorrecto = %c \n",c);
	
	    fflush(stdout);
        }
}
