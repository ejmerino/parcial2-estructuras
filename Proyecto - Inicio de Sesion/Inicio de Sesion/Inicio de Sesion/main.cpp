/*
    Universidad de las Fuerzas Armadas - ESPE
    Proyecto - Segundo Parcial - Inicio de Sesion
    Autores:
    Paúl Mena
    Josué Merino
    Daniel Vizcarra

    Fecha de Creación: 18/01/2022
    Fecha de Modificación: 19/01/2022
*/

#include <iostream>
#include "stdio.h"
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <string.h>
#include <conio.h>

#define MAX 4
#define MIN 0

using namespace std;


//Variables utilizadas en el programa
const char FINCAD = char(0);
const int MAXCAD = 20;

const char SP = ' ';
char contrasena;
int i;
int contador = 0;

//Tcadena: cadena de caracteres ocupadas con MAXCAD + FINCAD
typedef char TCadena[MAXCAD + 1]; // MAXCAD caracteres + FINCAD
struct Person_R
{
    TCadena contras;
};


//Funciones Principales

void Ingresar_contrasena(Person_R& p);
void Aceptar_contrasena(Person_R& p);

void Crear_archivo(TCadena nombreFichero, Person_R p);
void Ingreso_archivo_person(ofstream& fichero, Person_R p);
void verificar_existencia_fichero(TCadena nombreFichero);
void verificar_existencia_person(TCadena nombreFichero);
void verificar_contrasena(TCadena nombreFichero, Person_R& password);

void borrar();
void pausa();
void finalizar();



int main()
{
    Person_R p;;
    Person_R password;;
    char opcion;
    int num;
    bool fin, encontrado;
    TCadena nombre_usuario_registrado;
    int opcion_menu;

    cout << "\t ======================================================" << endl;
    cout << "\t|     Universidad de las Fuerzas Armadas - Espe        |" << endl;
    cout << "\t|                 Estructura de Datos                  |" << endl;
    cout << "\t|                                                      |" << endl;
    cout << "\t| Autores: Paul Mena - Josue Merino - Daniel Vizcarra  |" << endl;
    cout << "\t ======================================================" << endl;
    cout << "" << endl;


    cout << "1. Ingresar al Programa -> " << endl;
    cout << "2. Registrarse ->" << endl;
    cout << "3. Ingrersar sin registro ->" << endl;
    cout << "4. Salir " << endl;
    cout << "" << endl;
    cout << "Introduzca Opcion:  ";
    cin >> opcion_menu;


    if (opcion_menu == 4) { finalizar(); }
    if ((opcion_menu < MIN) || (opcion_menu > MAX)) {

        /* La declaración try... catch señala un bloque de instrucciones a intentar ( try ),
        y especifica una respuesta si se produce una excepción ( catch ).*/
        try {
            system("cls");

            cout << "\n\n\t Opcion incorrecta. \n";
            Sleep(1500);
            system("cls");  
            main(); 
        }
        catch (...)
        {
            cout << "\n Error " << endl;
        }
    }

    switch (opcion_menu)
    {
    case 1:
        //Ingreso de Usuario
        cout << "\nIngrese su nombre de usuario -->     ";
        cin >> nombre_usuario_registrado;
        verificar_existencia_fichero(nombre_usuario_registrado);

        verificar_contrasena(nombre_usuario_registrado, password);
        Sleep(1000); borrar(); main();
        break;


    case 2:
        //Registro
        cout << "\nIngrese el nombre de usuario -->    ";
        cin >> nombre_usuario_registrado;
        verificar_existencia_person(nombre_usuario_registrado);
        Ingresar_contrasena(p);
        Crear_archivo(nombre_usuario_registrado, p);
        Sleep(1000); borrar(); main();
        break;

    case 3:
        //Ingreso sin registro
        cout << "\nBienvenido \n"; 
        Sleep(1000); borrar(); main();
        break;
    }
    return 0;
}






void Ingresar_contrasena(Person_R& p)
{
    cout << "Ingrese la Contrasena --> ";
    cin >> p.contras;
    cout << "\nRegistro exitoso. " << endl; Sleep(2500);
}


void Aceptar_contrasena(Person_R& password)
{
    cout << "Ingrese su contrasena --> ";
    cin >> password.contras;
}

//Ficheros
void Crear_archivo(TCadena nombreFichero, Person_R p)
{
    ofstream out;
    out.open(nombreFichero, ios::app);

    //Abrir el fichero
    if (out.bad()) {
        out.open(nombreFichero);
    }
    Ingreso_archivo_person(out, p);
    out.close();
}

void Ingreso_archivo_person(ofstream& fichero, Person_R p)
{
    fichero << p.contras << SP;
}

void verificar_existencia_fichero(TCadena nombreFichero)
{
        ifstream archivo(nombreFichero);
    if (!archivo)
    {
        cout << "\nUsuario incorrecto, ingrese nuevamente el Nombre de Usuario --> " << endl; Sleep(2500); borrar(); main();
    }
    else
    {
        cout << "\nUsuario correcto.\n" << endl; Sleep(2500);
    }
}

void verificar_existencia_person(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero);
    if (!archivo)
    {
        cout << "\nSe Registro el nombre de usuario \n" << endl;  Sleep(2500);
    }
    else
    {
        cout << "\nNombre de Usuario existente, ingrese un Nombre de Usuario diferente --> " << endl; Sleep(2500); borrar(); main();

    
    }
}

void verificar_contrasena(TCadena nombreFichero, Person_R & password)
{
    string cadena;
    string contrase;
    cout << "Escriba su contrasena--> ";
    cin >> password.contras;
    ifstream fichero(nombreFichero, ios::in);

    while (!fichero.eof()) {
        fichero >> cadena;


    } 
    if (cadena != password.contras) {
        cout << "\nContrasena incorrecta " << endl; Sleep(2000);
        cout << "\nIntente nuevamente ingresar la contrasena --> " << endl; Sleep(2000); borrar(); main();

       
        fichero.close();
    }

    if (cadena == password.contras) {

        cout << "\n Contraseña correcta, Bienvenido. \n" << endl;  Sleep(2500);

    }
}

void borrar()
{
    system("cls");
}


void pausa()
{
    system("pause");
}

void finalizar()
{
    borrar();
    printf("Se procedera a cerrar el progrmaa"); Sleep(3000);
    exit(0);
}






