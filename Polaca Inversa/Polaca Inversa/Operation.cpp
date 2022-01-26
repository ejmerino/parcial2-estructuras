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

#include "Operation.h"

string Operation::infix_to_prefix(string infix)
{
    Stack<char> stack;
    String_p str;
    string cad = str.reverse(infix);
    string result, prefix;
    string aux;
    char anterior = '.';
    for (char& character : cad) {
        if (character == '(') {
            character = ')';
        }
        else if (character == ')') {
            character = '(';
        }
    }
    infix = cad;
    for (char& character : infix) {

        if ((character >= 'a' && character <= 'z' || character >= '0' && character <= '9')) {
            prefix += character;
        }
        else if (character == '(') {
            stack.insertar_por_la_cabeza(character);
        }
        else if (character == ')') {
            while ((stack.get_primero()->get_dato() != '(') && (!stack.empty_stack())) {
                prefix += stack.get_primero()->get_dato();
                stack.borrar_por_la_cabeza();
            }

            if (stack.get_primero()->get_dato() == '(') {
                stack.borrar_por_la_cabeza();
            }
        }
        else if (is_operator(character)) {
            if (stack.empty_stack()) {
                stack.insertar_por_la_cabeza(character);
            }
            else {
                if (precedence(character) > precedence(stack.get_primero()->get_dato())) {
                    stack.insertar_por_la_cabeza(character);
                }
                else if ((precedence(character) == precedence(stack.get_primero()->get_dato()))
                    && (character == '^')) {
                    while ((precedence(character) == precedence(stack.get_primero()->get_dato()))
                        && (character == '^')) {
                        prefix += stack.get_primero()->get_dato();
                        stack.borrar_por_la_cabeza();
                    }
                    stack.insertar_por_la_cabeza(character);
                }
                else if (precedence(character) == precedence(stack.get_primero()->get_dato())) {
                    stack.insertar_por_la_cabeza(character);
                }
                else {
                    while ((!stack.empty_stack()) && (precedence(character) < precedence(stack.get_primero()->get_dato()))) {
                        prefix += stack.get_primero()->get_dato();
                        stack.borrar_por_la_cabeza();
                    }
                    stack.insertar_por_la_cabeza(character);
                }
            }
        }
        else if (is_trig_fun(character) && anterior == ')') {
            prefix += character;
        }
        anterior = character;
    }

    while (!stack.empty_stack()) {
        prefix += stack.get_primero()->get_dato();
        stack.borrar_por_la_cabeza();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string Operation::infix_to_postfix(string infix)
{
    string prefix = infix_to_prefix(infix);
    string postfix = prefix_to_postfix(prefix);
    return postfix;

}

int Operation::precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string Operation::infix_to_funtional(string expression)
{
    string expression1 = infix_to_prefix(expression);
    string expression2 = prefix_to_funtional(expression1);

    return expression2;
}

string Operation::prefix_to_infix(string prefix)
{
    String_p str;
    string cad = str.reverse(prefix);
    string aux, aux2;
    string charac = "";
    char anterior = '.';
    Stack<string> stack;

    for (char& character : cad) {
        if (is_operand(character)) {

            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (character == '+' || character == '-') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + character + aux2);

        }
        else if (character == '*' || character == '/') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.length(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.length(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux + character + aux2 + ")");
        }
        else if (character == '%') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.length(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.length(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux + character + aux2 + ")");
        }
        else if (character == '^') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.length(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.length(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux + character + aux2 + ")");
        }
        else if (is_trig_fun(character)) {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();

            if (str.length(aux) == 1) {
                charac.push_back(character);
                stack.insertar_por_la_cabeza(charac + "(" + aux + ")");
                charac = "";
            }
            else if (str.substract(aux, 0, 1) == "(") {
                stack.insertar_por_la_cabeza(character + aux);
            }
            else {
                stack.insertar_por_la_cabeza(character + "(" + aux + ")");
            }
        }

    }
    return stack.get_primero()->get_dato();
}

string Operation::prefix_to_postfix(string prefix)
{
    String_p str;
    string cad = str.reverse(prefix);
    string aux, aux2;
    string charac = "";
    char anterior = '.';
    Stack<string> stack;

    for (char& character : cad) {
        if (is_operand(character)) {

            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (character == '+') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "+");

        }
        else if (character == '-') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "-");

        }
        else if (character == '*') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "*");

        }
        else if (character == '/') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "/");

        }
        else if (character == '%') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "%");

        }
        else if (character == '^') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + aux2 + "^");

        }
        else if (character == 'T') {
            charac.push_back(character);

            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + "T");
            charac = "";
        }
        else if (character == 'S') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + "S");
        }
        else if (character == 'C') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux + "C");
        }

    }
    return stack.get_primero()->get_dato();

}

string Operation::prefix_to_funtional(string prefix)
{
    String_p str;
    string cad = str.reverse(prefix);
    string aux, aux2;
    string charac = "";
    char anterior = '.';
    Stack<string> stack;

    for (char& character : cad) {
        if (is_operand(character)) {

            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (character == '+') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("SUMA(" + aux + "," + aux2 + ")");

        }
        else if (character == '-') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("RESTA(" + aux + "," + aux2 + ")");

        }
        else if (character == '*') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("MULTIPLICACION(" + aux + "," + aux2 + ")");

        }
        else if (character == '/') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("DIVISION(" + aux + "," + aux2 + ")");

        }
        else if (character == '%') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("MODULO(" + aux + "," + aux2 + ")");

        }
        else if (character == '^') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("POTENCIA(" + aux + "," + aux2 + ")");

        }
        else if (character == 'T') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("TANGENTE(" + aux + ")");
        }
        else if (character == 'S') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("SENO(" + aux + ")");
        }
        else if (character == 'C') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("COSENO(" + aux + ")");
        }

    }
    return stack.get_primero()->get_dato();
}

string Operation::postfix_to_infix(string expression)
{
    String_p str;
    string aux, aux2;
    string charac = "";
    Stack<string> stack;
    for (char& character : expression) {
        if (is_operand(character)) {

            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (character == '+' || character == '-') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux2 + character + aux);

        }
        else if (character == '*' || character == '/' || character == '%') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.length(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.length(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux2 + character + aux + ")");
        }
        else if (character == '^') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.length(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.length(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux2 + character + aux + ")");
        }
        else if (is_trig_fun(character)) {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();

            if (str.length(aux) == 1) {
                charac.push_back(character);
                stack.insertar_por_la_cabeza(charac + "(" + aux + ")");
                charac = "";
            }
            else if (str.substract(aux, 0, 1) == "(") {
                stack.insertar_por_la_cabeza(character + aux);
            }
            else {
                stack.insertar_por_la_cabeza(character + "(" + aux + ")");
            }
        }
    }
    return stack.get_primero()->get_dato();
}

string Operation::postfix_to_prefix(string postfix)
{
    string expression = postfix_to_infix(postfix);
    string expression1 = infix_to_prefix(expression);
    return expression1;
}

string Operation::postfix_to_funtional(string expression)
{
    string expression1 = postfix_to_prefix(expression);
    cout << expression1 << endl;
    string expression2 = prefix_to_funtional(expression1);
    return expression2;
}

bool Operation::is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') {
        return true;
    }
    return false;
}

bool Operation::is_trig_fun(char c)
{
    if (c == 'S' || c == 'C' || c == 'T') {
        return true;
    }
    return false;
}

bool Operation::is_operand(char c)
{
    if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool Operation::is_postfix(string expression)
{
    String_p str;
    int lenth = str.length(expression);
    char c = str.at(1, expression);
    char c2 = str.at(lenth, expression);
    if (!has_parenthesis(expression) && is_operand(c) && (is_operator(c2) || is_trig_fun(c2)))
        return true;
    else
        return false;
}

bool Operation::is_infix(string expression)
{
    String_p str;
    int lenth = str.length(expression);
    char c = str.at(1, expression);
    char c2 = str.at(lenth, expression);
    if (is_operator(c) || is_operator(c2) || is_trig_fun(c2))
        return false;
    else
        return true;
}

bool Operation::is_prefix(string expression)
{
    String_p str;
    int lenth = str.length(expression);
    char c = str.at(1, expression);
    char c2 = str.at(lenth, expression);
    if (!has_parenthesis(expression) && is_operand(c2) && (is_operator(c) || is_trig_fun(c)))
        return true;
    else
        return false;
}

bool Operation::has_parenthesis(string expression)
{
    for (char& cad : expression)
    {
        if (cad == '(' || cad == ')')
            return true;
        else
            return false;
    }
}