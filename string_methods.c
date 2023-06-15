#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char at(char* arr,int index){
    int size = strlen( arr);
    if ( index > size-1 || -index > size-1 ) {
        printf("Invalid index");
        return NULL;
    }
    else if( index <0) {
        index -=size;
    }
    return arr[index];
}
char charAt(char* arr, int index){
    if(index > strlen(arr) || index < 0) {
        printf("Invalid index");
        return NULL;
    }
    return arr[index];
 }
size_t charCodeAt(char* str, size_t index){
    return (size_t)(str[index]);
}
char* concat(const char* str1,const char* str2){
    size_t size = strlen(str1) + strlen(str2) +1;
    char* str = (char*)calloc( size, sizeof(char));
    strcpy(str, str1);
    strcat(str, str2);
    return str;
}
bool endsWith(char* str, char* target){
    size_t size = strlen(target);
    size_t size2 = strlen(str);
    for (int i =size ; i >=0 ; --i) {
        if( str[size2 - size + i] != target[i]) {    
            return false;
        }
    }
    return true;
}
bool includes(const char* str, const char* target){
    for (int i = 0, j = 0; i <strlen(str) ; ++i) {
          if (str[i] == target[j]) {
                ++j;
                if( j == strlen(target)) {
                    return true;
                }
            }else {
                j=0;
        }
    }
    return false;
}
int indexOf(const char* arr, const char* target){
    for(int i = 0 , j = 0 ; i < strlen(arr) ; ++i) {
        if(arr[i] == target[j]) {
            j++;
            if(j == strlen(target)) {
                return i-strlen(target)+1;
            }
        } else {
            j= 0;
        }
    }
    return NULL;
}
int lastIndexOf(const char* arr, const char* target){
    for(int i = strlen(arr), j = strlen(target) ; i>=0; --i) {
        if(arr[i] == target[j]) {
            --j;
            if(j<0) {
                return i;
            }
        } else {
            j= strlen(target);
        }
    }
    return NULL;
}
char* padEnd(char* str, size_t size, char elem){
    char* result = (char*)calloc(size , sizeof(char));
    strcpy(result, str);
    for(int i = strlen(str) ; i < size; ++i) {
        result[i] = elem;
    }
    return result;
}
char* padStart(char* str, size_t size, char elem){
    char* result = (char*)calloc(size , sizeof(char));
    for(int i = 0 ; i < strlen(str); ++i) {
        result[i] = elem;
    }
  strcat(result, str);
  return result;
}
char* repeat(const char* str, size_t num){
    char* res = (char*)calloc( num*strlen(str), sizeof(char));
    strcpy(res,str);
    for( int i = 1 ; i < num; ++i) {
        strcat(res,str);
    }
    return res;
}
char* replaceAll(const char* str, char* target, char* rep){
    if( strlen(target) != strlen(rep)) {
        return NULL;
    }
    int qty=0;
    for (int i = 0, j = 0; i <strlen(str) ; ++i) {
          if (str[i] == target[j]) {
                ++j;
                if( j == strlen(target)) {
                    ++qty;
                    j=0;
                }
            }else {
                j=0;
        }
    }
    char* ret = (char*)calloc(strlen(str), sizeof(char));
    for (int i = 0, j = 0 , k = 0; i <strlen(str) ; ++i, ++k) {
        if (str[i] == target[j]) {
            ++j;
            if( j == strlen(target)) {
                strcat(ret,rep);
                j=0;
            }
         }else {
             ret[i] = str[k];
        }
    }
    return ret;
}

int main()
{
    char* str = "Hello Jim, Love you Jim Bye";
    char* str1 = "Jim";
    char* str2 = "Eva";
    printf("%c\n" , at(str,-10));
    printf("%ld\n" , charCodeAt(str, 0));
    printf("%s\n" , str);
    printf("%d\n", endsWith(str, str1));
    printf("%d\n" , indexOf(str, str1));
    printf("%s\n" , replaceAll(str, str1, str2));
}
