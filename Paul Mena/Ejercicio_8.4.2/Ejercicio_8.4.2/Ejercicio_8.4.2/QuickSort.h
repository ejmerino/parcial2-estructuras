/* Universidad de las Fuerzas Armadas "ESPE"
* 8.4.11
* Paul Mena
* 31 / 12 / 2021
* 03 / 01 / 2022
* 7167 Estructura de datos
*/



#pragma once
template <class T>

class QuickSort
{
private:
	int auxIzq;
	int auxDer;
	int pivote;
	int auxDato;
public:
	
	void intercambiar(T* vector, int prim, int ulti);
	
	void ordenar(T*, int, int);
	
	void intercambio(T* vector);
	
	void primer_while(T* vector, int prim);

	void segundo_while(T* vector, int ult);
};



