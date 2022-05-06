
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
        else 
            return false;
        }
    return isPrefix;
}

bool str_ends_with(char str[], char suffix[]) {
    int cnt = 0;
    for (int i = strlen(str)-strlen(suffix); i < strlen(str); i++) {
        if(str[i] == suffix[0]) {   
            for (int j = 0; j < strlen(suffix); j++) {
                if (str[i] == suffix[j]) {
                    cnt++;
                    i++;
                }
            }        
        }
    }
    if (cnt == strlen(suffix))
        return true;
    return false;
}

int str_count(char str[], char sub[]) {
    int occ = 0, cnt = 0;
    for (int i = 0; i < strlen(str)-1; i++){
        if (str[i] == sub[0]){
            for (int j = 0; j < strlen(sub)-1; j++) {
                if (str[i+j] == sub[j])
                    cnt+=1;
                if (cnt == strlen(sub)-1) {
                    occ+=1;
                    cnt=0;
                }
            }
        }
    }
    return occ;
}

bool str_is_ascii(char str[]) { // true if only ASCII characters
    for (int i = 0; i < strlen(str)-1; i++) {
        if (str[i] < 0 || str[i] > 127)
            return false;
    }
    return true;
}


bool str_is_digit(char str[]) {
    int count = 0;
    for (int i = 0; i < strlen(str)-1; i++) {
        if (str[i] <= 57 && str[i] >= 48)
            count+=1;
    }
    if (count == strlen(str)-1)
        return true;
    else
        return false;
}

int str_index(char str[], char sub[]) {
    int index, isSubstr = 0, cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < strlen(sub); j++) {
            if (sub[j] == str[i+j]) {
                cnt++;
                index = i+1;
                if (cnt == strlen(sub)) {
                    isSubstr = 1;
                    return index;
                }
            }
            else
                break;
        }
    }
    return -1;
}


int main(){
printf("=== Inverting case in a string ===\n");
    char strprobe[] = "Hello World";
    str_inverse_case(strprobe);
  
printf("\n=== Checking string's prefix ===\n");
    char str[] = "Hello World";
	char sub1[] = "Hello";
    char sub2[] = "nHello";
	bool res = str_starts_with(str, sub1);
    bool res1 = str_starts_with(str, sub2);
	if (res) printf("true\n");
	else printf("false\n");
	if (res1) printf("true\n");
	else printf("false\n");	

printf("\n=== Checking string's suffix ===\n");
  char suffix1[] = " World";
  char suffix2[] = "Hello";
  bool res2 = str_ends_with(str, suffix1);
  bool res3 = str_ends_with(str, suffix2);
  if (res2) printf("true\n");
  else printf("false\n");
  if (res3) printf("true\n");
  else printf("false\n");

printf("\n=== Counting string's occurences ===\n");
  char sub3[] = "el";
  char sub4[] = "qx";
  printf("Occurences: %d\n",str_count(str, sub3));  // number of occurences of sub in text
  printf("Occurences: %d\n",str_count(str, sub4));

printf("\n=== Check if str is ASCII ===\n");              // NEEEEEEEEEEEEEEEEDS FIX
  char sub5[] = "Hello there";
  char no_ascii[] = "¢";
  bool res4 = str_is_ascii(sub5);
  bool res5 = str_is_ascii(no_ascii);  // true if string only has ascii chars
  if (res4) printf("true\n");
  else printf("false\n");
  if (res5) printf("true\n");
  else printf("false\n");

printf("\n=== Check if str only has digits ===\n");
  char sub6[] = "213454509";
  char sub7[] = "Hello there";
  bool res6 = str_is_digit(sub6);  // true if string only has digits
  bool res7 = str_is_digit(sub7);
  if (res6) printf("true\n");
  else printf("false\n");
  if (res7) printf("true\n");
  else printf("false\n");
  
printf("\n=== Get the position of substring ===\n");
  char sub8[] = "nana";
  char sub9[] = "Worl";
  printf("nana, expected -1 => %d\n",str_index(str, sub8));  // pos. of first occ. of sub in str | -1
  printf("Worl, expected 7 => %d\n",str_index(str, sub9));
  
  return 0;
}