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
void PrintSudoku(){
    for(int i=0;i<9;i++){
        for(int y=0;y<9;y++){
            printf("%d ",su[i][y]);
        }
        printf("\n");
    }

}
int FindNextEmpty(int x,int y,int* xx,int* yy){
    for(;y<9;y++){
        if(su[x][y]==0){
            *xx=x;
            *yy=y;
            return 1;
        }
    }
    for(x++;x<9;x++){
        for(y=0;y<9;y++){
            if(su[x][y]==0){
            *xx=x;
            *yy=y;
            return 1;
        }
        }
    }
   
            return -1;



}
void update(int x,int y,int i){
    rr[x][i]=1;
    cr[y][i]=1;
    //PrintSudoku();
    br[FindBlock(x,y)][i]=1;
    su[x][y]=i;
}
void unupdate(int x,int y,int i){
    rr[x][i]=0;
    cr[y][i]=0;
    su[x][y]=0;
    br[FindBlock(x,y)][i]=0;
}
int recursion(int x,int y){
   //PrintSudoku();
    for(int i=1;i<9;i++){
        if(rr[x][i]==0&&cr[y][i]==0&&br[FindBlock(x,y)][i]==0){
            
            update(x,y,i);
            int a,b;
            int c=FindNextEmpty(x,y,&a,&b);
            printf("%d %d\n",a,b);
            printf("%d\n",FindBlock(x,y));
            
            PrintSudoku();
            if(c==1){
                
                int xn=recursion(a,b);
                if(xn==-1){

                    unupdate(x,y,i);
                    continue;
                }
                else{
                    return 1;
                }

            }
            else{
                return (1);
            }


        }
    }return -1;

    
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
    PrintSudoku();
    return 0;
}