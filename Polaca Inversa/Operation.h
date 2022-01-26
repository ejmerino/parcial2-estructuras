/*
	Universidad de las Fuerzas Armadas - ESPE
	Proyecto - Segundo Parcial - Calculadora Polaca Inversa
	Autores:
	Paúl Mena
	Josué Merino
	Daniel Vizcarra
	Fecha de Creación: 15/01/2022
	Fecha de Modificación: 25/01/2022
*/

#pragma once
#include "String.h"
#include "Stack.h"
class Operation
{
public:
	string infix_to_prefix(string);
	string infix_to_postfix(string);
	string infix_to_funtional(string);
	string prefix_to_infix(string);
	string prefix_to_postfix(string);
	string prefix_to_funtional(string);
	string postfix_to_infix(string);
	string postfix_to_prefix(string);
	string postfix_to_funtional(string);
	bool is_operator(char);
	bool is_trig_fun(char);
	bool is_operand(char);
	int precedence(char);
	bool is_postfix(string);
	bool is_prefix(string);
	bool is_infix(string);
	bool has_parenthesis(string);
};
