// Malka Abramovitch 314723586
// Dor Shukrun 203841697
#include <stdio.h>
#include <stdlib.h>

#define MAGIC 0x0087008700870087ll


/**
 * The function reads a compressed binary file in 8to7 format, and unzips it in 7to8 format and writes it to a file.
 * @param inputFile
 * @param outputFile
 */
void uncompress8to7(FILE *inputFile, FILE *outputFile) {
    FILE *read = fopen((const char *) inputFile, "r");
    if (!read) {
        fprintf(stderr, "oopsi poopsi The file did not open... Darn!");
        exit(-1);
    }
    FILE *write = fopen((const char *) outputFile, "wb");
    if (!write) {
        fprintf(stderr, "oopsi poopsi The file did not open... Darn!");
        exit(0);
    }
    uint64_t magic, fileSize;
    int actualSize = 0;
    fread(&magic, sizeof(magic), 1, read);
    fread(&fileSize, sizeof(fileSize), 1, read);
    if (magic != MAGIC) {
        fprintf(stderr, "Ooopsi Poopsi, the format of the file is invalid");
        exit(0);
    }
    int saveSecondBits = 0;
    int count = 0;
    int toFile;
    int gc;
    while (fileSize != 0) {
        gc = fgetc(read);
        if (gc == EOF) {
            actualSize++;
            fputc(saveSecondBits, write);
            break;
        }
        if (count % 7 == 0 && count > 0) {
            actualSize++;
            fputc(saveSecondBits, write);
            count = 0;
            saveSecondBits = 0;
        }
        toFile = (gc << count);
        toFile |= saveSecondBits;
        toFile &= 127;
        actualSize++;
        fputc(toFile, write);
        saveSecondBits = gc >> (7 - count);
        count++;
    }
    fclose(read);
    fclose(write);
    if (actualSize != fileSize) {
        fprintf(stderr, "Ooopsi Poopsi, the file size doe's not match to the actual size\n");
        exit(-1);
    }
}


/*int main(int argc, char *argv[]) {
    uncompress8to7(argv[2], argv[3]);
}*/
