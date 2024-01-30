#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void play(int bet) 
{
    char *c = (char*)malloc(3 * sizeof(char));
    *c = 'J'; 
    *(c + 1) = 'Q'; 
    *(c + 2) = 'K';

    printf("Suffling...\n");

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = c[x]; 
        c[x] = c[y]; 
        c[y] = temp;
    }

    int playerGuess;
    printf("What's the position of queen - 1, 2, or 3? ");
    scanf("%d", &playerGuess);
    if (c[playerGuess - 1] == 'Q')
    {
        cash += 3 * bet;
        printf("You Win! Result = \"%c%c%c\" Total Cash = %d\n", c[0], c[1], c[2], cash);
    } else
    {
        cash -= bet;
        printf("You Lose! Result = \"%c%c%c\" Total Cash = %d\n", c[0], c[1], c[2], cash);
    }

    free(c);
}

int main()
{
    int bet;

    printf("Welcome to the Virtual Casino\n");
    printf("Total Cash = $%d\n", cash);
    
    while(cash > 0)
    {
        printf("What's your bet? $");
        scanf("%d", &bet);
        if (bet == 0 || bet > cash)
        {
            break;
        }
        play(bet);
        printf("\n***************************************\n");
    }

    return 0;
}
