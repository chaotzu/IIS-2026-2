#include <stdio.h>
 
int main(void)
{
    FILE *f;
    int n;
    int cuad;
    double mitad;
    char encabezado[100];
 
    f = fopen("tabla.txt", "r");
    if (f == NULL) {
        printf("No existe tabla.txt\n");
        return 1;
    }
 
    fgets(encabezado, sizeof(encabezado), f);   /* saltar la primera linea */
 
    while (fscanf(f, "%d %d %lf", &n, &cuad, &mitad) == 3) {
        printf("n=%d cuadrado=%d mitad=%.2f\n", n, cuad, mitad);
    }
 
    fclose(f);
    return 0;
}
