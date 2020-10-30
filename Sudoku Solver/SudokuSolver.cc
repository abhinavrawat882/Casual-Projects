#include<stdio.h>
int su[9][9];// stores main sudoku
int rr[9][9];//rr means rows record
int cr[9][9];//cr means column record
int br[9][9];//br is the block record
int FindBlock(int i,int y){
    if(i>=0&&i<=2){
        if(y>=0&&y<=2){
            return 0;
        }
        else if(y>2&&y<=5){
            return 1;

        }   
        else{
            return 2;
        
        } 

    }
    else if(i>2&&i<=5){
        if(y>=0&&y<=2){
            return 3;
        }
        else if(y>2&&y<=5){
            return 4;

        }   
        else{
            return 5;
        
        } 
    }   
    else{
        if(y>=0&&y<=2){
            return 6;
        }
        else if(y>2&&y<=5){
            return 7;

        }   
        else{
            return 8;
        
        } 
    } 
}
void PrintSudoku(int* sd){
    for(int i=0;i<9;i++){
        for(int y=0;y<9;y++){
            printf("%d ",sd[i][y]);
        }
    }

}
void FindNextEmpty(int x,int y,int* xx,int* yy){
    for(;y<9;y++){
        if(su[x][y]==0){
            *xx=x;
            *yy=y;
            return;
        }
    }
    for(x++;x<9;x++){
        for(y=0;y<9;y++){
            if(su[x][y]==0){
            *xx=x;
            *yy=y;
            return;
        }
        }
    }
    *xx=-1;
            *yy=-1;
            return;



}
void recursion(x,y){
    
}
int main(){
   
    
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