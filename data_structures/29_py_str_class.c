/* Copyright (c) Kashaan Mahmood */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "29_py_str_class.h" /* header file containing structures and  functions definitions */
#define MAXVAL 1000

/* Attempted Implementation of Python-like string class

x = str()
x = x + 'H'
x = x + "ello World."
x = "Thanks for the offer.";
*/

int main(){
    struct Pystr* p  = pystr_new();
    pystr_dump(p);
    pystr_append(p,'H');
    pystr_append(p,'e');
    pystr_append(p,'l');
    pystr_append(p,'l');
    pystr_append(p,'o');
    pystr_append(p,' ');
    pystr_append(p,'W');
    pystr_append(p,'o');
    pystr_append(p,'r');
    pystr_append(p,'l');
    pystr_append(p,'d');
    pystr_append(p,'.');
    pystr_dump(p);
    pystr_appends(p," Welcome to C programming");
    pystr_dump(p);
    pystr_assign(p,"Thanks. I am not sure I want to learn it...");
    pystr_dump(p);
}
