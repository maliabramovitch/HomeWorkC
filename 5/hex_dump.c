// Malka Abramovitch 314723586
// Dor Shukrun 203841697

#include <stdio.h>
#include <stdlib.h>
#define MAGIC 0x0087008700870087ll

/**
 * creats and prints the offset format.
 * @param c
 */
void printOffset(int c) {
    printf("\n%08x ", c);
}

/**
 * Prints the text as Shlomo requested.
 * @param fileToRead
 */
void hexDump(const char* fileToRead) {
    int count = 0;
    FILE *f = fopen(fileToRead, "rb");
    if (!f) {
        fprintf(stderr, "oopsi poopsi The file did not open... Darn!");
        exit(0);
    }
    int first, second, gc;
    while(1){
        gc = fgetc(f);
        if (count % 16 == 0) {
            printOffset(count);
        }
        count += 2;
        first = gc;
        second = fgetc(f);
        if (first == EOF) {
            if (((count-2) % 16) != 0)
                printOffset(count - 2);
            break;
        }
        if (second == EOF) {
            printf("%04x", first);
            if ((count % 16) != 0)
                printOffset(count - 1);
            break;
        }
        printf("%02x%02x ", second, first);
    }
    fclose(f);
}


int main(int argc, char *argv[]) {
        hexDump(argv[3]);
    return 0;
}










