#include "Quicksort.h"
#include <iostream>
#include "Vector.h"

template <class T>
void QuickSort<T>::intercambiar(T* vector, int prim, int ulti) {
	auxIzq = prim;
	auxDer = ulti;
	pivote = *(vector + ((prim + ulti) / 2));
	auto inter = [&](T* vector) -> void {
		do {
			primer_while(vector, ulti);
			segundo_while(vector, prim);
			intercambio(vector);
		} while (auxIzq <= auxDer);
	};

	inter(vector);
}
template <class T>
void QuickSort<T>::primer_while(T* vector, int ulti) {
	while ((*(vector + auxIzq) < pivote) && (auxDer <= ulti))
	{
		auxIzq++;
	}
}
template <class T>
void QuickSort<T>::segundo_while(T* vector, int prim) {
	while ((pivote < *(vector + auxDer)) && (auxDer > prim))
	{
		auxDer--;
	}
}
template <class T>
void QuickSort<T>::intercambio(T* vector) {

	if (auxIzq <= auxDer)
	{
		auxDato = *(vector + auxIzq);
		*(vector + auxIzq) = *(vector + auxDer);
		*(vector + auxDer) = auxDato;
		auxIzq++;
		auxDer--;
	}
}
template <class T>
void QuickSort<T>::ordenar(T* vector, int izq, int der)
{
	intercambiar(vector, izq, der);
	if (izq < auxDer)
		ordenar(vector, izq, auxDer);
	if (auxIzq < der)
		ordenar(vector, auxIzq, der);
}


