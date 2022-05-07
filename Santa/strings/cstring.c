
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void str_inverse_case(char str[]);
bool str_starts_with(char str[], char prefix[]); // Return true if str starts with prefix, otherwise false.
bool str_ends_with(char str[], char suffix[]);  // true if str ends with suffix
int str_count(char str[], char sub[]);  // number of occurences of sub in text
bool str_is_ascii(char str[]);  // true if string only has ascii chars
bool str_is_digit(char str[]);  // true if string only has digits
int str_index(char str[], char sub[]);  // pos. of first occ. of sub in str | -1

void str_inverse_case(char str[]){
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == 32){
            printf("%c", str[i]);
            i++;
        }
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
            printf("%c",str[i]);
        } else {
            str[i] = tolower(str[i]);
            printf("%c",str[i]);
        } 
    }
    printf("\n");
}

bool str_starts_with(char str[], char prefix[]) {
    bool isPrefix = false;
    for (int i = 0; i < strlen(prefix); i++) {
	    if (str[i] == prefix[i])
            isPrefix = true;
        else {
            isPrefix = false;
            break;
        }
    }
    return isPrefix;
}

bool str_ends_with(char str[], char suffix[]) {
    int cnt = 0;
    for (int i = strlen(str)-strlen(suffix); i < strlen(str); i++) {  
        for (int j = 0; j < strlen(suffix); j++) {
            if (str[i+j] == suffix[j])
                cnt++;  
        }        
    }
    if (cnt == strlen(suffix))
        return true;
    return false;
}

int str_count(char str[], char sub[]) {
    int occ = 0, cnt = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == sub[0]){
            for (int j = 0; j < strlen(sub); j++) {
                if (str[i+j] == sub[j])
                    cnt++;
                if (cnt == strlen(sub)) {
                    occ++;
                    cnt=0;
                }
            }
        }  

    }
    return occ;
}

bool str_is_ascii(char str[]) { // true if only ASCII characters
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < 0 || str[i] > 127)
            return false;
    }
    return true;
}

bool str_is_digit(char str[]) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] > 57 || str[i] < 48)
            return false;
    }
    return true;
}

int str_index(char str[], char sub[]) {
    int index, cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < strlen(sub); j++) {
            if (sub[j] == str[i+j]) {
                cnt++;
                index = i+1;
                if (cnt == strlen(sub))
                    return index;
            }
            else
                break;
        }
    }
    return -1;
}

int main(){
printf("=== Inverting case in a string ===\n");
    char str_inv[] = "Hello World";
    str_inverse_case(str_inv);
  
printf("\n=== Checking string's prefix ===\n");
    char str[] = "Hello World";
	char pre[] = "Hello";
    char not_pre[] = "nHello";
	fputs(str_starts_with(str, pre) ? "true\n" : "false", stdout);
    fputs(str_starts_with(str, not_pre) ? "true" : "false\n", stdout);

printf("\n=== Checking string's suffix ===\n");
  char ends_w[] = " World";
  char ends_not[] = "Hello";
  fputs(str_ends_with(str, ends_w) ? "true\n" : "false", stdout);
  fputs(str_ends_with(str, ends_not) ? "true" : "false\n", stdout);

printf("\n=== Counting string's occurences ===\n");
  char count1[] = "el";
  char count2[] = "qx";
  printf("Occurences: %d\n",str_count(str, count1));
  printf("Occurences: %d\n",str_count(str, count2));

printf("\n=== Check if str is ASCII ===\n");
  char not_ascii[] = "日本人中國的’éè∞¥₤€";
  fputs(str_is_ascii(str) ? "true\n" : "false", stdout);
  fputs(str_is_ascii(not_ascii) ? "true" : "false\n", stdout);

printf("\n=== Check if str only has digits ===\n");
  char is_digit[] = "213454509";
  fputs(str_is_digit(is_digit) ? "true\n" : "false", stdout);
  fputs(str_is_digit(str) ? "true" : "false\n", stdout);
  
printf("\n=== Get the position of substring ===\n");
  char sub8[] = "nana";
  char sub9[] = "Worl";
  printf("nana, expected: -1 => %d\n",str_index(str, sub8));
  printf("Worl, expected: 7 => %d\n",str_index(str, sub9));
  
  return 0;
}