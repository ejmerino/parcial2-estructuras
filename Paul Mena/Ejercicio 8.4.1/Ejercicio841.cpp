/* Universidad de Las Fuerzas Armadas - ESPE
* Ejercicio 8.4.1 - Desarrolla un programa que permita ingresar y ordenar la siguiente numeración 
33,45,67,8,12,32,56,7,9,10,22,45,98,9. De forma ascendente y descendente, usando el método de Quicksort
*Nombres: Paúl Mena, Josué Merino, Daniel Vizcarra
* Fecha de creación: 26/12/2021
* Fecha de modificación: 26/12/2021
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>


int Comparacion1(const void* a, const void* b) {
    int aInt = *(int*)a;
    int bInt = *(int*)b;
    return aInt - bInt;
}

int Comparacion2(const void* a, const void* b) {
    int aInt = *(int*)a;
    int bInt = *(int*)b;
    return bInt - aInt;
}


int main(void) {
    int arreglo[] = { 33,45,67,8,12,32,56,7,9,10,22,45,98,9 };
    int tamanioElemento = sizeof arreglo[0];
    int longitud = sizeof arreglo / tamanioElemento;
    std::cout << "Ejercicio 8.4.1\n\n";
    printf("Arreglo antes de ordenar:\n");
    for (int x = 0; x < longitud; x++) {
        printf("%d ", arreglo[x]);
        std::cout << std::endl;
    }
    qsort(arreglo, longitud, tamanioElemento, Comparacion1);

    printf("\nArreglo ordenado ascendentemente:\n");
    for (int x = 0; x < longitud; x++) {
        printf("%d ", arreglo[x]);
        std::cout << std::endl;
    }

    qsort(arreglo, longitud, tamanioElemento, Comparacion2);

    printf("\nArreglo ordenado descendentemente:\n");
    for (int x = 0; x < longitud; x++) {
        printf("%d ", arreglo[x]);
        std::cout << std::endl;
    }
    return 0;
}