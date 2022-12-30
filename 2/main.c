/*
 * Malka Abramovitch
 * 314723586
 */

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * func that checks if two nearby numbers are equals.
 * @param arr - array of int
 * @param size - array's size
 * @return the index of the first number.
 */
int same_value(const int arr[], int size){
    int pair = -1; int i=0;
    while (i < size){
        if (arr[i] == arr[i+1]){
            return  i;
        }
        i++;
    }
    return pair;
}

/**
 * func that counts how many pairs in the array equals to the target.
 * @param arr- array of int
 * @param size -array's size
 * @param target - the sum of the pairs that we are wont.
 * @return - how many pairs exist.
 */
int sum_n(const int arr[] , int size , int target){
    int count = 0;
    for (int i = 0 ; i < size-1 ; i++){
        for (int j= i+1 ; j < size ; j ++){
            if ((arr[i]+arr[j]) == target)
                count++;
        }
    }
    if (count == 0 ) return -1;
    return count;
}

/**
 * func that remove zero's from the array. all the integers placed in the right side of the array, and replaced by zeros.
 * @param arr- array of int
 * @param size -array's size
 * @return - array's size after the change. (how many ints).
 */
int reduce(int arr[], int size){
    int count = 0;
    int j = 0;
    for (int i=0; i<size; i++)
        if (arr[i] == 0)
            count ++;
    for (int i=0; i<size; i++)
        if (arr[i] != 0){
            arr[j] = arr [i];
            if (i != j)
                arr[i] = 0;
            j++;
        }
    return size - count;
    }

/**
 * func that checks if array of chars is a valid E-mail address.
 * @param email
 * @return True / False.
 */
bool is_legal_email(const char email[]) {
    int countAll = 0; // count's the length of the e-mail address.
    int countShtrudel = 0; //count's '@'.
    int countDot = 0; //count's '.' after '@';
    int shtrudelIndex = 0; // The index of '@'.
    int i = 0;
    while (email[i] != '\0') {
        if (email[0] == '@') {
            return false;
        }
        if (email[i] == '@') {
            shtrudelIndex = i;
            break;
        }
        i++;
    }
    i=0;
    while (email[i] != '\0') {
        if (countAll > 20) {
            return false;
        }
        countAll++;
        if (i < shtrudelIndex && !(isalpha(email[i]) || isdigit(email[i]))) {
                return false;
            }
        if (email[i] == '@') {
            countShtrudel++;
            shtrudelIndex = i;
        }
        if (shtrudelIndex != 0 && countShtrudel > 1) {
            return false;
        }
        if (i > shtrudelIndex) {
            if (email[i] == '.'){
                countDot++;
            }
            if (!(isalpha(email[i])) && email[i] != '.' ) {
                return false;
            }
        }

        i++;
    }
    if (countDot == 0 || countShtrudel ==0) return false;
    return true;
}

/**
 * func that compares between the E-mail addresses, and checks if they are the same.
 * @param email1
 * @param email2
 * @return true / false.
 */
bool is_same_email(char email1[], char email2[]){
    if (is_legal_email(email1) && is_legal_email(email2)) {
        int i = 0;
        int countEmail1=0, countEmail2=0;
        while (email1[i] != '\0') {
            countEmail1 ++;
            if (isalpha(email1[i]))
                if (isupper(email1[i])) {
                    char c = tolower(email1[i]);
                    email1[i] = c;
                }
            i ++;
        }
        i=0;
        while (email2[i] != '\0') {
            countEmail2 ++;
            if (isalpha(email2[i]))
                if (isupper(email2[i])) {
                    char c = tolower(email2[i]);

                    email2[i] = c;
                }
            i ++;
        }
        if (countEmail1 != countEmail2) {
            return false;
        }

        for (i=0 ; i<countEmail1 ; i++)
            if (email1[i] != email2[i]) {
                return false;
            }

        return true;
    }
}


int main() {
    int arr1[] = {1,2,0,3,0,0,5,0,7,0,0};
    assert(same_value(arr1, 11)==4);
    printf("PASS\n");

    int arr2[] = {1,2,0,3,0,0,5,0,7,0,0};
    assert(sum_n(arr2, 11, 5)==7);
    printf("PASS\n");

    int arr3[] = {1,0,0,3,0,0,0,0,7,0,8};
    assert(reduce(arr3,11 )==4);
    printf("PASS\n");

    char arr4[] = "malI@gmail.com";
    assert(is_legal_email(arr4)==1);
    printf("PASS\n");

    char arr5[] = "@gmail.com";
    assert(is_legal_email(arr5) == 0);
    printf("PASS\n");

    char arr6[] = "mali@@gmail.com";
    assert(is_legal_email(arr6) == 0);
    printf("PASS\n");

    char arr7[] = "maligmail.com";
    assert(is_legal_email(arr7) == 0);
    printf("PASS\n");

    char arr8[] = "mali@gmailcom";
    assert(is_legal_email(arr8) == 0);
    printf("PASS\n");

    char arr9[] = "maligmail.c8om";
    assert(is_legal_email(arr9) == 0);
    printf("PASS\n");

    char arr10[] = "maligmail.com";
    char arr11[] = "maligmail.com";
    assert(is_same_email(arr10, arr11) == 0);
    printf("PASS\n");

    char arr12[] = "mali@gmail.com";
    char arr13[] = "mali@gmail.com";
    assert(is_same_email(arr12, arr13) == 1);
    printf("PASS\n");

    char arr14[] = "MALI@gmail.com";
    char arr15[] = "mali@Gmail.coM";
    assert(is_same_email(arr14, arr15) == 1);
    printf("PASS\n");
}
