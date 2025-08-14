/**
 * This file belongs to the oop.string repository by nasccped. Take a look at
 * https://github.com/nasccped/oop.string/blob/main/LICENSE if you're unsure
 * about the use/reproduction conditions */
#include <stdio.h>
#include <string.h>

void example_01();
void example_02();
void example_03();
void example_04();

int main(int argc, char *argv[]) {
    // example_01();
    // example_02();
    // example_03();
    // example_04();
    printf("Each function example have it own sequence of procedures!\n");
    printf("Try removing the comments!\n");
    return 0;
}

/* Example 1: string creation */
void example_01() {
#define DEFINE_STRING "define string"
    char *char_pointer = "char pointer";
    char char_array[] = {'c', 'h', 'a', 'r', ' ', 'a', 'r', 'r', 'a', 'y'};

    printf("String from `#define`: %s\n", DEFINE_STRING);
    printf("String from `char *`: %s\n", char_pointer);
    printf("String from `char []`: %s\n", char_array);
}

/* Example 2: string length */
void example_02() {
    char *point = "string input", arr[] = "string input";
    printf("Our input is: \"%s\"\n\n", point);
    printf("Input lenght as char pointer: %d\n",
           sizeof(point) / sizeof(point[0]));
    printf("Input lenght as char arr: %d\n", sizeof(arr) / sizeof(arr[0]));
    printf("Input lenght with strlen function: %d\n", strlen(point));
}

/* Example 3: string char access */
void example_03() {
    char string[] = "Hello, String!";
    for (int i = 0; i < strlen(string); i++)
        printf(" - %2d: %c\n", i, string[i]);
    printf("Our complete string: \"%s\"\n", string);
}

/* Example 4: string char change */
void example_04() {
    char string[] = "string";
    printf("Original String: \"%s\"\n", string);
    string[3] = 'o';
    printf("Modified String: \"%s\"\n", string);
}
