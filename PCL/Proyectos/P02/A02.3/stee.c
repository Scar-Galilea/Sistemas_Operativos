// stee.c
// Similar a tee (1). Version con llamadas al sistema
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

#define TAMANO_BUFFER 1

int main(int argc, char* argv[])
{
    int n;
    char buf[TAMANO_BUFFER];
    int fd;
    struct timeval inicio, fin;
    double tiempo_total;
    
    gettimeofday(&inicio, NULL);
    if (argc != 2) {
        fprintf(stderr, "Uso: %s fichero_salida\n", argv[0]);
        exit(1);
    }

    if ((fd= open(argv[1], O_WRONLY|O_CREAT, 0660)) < 0) {
        fprintf(stderr, "No se puede abrir para escritura %s\n", argv[1]);
        exit(2);
    }
    while ((n= read(0, buf, TAMANO_BUFFER)) > 0) {
       write(1, buf, 1);
       write(fd, buf, 1);
    }
    gettimeofday(&fin, NULL);
    tiempo_total = (double)(fin.tv_sec - inicio.tv_sec) + 
                   (double)(fin.tv_usec - inicio.tv_usec) / 1000000.0;
    printf("\nTiempo transcurrido en segundos: %.10f",tiempo_total);
    fprintf(stdout,"\n%s",argv[1]);
}
