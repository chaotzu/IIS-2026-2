
#include <stdio.h>
#include <stddef.h>  
typedef struct{
    char nombre[20];
    int ataque;
    int durabilidad;
}Arma;
typedef struct {
    char nombre[30];
    int vida;
    int vida_max;
    int ataque;
    int defensa;
    Arma *arma;
} Personaje;
int ataque_total(const Personaje *p);
void equipar(Personaje *p, Arma *a);
void mostrar(const Personaje *p) {
    if (p == NULL) {
        return;
    }
    if(p->arma == NULL)
        printf("%s  Vida: %d/%d  Atq: %d  Def: %d\n",
            p->nombre, p->vida, p->vida_max, p->ataque, p->defensa);
    else{
        printf("%s  Vida: %d/%d  Atq: %d  Def: %d Arma: %s\n",
           p->nombre, p->vida, p->vida_max, p->ataque, p->defensa, p->arma->nombre);
    }
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
    int atq = ataque_total(atacante);
    int dano = atq - defensor->defensa;
    if (dano < 1) dano = 1;
    recibir_dano(defensor, dano);
    printf("%s golpea a %s por %d de daño.\n",
    atacante->nombre, defensor->nombre, dano);
    // Reducir la durabilidad del arma si tiene una equipada y activa
    if (atacante->arma != NULL && atacante->arma->durabilidad > 0) {
        atacante->arma->durabilidad--;
        if (atacante->arma->durabilidad == 0) {
            printf("¡El arma %s de %s se ha roto!\n",
            atacante->arma->nombre, atacante->nombre);
        }
    }
    return dano;
}
/*int atacar(Personaje *atacante, Personaje *defensor) {
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
}*/
int ataque_total(const Personaje *p) {
    if (p->arma != NULL && p->arma->durabilidad > 0) {
        return p->ataque + p->arma->ataque;
    }
    return p->ataque;
}
void equipar(Personaje *p, Arma *a){
    p->arma = a;
}
int main(void) {
    Arma armeria[3]={{"Espada", 50, 50},{"Hacha", 50, 50},{"Daga", 50, 50}};
    Arma *ptr = armeria;
    Personaje heroe = {"Aria", 100, 100, 18, 5, NULL};
    Personaje *p = &heroe;
    equipar(&heroe, &armeria[1]);
    printf("Armas disponibles\n");
    for(int i = 0; i<=2 ; i++){
        printf("%d.- %s\n", i+1, ptr->nombre);
        ptr++;
    }
    printf("%d\n", heroe.vida);   /* con punto */
    printf("%d\n", (*p).vida);    /* desreferenciando */
    printf("%d\n", p->vida);      /* con flecha */
    printf("%p %p\n", (void *)p, (void *)&heroe);
    mostrar(&heroe);
    Personaje prueba = {"Orco", 50, 50, 1, 0, NULL};

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

    Personaje aria = {"Aria", 100, 100, 18, 5, NULL};
    Personaje kakaroto = {"Kakaroto", 120, 120, 12, 3, NULL};

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
