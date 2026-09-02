#include <stdio.h>

int main(){
    int filas, columnas, lugaresOcupados=0, espaciosLibres=0;
    int coordenadaX=0, coordenadaY=0, libreEncontrado=0, filaLibreEncontrada = 0;
    int espaciosFilaConMasEspacios=0, filaMasEspacios=0;
    float porcetajeOcupacion;
    printf("Ingresa el # de filas\n");
    scanf("%d", &filas);
    printf("Ingresa el # de columnas\n");
    scanf("%d", &columnas);
    for( int i = 0; i<= filas-1; i++){
        printf("\n");
        for(int j=0;j<=columnas-1;j++){
            printf("0 |");
        }
    }
    int lugaresEstacionamiento[filas][columnas];
    filas--;
    columnas--;
    printf("Ingresa estado actual del estacionamiento 1 = ocupado  0 = libre\n");
    for( int i = 0; i<= filas; i++){
        for(int j=0;j<=columnas;j++){
            printf("Lugar %d, %d", i, j);
            scanf("%d", &lugaresEstacionamiento[i][j]);
        }
    }
    printf("Estado actual\n");
    for( int i = 0; i<= filas; i++){
        printf("\n");
        for(int j=0;j<=columnas;j++){
            printf("%d |", lugaresEstacionamiento[i][j]);
        }
    }
    for( int i = 0; i<= filas; i++){
        for(int j=0;j<=columnas;j++){
            if(lugaresEstacionamiento[i][j]==1){
                lugaresOcupados++;
            }
            if(lugaresEstacionamiento[i][j]==0 &&libreEncontrado==0){
                coordenadaX=i;
                coordenadaY=j;
                libreEncontrado=1;
            }
        }
    }
    printf("%f = (%d/(%d * %d)*100)", porcetajeOcupacion, lugaresOcupados, filas + 1, columnas+1);
    porcetajeOcupacion = (float)(lugaresOcupados/((filas +1) * (columnas +1))) * 100;
    porcetajeOcupacion = (6/(3)*(3)) * 100;
    for( int i = 0; i<= filas; i++){
        for(int j=0;j<=columnas;j++){
           if(lugaresEstacionamiento[i][j]==0){
                espaciosLibres++;
           }
        }
        //printf("%d - %d", espaciosLibres, espaciosFilaConMasEspacios);
        if(espaciosFilaConMasEspacios<espaciosLibres){
            espaciosFilaConMasEspacios = espaciosLibres;
            filaMasEspacios = i;
            printf("%d", filaMasEspacios);
        }
    }
    printf("porcentaje de ocupacion = %f\n", porcetajeOcupacion);
    printf("Primer espacio libre fila %d - columna %d\n", coordenadaX, coordenadaY);
    printf("Fila con mas espacios libres = %d\n", filaMasEspacios);
}
