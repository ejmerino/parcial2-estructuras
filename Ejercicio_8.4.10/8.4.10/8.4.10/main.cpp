/* Universidad de las Fuerzas Armadas "ESPE"
* 8.4.10
* Paul Mena
* 31 / 12 / 2021
* 03 / 01 / 2022
* 7167 Estructura de datos
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double CalcMediana(vector<int>);

double CalcMediana(vector<int> scores)
{
    size_t size = scores.size();

    if (size == 0)
    {
        return 0;
    }
    else
    {
        sort(scores.begin(), scores.end());
        if (size % 2 == 0)
        {
            return (scores[size / 2 - 1] + scores[size / 2]) / 2;
        }
        else
        {
            return scores[size / 2];
        }
    }
}

int main()
{
    vector<int> v1;
    int numero = 0;
    int valor = 0;
    double mediana = 0;
    cout << "Ingrese el numero de datos en impar -> " << endl;
    cin >> numero;
    while (numero % 2 == 0) {
        cout << "- Debe ser un numero impar " << endl;
        cout << "Ingrese el numero de datos en impar ->  " << endl;
        cin >> numero;
    }
    for (int i = 0; i < numero; i++) {
        cout << "Ingrese el valor: " << endl;
        cin >> valor;
        v1.push_back(valor);
    }

    cout << "---------------- " << endl;
    for (int j = 0; j < numero; j++) {
        cout << " " << v1[j] << endl;
    }

    mediana = CalcMediana(v1);
    cout << "La Mediana calculada es -> " << mediana;


    return 0;
} 