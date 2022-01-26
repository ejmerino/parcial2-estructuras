/*
	Universidad de las Fuerzas Armadas - ESPE
	Proyecto - Segundo Parcial - Calculadora Polaca Inversa
	Autores:
	Pa�l Mena
	Josu� Merino
	Daniel Vizcarra
	Fecha de Creaci�n: 15/01/2022
	Fecha de Modificaci�n: 25/01/2022
*/

#pragma once
#include <iostream>
#include <ctime>
#include <random>
template <class T>
class Nodo
{
private:
	T dato;
	Nodo<T>* siguiente;
public:
	Nodo<T>(T, Nodo*);
	T get_dato();
	void set_dato(T);
	Nodo<T>* get_siguiente();
	void set_siguiente(Nodo*);

};
template<class T>
Nodo<T>::Nodo(T val, Nodo* sig)
{
	sig = NULL;
	this->dato = val;
	this->siguiente = sig;
}
template<class T>
T Nodo<T>::get_dato()
{
	return this->dato;
}

template<class T>
void Nodo<T>::set_dato(T val)
{
	this->dato = val;
}


template<class T>
Nodo<T>* Nodo<T>::get_siguiente()
{
	return this->siguiente;
}
template<class T>
void Nodo<T>::set_siguiente(Nodo<T>* nuevo)
{
	this->siguiente = nuevo;
}
