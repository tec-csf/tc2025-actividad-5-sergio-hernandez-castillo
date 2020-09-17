/*
Autór: Sergio Hernandez Castillo
Matrícula: A01025210
Descripción: Actividad 5 - IPC

Nota: Trabajé junto con Daniel Roa en este ejercicio
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char * const * argv){
    int dato;
    int cantidadDeHijos = 0;
    char * cvalue = NULL;

    opterr = 0;

    while ((dato = getopt(argc, argv, "n:")) != -1){
        switch (dato){
            case 'n':
                cvalue = optarg;

                if (isdigit(*cvalue) > 0){
                    cantidadDeHijos = atoi(cvalue);
                    printf("Cantidad de hijos: %d\n\n", cantidadDeHijos);
                }

                else {
                    printf("No se proporcionó un valor numérico\n");
                }
            break;

            case '?':
                if (optopt == 'n'){
                    fprintf(stderr, "Opción -%c requiere un argumento.\n", optopt);
                }
                    
                else if (isprint (optopt)){
                    fprintf (stderr, "Opción desconocida '-%c'.\n", optopt);
                }
                    
                else {
                    fprintf (stderr, "Opción desconocida '\\x%x'.\n", optopt);
                }
            
                return 1;
            break;

            default:
                abort();
            break;
        }
    }

    if (cantidadDeHijos == 0){
        printf("No se pueden crear %d hijos\n", cantidadDeHijos);

        return 0;
    }

    return 0;
}