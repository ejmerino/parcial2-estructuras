#include "Vector.h"
#include <iostream>


template <class T>
Vector<T>::Vector() {
	dim = 0;
	vector = NULL;
}
template <class T>
Vector<T>::Vector(int newDim) {
	dim = newDim;
	reservar(dim);
	encerar();
}
template <class T>
T* Vector<T>::reservar(int newDim) {
	dim = newDim;
	vector = new T[newDim];
	return vector;
}
template <class T>
void Vector<T>::encerar() {
	
	for (int i = 0; i < dim; i++)
		*(vector + i) = 0;
}
template <class T>
void Vector<T>::imprimirD() {
	std::cout << char(204) << " ";

	for (int i = (dim - 1); i >= 0; i--)
		std::cout << *(vector + i) << " ";
	std::cout << char(185) << " " << std::endl;
}
template <class T>
void Vector<T>::imprimirA() {
	std::cout << char(204) << " ";
	
	for (int i = 0; i < dim; i++)
		std::cout << *(vector + i) << " ";
	std::cout << char(185) << " " << std::endl;
}
template <class T>
int Vector<T>::buscar(int num) {

	int numbuscado=0;


	for (int i = 0; i < dim; i++) {
		if (num == *(vector + i)) {
			numbuscado++;
		}
	}

	return numbuscado;
		
}
template <class T>
void Vector<T>::ingresar() {

	int num = 0;

	for (int i = 0; i < dim; i++) {
		std::cout << "[" << (i + 1) << "] = ";
		std::cin >> num;
		*(vector + i) = num;
	}
}

template <class T>
void Vector<T>::setDim(int newDim) {
	dim = newDim;
}
template <class T>
int Vector<T>::getDim() {
	return dim;
}
template < class T>
void Vector<T>::setVector(T* newVector) {
	vector = newVector;
}
template <class T>
T* Vector<T>::getVector() {
	return vector;
}
template <class T>
Vector<T>::~Vector() {
}