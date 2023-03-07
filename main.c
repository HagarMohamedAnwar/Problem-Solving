//  Hagar Mohamed 20107325 & Mohamed Wael 20107387
//  21/5/2021
//  Project 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void PrintMatrix(char grid[5][5]);
void CheckCoordinates(int PlayerTurn,char grid[5][5]);
void begin();
int Howto();
int CheckWin(char grid[5][5]);
int menu ();

int main()
{
    menu();
    return 0;
}

int Howto(){
    system("cls");
    printf("The game consists of 2 players \n");
    printf ("Player 1 symbol is 'O', Player 2 symbol is '@'\n");
    printf ("To win you have to place 4 symbols vertically, horizontally or diagonally \n");
    printf ("If the grid is full it would be a draw \n");
    printf ("The grid is 5x5 with a cross gap in the middle\n");
    menu();
}

void begin (){
    int wincondition, drawgame = 0;
    char grid[5][5] = {NULL};
    memset(grid, 0 ,sizeof(grid));
    int RoundNumber = 1;
    int PlayerTurn = 1; //Variable that tells which player has the turn
        for(;;)
        {
            system("cls");
            printf("ROUND %d\n\n",RoundNumber);
            PrintMatrix(grid);
            if(PlayerTurn == 1)
            {
                printf("Player 1 Turn, please enter your coordinates as following:x y\n");
                CheckCoordinates(PlayerTurn,grid);
                PlayerTurn = 2;
            }
            else if(PlayerTurn == 2)
            {
                printf("Player's 2 Turn, please enter your coordinates as following:x y\n");
                CheckCoordinates(PlayerTurn,grid);
                PlayerTurn = 1;
                RoundNumber++;
            }
            drawgame++;
            wincondition = CheckWin(grid);
            if (wincondition==1){
                system("cls");
                PrintMatrix(grid);
                printf("Player 1 won!\n");
                menu();
                }
            if (wincondition==2){
                system("cls");
                PrintMatrix(grid);
                printf("Player 2 won!\n");
                menu();
            }
            if (drawgame==16){
                system("cls");
                PrintMatrix(grid);
                printf("\nDraw!\n");
                sleep(2);
                menu();
            }
        }
}

void CheckCoordinates(int PlayerTurn,char grid[5][5])
{
    int x,y; //Coordinates
    for(;;) //Loop to check if coordinates are inside the grid.
    {
        scanf("%d %d",&x,&y);
        if(x < 0 || x >= 5 || y < 0 || y >= 5)
        {
            printf("Wrong Input, please enter your coordinates as following:x y\n");
        }
        else if(x == 2 || y == 2)
        {
            printf("Invalid position\n");
        }
        else if (grid[y][x] != NULL)
            printf("Taken position\n");
        else break;
    }
        if(PlayerTurn == 1)
            grid[y][x] = 'O';
        else if(PlayerTurn == 2)
            grid[y][x] = '@';
}

void PrintMatrix(char grid[5][5])
{
    for(int i= 0; i< 6; i++)
    {
        if(i == 0)
            printf("  ");
        else if(i != 0)
            printf("%d ",i-1);
        for(int j= 0;j < 5;j++)
        {
            if(i == 0)
                printf("%d ",j);
            else if(i == 3 && j == 2)
                printf("+ ");
            else if(i == 3 || j == 2)
                printf("# ");
            else if(grid[i-1][j] == NULL)
                printf("  ");
            else printf("%c ",grid[i-1][j]);
        }
        printf("\n");
    }
}

int CheckWin(char grid[5][5]){
    int count1 , count2;
    for (int i=0; i<5; i++){
        count1 = 0;
        count2 = 0;
        for (int j=0; j<5; j++){
            if (grid[i][j]=='O')
                count1++;
            if (grid[i][j]=='@')
                count2++;
        }
        if( count1 == 4){
            return 1;
        }
        if (count2 == 4){
            return 2;
        }
    }
    for (int i=0; i<5; i++){
        count1 = 0;
        count2 = 0;
        for (int j=0; j<5; j++){
            if (grid[j][i]=='O')
                count1++;
            if (grid[j][i]=='@')
                count2++;
        }
        if( count1 == 4){
            return 1;
        }
        if (count2 == 4){
            return 2;
        }
    }
    count1 = 0;
    count2= 0;
    for (int i=0; i<5; i++){
        if( grid[i][i]=='O')
            count1++;
        if( grid[i][i]=='@')
            count2++;
    }
    if(count1==4)
        return 1;
    if(count2==4)
        return 2;
    count1 = 0;
    count2 = 0;
    for (int i=0; i<5; i++){
        if( grid[i][4-i]=='O')
            count1++;
        if( grid[i][4-i]=='@')
            count2++;
    }
    if(count1==4)
        return 1;
    if(count2==4)
        return 2;
    return 0;
}


int menu (){
    char choose[100];
    int temp;
    for(;;){
    printf("=================================\n");
    printf("To play type 'Begin'\n");
    printf("For instructions type 'Howto'\n");
    printf("To exit type 'Close'\n");
    printf("=================================\n");
    gets(choose);
    temp = strcmp(choose,"");
    if(temp == 0)
        gets(choose);
    temp = strcmp(choose,"Begin");
    if(temp == 0)
    {
        begin();
    }
    temp = strcmp(choose,"Howto");
    if(temp == 0)
    {
        Howto();
    }
    temp = strcmp(choose,"Close");
    if(temp == 0)
    {
        exit(0);
    }
    if(temp != 0)
        printf("Wrong input try again\n");
}
}
