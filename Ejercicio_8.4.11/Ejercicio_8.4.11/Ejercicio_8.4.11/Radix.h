/* Universidad de las Fuerzas Armadas "ESPE"
* 8.4.11
* Paul Mena
* 31 / 12 / 2021
* 03 / 01 / 2022
* 7167 Estructura de datos
*/

#pragma once
#include <iostream>
#include <map>
using namespace std;

class Radix {
private:
	string palabra; ///Palabra a insertar en el Trie
	int tamPalabra; ///Tamanio de la palabra + 1
	map<char, Radix> arbol;

public:
	bool finPalabra = false;
	void insertar(Radix&, int);
	void recorrer(Radix, string);
	void setPalabra(string);
	void setTamPalabra(int);
	string getPalabra();
	int getTamPalabra();
};

