/* Universidad de las Fuerzas Armadas "ESPE"
* 8.4.11
* Paul Mena
* 31 / 12 / 2021
* 03 / 01 / 2022
* 7167 Estructura de datos
*/

#include "Radix.h"
#include <iostream>
using namespace std;
int main()
{
	Radix objRadix;
	int dimension=0;
	string nombre="";
	cout << "Ingrese el numero de nombres: ";
	cin >> dimension;
	string* pal = new string[dimension];
	
	for (int j = 0; j < dimension;j++) {
		cout << "[" << (j + 1) << "] => ";
		cin >> nombre;
		*(pal + j) = nombre;
	}
	cout << endl;
	cout << "Nombres ordenados " << char(25) << endl;
	for (int i = 0; i < dimension; i++)
		{
			objRadix.setPalabra(*(pal+i));
			objRadix.setTamPalabra(objRadix.getPalabra().size() + 1);
			objRadix.insertar(objRadix, 0);
		}
	objRadix.recorrer(objRadix, " ");

}
