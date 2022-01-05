/* Universidad de las Fuerzas Armadas "ESPE"
* 8.4.11
* Paul Mena
* 31 / 12 / 2021
* 03 / 01 / 2022
* 7167 Estructura de datos
*/


#pragma once
template <class T>

class Vector
{
private:
	int dim;
	T* vector;
public:
	
	Vector();
	
	Vector(int dim);

	T* reservar(int);
	
	void ingresar();
	
	void encerar();
	
	int buscar(int num);
	
	void imprimirD();
	
	void imprimirA();
	
	void setDim(int newDim);
	
	int getDim();
	
	void setVector(T* newVector);
	
	T* getVector();
	
	~Vector();
};

