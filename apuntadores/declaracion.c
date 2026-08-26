#include <stdio.h>

int main() {
    int numero = 10;        // Variable normal entera
    int *apuntador = &numero; // Apuntador que guarda la dirección de 'numero'

    printf("Valor de numero: %d\n", numero);          // Muestra 10
    printf("Direccion de numero: %p\n", &numero);     // Muestra la dirección en memoria
    printf("Valor del apuntador: %p\n", apuntador);   // Muestra la misma dirección
    printf("Valor al que apunta: %d\n", *apuntador);  // Muestra 10 (desreferenciación)

    return 0;
}
