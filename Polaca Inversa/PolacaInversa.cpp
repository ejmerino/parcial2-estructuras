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

#include <iostream>
#include <thread>
#include "Stack.h"
#include "Operation.h"
#include "Menu.h"
#include "Marquee.h"
#include "Image.h"


void marquee_limit(std::string text, size_t limit) {
    bool ciclo = true;
    while (ciclo)
    {
        std::string temp = text;
        text.erase(0, 1);
        text += temp[0];
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        //poner titulo en la consola

        SetConsoleTitleA(text.substr(0, limit).c_str());
        if (GetAsyncKeyState(VK_RETURN)) {
            ciclo = false;
            break;
        }

    }
}

int main()
{
    std::string test = "UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ";
    std::thread t2(marquee_limit, test, test.size());


    Marquee mark1("Paul Mena  Josue Merino   Daniel Vizcarra", 27);
    mark1.animation();

    menu_principal();

    Image img;
    img.showImage();

    t2.join();
}