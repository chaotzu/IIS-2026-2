#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char nombre[30];
    int edad;
    float promedio;
} Alumno;
Alumno *crear_alumno(const char *nombre, int edad, float promedio)
{
    Alumno *a;
    a = malloc(sizeof(Alumno));
    if (a == NULL) return NULL;
    strncpy(a->nombre, nombre, sizeof(a->nombre) - 1);
    a->nombre[sizeof(a->nombre) - 1] = '\0';
    a->edad = edad;
    a->promedio = promedio;
    return a;
}
void imprimir_alumno(const Alumno *a)
{
    printf("%s, %d anios, promedio %.1f\n", a->nombre, a->edad, a->promedio);
}
void destruir_alumno(Alumno *a)
{
    free(a);
}
int main(void)
{
    Alumno *a;
    a = crear_alumno("Rosa", 19, 9.2f);
    if (a == NULL) {
        printf("Sin memoria\n");
        return 1;
    }
    imprimir_alumno(a);
    destruir_alumno(a);
    return 0;
}

