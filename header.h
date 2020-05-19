#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct Palya
{
    int n,m;
    int **matrix;
}Palya;

typedef struct Karakter
{
    int x,y;
}Karakter;

int menu();

void inditas();

Palya *inicializalas(char*,Karakter*);

void jatek(Palya*,Karakter*);

Palya* mozgat(Palya*,Karakter*,int,int);

void finish();

void kiir(Palya*);

double ido (clock_t,clock_t);

#endif // HEADER_H_INCLUDED
