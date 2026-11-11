#include <stdio.h>
 
int main(void)
{
    FILE *f;
    int i;
    double mitad;
 
    f = fopen("tabla.txt", "w");
    if (f == NULL) return 1;
 
    fputs("n cuadrado mitad\n", f);        /* una cadena; el salto va en el texto */
    for (i = 1; i <= 5; i++) {
        mitad = i / 2.0;
        fprintf(f, "%d %d %.2f\n", i, i * i, mitad);
    }
    fputc('#', f);                          /* un solo caracter: marca de fin */
    fputc('\n', f);
 
    fclose(f);
    return 0;
}
