#include<stdio.h>
#include<stdlib.h>
char board[]={'0','1','2','3','4','5','6','7','8','9'};
void printboard()
{
    system("cls");
    printf("\n\n");
    printf("---TIC TAC TOE---\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",board[1],board[2],board[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",board[4],board[5],board[6]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n",board[7],board[8],board[9]);
    printf("   |   |   \n\n");
};
int checkwin()
{
    if(board[1]==board [2] && board[2]==board[3])
    return 1;
    if(board[4]==board [5] && board[5]==board[6])
    return 1;
    if(board[7]==board [8] && board[8]==board[9])
    return 1;
    if(board[1]==board [4] && board[4]==board[7])
    return 1;
    if(board[2]==board [5] && board[5]==board[8])
    return 1;
    if(board[3]==board [6] && board[6]==board[9])
    return 1;
    if(board[1]==board [5] && board[5]==board[9])
    return 1;
    if(board[7]==board [5] && board[5]==board[3])
    return 1;

    int count=0;
    for(int i=1;i<=9;i++)
    {
        if(board[i]=='X' || board[i]=='O')
        count++;
    }
    if(count==9)
    return 2;

    return -1;
};

int main()
{
    int player=1,input,result;
    char mark;
    printboard();
    while(1)
    {
        if(player%2==0)
        {
            player =2;
        }
        else 
        {
            player=1;
        }
        if(player==1)
        {
            mark='X';
        }
        else{
            mark ='O';
        }
        sos:
        printf("\nplayer%d turn :",player);
        scanf("%d",&input);
        if(input>9 || input<1)
        {
            printf("\ninvalid input. try again,\n");
            goto sos;
        }
        if(input>=1 || input<=9)
        {
            if(board[input]=='X' || board[input]=='O')
            {
                 printf("\ninvalid input. try again,\n");
                 goto sos;
            }
        }
        board[input]=mark;
       
        printboard();
        result=checkwin();
        if(result==1)
        {
            printf("player %d is winner",player);
            return 0;
        }
        if(result==2)
        {
            printf("draw");
        }

         player++;
    }

    return 0;
} 