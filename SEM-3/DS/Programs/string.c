#include <stdio.h>
#include <conio.h>

typedef struct {
    char a[100];
} string_adt;

void create(string_adt *s1, string_adt *s2) {    
    printf("Enter string 1: \n");
    scanf("%s", s1->a);

    printf("Enter string 2: \n");
    scanf("%s", s2->a);
}

string_adt concat(string_adt s1, string_adt s2) {
    string_adt new_str;
    int i = 0, j = 0;
    while(s1.a[i] != '\0') {
        new_str.a[j] = s1.a[i];
        i++;
    }
    while (s2.a[j] != '\0') {
        new_str.a[i] = s2.a[j];
        i++;
        j++;
    }
    new_str.a[i] = '\0';
    return new_str;
}

int stringlength(string_adt s1) {
    int i = 0;
    while (s1.a[i] != '\0') {
        i++;
    }
    return i;
}

string_adt substring(string_adt s,int str,int e) {
    string_adt new_str;

    int i=str;
    int j=0;

    while(i<e) {
        new_str.a[j]=s.a[i];
        i++;
        j++;
    }

    return new_str;
}

void compare(string_adt s1, string_adt s2) {
    int i = 0;
    while (s1.a[i]!='\0' && s2.a[i]!='\0') {
        if (s1.a[i]!=s2.a[i]) {
            printf("Strings are not equal\n");
            return;
        }
        i++;
    }
    printf("Strings are equal\n");
}

int main() {
    string_adt s1, s2;
    create(&s1,&s2);
    
    printf("Length of string 1: %d\n", stringlength(s1));
    printf("Length of string 2: %d\n", stringlength(s2));


    string_adt new_str=concat(s1,s2);
    printf("Concatenated string: %s\n", new_str.a);

    string_adt sub_str=substring(s1,0,3);
    printf("Substring: %s\n", sub_str.a);

    compare(s1,s2);
}