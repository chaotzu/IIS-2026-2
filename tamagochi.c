#include <stdio.h>
typedef enum { FELIZ, TRISTE, ENOJADA, ENFERMA, DORMIDA, MUERTA } Animo;
typedef struct{
     int hambreComida;
     int energia;
     int felicidad;
     int salud;
 } Estadistica;
typedef struct {
    char nombre[30];
    int edad; // en días
    int hambre; // 0 = lleno, 100 = famélico
    Estadistica stats;
    Animo a;
} Mascota;
Mascota alimentar(Mascota m);
Mascota jugar(Mascota m);
Mascota crear_mascota(void);
void mostrar_mascota(Mascota g);
Mascota dormir(Mascota m);
Mascota alimentar2(Mascota m);
int limitar(int valor, int minimo, int maximo);
Animo calcular_animo(Estadistica s);
int main(void) {
    Mascota tobi = crear_mascota();
    tobi = jugar(tobi);
    tobi = dormir(tobi);
    tobi = alimentar2(tobi);
    tobi.a = calcular_animo(tobi.stats);
    //tobi = alimentar(tobi); // hay que reasignar
    mostrar_mascota(tobi);
    return 0;
}
Mascota alimentar(Mascota m) {
    m.hambre = m.hambre - 20;
    return m;
}
Mascota alimentar2(Mascota m){
    limitar(m.stats.hambreComida -= 20, 0, 100);
    limitar(m.stats.energia += 5, 0, 100);
    limitar(m.stats.felicidad += 5, 0, 100);
    return m;
}
Mascota jugar(Mascota m){
    limitar(m.stats.hambreComida += 10, 0, 100);
    limitar(m.stats.energia -= 15, 0, 100);
    limitar(m.stats.felicidad += 20, 0, 100);
    return m;
}
Mascota dormir(Mascota m){
    limitar(m.stats.hambreComida += 15, 0, 100);
    limitar(m.stats.energia += 40, 0, 100);
    return m;
}
Mascota crear_mascota(void){
    Mascota x;
    printf("Ingresa el nombre\n");
    scanf("%s", x.nombre);
    printf("Ingresa la edad\n");
    scanf("%d", &x.edad);
    printf("Ingresa cuanta hambre en la vida tiene 0-100\n");
    scanf("%d", &x.hambre);
    x.stats.hambreComida = 100;
    x.stats.energia = 50;
    x.stats.felicidad = 0;
    x.stats.salud = 100;
    return x;
}
void mostrar_mascota(Mascota g){
    printf("Nombre: %s\n", g.nombre);
    printf("Edad: %d dias\n", g.edad);
    printf("Hambre de vida: %d\n", g.hambre);
    printf("Hambre comida: %d\n", g.stats.hambreComida);
    printf("Felicidad: %d\n", g.stats.felicidad);
    printf("Salud: %d\n", g.stats.salud);
    printf("Energia: %d\n", g.stats.energia);
    switch(g.a){
        case FELIZ:
            printf("Tu mascota esta contenta :)\n");
        break;
        case TRISTE:
            printf("Tu mascota ta tite :(\n");
        break;
        case ENOJADA:
            printf("Tu mascota te mira feo\n");
        break;
        case ENFERMA:
            printf("Tengo moquillo\n");
        break;
        default:
            printf("Caso default");
    }
}
int limitar(int valor, int minimo, int maximo) {
    if (valor < minimo) return minimo;
    if (valor > maximo) return maximo;
    return valor;
}
Animo calcular_animo(Estadistica s) {
    if (s.salud <= 0) return MUERTA;
    if (s.salud < 20) return ENFERMA;
    if (s.hambreComida > 80) return ENOJADA;
    if (s.energia < 20) return DORMIDA;
    if (s.felicidad < 30) return TRISTE;
    return FELIZ;
}
