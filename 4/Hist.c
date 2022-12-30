//
// Malka Abramovitch 314723586
// Dor Shukrun 203841697
//

#include "Hist.h"
#include <stdbool.h>
#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>


/**
 * clone func for int.
 * @param int_elem
 * @return
 */
/**
 *
 * @param int_elem
 * @return
 */
static Element clone_int(Element int_elem) {
    if (!int_elem) return NULL;
    int *p = malloc(sizeof(int));
    *p = *((int*)int_elem);
    return p;
}

struct Hist {
    LinkedList lilElement;
    LinkedList lilTimes; //int
    Element (*clone_func)(Element);

    void (*free_func)(Element);

    bool (*cmp_func)(Element, Element);
};

// Create a new histogram object, with element manipulation functions:
// clone_func - return a pointer to the cloned element.
// free_func - free an element returned by clone_func
// cmp_func - return true if the two elements are equal
Hist HistCreate(Element (*clone_func)(Element), void (*free_func)(Element), bool (*cmp_func)(Element, Element)) {
    Hist hist = (Hist) malloc(sizeof(struct Hist));
    hist->lilElement = LLCreate(clone_func, free_func);
    hist->lilTimes = LLCreate((Element (*)(Element)) clone_int, free);
    hist->free_func = free_func;
    hist->clone_func = clone_func;
    hist->cmp_func = cmp_func;
    return hist;
}


// Destroy a histogram object (along with all its elements)
void HistDestroy(Hist hist) {
    LLDestroy(hist->lilElement);
    LLDestroy(hist->lilTimes);
    hist->free_func(hist);

}


// Return the number of elements in the hist object
unsigned int HistSize(Hist hist) {
    return LLSize(hist->lilElement);
}


// Get the count of element e. If e is not in hist, returns 0.
int HistGetCount(Hist hist, Element e) {
    unsigned int index = 0;
    unsigned int size = HistSize(hist);
    if (size == 0)
        return 0;
    for (int i = 0; i <= size; i++) {
        Element element = LLRemove(hist->lilElement, index);
        LLAdd(hist->lilElement, index, element);
        if (hist->cmp_func(e, element)) {
            int *repetitionsCount = LLRemove(hist->lilTimes, index);
            LLAdd(hist->lilTimes, index, repetitionsCount);
            return *repetitionsCount;
        }
        index++;
    }
    if (size == index) {
        return 0;
    }
    return 0;
}


// Increment the count of e by one.
// If e is not in hist, create a new entry with a clone of e and a count of 1.
void HistInc(Hist hist, Element e) {
    unsigned int index = 0;
    unsigned int size = HistSize(hist);
    if (size == 0) {
        LLAdd(hist->lilElement, 0, hist->clone_func(e));

        int time = 1;
        LLAdd(hist->lilTimes, 0, &time);
        return;
    } else {
        for (int i = 0; i <= size; i++) {
            Element element = hist->clone_func(LLRemove(hist->lilElement, index));
            LLAdd(hist->lilElement, index, element);
            if (hist->cmp_func(e, element)) {
                break;
            }
            index = i;
        }
        if (index == size) {
            LLAdd(hist->lilElement, size, e);
            int time = 1;
            LLAdd(hist->lilTimes, size, &time);
        } else {
            int time = 1 + *(int*) LLRemove(hist->lilTimes, index);
            LLAdd(hist->lilTimes, index,  &time);
        }
    }
}


// Gets (a clone of) the element at given index.
// If index<0 or index >= HistSize(hist) then NULL is returned.
Element HistGetElement(Hist hist, unsigned int index) {
    if (index < 0 || index >= HistSize(hist)) {
        return NULL;
    }
    Element e = LLRemove(hist->lilElement, index);
    LLAdd(hist->lilElement, index, e);
    return hist->clone_func(e);
}

