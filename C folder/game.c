#include <stdio.h>
#include <stdlib.h>
char board[]={'0','1','2','3','4','5','6','7','8','9'};
void printBoard();
int checkWin();

int main(){
    int player=1,input;
    char mark;
    printBoard();

    while (1)
    {
        // player=(player%2==0) ? 2 : 1;
        if(player%2==0)
        {
            player=2;
        }
        else
        {
            player=1;
        }
        // mark=(player==1) ? 'X' :'O';
        if(player==1)
        {
            mark='X';
        }
        else
        {
            mark='O';
        }
        sos:
        printf("\nPlayer%d turn:",player);
        scanf("%d",&input);
    if(input<1 || input>9)
    {
        printf("invalid input");
        goto sos;
    }
    if(input>=1 || input<=9)
    {
        if(board[input]=='X' || board[input]=='O')
        {
            printf("invalid input, try again");
            goto sos;
        }
    }
    board[input]=mark;
    printBoard();

    int result=checkWin();

    if(result==1){
        printf("Player %d is the Winner",player);
        return 0;
    }else if(result==2){
        printf("draw");
        return 0;
    }

    player++;
    }

return 0;
}

void printBoard(){
    system("cls");
    printf("\n\n");
    printf("=== TIC TAC TOE ===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
    printf("     |     |     \n");
    printf("\n\n");
}

int checkWin(){

    if(board[1]==board[2] && board[2]==board[3]){
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7]){
        return 1;
    }
    if(board[7]==board[8] && board[8]==board[9]){
        return 1;
    }
    if(board[3]==board[6] && board[6]==board[9]){
        return 1;
    }
    if(board[1]==board[5] && board[5]==board[9]){
        return 1;
    }
    if(board[3]==board[5] && board[5]==board[7]){
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8]){
        return 1;
    }
    if(board[4]==board[5] && board[5]==board[6]){
        return 1;
    }

    int count=0;
    for (int i = 1; i <=9; i++)
    {
        if(board[i]=='X' || board[i]=='O'){
            count++;
        }
    }

    if(count==9){
        return 2;
    }
    return -1;
}