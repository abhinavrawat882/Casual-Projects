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

//***********************
//diceroler Discription//
//***********************
// well this function simply rolls the dice
// it needs to make sure that when it roles dice it should do it in a manner so that no two buttons of same colour should overlap

int diceroler(int playerId)
{ // below discription is how to implement that above goal.

    //declaring this array does help us keep track of how many of these no's are usable.
    int diceNo[6] = {1, 2, 3, 4, 5, 6};
    int buttonsRemaining = 6;

    //first comes the elemination process in which we will eliminate all the possible outcomes that will cause an overlap
    //it will go button by button and thenmake them move using btmover projection mode that will return the position of the dice after a move
    // then we will compare it to the position of other buttons...
    // if an overlapting is found the move will be eliminated
    for (int btNo = 0; btNo < 3; btNo++)
    {
        for (int step = 0; step < 6; step++)
        {
            if (diceNo[step] != 0)
            {
                int pos = btmover(playerId, btNo, step + 1, 1);
                if (pos != 0 && pos != 6 && pos != 11 && pos != 17 && pos != 22 && pos != 28 && pos != 33 && pos != 39)
                {
                    for (int tbt = btNo + 1; tbt < 4; tbt++)
                    {
                        if (pos == bt[tbt][playerId][0])
                        {
                            diceNo[step] = 0;
                            buttonsRemaining--;
                            break;
                        }
                    }
                }
            }
        }
    }
    int num = (rand() % (buttonsRemaining - 1 + 1)) + 1; // this will get is a random value
    int temp = 0;
    for (int i = 0; i < 6; i++)
    {
        if (diceNo[i] != 0)
        {

            if (++temp == num)
            {
                return diceNo[i];
            }
        }
    }
    return 6;
}

//*******************
//btmover DISCRIPTION
//*******************
//it's task is to move a button
// there are 2 modes to this fuction
// mode ==1 means move the button
// mode ==2 means project the position of button after moving

//RETURN POLICY:
//
int btmover(int playerId, int ButtonIdentifier, int nom, int mode)
{
    if (bt[ButtonIdentifier][playerId][1] != 2)
    {

        int pos = bt[ButtonIdentifier][playerId][0];
        if (pos < 0)
        {
            if (nom == 6)
            {
                bt[ButtonIdentifier][playerId][0] = bset[playerId][0];
                bset[playerId][3] -= 1;
                return 0;
            }

            return -1;
        }

        else if (pos >= 100)
        {
            pos += nom;
            if (pos > 105)
            {
                return -1;
            }

            bt[ButtonIdentifier][playerId][0] += nom;
            if (pos == 105)
            {
                bset[playerId][2] += 1;
                return 2;
            }

            return 0;
        }
        else
        {
            int x = pos + nom;
            if (x > bset[playerId][1])
            {
                pos = x - bset[playerId][1];
                if (pos == 6)
                {
                    return -1;
                }
                bt[ButtonIdentifier][playerId][0] = 100 + pos;
                if (pos == 5)
                {
                    bset[playerId][2] += 1;
                    return 2;
                }
                return 0;
            }
            bt[ButtonIdentifier][playerId][0] += nom;
            if (bt[ButtonIdentifier][playerId][0] >= 45)
            {
                bt[ButtonIdentifier][playerId][0] -= 45;
            }
            if (x != 0 && x != 6 && x != 11 && x != 17 && x != 22 && x != 28 && x != 33 && x != 39)
            {
                for (int checkplayer = 0; checkplayer < 4; checkplayer++)
                {
                    if (checkplayer != playerId)
                    {

                        for (int justA = 0; justA < 4; justA++)
                        {
                            if (bt[justA][checkplayer][0] == bt[ButtonIdentifier][playerId][0])
                            {
                                bt[justA][checkplayer][0] = -1;
                                bset[checkplayer][3] += 1;
                                return 2;
                            }
                        }
                    }
                }
            }
            return 1;
        }
    }

    return -1;
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

int checkCurrent(int playerId, int nom)
{
    int noOfButtonsThatMove = 0;
    int lastButtonIdentifier = 0;

    //if((buttonIsNotOpen && nom==6)||(buttonIsOpen && buttonPosition+nom<buttonEnd+5)){

    //button 1
    if (((bt[0][playerId][1] == -1 && nom == 6) || (bt[0][playerId][1] == 1 && bt[0][playerId][0] + nom <= bset[playerId][1] + 5)))
    {
        noOfButtonsThatMove++;
        lastButtonIdentifier = 0;
    }

    //button 2
    if ((bt[1][playerId][1] == -1 && nom == 6) || (bt[1][playerId][1] == 1 && bt[1][playerId][0] + nom <= bset[playerId][1] + 5))
    {
        noOfButtonsThatMove++;
        lastButtonIdentifier = 1;
    }

    //button 3
    if ((bt[2][playerId][1] == -1 && nom == 6) || (bt[2][playerId][1] == 1 && bt[2][playerId][0] + nom <= bset[playerId][1] + 5))
    {
        noOfButtonsThatMove++;
        lastButtonIdentifier = 2;
    }

    //button 4
    if ((bt[3][playerId][1] == -1 && nom == 6) || (bt[3][playerId][1] == 1 && bt[3][playerId][0] + nom <= bset[playerId][1] + 5))
    {
        noOfButtonsThatMove++;
        lastButtonIdentifier = 3;
    }

    //check how many buttons are movable

    if (noOfButtonsThatMove == 0)
    {
        return -1;
    }
    else if (noOfButtonsThatMove == 1)
    {
        int isCut = btmover(playerId, lastButtonIdentifier, nom, 1); //make this function
        if (isCut == 1)
        {
            return 2;
        }
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}

void intermediator(int i, int nom)
{
    int availableMoves = 0;
    if (nom == 6)
    {
        availableMoves = 1;
    }

    while (1 == 1)
    {
        int availableMoves = 0;
        if (nom)

            while (1 == 1)
            {
                char cmd = 'd';
                printf("%s :/ ", pn[i]);
                scanf("%c", &cmd);
                switch (cmd)
                {
                case 'd':
                    //if(end->move_value==6){

                    nom += diceroler(i);
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
                    intermediator(i, nom);
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