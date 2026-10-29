#include <stdio.h>
#include <stdlib.h>

void invertirArreglo(int *x, int n);

int main(void)
{
    int *datos;
    int n;
    int i;
    long suma;
    printf("Cuantos numeros? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Cantidad invalida\n");
        return 1;
    }
    //datos = malloc(n * sizeof(int));
    datos = calloc(n, sizeof(int));
    if (datos == NULL) {
        printf("Sin memoria\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Ingresa el valor %d\n", i+1);
        scanf("%d", &datos[i]);
    }
    invertirArreglo(datos, n);
    for (i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    free(datos);
    datos = NULL;
    return 0;
}

void invertirArreglo(int *x, int n) {
    int j = n - 1;
    for (int i = 0; i < j; i++) {
        int temp = x[i];
        x[i] = x[j];
        x[j] = temp;
        j--;
    }
}
