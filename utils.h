#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int aleatorio(int min, int max);

void lerString(char * texto, char * string);

int lerInteiro(char * texto);

int lerFloat(char * texto);

void debugInt(char * txt, char * file, int num);

void debugFloat(char * txt, char * file, float num);

void debugTxt(char * txt, char * file);

void calcularTempoExe();



#endif // UTILS_H_INCLUDED
