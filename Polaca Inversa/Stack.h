/*
	Universidad de las Fuerzas Armadas - ESPE
	Proyecto - Segundo Parcial - Calculadora Polaca Inversa
	Autores:
	Paúl Mena
	Josué Merino
	Daniel Vizcarra
	Fecha de Creación: 15/01/2022
	Fecha de Modificación: 25/01/2022
*/

#pragma once
#include "Nodo.h"
#include <ctime>
#include <random>
#include <functional>
#include <iostream>
using namespace std;
template <class T>
class Stack
{
private:
	Nodo<T>* primero;
	Nodo<T>* actual;
public:
	bool listaVacia();
	/**
	 * @brief Verifica la pila este creada y vacia
	 *
	 * @return true
	 * @return false
	 */
	bool empty_stack();
	Stack<T>();
	/**
	 * @brief Inserta por la cola de una pila
	 *
	 * @return T
	 */
	void insertar_por_la_cola(T);
	/**
	 * @brief setter
	 *
	 * @return void
	 */
	void set_primero(Nodo<T>*);
	Nodo<T>* get_primero();
	/**
	 * @brief setter
	 *
	 * @return void
	 */
	void set_actual(Nodo<T>*);
	Nodo<T>* get_actual();
	/**
	 * @brief Inserta por la cabeza de la pila
	 *
	 * @return void
	 */
	void insertar_por_la_cabeza(T);
	/**
	 * @brief Borra por la cola de la pila
	 *
	 * @return void
	 */
	void borrar_por_la_cola();
	/**
	 * @brief Borra por la cabeza de la pila
	 *
	 * @return void
	 */
	void borrar_por_la_cabeza();
	/**
	 * @brief Muestra la pila completa
	 *
	 * @return void
	 */
	void mostrar();
	/**
	 * @brief llena la pila, con numeros aleatorios
	 *
	 * @return void
	 */
	void llenar_aleatorio_lista();
	/**
	 * @brief borra los datos de la pila
	 *
	 * @return void
	 */
	void vaciar_lista();
	T maximo_comun_divisor(T);
	T contar_elementos();

};

template<class T>
void Stack<T>::mostrar()
{
	Nodo<T>* temporal = this->primero;
	while (temporal) {
		cout << temporal->get_dato() << " " << endl;
		temporal = temporal->get_siguiente();

	}
	cout << endl;
}
template<class T>
void Stack<T>::vaciar_lista() {
	while (listaVacia()) {
		borrar_por_la_cola();
	}
}
template<class T>
bool Stack<T>::listaVacia()
{
	return (this->primero == NULL);
}
template<class T>
bool Stack<T>::empty_stack()
{
	return (this->primero == NULL);
}
template<class T>
Stack<T>::Stack()
{
	this->primero = NULL;
	this->actual = NULL;
}
template<class T>
void Stack<T>::insertar_por_la_cola(T val)
{
	Nodo<T>* nuevo = new Nodo<T>(val, NULL);
	if (listaVacia()) {
		this->primero = nuevo;
	}
	else {
		this->actual->set_siguiente(nuevo);
	}
	this->actual = nuevo;
}
template<class T>
void Stack<T>::set_primero(Nodo<T>* new_primero) {
	this->primero = new_primero;
}
template<class T>
Nodo<T>* Stack<T>::get_primero() {
	return primero;
}
template<class T>
void Stack<T>::set_actual(Nodo<T>* new_actual) {
	this->actual = new_actual;
}
template<class T>
Nodo<T>* Stack<T>::get_actual() {
	return actual;
}
template<class T>
void Stack<T>::insertar_por_la_cabeza(T val)
{
	Nodo<T>* nuevo = new Nodo<T>(val, NULL);

	if (listaVacia()) {
		this->actual = nuevo;
	}
	else {
		nuevo->set_siguiente(this->primero);
	}
	this->primero = nuevo;
}
template<class T>
void Stack<T>::borrar_por_la_cola()
{
	if (!listaVacia()) {
		Nodo<T>* temp = this->actual;
		Nodo<T>* temp1 = this->primero;
		while (temp1->get_siguiente()->get_siguiente() != NULL) {
			temp1 = temp1->get_siguiente();
		}
		temp1->set_siguiente(NULL);
		this->actual = temp1;
		free(temp);
	}
}
template<class T>
void Stack<T>::borrar_por_la_cabeza()
{
	if (!listaVacia()) {
		Nodo<T>* temp;
		temp = this->primero;
		this->primero = this->primero->get_siguiente();
		free(temp);
	}
}
template<class T>
void Stack<T>::llenar_aleatorio_lista()
{
	Nodo<T>* temp = this->primero;
	std::srand(std::time(nullptr));
	int aleatorio = 0;
	while (aleatorio != 5) {
		aleatorio = 1 + rand() % (6);
		if (aleatorio == 2 || aleatorio == 4) {
			insertar_por_la_cola(aleatorio);
		}
	}
}
template<class T>
T Stack<T>::maximo_comun_divisor(T elementos)
{
	int mcd = 0;
	int contador = 0;
	Nodo<T>* temporal = this->primero;
	for (int i = 1; i < 1000; i++) {
		contador = 0;
		temporal = this->primero;
		while (temporal) {

			if (temporal->get_dato() % i == 0) {

				contador = contador + 1;
			}
			temporal = temporal->get_siguiente();
		}

		if (elementos == contador) {
			mcd = i;
		}
	}
	return T(mcd);
}
template<class T>
T Stack<T>::contar_elementos()
{
	int elementos = 0;
	Nodo<T>* temporal = this->primero;
	while (temporal) {
		elementos = elementos + 1;
		temporal = temporal->get_siguiente();

	}
	return T(elementos);
}
