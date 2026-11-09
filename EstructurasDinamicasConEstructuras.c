#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Vector;

typedef struct {
    Vector *elementos; 
    int tamano;        
    int capacidad;     
} ArregloVectores;

ArregloVectores* crearArreglo(int capacidadInicial) {
    ArregloVectores *arr = malloc(sizeof(ArregloVectores));
    if (arr == NULL) return NULL;

    arr->elementos = malloc(capacidadInicial * sizeof(Vector));
    if (arr->elementos == NULL) {
        free(arr);
        return NULL;
    }

    arr->tamano = 0;
    arr->capacidad = capacidadInicial;
    return arr;
}

int agregarVector(ArregloVectores *arr, int x, int y) {
    if (arr->tamano == arr->capacidad) {
        int nuevaCapacidad = arr->capacidad * 2;
        Vector *nuevoBloque = realloc(arr->elementos, nuevaCapacidad * sizeof(Vector));
        if (nuevoBloque == NULL) return 0; // Error al reasignar memoria

        arr->elementos = nuevoBloque;
        arr->capacidad = nuevaCapacidad;
    }

    arr->elementos[arr->tamano].x = x;
    arr->elementos[arr->tamano].y = y;
    arr->tamano++;
    return 1;
}

void destruirArreglo(ArregloVectores *arr) {
    if (arr != NULL) {
        free(arr->elementos);
        free(arr);
    }
}

int main() {
    ArregloVectores *misVectores = crearArreglo(2); 

    agregarVector(misVectores, 1, 2);
    agregarVector(misVectores, 3, 4);
    agregarVector(misVectores, 5, 6); // realloc

    printf("Elementos en el arreglo (Capacidad: %d):\n", misVectores->capacidad);
    for (int i = 0; i < misVectores->tamano; i++) {
        printf("Vector %d: (%d, %d)\n", i, misVectores->elementos[i].x, misVectores->elementos[i].y);
    }

    destruirArreglo(misVectores);
    return 0;
}
