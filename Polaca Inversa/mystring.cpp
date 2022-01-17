/*
    Universidad de las Fuerzas Armadas - ESPE
    Proyecto - Segundo Parcial - Calculadora Polaca Inversa
    Autores:
    Paúl Mena
    Josué Merino
    Daniel Vizcarra
    Fecha de Creación: 15/01/2022
    Fecha de Modificación: 17/01/2022
*/

#include "mystring.h"
#include <iostream>
using namespace std;
char mystring::to_lower(char character)
{
    if (character >= 65 && character <= 90) {
        return character + 32;
    }
    return character;
}

char mystring::to_upper(char character)
{
    if (character >= 97 && character <= 122) {
        return character - 32;
    }
    return character;
}

string mystring::capitalize(string cad)
{
    for (char& c : cad) {
        c = to_upper(c);
    }
    return cad;
}

string mystring::minusculize(string cad)
{
    for (char& c : cad) {
        c = to_lower(c);
    }
    return cad;
}

int mystring::find_character(string cad, char character, int position_initial)
{
    int position_found = -1;
    int cont = 0;
    for (char& c : cad) {
        if (cont >= position_initial && c == character) {
            return cont;
        }
        cont++;
    }

    return position_found;
}

int mystring::find(string cad, string cad_to_find, int position_initial)
{

    string data;
    for (int i = 0; i < length(cad); i++) {
        data = substract(cad, i, length(cad_to_find));
        if (is_equal(data, cad_to_find) && i >= position_initial) {
            return i;
        }
    }
    return -1;
}

int mystring::length(string cad)
{
    int size = 0;
    for (char& c : cad) {
        size++;
    }

    return size;
}

string mystring::substract(string cad, int position_initial, int number_character)
{
    string cad_sub;
    int cont = 0;
    int cont_ch = 1;
    for (char& c : cad) {
        if (cont >= position_initial && cont < (position_initial + number_character)) {
            if (c == ' ') {
                cad_sub += " ";
            }
            else {
                cad_sub += c;
            }

        }
        cont++;

    }
    return cad_sub;
}

bool mystring::is_equal(string cad1, string cad2)
{
    if (length(cad1) != length(cad2)) {
        return false;
    }
    bool flag = false;
    int cont = 0;
    for (int i = 0; i < length(cad1); i++) {
        if (substract(cad1, i, 1) == substract(cad2, i, 1)) {
            cont++;
        }
    }
    if (cont == length(cad1)) {
        flag = true;
    }
    return flag;
}

int mystring::atoi(char character)
{
    if (character >= 48 && character <= 57) {
        return character - 48;
    }
    return 0;
}

int mystring::stoi(string cad)
{
    int r = 0;
    int dato = 0;
    int cont = 0;
    if (substract(cad, 0, 1) == "-") {

        for (char& c : cad) {
            if (cont > 0) {
                dato = atoi(c);
                r = r * 10 + dato;

            }
            cont++;

        }
        r = r * -1;
    }
    else {
        for (char& c : cad) {
            dato = atoi(c);
            r = r * 10 + dato;

        }
    }
    return r;
}

long mystring::stol(string cad)
{
    long r = 0;
    int dato = 0;
    int cont = 0;
    if (substract(cad, 0, 1) == "-") {

        for (char& c : cad) {
            if (cont > 0) {
                dato = atoi(c);
                r = r * 10 + dato;

            }
            cont++;

        }
        r = r * -1;
    }
    else {
        for (char& c : cad) {
            dato = atoi(c);
            r = r * 10 + dato;

        }
    }
    return r;
}

string mystring::reverse(string cad)
{
    string cad_inverse;
    string aux;
    for (char& c : cad) {
        aux.push_back(c);
        cad_inverse = aux + cad_inverse;
        aux = "";

    }
    return cad_inverse;
}

char mystring::at(int position, string cad)
{
    const char* p = cad.c_str();
    char c = ' ';
    if (position <= length(cad)) {
        for (int i = 0; i < position; i++)
        {
            c = *p;
            p++;
        }
    }
    else {
        cout << "La posicion ingresada excede el tamaño de la cadena." << endl;
    }
    return c;
}