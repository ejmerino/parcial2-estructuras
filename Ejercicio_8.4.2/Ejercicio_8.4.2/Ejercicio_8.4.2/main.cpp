/* Universidad de las Fuerzas Armadas "ESPE"
* 8.4.11
* Paul Mena
* 31 / 12 / 2021
* 03 / 01 / 2022
* 7167 Estructura de datos
*/

#include <iostream>
#include "Quicksort.h"
#include "Vector.h"
#include <stdlib.h>
#include "Quicksort.cpp"
#include "Vector.cpp"

int main()
{
  
    int dimension = 30;
    int num = 0;
    Vector<int> vec;
    QuickSort<int> qr = QuickSort<int>();
    vec = Vector<int>(dimension);
    std::cout << "Ingrese el vector " << std::endl;
    vec.ingresar();
    qr.ordenar(vec.getVector(), 0, dimension - 1);
    std::cout << std::endl << "Vector " << char(25) << std::endl;
    vec.imprimirA();
    std::cout << std::endl << "Ingrese el numero a buscar: ";
    std::cin >> num;
    if (vec.buscar(num) != 0) {
        if (vec.buscar(num) == 1)
        std::cout << "\nEl numero buscado se encuentra " << vec.buscar(num) << " vez en el vector" << std::endl;
        else
        std::cout << "\nEl numero buscado se encuentra " << vec.buscar(num) << " veces en el vector" << std::endl;
    }
    else {
        std::cout << "\nEl numero buscado no se encuentra en el vector" << std::endl;
    }

}
