/*
    Universidad de las Fuerzas Armadas - ESPE
    Proyecto - Segundo Parcial - Calculadora Polaca Inversa
    Autores:
    Paúl Mena
    Josué Merino
    Daniel Vizcarra
    Fecha de Creación: 15/01/2022
    Fecha de Modificación: 26/01/2022
*/

#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include "Operation.h"


#pragma warning(disable:4996)
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
using namespace std;
/**
 * @brief Menu principal
 *
 * @return void
 */
void menu_principal();
/**
 * @brief Menu Colores
 *
 * @return void
 */
void Color(int Background, int Text);
/**
 * @brief posicion en la pantalla del color
 *
 * @return void
 */
void gotoxy(USHORT x, USHORT y) {
    COORD cp = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}
/**
 * @brief posicion en la pantalla del color
 *
 * @return void
 */
void Color(int Background, int Text) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    int    New_Color = Text + (Background * 16);
    SetConsoleTextAttribute(Console, New_Color);
}
int menu(const char titulo[], const char* opciones[], int n);
void menu_principal()
{
    bool repite = true;
    int opcion;
    string expression;
    const char* titulo = "MENU DE OPCIONES";
    const char* opciones[] = { "Notacion infija", "Notacion prefija","Notacion postfija", "Salir" };
    Operation op;
    string infix = "";
    int n = 4;  // Numero de opciones
    do {
        opcion = menu(titulo, opciones, n);

        switch (opcion) {
        case 1:
            system("cls");
            do {
                gotoxy(15, 3); cout << "Ingrese la expresion infija:";
                cin >> expression;
            } while (!op.is_infix(expression));
            cout << "Notacion prefija:" << op.infix_to_prefix(expression) << endl;
            infix = op.infix_to_prefix(expression);
            cout << "Notacion postfija:" << op.prefix_to_postfix(infix) << endl;
            cout << "Notacion funcional:" << op.infix_to_funtional(expression) << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            do {
                gotoxy(15, 3); cout << "Ingrese la expresion prefija:";
                cin >> expression;
            } while (!op.is_prefix(expression));
            cout << "Notacion infija:" << op.prefix_to_infix(expression) << endl;
            cout << "Notacion postfija:" << op.prefix_to_postfix(expression) << endl;
            cout << "Notacion funcional:" << op.prefix_to_funtional(expression) << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            do {
                gotoxy(15, 3); cout << "Ingrese la expresion sufija:";
                cin >> expression;
            } while (!op.is_postfix(expression));
            cout << "Notacion prefija:" << op.postfix_to_prefix(expression) << endl;
            cout << "Notacion infija:" << op.postfix_to_infix(expression) << endl;
            cout << "Notacion funcional:" << op.postfix_to_funtional(expression) << endl;
            system("pause>nul");
            break;
        case 4:
            system("cls");
            gotoxy(15, 3); cout << "\nGracias!" << endl;
            repite = false;
            system("pause>nul");
            break;
        }

    } while (repite);
}

int menu(const char titulo[], const char* opciones[], int n)
{
    int opcionSeleccionada = 1;
    int tecla;
    bool repite = true;



    do {
        system("cls");
        gotoxy(5, 3 + opcionSeleccionada);  Color(1, 2); cout << "==>" << endl;
        Color(0, 15);
        gotoxy(15, 2); cout << titulo;
        for (int i = 0; i < n; ++i) {
            gotoxy(10, 4 + i); cout << i + 1 << ") " << opciones[i];
        }

        do {
            tecla = getch();

        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
        switch (tecla) {
        case ARRIBA:
            opcionSeleccionada--;
            if (opcionSeleccionada < 1) {
                opcionSeleccionada = n;
            }
            break;
        case ABAJO:
            opcionSeleccionada++;
            if (opcionSeleccionada > n) {
                opcionSeleccionada = 1;
            }
            break;
        case ENTER:
            repite = false;
            break;
        }
    } while (repite);
    return opcionSeleccionada;
}
