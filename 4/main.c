//
// Malka Abramovitch 314723586
// Dor Shukrun 203841697
//

#include <stdio.h>
#include "Hist.h"
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include "test_hist.h"


/**
 * Duplicate a string.
 * @param str_elem
 * @return
 */
static Element clone_str(Element str_elem) {
    if (!str_elem) return NULL;
    char *p = malloc(strlen(str_elem) + 1);
    strcpy(p, str_elem);
    return p;
}


/**
 * Compares 2 strings
 * @param e1
 * @param e2
 * @return
 */
static bool cmp_str(Element e1, Element e2) {
    if (strcmp(e1, e2) == 0)
        return true;
    return false;
}




/**
 * Reads from a file and returns a linked list.
 * @param fileToRead
 * @return
 */
LinkedList getFromFile(FILE *fileToRead) {
    LinkedList lili = LLCreate(clone_str, free);
    char *buff = NULL;
    size_t buffSize = 0;
    unsigned int index = 0;
    while (getline(&buff, &buffSize, fileToRead) != EOF) {
        LLAdd(lili, index, buff);
        index++;
    }
    free(buff);
    return lili;
}


LinkedList getFromUser() {
    fprintf(stdout, "Please insert Strings to the hist. to brake type 'stop'.\n");
    LinkedList lili = getFromFile(stdin);
    return lili;
}
/**
 * Receives a linked list and hist; and prints to stdout.
 * @param h
 * @param ll
 */
void toSTDOUT(Hist h, LinkedList ll) {
    for (int i = 0; i < LLSize(ll); i++) {
        char *line = LLRemove(ll, i);
        LLAdd(ll, i, line);
        fprintf(stdout, "  %d  %s", HistGetCount(h, line), line);
    }
}

/**
 * Receives a linked list and hist prints to a file.
 * @param h
 * @param ll
 * @param outFile
 */
void toFILE(Hist h, LinkedList ll, FILE *outFile) {
    for (int i = 0; i < LLSize(ll); i++) {
        char *line = LLRemove(ll, i);
        LLAdd(ll, i, line);
        fprintf(outFile, "  %d  %s\n", HistGetCount(h, line), line);
    }
}


/**
 * Receives a linked list. Returns HIST.
 * @param lili
 * @return
 */
Hist FromliliToHist(LinkedList lili) {
    Hist h = HistCreate(clone_str, free, cmp_str);
    for (int i = 0; i < LLSize(lili); i++) {
        Element e = LLRemove(lili, i);
        LLAdd(lili, i, e);
        HistInc(h, e);
    }
    return h;
}


int main(int argc, char *argv[]) {
    FILE *theBeatlesFileIn = fopen(argv[1], "r");
    FILE *theBeatlesFileOut = fopen(argv[2], "w");
    char *hypen = "-";
    if (argc > 3)
        if(theBeatlesFileIn == NULL || theBeatlesFileOut == NULL) {
        fprintf(stderr, "oopsi poopsi Commend Line definition not as expected or the files not opening...\n");
        exit(0);
    }
    LinkedList lili;
    Hist hist;
    if (cmp_str(argv[1], hypen)) {
        lili = getFromUser();
        printf("guy");
        hist = FromliliToHist(lili);

        if (argc == 2 || cmp_str(argv[2], hypen)) {
            toSTDOUT(hist, lili);
        } else {
            toFILE(hist, lili, theBeatlesFileOut);
        }
    } else if (!cmp_str(argv[1], "-")) {
        if (argc == 3 && !cmp_str(argv[2],hypen)) {
            lili = getFromFile(theBeatlesFileIn);
            hist = FromliliToHist(lili);
            toFILE(hist, lili, theBeatlesFileOut);
        } else {
            lili = getFromFile(theBeatlesFileIn);
            hist = FromliliToHist(lili);
            toSTDOUT(hist, lili);
        }
    } else {
        lili = getFromUser();
        hist = FromliliToHist(lili);
        toSTDOUT(hist, lili);
    }
    hist_test();
    fclose(theBeatlesFileOut);
    fclose(theBeatlesFileIn);
    LLDestroy(lili);
    HistDestroy(hist);
    return 0;
}

