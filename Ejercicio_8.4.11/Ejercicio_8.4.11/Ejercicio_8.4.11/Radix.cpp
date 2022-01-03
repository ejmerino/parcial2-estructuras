#include <iostream>
#include "Radix.h"
#include <map>
using namespace std;

void Radix::setPalabra(string _palabra) {
	palabra = _palabra;
}
void Radix::setTamPalabra(int _TamPalabra) {
	tamPalabra = _TamPalabra;
}
string Radix::getPalabra() {
	return palabra;
}
int Radix::getTamPalabra() {
	return tamPalabra;
}
void Radix::insertar(Radix& aux, int pos)
{
	if (pos < tamPalabra)
	{
		if (pos == tamPalabra - 1)
			aux.finPalabra = true;
		insertar(aux.arbol[palabra[pos]], pos + 1);
	}
}
void Radix::recorrer(Radix aux, string palabra)
{
	if (aux.finPalabra)
		cout << palabra << endl;
	for (auto& i : aux.arbol)
		recorrer(i.second, palabra + i.first);
}
