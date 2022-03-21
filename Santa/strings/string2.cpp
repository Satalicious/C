

/*
String Functions Implement the following functions:

void str_inverse_case(char str[]);  // "Hello World!" => "hELLO wORLD!"
// Return true if str starts with prefix, otherwise false.
bool str_starts_with(char str[], char prefix[]);
bool str_ends_with(char str[], char suffix[]);  // true if str ends with suffix
int str_count(char str[], char sub[]);  // number of occurences of sub in text
bool str_is_ascii(char str[]);  // true if string only has ascii chars
bool str_is_digit(char str[]);  // true if string only has digits
int str_index(char str[], char sub[]);  // pos. of first occ. of sub in str | -1

Design multiple appropriate test cases (input output combinations) before implementing the above functions. Call the functions from within main(.) to make sure that the test cases pass.
Name the source file: cstring.c 
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void str_inverse_case(char str[]);
bool str_starts_with(char str[], char prefix[]);
bool str_ends_with(char str[], char suffix[]);  // true if str ends with suffix
int str_count(char str[], char sub[]);  // number of occurences of sub in text
bool str_is_ascii(char str[]);  // true if string only has ascii chars
bool str_is_digit(char str[]);  // true if string only has digits
int str_index(char str[], char sub[]);  // pos. of first occ. of sub in str | -1

void str_inverse_case(char str[]){
    for (int i = 0; i < strlen(str); i++){
        if (islower(str[i]))
            toupper(str[i]);
        else
            tolower(str[i]);
    } 
}
bool str_starts_with(char str[], char prefix[]){
    int count = 0;
    for (int i = 0; i < strlen(str); i++){
        for (int j = 0; j < strlen(prefix); j++){
            if (prefix[j] == str[i])
                count+=1;
        }
    }
    if (count == strlen(prefix))
        return true;
    else
        return false;
}

bool str_ends_with(char str[], char suffix[]){
    int count = 0;
    for (int i = 0; i < strlen(str); i++){
        for (int j = 0; j < strlen(suffix); j++){
            
        }
    }
}

int str_count(char str[], char sub[]) {
    int occ = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == sub)
            occ +=1;
    }
    return occ;
}

bool str_is_ascii(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] > 127)
            return false;
        else
            return true;
    }
}

bool str_is_digit(char str[]) {
    int counter = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] <= 57 || str[i] >= 48)
            counter+=1
    }
    if (counter == strlen(str))
        return true;
    else
        return false;
}

int str_index(char str[], char sub[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == sub)
            return i+1
    }
}

int main(){
    str_inverse_case("Hello World!");
    return 0;
}