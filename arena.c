
#include <stdio.h>
#include <stddef.h>  
typedef struct {
    char nombre[30];
    int vida;
    int vida_max;
    int ataque;
    int defensa;
} Personaje;
void mostrar(const Personaje *p) {
    if (p == NULL) {
        return;
    }
    printf("%s  Vida: %d/%d  Atq: %d  Def: %d\n",
           p->nombre, p->vida, p->vida_max, p->ataque, p->defensa);
}
int limitar(int valor, int minimo, int maximo) {
    if (valor < minimo) return minimo;
    if (valor > maximo) return maximo;
    return valor;
}
void recibir_dano(Personaje *p, int dano) {
    if (p == NULL) {
        return;
    }
    p->vida = limitar(p->vida - dano, 0, p->vida_max);
}

void curar(Personaje *p, int cantidad) {
    if (p == NULL) {
        return;
    }
    p->vida = limitar(p->vida + cantidad, 0, p->vida_max);
}
int esta_vivo(const Personaje *p) {
    if (p == NULL) {
        return 0;
    }
    return p->vida > 0;
}
int atacar(Personaje *atacante, Personaje *defensor) {
    if (atacante == NULL || defensor == NULL || atacante == defensor) {
        return 0;
    }

    int dano = atacante->ataque - defensor->defensa;
    if (dano < 1) {
        dano = 1;
    }

    recibir_dano(defensor, dano);
    printf("%s golpea a %s por %d de dano.\n",
           atacante->nombre, defensor->nombre, dano);
    return dano;
}
int main(void) {
    Personaje heroe = {"Aria", 100, 100, 18, 5};
    Personaje *p = &heroe;

    printf("%d\n", heroe.vida);   /* con punto */
    printf("%d\n", (*p).vida);    /* desreferenciando */
    printf("%d\n", p->vida);      /* con flecha */
    printf("%p %p\n", (void *)p, (void *)&heroe);
    mostrar(&heroe);
    Personaje prueba = {"Orco", 50, 50, 1, 0};

    recibir_dano(&prueba, 30);    /* ya no hay que reasignar */
    mostrar(&prueba);

    for (int i = 0; i < 20; i++) {
        curar(&prueba, 10);
    }
    printf("Despues de curar 20 veces: ");
    mostrar(&prueba);             /* nunca pasa de vida_max */

    for (int i = 0; i < 20; i++) {
        recibir_dano(&prueba, 10);
    }
    printf("Despues de recibir dano 20 veces: ");
    mostrar(&prueba);             /* nunca baja de 0 */
    printf("Orco esta vivo? %d\n", esta_vivo(&prueba));

    Personaje aria = {"Aria", 100, 100, 18, 5};
    Personaje kakaroto = {"Kakaroto", 120, 120, 12, 3};

    printf("atacar(&aria, &aria) devuelve %d\n", atacar(&aria, &aria));
    printf("atacar(NULL, &orco) devuelve %d\n", atacar(NULL, &kakaroto));
    printf("atacar(&aria, NULL) devuelve %d\n\n", atacar(&aria, NULL));

    Personaje *turno = &aria;
    Personaje *otro  = &kakaroto;

    while (esta_vivo(turno) && esta_vivo(otro)) {
        atacar(turno, otro);

        Personaje *tmp = turno;   /* intercambio de apuntadores */
        turno = otro;
        otro  = tmp;
    }

    const Personaje *ganador = esta_vivo(turno) ? turno : otro;
    printf("\n%s gana el combate\n", ganador->nombre);
    mostrar(&aria);
    mostrar(&kakaroto);

    return 0;
}
