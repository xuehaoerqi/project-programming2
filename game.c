//
// Created by 12574 on 2022/5/14.
//

#include "game.h"
#include<stdio.h>
extern cell[1000][1000];
Game(int length,int width,int cell[length][width]){
    int cnt=0;//record the number of cells round the cell
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++) {//judge the situation of the cell by add all cell around it
            if (cell[i][j]!=0 && cell[i][j]!=1){
                printf("invalid symbol found");//judge if there is a invalid symbol
            }
            if (i == 0){//special case:the first line
                if(j == 0){//special case:top left corner
                    cnt=cell[i][j+1]+cell[i+1][j]+cell[i+1][j+1];
                }
                else if(j == width-1){//special case:top right corner
                    cnt=cell[i][j-1]+cell[i+1][j]+cell[i+1][j-1];
                }
                else{//left cases the first line
                    cnt=cell[i][j-1]+cell[i][j+1]+cell[i+1][j-1]+cell[i+1][j]+cell[i+1][j+1];
                }
            }
            else if (i == length-1) {//special case:the last line almost the same as the first line
                if (j == 0) {
                    cnt = cell[i][j + 1] + cell[i - 1][j] + cell[i - 1][j + 1];
                }
                else if (j == width - 1) {
                    cnt = cell[i][j - 1] + cell[i - 1][j] + cell[i + 1][j - 1];
                }
                else {
                    cnt = cell[i][j + 1] + cell[i][j - 1] + cell[i - 1][j - 1] + cell[i - 1][j] + cell[i - 1][j + 1];
                }
            }
            else {//all the left cells which rounded by 8 cells
                cnt = cell[i-1][j-1]+cell[i-1][j]+cell[i-1][j+1]+cell[i][j-1]+cell[i][j+1]+cell[i+1][j-1]+cell[i+1][j]+cell[i+1][j+1];
            }
            if (cnt==3){//judge the situation of the cell
                cell[i][j]=1;
            }
            else if (cnt<2||cnt>3){
                cell[i][j]=0;
            }
        }
    }
}
void Showcells(int cell[100][100]){
    int i = 0,j = 0;
    for(i = 0;i < 100;i++)
    {
        for(j = 0;j < 100;j++)
        {
            if(0 == cell[i][j])
                printf("□");
            else
                printf("■");
        }
        printf("\n");
    }
    printf("press x to continue");
}