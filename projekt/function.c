#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "header.h"

int menu()
{
    char x = '0';

    system("cls");
    printf("1. Jatek inditasa \n2. Kilepes \n");
    while(1)
    {
        x = getch();
        switch(x)
        {
            case '1':
                return x;
            break;

            case '2':
                return x;
            break;
        }
    }
}

void inditas()
{
    Karakter *k;
    k = (Karakter*)malloc(sizeof(Karakter));
    Palya* p;
    clock_t start,stop;
    double score = 0;
    p = inicializalas("labirintus0.txt",k);
    printf("Nyomj meg egy gombot a kezdeshez!");
    start = getch();
    start = clock();
    jatek(p,k);
    stop = clock();
    score += ido(start,stop);
    p = inicializalas("labirintus1.txt",k);
    start = clock();
    jatek(p,k);
    stop = clock();
    score += ido(start,stop);
    p = inicializalas("labirintus2.txt",k);
    start = clock();
    jatek(p,k);
    stop = clock();
    score += ido(start,stop);
    p = inicializalas("labirintus3.txt",k);
    start = clock();
    jatek(p,k);
    stop = clock();
    score += ido(start,stop);
    p = inicializalas("labirintus4.txt",k);
    start = clock();
    jatek(p,k);
    stop = clock();
    score += ido(start,stop);
    p = inicializalas("labirintus5.txt",k);
    start = clock();
    jatek(p,k);
    stop = clock();
    score += ido(start,stop);
    int o = 5;
    while(o)
    {
        finish();
        Sleep(100);
        o--;
    }

    printf("\n\n                EREDMENY:--> %lf sec <--",score);
    printf("\n\nNyomjon p-t a kilepeshez");
    char q;
    while(q != 'p')
    {
        q=getch();
    }
}

Palya *inicializalas(char* input,Karakter *k)
{
    FILE* be = fopen(input,"r");
    if(!be)
    {
        printf("Hiba az allomannyal 1.");
        exit(-1);
    }
    Palya *p = (Palya*)malloc(sizeof(Palya));
    if(!p)
    {
        printf("Hiba a helyfoglalassal 2.");
        exit(-2);
    }
    fscanf(be,"%i%i\n",&p->n,&p->m);
    fscanf(be,"%i%i\n",&k->x,&k->y);

   // printf("%i %i\n",p->n,p->m);
    //printf("%i %i",k->x,k->y);
    p->matrix = (int**)calloc(p->n,sizeof(int*));
    if(!p->matrix)
    {
        printf("Hiba a helyfoglalassal 3.");
        exit(-3);
    }
    for(int i=0;i<p->n;i++)
    {
        p->matrix[i] = (int*)calloc(p->m,sizeof(int));
    }
    for(int i=0;i<p->n;i++)
    {
        for(int j=0;j<p->m;j++)
        {
            fscanf(be,"%i",&p->matrix[i][j]);
        }
    }
    p->matrix[k->x][k->y] = 5;
    //printf("\n%i",p->matrix[k->x][k->y]);
    return p;
}

Palya* mozgat(Palya *p, Karakter *k, int x, int y)
{
    p->matrix[k->x][k->y] = 0;
    k->x = x;
    k->y = y;
    p->matrix[k->x][k->y] = 5;
    return p;
}

void jatek(Palya *p, Karakter *k)
{
    char a;
    system("cls");
    kiir(p);
    while (a != 'p')
    {
        a = getch();
        switch(a)
        {
            case 119: //w - fel
                if(p->matrix[k->x-1][k->y] == 0 || p->matrix[k->x-1][k->y] == 6)
                {
                    system("cls");
                    if(p->matrix[k->x-1][k->y] == 6)
                    {
                        return 0;
                    }
                    p = mozgat(p,k,k->x-1,k->y);
                    kiir(p);
                }
            break;

            case 115: //s - le

                if(p->matrix[k->x+1][k->y] == 0 || p->matrix[k->x+1][k->y] == 6)
                {
                    system("cls");
                    if(p->matrix[k->x+1][k->y] == 6)
                    {
                        return 0;
                    }
                    p = mozgat(p,k,k->x+1,k->y);
                    kiir(p);
                }
            break;

            case 97: //a - bal
                if(p->matrix[k->x][k->y-1] == 0 || p->matrix[k->x][k->y-1] == 6)
                {
                    system("cls");
                    if(p->matrix[k->x][k->y-1] == 6)
                    {
                        return 0;
                    }
                    p = mozgat(p,k,k->x,k->y-1);
                    kiir(p);
                }
            break;

            case 100: //d - jobb
                if(p->matrix[k->x][k->y+1] == 0 || p->matrix[k->x][k->y+1] == 6)
                {
                    system("cls");
                    if(p->matrix[k->x][k->y+1] == 6)
                    {
                        return 0;
                    }
                    p = mozgat(p,k,k->x,k->y+1);
                    kiir(p);
                }
            break;

            case 112: //p - exit
                exit(0);
            break;
        }
    }
}

void finish()
{
    int n,m,**v;
    FILE *f = fopen("finish.txt","r");
    fscanf(f,"%i%i\n",&n,&m);
    v = (int**)malloc(n*sizeof(int*));
    if(!v) {printf("ERROR FINISH1"); exit(-4);}
    for(int i=0;i<n;i++)
    {
        v[i] = (int*)malloc(m*sizeof(int));
        if(!v[i]) {printf("ERROR FINISH2"); exit(-5);}
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            fscanf(f,"%i",&v[i][j]);
        }
    }
    system("cls");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j] == 0)
            {
                printf(" ");
            }
            if(v[i][j] == 5)
            {
                printf("%c",178);
            }
        }
        printf("\n");
    }
}

void kiir(Palya *p)
{
    printf("w - up, s - down, a - right, d - left, p - exit\n\n");
    for(int i=0;i<p->n;i++)
    {
        printf(" ");
        for(int j=0;j<p->m;j++)
        {
            if(p->matrix[i][j] == 0)
            {
                printf(" ");
            }
            if(p->matrix[i][j] == 1)
            {
                printf("%c",220);
            }

            if(p->matrix[i][j] == 2)
            {
                printf("%c",219);
            }
            if(p->matrix[i][j] == 3)
            {
                printf("%c",223);
            }
            if(p->matrix[i][j] == 4)
            {
                printf("%c",186);
            }
            if(p->matrix[i][j] == 5)
            {
                printf("%c",207);
            }
            if(p->matrix[i][j] == 6)
            {
                printf("%c",176);
            }
            if(p->matrix[i][j] == 7)
            {
                printf("%c",176);
            }
        }
        printf("\n");
    }
}

double ido (clock_t start,clock_t stop)
{
    double timer=stop-start;
    timer/=CLOCKS_PER_SEC;
    return timer;
}








