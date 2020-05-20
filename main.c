#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "function.c"

int main()
{
    if(menu() == '1')
    {
        inditas();
        printf("\n\n\nNyomjon p-t a kilepeshez\n");
        char q;
        while(q != 'p')
        {
            q=getch();
        }
    }
    else
    {
        printf("\n\n\nNyomjon p-t a kilepeshez\n");
        char q;
        while(q != 'p')
        {
            q=getch();
        }
    }

    return 0;
}
