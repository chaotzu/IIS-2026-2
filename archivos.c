#include <stdio.h>
int main(void)
{
    FILE *f;
    char linea[100];
 
    f = fopen("saludo.txt", "w");           /* 1. abrir para escribir */
    if (f == NULL) {                        /* 2. verificar */
        printf("No se pudo crear el archivo\n");
        return 1;
    }
    fprintf(f, "Hola archivo\n");           /* 3. usar */
    fclose(f);                              /* 4. cerrar */
    f = NULL;
 
    f = fopen("saludo.txt", "r");           /* ahora para leer */
    if (f == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }
    if (fgets(linea, sizeof(linea), f) != NULL) {
        printf("Leido: %s", linea);
    }
    fclose(f);
    f = NULL;
 
    return 0;
}
