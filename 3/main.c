/*
 * Malka Abramovitch
 * 314723586
 * Dor Shukrun
 * 203841697
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * return the length of given array.
 */
int my_strlen(const char *str) {
    int count = 0;
    int i = 0;
    while (*(str+i) != '\0') {
        count++;
        i++;
    }
    return count;
}


/**
 * A function that receives 2 arrays,
 * and adds the second array to the end of the first.
 * @param dest #first array.
 * @param src #seond array.
 */
void my_strcat(char *dest , const char *src) {
    int lenDest = my_strlen(dest);
    int lenSrc = my_strlen(src);
    for (int i = 0; i <= lenSrc; i++) {
        dest [lenDest + i] = *(src + i);
    }
}

/**
 * A function that accepts a string: s and a string: prefix for search,
 * and returns true if s starts with a prefix.
 * @param s
 * @param prefix
 * @return true/false
 */
bool starts_with(const char *s, const char *prefix) {
    for (int i =0; i < my_strlen(prefix); i++) {
        if (*(s+i) != *(prefix+i))
            return false;
    }
    return true;
}


/**
 * A function that receives a string, and returns the number of words in the string.
 * A word is defined as the longest sequence Of characters that are not white-space,
 * that is, not '\ n' or '\ t' or space.
 * @param st
 * @return count.
 */
int num_words(const char *st) {
    int count =0;
    int i = 0;
    if (my_strlen(st) == 0) {
        return count;
    }
    if (my_strlen(st) == 1 && isspace(*st))
        return count;
    while (*(st + i) != '\0') {
        if(!isspace(*(st + i)) && *(st + i +1) == '\0')
            count++;
        if (isspace(*(st + i)) && isspace(*(st + i + 1)) && isspace(*(st + i - 1)))
            continue;
        if (isspace(*(st + i)) && !isspace(*(st + i -1))) {
            count ++;
        }
        i++;
    }
    return count;
}


/**
 * A function that checks where the string ends and takes down characters that are white-space.
 * @param arr
 */
void cutTheTail(char *arr) {
    int arrLen = my_strlen(arr);
        for (int i = arrLen; i >= 0; i--) {
            if (isalpha(*(arr + i - 1)) || isdigit(*(arr + i - 1)) || *(arr + i - 1) == '-')
                return;
            if (isspace(*(arr + i - 1))) {
                if (!isspace(*(arr + i - 2))) {
                    arr[i - 1] = '\0';
                }
            }
        }
    }


/**
 * Function that replaces ' ' with '-'
 * @param arr
 */
void putHyphenOnIt(char *arr) {
    int i = 0;
    cutTheTail(arr);
    while (*(arr +i) != '\0') {
       if(*(arr + i) == ' ') {
           arr[i] = '-';
       }
       i++;
    }
}


/**
 *A function that receives an s string, a prefix string, and an extension string, and returns a file name.
 * To do this it normalizes s, and attaches it to the beginning before the turn and with the suffix after.
 */
char* get_chapter_file_name(const char *s, const char *prefix, const char *suffix) {
    char *tempS = malloc(my_strlen(s)*sizeof(char));
    if (tempS == NULL) {
        printf("oopsi poopsi... malloc has faild...");
        exit(0);
    }

    for (int i = 0; i < my_strlen(s); i++)
        *(tempS + i) = *(s + i);
    *(tempS + my_strlen(s)) = '\0';

    putHyphenOnIt(tempS);

    int newSizeS = my_strlen(prefix) + my_strlen(tempS) + my_strlen(suffix);
    char *newStr = malloc(newSizeS*sizeof(char));
    if (newStr == NULL) {
        printf("oopsi poopsi... malloc has faild...");
        exit(0);
    }

    for (int i = 0; i < my_strlen(prefix); i++) {
        newStr[i] = prefix[i];
    }

    newStr[my_strlen(prefix)] = '\0';
    my_strcat(newStr, tempS);
    my_strcat(newStr, suffix);
    newStr[newSizeS] = '\0';
    free(tempS);

    return newStr;
}


int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "\n Usage: %s <fileName> [output-suffix]>\n", argv[0]);
        return 0;
    }
    char outputSuffix[] = ".txt";
    if (argc > 3)
        argv[3] = outputSuffix;

    FILE *writeFile;
    FILE *readFile = fopen(argv[1], "r");
    if (readFile == NULL) {


    int charactersCounter = 0, linesCounter = 0, wordsCounter = 0;
    int totalLines = 0, totalWords = 0, totalCharacters = 0;

    char *buf = NULL;
    size_t bufSize = 0;
    char *outputS = "PREFIX";
    char *outFileName = get_chapter_file_name(outputS, argv[2], outputSuffix);
    char chapter[] = "CHAPTER";
    writeFile = fopen(outFileName, "w");
    if (writeFile == NULL) {
        printf("oopsi poopsi file *for writing* opening went wrong");
               exit(0);
    }
    while (getline(&buf, &bufSize, readFile) != EOF) {

        wordsCounter += num_words(buf);
        charactersCounter += my_strlen(buf);
        totalCharacters += my_strlen(buf);
        totalWords += num_words(buf);

        if (starts_with(buf, chapter)) {
            printf("%-30s: %d lines, %d words, %d characters\n",outFileName, linesCounter, wordsCounter, charactersCounter);
            linesCounter = 0;
            wordsCounter = 0;
            charactersCounter = 0;
            fclose(writeFile);
            outFileName = get_chapter_file_name(buf, argv[2], outputSuffix);
            writeFile = fopen(outFileName, "w");
            if (writeFile == NULL) {
                printf("oopsi poopsi file *for writing* opening went wrong");
                exit(0);
            }
        }
        fprintf(writeFile, "%s", buf);

        linesCounter++;
        totalLines++;
    }
    fclose(readFile);
    fclose(writeFile);
    printf("%-30s: %d lines, %d words, %d characters\n", "TOTAL", totalLines, totalWords, totalCharacters);
    free(buf);
    free(outFileName);
    return (0);
}