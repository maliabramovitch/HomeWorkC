/*
 * Name: Malka Abramovitch
 * ID: 314723586
 * Name: Dor Shukrun
 * ID: 203841697
 */

#include <stdio.h>
#include <stdlib.h>


void guessing_game()
    {
    int n, g, c=0;
    n = rand() % 1000 + 1;
    while(g!=n)
    {
        c++;
        printf("Enter a number (1-1000): ");
        scanf("%d", &g);
        if (n>g)
            printf("Nope, too low!\n");
        if (n<g)
            printf("Nope, too high!\n");
        if (g==n)
            printf("Correct, the number is %d! You guessed it right after %d attempts", g, c);
    }
}


void is_arithmetic_progression()
{
    int initi1, fir, sec, gap,count, boo;
    count = 2;
    boo = 1;
    printf ("Enter the first and second items separated by a comma: ");
    if(scanf ("%d, %d", &fir, &sec)!=2)
    {
        printf ("Wrong input! goodbye");
        exit(0);
    }
    initi1 = fir;
    gap = sec-fir;
    fir = sec;
    printf ("What is the next item?");
    while (scanf("%d", &sec) == 1) {
        count++;
        if (sec - fir != gap)
        {
            boo = 0;
        }
        fir = sec;
        printf("What is the next item?");
    }
    if (boo == 1)
        printf("This series of %d items is an arithmetic progression with a1=%d and diff=%d", count, initi1, gap);
    else
        printf("This series of %d items is not an arithmetic progression", count);
}


void ascii_art()
{
    int shap, size, i, j, l, space, k;
    float sizee, shapp ;
    printf("Would you like to draw a square (1) or a diamond (2)? ");
    if (scanf("%f", &shapp) != 1)
        {
        printf("Wrong choice! good bye");
        exit(0);
        }
    shap = shapp;
    if (shapp - shap != 0)
    {
        printf("Wrong choice! good bye");
        exit(0);
    }
    else if (shap == 1)
    {
        printf("What should be the edge size? (1-30): ");
        if(scanf("%f", &sizee)!=1)
        {
            printf("Wrong choice! good bye");
            exit(0);
        }
        size = sizee ;
        if (sizee - size != 0)
        {
            printf("Wrong choice! good bye");
            exit(0);
        }
        else if (size > 30 || size < 1)
        {
            printf("Wrong choice! good bye");
            exit(0);
        }
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    else if (shap == 2)
    {
        printf("What should be the diagonal size? (odd, 1-29): ");
        if(scanf("%f", &sizee)>1)
        {
            printf("Wrong choice! good bye");
            exit(0);
        }
        size = sizee ;
        if (sizee- size != 0)
        {
            printf("Wrong choice! good bye");
            exit(0);
        }
        else if (size%2 == 0 || size>29 || size<1)
        {
            printf("Wrong choice! good bye");
            exit(0);
        }

        space = size/2 ;
        k=1;
        while (k<=size)
        {
            {
                for (l = 0; l < space; l++)
                {
                    printf(" ");
                }
                for (j=0 ; j<k; j++)
                {
                    printf("*");
                }
                k+=2;
                printf("\n");
                space-=1;
            }
        }
        space = 1;
        k= size-2;
        while (k>=1)
        {
            {
                for (l =0; l < space; l++)
                {
                    printf(" ");
                }
                for (j=0 ; j<k; j++)
                {
                    printf("*");
                }
                printf("\n");
                space+=1;
                k-=2;
            }
        }
    }
    else
    {
        printf("Wrong choice! good bye");
        exit(0);
    }
}


int main()
{
    //guessing_game();
    //is_arithmetic_progression();
    ascii_art();
}

