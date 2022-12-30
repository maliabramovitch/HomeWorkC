#include <stdio.h>
#include <stdlib.h>

void ascii_art()
    {
    int shap, size, i, j, l, space, k;
    float sizee, shapp ;
    printf("Would you like to draw a square (1) or a diamond (2)? ");
    scanf("%f", &shapp);
    shap = shapp;
    if (shapp - shap != 0)
    {
        printf("Wrong choice! good bye, %f, %d", shapp, shap);
        exit(0);
    }
    else if (shap == 1)
    {
        printf("What should be the edge size? (1-30): ");
        scanf("%f", &sizee);
        size = sizee ;
        if (sizee- size != 0)
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
        scanf("%f", &sizee);
        size = sizee ;
        if (sizee- size != 0)
        {
            printf("Wrong choice! good bye", shapp, shap);
            exit(0);
        }
        else if (size%2 == 0)
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
        //printf("%d,%d \n", space, k);
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

void check()
{

    float f;
    int n;
    scanf("%f", &n);
    n = f;
    printf("%d, %d", n ,f);
}

int main()
{
    ascii_art();
    //check();
}

