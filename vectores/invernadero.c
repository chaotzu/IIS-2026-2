#include <stdio.h>

int main(){
    float temperaturas[24];
    float temperaturaMaxima, temperaturaMinima, temperaturaLimite, promedio=0;
    int numSupTemp=0; //nuimero de veces que se supera la temperatura limite
    printf("Mi invernadero\n Control de temperaturas durante un dia\n");
    printf("Ingresa la temperatura limite que no deberia superar el invernadero\n");
    scanf("%f", &temperaturaLimite);
    for(int i = 0; i<=23 ; i++){
        printf("Ingresa la temperastura de las %d:00: \n", i);
        scanf("%f", &temperaturas[i]);
    }
    temperaturaMaxima = temperaturas[0];
    temperaturaMinima = temperaturas[0];
    for(int i = 0; i<=23 ; i++){
        promedio = promedio + temperaturas[i];
        if(temperaturaMaxima < temperaturas[i]){
            temperaturaMaxima = temperaturas[i];
        }
        if(temperaturaMinima > temperaturas[i]){
            temperaturaMinima = temperaturas[i];
        }
        if(temperaturas[i]>temperaturaLimite){//x
            numSupTemp++;
        }
    }
    promedio = promedio / 24;
    printf("La temperatura maxima fue %f, la minima %f  \n", temperaturaMaxima, temperaturaMinima);
    printf("El npromedio de temp es %f y la temp limite se supero %d veces", promedio, numSupTemp);
}