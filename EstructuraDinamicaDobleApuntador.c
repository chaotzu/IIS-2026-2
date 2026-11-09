//Arreglar para que no crezca de uno en uno
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Vector;

Vector* crearVector(int x, int y);
Vector* suma(Vector *uno, Vector *dos);

int main()
{
    char respuesta = 's';
    int x, y;
    int total = 0;
    
    Vector **lista = NULL; 

    printf("¿Quieres crear un vector? (s/n): ");
    scanf(" %c", &respuesta);

    while (respuesta == 's' || respuesta == 'S') {
        printf("\nVector %d\n", total + 1);
        printf("Dame el valor de x: ");
        scanf("%d", &x);
        printf("Dame el valor de y: ");
        scanf("%d", &y);

        Vector **temp = realloc(lista, (total + 1) * sizeof(Vector*));
        if (temp == NULL) {
            printf("Error al asignar memoria.\n");
            for (int i = 0; i < total; i++) free(lista[i]);
            free(lista);
            return 1;
        }
        lista = temp;

        lista[total] = crearVector(x, y);
        if (lista[total] == NULL) return 1;
        total++;

        printf("\n¿Quieres agregar otro vector? (s/n): ");
        scanf(" %c", &respuesta);
    }

    printf("\nVectores (%d)\n", total);
    for (int i = 0; i < total; i++) {
        printf("Vector %d: (%d, %d)\n", i + 1, lista[i]->x, lista[i]->y);
    }

    if (total >= 2) {
        Vector *resultante = suma(lista[0], lista[1]);
        if (resultante != NULL) {
            printf("\nSuma de Vector 1 y Vector 2: (%d, %d)\n", resultante->x, resultante->y);
            free(resultante);
        }
    }

    for (int i = 0; i < total; i++) {
        free(lista[i]);
    }
    free(lista);

    return 0;
}

Vector* crearVector(int x, int y) {
    Vector *ap = malloc(sizeof(Vector));
    if (ap == NULL) return NULL;
    ap->x = x;
    ap->y = y;
    return ap;
}

Vector* suma(Vector *uno, Vector *dos) {
    if (uno == NULL || dos == NULL) return NULL;
    return crearVector(uno->x + dos->x, uno->y + dos->y);
}
