#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char pn[4][10];
//these variables will stores the names of players
// 0 will represent blue colour
// 1 will represent red colour
// 2 will represent yellow colour
// 3 will represent green colour

int bt[4][4][2];
// bt[diceIndiator][ColourIndicator][property]
// property=0 will tell the index of the path which will tell the location of player button on screen
// property=1 will tell wheater the button is even open closed or has
// -1 is not opened
// 1 means opened
// 2 means win

int bset[4][4];
// bset sands for button start end index
// so the first index will tell the the colour
// second index will tell start and end points of that colour respectively and it will also tell that the no of buttons opened and no of button won

int nop;
int diceroler(int i)
{
    int diceNo[6] = {1, 2, 3, 4, 5, 6};

    for (int btNo = 0; btNo < 4; btNo++)
    {
        for (int step = 1; step <= 6; step++)
        {
            int position = bt[btNo][i][0] + step;
            if (position > bset[i][1])
            {
                break;
            }
            else if (position != sp1 && position != sp2 && position != sp3 && position != sp4 && position != sp5 && position != 6 && position != sp7 && position != sp8)
            {
                // fill in the values of sp(safe spots) later
                for (int tbtNo = 0; tbtNo < 4; tbtNo++)
                {
                    if (btNo != tbtNo && position == [tbtNo][i][0])
                    {
                        diceNo[step - 1] = 0;
                        break;
                    }
                }
            }
        }
    }

    return 6;
}



void btmover(int playerId,int lastButtonIdentifier,int nom){

}

///checkCurrent Discriptionne 
    //this function does 2 things
    //check how many players can move
        //if none can move it will return -1 indicating to skip the player
        //if only one can move function will automatically move the player
            // if tht moved button cuts another button or wins then extra dice roll is awarded
            // it returns 0 for moved chance 
            // 2 for extra dice roll
        // if many buttons can move then 1 is returned so that player can choose which button to move
        

int checkCurrent(int playerId,int nom){
    int noOfButtonsThatMove=0;
    int lastButtonIdentifier=0;
        
        //if((buttonIsNotOpen && nom==6)||(buttonIsOpen && buttonPosition+nom<buttonEnd+5)){
        
        //button 1
        if((bt[0][playerId][1]==-1&& nom==6)||(bt[0][playerId][1]==1 && bt[0][playerId][0]+nom<=bset[playerId][1]+5)){

            noOfButtonsThatMove++;
            lastButtonIdentifier=0;
        }

        //button 2
        if((bt[1][playerId][1]==-1&& nom==6)||(bt[1][playerId][1]==1 && bt[1][playerId][0]+nom<=bset[playerId][1]+5)){
            noOfButtonsThatMove++;
            lastButtonIdentifier=1;
        }

        //button 3
        if((bt[2][playerId][1]==-1&& nom==6)||(bt[2][playerId][1]==1 && bt[2][playerId][0]+nom<=bset[playerId][1]+5)){
            noOfButtonsThatMove++;
            lastButtonIdentifier=2;
        }

        //button 4
        if((bt[3][playerId][1]==-1&& nom==6)||(bt[3][playerId][1]==1 && bt[3][playerId][0]+nom<=bset[playerId][1]+5)){
            noOfButtonsThatMove++;
            lastButtonIdentifier=3;
        }
        
        //check how many buttons are movable
        
        if(noOfButtonsThatMove==0){
            return -1;
        }
        else if(noOfButtonsThatMove==1){
            isCut=btmover(playerId,lastButtonIdentifier,nom);//make this function
            if(isCut==1){
                return 2;
            }
            return 0;
        }
        else{
            return 1;
        }
        

            
}


void diceMover(int i, int nom)
{  // struct node{
   //     int move_value;
   //     struct node* next;
   // };

    //struct node* head=(struct node*)malloc(sizeof(struct node));
    //head->move_value=nom;
   // head->next=NULL;
    //struct node* end=head;
    int availableMoves=0;
    if(nom==6){
        availableMoves=1;
    }
    
    while (1 == 1)
    {   int availableMoves=0;
        if(nom)
        char cmd;
        while (1 == 1)
        {   printf("%s :/ ", pn[i]);
            scanf("%c", &cmd);
            switch (cmd){
                case 'd':
                    //if(end->move_value==6){
                    
                    nom+=diceroler(i);
                        


                    
            }
        }
    }
}
void gamerunner()
{
    int win = 0;
    while (win != nop - 1)
    {

        for (int i = 0; i < nop; i++)
        {
            if (bset[i][3] == 4)
            {
                int nom = 0;
                char ch;
                printf("%s enter d to roll dice");
                nom = diceroler(i); // make this function later
                if (nom != -1)
                {
                    diceMover(i, nom);
                }
            }
        }
    }
}
int main()
{

    printf("Enter the no of players playing: ");
    while (1 == 1)
    {
        scanf("%d", &nop);
        if (nop == 0)
        {
            printf("No of players can not be one");
            continue;
        }
        break;
    }
    for (int i = 0; i < nop; i++)
    {
        printf("Colour Picker");
        printf("Enter name of player %d : ", i);
        //char tempname[10];
        scanf("%s", &pn[i]); // this might give error
        //printf("%s pic a colour from following");
        bset[i][2] = 1;
    }
    for (int i = nop; i < 4; i++)
    {
        bset[i][2] = 0;
    }
    // the main game initalization part is over
    // so now the game cuntrol will be given to game runner
    gamerunner();

    return 0;
}