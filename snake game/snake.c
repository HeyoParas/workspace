#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define HEIGHT 40
#define WIDTH 20

int x, y, fruitX, fruitY, score, gameover, flag, level;
int tailX[100], tailY[100];
int countTail;

void draw()
{
    int i, j, k;
    system("cls");
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            if (i == 0 || j == 0 || i == WIDTH - 1 || j == HEIGHT - 1)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("O");
                }
                else if (i == fruitX && j == fruitY)
                {
                    printf("@");
                }
                else
                {
                    if (level > 1)
                    {
                        int x = 0;
                        for (k = 0; k < countTail; k++)
                        {
                            if (i == tailX[k] && j == tailY[k])
                            {
                                printf("o");
                                x = 1;
                            }
                        }
                        if (x == 0)
                            printf(" ");
                    }
                    else
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("level: %d\n", level);
    printf("score: %d\n", score);
    printf("FOR EXIT THE GAME ANY TIME PRESS P KEY");
}

void setup()
{
    x = WIDTH / 2;
    y = HEIGHT / 2;

    do
    {
    fruitX = rand() % WIDTH;
    } while (fruitX == 0);

    do
    {
    fruitY = rand() % HEIGHT;
    } while (fruitY == 0);

    score = 0;
    gameover = 0;
    level = 1;
}

void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag= 1;
            break;
        case 's':
            flag= 2;
            break;
        case 'w':
            flag= 3;
            break;
        case 'd':
            flag= 4;
            break;
        case 'p':
            gameover = 1;
            break;
        }
    }
}

int logic(int speed)
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int tempX, tempY;
    int i;
    tailX[0] = x;
    tailY[0] = y;

    for (i = 1; i < countTail; i++)
    {
        tempX = tailX[i];
        tempY = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        x--;
        break;
    case 4:
        y++;
        break;
    }
    if (score <= 9)
    {
        level = 1;
        speed = 100;
    }
    if (score == 10)
    {
        level = 2;
        speed = 70;
    }
    if (score == 20)
    {
        level = 3;
        speed = 40;
    }
    if (level == 1 || level == 2)
    {
        if (x == 0)
            x = WIDTH - 1;
        else if (x == WIDTH - 1)
            x = 1;
        else if (y == 0)
            y = HEIGHT - 1;
        else if (y == HEIGHT - 1)
            y = 1;
    }
    if ((x == 0 || x == WIDTH || y == 0 || y == HEIGHT) && level == 3)
    {
        gameover = 1;
    }
    if (level == 3)
    {
            for(int i=1;i<countTail;i++)
            {
                if(x==tailX[i] && y==tailY[i])
                gameover=1;
            }   
    }
    if (x == fruitX && y == fruitY)
    {
        do
        {
            fruitX = rand() % WIDTH;
        } while (fruitX == 0);

        do
        {
            fruitY = rand() % HEIGHT;
        } while (fruitY == 0);

        score += 2;
        if (level == 2 || level == 3)
            countTail++;
    }
    return speed;
}

int main()
{
    int speed;
    char ch;
sos:
    setup();
    while (!gameover)
    {
        draw();
        input();
        speed = logic(speed);
        Sleep(speed);
    }
    printf("\n enter Y for play again:");
    scanf("%c", &ch);
    if (ch == 'y')
        goto sos;
    return 0;
}
