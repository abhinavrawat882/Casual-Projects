#include<stdio.h>
int main(){
    char lra[27][27]={{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                      {'#',' ','|',' ','|',' ','|','_','|','_','#','_','|','_','|','_','#','_','|','_','|','_','|','_','|','_','#'},
                      {'#','-','-','-','-','-','-','-','-','-','#','-','-','-','-','-','#','-','-','-','-','-','-','-','-','-','#'},
                      {'#',' ','|',' ','|',' ','|','_','|','_','#','_','|','_','|','_','#','_','|','_','|','_','|','_','|','_','#'},
                      {'#','-','-','-','-','-','-','-','-','-','#','-','-','-','-','-','#','-','-','-','-','-','-','-','-','-','#'},
                      {'#',' ','|',' ','|',' ','|','_','|','_','#','_','|','_','|','_','#','_','|','_','|','_','|','_','|','_','#'},
                      {'#','-','-','-','-','-','-','-','-','-','#','-','-','-','-','-','#','-','-','-','-','-','-','-','-','-','#'},
                      {'#',' ','|',' ','|',' ','|','_','|','_','#','_','|','_','|','_','#','_','|','_','|','_','|','_','|','_','#'},
                      {'#','-','-','-','-','-','-','-','-','-','#','-','-','-','-','-','#','-','-','-','-','-','-','-','-','-','#'},
                      {'#',' ','|',' ','|',' ','|','_','|','_','#','_','|','_','|','_','#','_','|','_','|','_','|','_','|','_','#'},
                      {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}

                        };
    for(int i=0;i<27;i++){
        for(int y=0;y<27;y++){
            if(i%2==0||y%2==0){
                lra[i][y]='+';
            }
            else{
                lra[i][y]=' ';
            }
            printf("%c",lra[i][y]);
        }
        printf("\n");
    }
    return 0;
}