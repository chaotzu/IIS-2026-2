#include <stdio.h>

// Callbacks que el usuario registra
void al_avanzar(int porcentaje) {
    printf("Progreso: %d%%\n", porcentaje);
}
void al_terminar(void) {
    printf("Descarga completa.\n");
}
void descargar(void (*progreso)(int), void (*fin)(void)) {
    for (int p = 25; p <= 100; p += 25) {
        progreso(p);        // "avisa" cada vez que hay avance
    }
    fin();                  // "avisa" cuando termina
}
int main() {
    descargar(al_avanzar, al_terminar);
    return 0;
}
