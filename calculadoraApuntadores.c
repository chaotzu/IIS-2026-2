#include <stdio.h>
void suma(int *x, int *y){
    printf("La suma es %d\n", (*x)+(*y));
}
void resta(int *x, int *y){
    printf("La resta es %d\n", (*x)-(*y));
}
void multiplicacion(int *x, int *y){
    printf("La multiplicacion es %d\n", (*x)*(*y));
}
void division(int *x, int *y){
    if((*y)!=0) printf("La division es %d\n", (*x)/(*y));
    else{
        printf("El dividendo no puede ser cero");
    }
}
void calcular(int *x, int *y, void (*ptrFuncion)(int *, int *)){
    ptrFuncion(x,y);
}

int main() {
    int a=5;
    int b=1;
    int *ptr = &a;
    int *ptr1 = &b;
    calcular(ptr, ptr1, suma);
     calcular(ptr, ptr1, resta);
/*    suma(ptr, ptr1);
    resta(ptr, ptr1);
    multiplicacion(ptr, ptr1);
    division(ptr, ptr1);*/
    return 0;
}
