//
// Created by 12574 on 2022/5/14.
//

#include <stdio.h>
#include "fileio.h"
int ReadGame()
{
    int cell[200][200];
    FILE *fp;
    int i = 0,j = 0;
    char ch = '\0';
    if(fopen("LifeGame.txt","w+")==NULL)//judge if the file is existed
    {
        printf("file not existed\n");
        return -1;
    }
    fp = fopen("LifeGame.txt","r");
    for(i = 0;i < 200;i++)//read by line
    {
        for(j = 0;j < 200;j++)
        {
            fscanf(fp,"%c",&ch);
            if('0' != ch)
            {
                cell[i][j] = 0;
            }
            else
            {
                cell[i][j] = 1;
            }
            else
            {
                print("invalid symbols found")//check if the file all contain the correct numbers
            }
        }
        fscanf(fp,"%c",&ch);
    }
    return 0;
}