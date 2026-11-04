
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int *datos = NULL;
    int *tmp;
    size_t cantidad = 0;
    size_t capacidad = 0;
    size_t i;
    int valor;
 
    printf("Escribe enteros (0 para terminar):\n");
    while (scanf("%d", &valor) == 1 && valor != 0) {
 
        if (cantidad == capacidad) {
            size_t nueva = (capacidad == 0) ? 4 : capacidad * 2;
 
            tmp = realloc(datos, nueva * sizeof(int));
            if (tmp == NULL) {
                printf("Sin memoria\n");
                free(datos);
                return 1;
            }
            datos = tmp;
            capacidad = nueva;
        }
 
        datos[cantidad] = valor;
        cantidad++;
    }
 
    printf("Leidos %lu valores (capacidad %lu)\n",
           (unsigned long)cantidad, (unsigned long)capacidad);
    for (i = 0; i < cantidad; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");
 
    free(datos);
    return 0;
}
