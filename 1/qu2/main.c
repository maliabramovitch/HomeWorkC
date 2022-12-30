#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void is_arithmetic_progression()
    {
    int initi1, initi2, fir, sec, count, boo=0;
    count = 2;
    printf ("Enter the first and second items separated by a comma: ");
    if(scanf ("%d, %d", &initi1, &initi2)!=2)
    {
        printf ("Wrong input! goodbye ");
        exit(0);
    }
    fir = initi1;
    printf ("What is the next item? ");
    while (scanf("%d", &sec) == 1)
        {
        count++;
        if (sec-fir == initi2-initi1)
            boo = 1;
        else
            boo = 0,
        fir = sec;
        printf ("What is the next item? ");
        }
    if (boo == 1)
        printf("This series of %d items is an arithmetic progression with a1=%d and diff=%d", count, initi1, initi2-initi1);
    else
        printf("This series of %d items is not an arithmetic progression", count);
    }

int main() {
    is_arithmetic_progression();
    return 0;
}
