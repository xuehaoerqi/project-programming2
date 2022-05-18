#include <stdio.h>
#include <synchapi.h>
#include "Game.h"
#include"fileio.h"
int main() {
    int a=0;
    printf("1.Enter the initial cells\n");
    printf("2.Read from files");
    printf("Please enter your choice:");
    scanf("%d",&a);
    while(a==1)
    {
        Sleep(500);
        Showcells();
    }
}
