#include<stdio.h>

int main(){
    int su[9][9];// stores main sudoku
    int rr[9][9];//rr means rows record
    int cr[9][9];//cr means column record
    int br[9][9];//br is the block record
    for(int i=0;i<9;i++){
        for(int y=0;y<9;y++){
            rr[i][y]=0;
            cr[i][y]=0;
            br[i][y]=0;
        }
    }
    for(int i=0;i<9;i++){
        for(int y=0;y<9;y++){
            scanf("%d",&su[i][y]);

            //maarking the values in record to tell what values are done
            rr[i][su[i][y]]=1;
            cr[y][su[i][y]]=1;
            br[FindBlock(i,y)][su[i][y]]=1;//find block finds out the block no of any box in sudoku
        }
    }
    int x=0,y=0;
    
    FindNextEmpty(0,0,&x,&y);//this finds the next empty place in sudoku 
    
    recursion(x,y);//this starts the recursion method to recursivly put values in each empty box and brute force the solution of sudoku

    return 0;
}