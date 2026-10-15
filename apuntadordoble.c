/*
Sistema de control de una secuencia musical
Una aplicación de producción musical almacena en un arreglo las intensidades de una secuencia de golpes de batería. Durante la edición de una pista, el usuario necesita invertir el orden de las intensidades para generar una variación rítmica sin crear un segundo arreglo.
El sistema deberá manipular los datos mediante apuntadores y utilizar un apuntador a apuntador para acceder indirectamente a la secuencia.
Historia de usuario 1. Consultar la secuencia musical
Como productor musical, quiero visualizar las intensidades de los golpes de batería almacenadas en la secuencia, para conocer el orden original antes de realizar modificaciones.
Criterios de aceptación
El sistema debe almacenar las intensidades iniciales en un arreglo con los valores 30, 28, 25, 22, 20.
El programa debe recorrer el arreglo mediante apuntadores, sin utilizar índices.
El sistema debe mostrar las cinco intensidades en su orden original.
Historia de usuario 2. Invertir el orden de la secuencia
Como productor musical, quiero invertir el orden de las intensidades de los golpes de batería, para generar una variación de la secuencia sin duplicar los datos.
Criterios de aceptación
El sistema debe implementar una función que reciba un apuntador a apuntador de tipo int.
La función debe invertir el orden de las intensidades modificando el arreglo original.
El programa no debe utilizar un segundo arreglo ni memoria adicional para almacenar una copia de la secuencia.
La función debe recorrer y modificar los elementos mediante operaciones con apuntadores, sin utilizar la notación de índices [].
Al finalizar, las intensidades deben quedar en el orden 20, 22, 25, 28, 30.
Historia de usuario 3. Verificar la secuencia modificada
Como productor musical, quiero consultar la secuencia después de invertirla, para comprobar que la modificación se realizó correctamente.
Criterios de aceptación
El sistema debe mostrar la secuencia después de ejecutar la función de inversión.
El programa debe recorrer los datos mediante apuntadores.
La secuencia final debe contener los mismos cinco valores que la original, sin pérdidas ni duplicaciones.
El programa debe finalizar sin errores.
Restricciones técnicas
El programa debe desarrollarse en ANSI C.
Se deben utilizar apuntadores simples y dobles apuntadores.
No se permite el uso de variables globales.
La inversión debe realizarse sobre el arreglo original.
La función de inversión debe recibir un parámetro de tipo int **.
No se permite utilizar la notación de indexación [] dentro de la función de inversión.
Producto esperado: un programa de consola que permita visualizar la secuencia original, invertir sus intensidades y mostrar el resultado final.


*/

#include <stdio.h>
void invertirSecuencia(int **pp){
    int *actual = *pp;
    int *fin = *pp+5;
    int temp;
    while(actual<fin){
        temp = *actual;
        *actual = *fin;
        *fin = temp;
        actual++;
        fin--;
    }
}
int main()
{
    int arreglo[5] = {30,28,25,22,20};
    int *actual = NULL;
    int *fin = NULL;
    int **doblePtr = NULL;
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    printf("\nCon while\n");
    actual = arreglo;
    fin = arreglo+n;
    while(actual<fin){
        printf("%d ", *actual);
        actual++;
    }
    /*actual = arreglo;
    printf("\nCon for\n");
    for(int i = 0; i < n ; i++)
    {
        printf("%d ", *(actual + i));
    }*/
    doblePtr=&actual;
    actual=arreglo;
    invertirSecuencia(doblePtr);
    //actual = arreglo;
    printf("\nCon for invertido\n");
    n = sizeof(arreglo) / sizeof(arreglo[0]);
    for(int i = 0; i < n ; i++)
    {
        printf("%d ", *(actual + i));
    }
    return 0;
}
