#include <stdio.h>
#include <stdlib.h>


void guessing_game()
{
    int n, g, c=0;
    n = rand() % 100 + 1;
    while(g!=n)
    {
        c++;
        printf("Enter a number (1-1000): \n");
        scanf("%d", &g);
        if (n>g)
            printf("Nope, too low!\n");
        if (n<g)
            printf("Nope, too high!\n");
        if (g==n)
            printf("Correct, the number is %d You guessed it right after %d attempts", g, c);
    }


}

int main(void)
{
    guessing_game();
}


