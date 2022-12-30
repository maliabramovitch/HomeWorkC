#include <ctype.h>
#include <stdio.h>
//
// Created by Mali Abramovitch on 09/04/2022.
//
int my_strlen(const char *str) {
    int count = 0;
    int i = 0;
    while (*(str+i) != '\0') {
        count++;
        i++;
    }
    return count;
}


int num_words(const char *st) {
    int count =0;
    int i = 0;
    if (my_strlen(st) == 0) {
        return count;
    }
    while (*(st + i) != '\0') {
        if(!isspace(*(st + i)) && *(st + i +1) == '\0')
            count++;
        if (isspace(*(st + i)) && !isspace(*(st + i -1))) {
            count ++;
        }
        i++;
    }
    return count;
}

int main(){
    char arr[] = "Printed in Great Britain by T. and A. CONSTABLE LTD             \n at the Edinburgh University Press         \n        \n";
    printf("%d", num_words(arr));
    return 0;
}