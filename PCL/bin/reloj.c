// Reloj_2.c
// Cuenta unidades de tiempo
// Es especifico para Linux
///////////////////////////////////////////////////
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
int main (int argc, char * argv[]) {
    struct timeval inicio, fin;
    long tiempo_total;
    int i;
    gettimeofday(&inicio, NULL);
    if (argc != 2) {
        printf("Uso: %s unidad de tiempo\n", argv[0]);
        exit(1);
    }
    for (i=1; i<=10; i++) {
        sleep (atoi(argv[1]));
        printf("%d\n", i);
    }
    gettimeofday(&fin, NULL);
    tiempo_total = (fin.tv_sec - inicio.tv_sec) * 1000000L + (fin.tv_usec - inicio.tv_usec);
    printf("Tiempo transcurrido: %ld microsegundos\n", tiempo_total);
return 0;
}
