//
// Malka Abramovitch 314723586
// Dor Shukrun 203841697
//
#include "Hist.h"
#include "test_hist.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>


static Element clone_str(Element str_elem) {
    if (!str_elem) return NULL;
    char *p = malloc(strlen(str_elem)+1);
    strcpy(p, str_elem);
    return p;
}

static bool cmp_str(Element e1, Element e2) {
    if (strcmp(e1, e2) == 0)
        return true;
    return false;
}


static bool test_str_at_index(Hist hist, int index, const char *ref) {
    char *cur = HistGetElement(hist,index);
    if (!cur || strcmp(cur,ref) != 0) return false;
    free(cur);
    return true;
}



void hist_test() {
    Hist hist = HistCreate(clone_str, free, cmp_str);
    HistInc(hist, "abc");// abc
    HistInc(hist, "d");// d abc
    HistInc(hist, "ef");// ef d abc
    HistInc(hist, "ghi");// ghi ef d abc
    HistInc(hist, "ghi");// doubleInc ---> to check repetitionsCounter
    assert(HistSize(hist) == 4);
    printf("HistSize: PASS\n");

    assert(HistGetCount(hist,"abc") == 1);
    assert(HistGetCount(hist,"d") == 1);
    assert(HistGetCount(hist,"ef") == 1);
    assert(HistGetCount(hist,"ghi") == 2);
    printf("HistGetCount: PASS\n");

    assert(test_str_at_index(hist, 0, "abc") );
    assert( test_str_at_index(hist, 1, "d") );
    assert( test_str_at_index(hist, 2, "ef") );
    assert( test_str_at_index(hist, 3, "ghi") );
    printf("HistGetElement: PASSED\n");

    HistDestroy(hist);
    printf("HistTest passed successfully\n");
}




