// Malka Abramovitch 314723586
// Dor Shukrun 203841697

#include <stdio.h>
#include <stdlib.h>

#define MAGIC 0x0087008700870087ll

/**
 * The function reads a binary file, compresses it according to the 8to7 format and writes it to a file.
 * @param fileToRead
 * @param fileToWrite
 */
void compress8to7(const char *fileToRead, const char *fileToWrite) {
    FILE *readFile = fopen(fileToRead, "r");
    if (!readFile) {
        fprintf(stderr, "oopsi poopsi The file did not open... Darn!");
        exit(0);
    }
    FILE *writeFile = fopen(fileToWrite, "wb");
    if (!writeFile) {
        fprintf(stderr, "oopsi poopsi The file did not open... Darn!");
        exit(0);
    }
    fseek(readFile, 0, SEEK_END);
    uint64_t byteNum = ftell(readFile);
    uint64_t magic = MAGIC;
    fclose(readFile);
    readFile = fopen(fileToRead, "r");
    if (!readFile) {
        fprintf(stderr, "oopsi poopsi The file did not open... Darn!");
        exit(0);
    }
    fwrite(&magic, sizeof(magic), 1, writeFile);
    fseek(writeFile, 64 / 8, SEEK_SET);
    fwrite(&byteNum, sizeof(byteNum), 1, writeFile);
    int first = fgetc(readFile);
    int second = fgetc(readFile);
    int count = 0;
    int mask, toWrite;
    while (1) {
        if (first > 127 || second > 127) {
            fprintf(stderr, "Oopsi Poopsi... your input is larger than 127");
        }
        if (second == EOF) {
            if (first != EOF) {
                toWrite = first >> count;
                fputc(toWrite , writeFile);
                break;
            } else {
                break;
            }
        }
        first = first >> count;
        mask = second << (7 - count);
        toWrite = first | mask;
        fputc(toWrite, writeFile);
        first = second;
        second = fgetc(readFile);
        count++;
        if (count == 7) {
            count = 0;
            first = second;
            second = fgetc(readFile);
        }
    }
    fclose(readFile);
    fclose(writeFile);
}


/*int main(int argc, char *argv[]) {
    compress8to7(argv[1], argv[2]);
}*/
