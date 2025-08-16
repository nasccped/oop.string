`00-basics`
===========

The C string basics, such as **creation** and **handling**.

## Example 1: String creation

In `C`, we can create strings using `#define`, `char` pointers and
`char` arrays:
```c
#define DEFINE_STRING "define string"

void example_01() {
    char *char_pointer = "char pointer";
    char char_array[] = {'c', 'h', 'a', 'r', ' ', 'a', 'r', 'r', 'a', 'y'};

    printf("String from `#define`: %s\n", DEFINE_STRING);
    printf("String from `char *`: %s\n", char_pointer);
    printf("String from `char []`: %s\n", char_array);
}
```

When printing with `printf` function, they all will work the same.

> [!NOTE]
>
> There's also dynamic size strings wich we can create by using
> `malloc` function from `stdlib.h`:
>
> ```c
> #define STRING_MAX_LENGTH <SOME_INT_NUMBER> + 1 // +1 for string terminator
> char *string = (char *) malloc(sizeof(STRING_MAX_LENGTH));
> ```
>
> There's also `strdup` function from `string.h` and a lot more that
> we can talk about later...

Key-differences:
- `#define` string are created before compile time (we can achieve a
  similar behavior by using `static char` or `static const`, but only
  `#define`s are read by the pre-processor **before** compilation
  starts);
- creating a string will allocate the **string content itself** +
  the `\0` char (a string terminator) used by the C system to detect
  strings ending.

## Example 2: String length

Since strings are a sequence of `char`s, we can get the sequence
lenght:

```c
void example_02() {
    char *point = "string input", arr[] = "string input";
    printf("Our input is: \"%s\"\n\n", point);
    printf("Input lenght as char pointer: %d\n", // prints '8' as result
           sizeof(point) / sizeof(point[0]));
    printf("Input lenght as char array: %d\n", // prints '13' as result
           sizeof(arr) / sizeof(arr[0]));
    printf("Input lenght with strlen function: %d\n", strlen(point));
}
```

### How does it works?

Unlike `Python`, C doesn't have a `len()` function to get string
length. Instead, we must use a memory size calculation:

1. **Get the entire variable size:**
```c
char string[] = "string here";
sizeof(string) /* this will return the size (in bytes) of the
                  string variable */
```
2. **Get the size of the first char:** since a C's string is an array
   of chars, we can access the first element using the array access
   syntax:
```c
sizeof(string[0]) /* will return the size (in bytes) of the first
                     char in the string variable */
```
3. Get the length by dividing the total size by the first element's
   size:
```c
sizeof(string) / sizeof(string[0])
```

### Why string lenght differs from char pointer to char array?

`char _[]` will allocate the content in the stack (or in static
storage if declared as `static`) while `char *_` is a pointer to a
**read-only** constant string literal (usually in the program's
binary at _rodata_ section).

The array will **own** the data, while the pointer will **points** to
it. The size of a **char array** will be the entire content and the
size of a **char pointer** will be the pointer itself (`4 or 8 bytes`
depending on the machines arch).

This behavior can results into unexpected and nonsense results.

### Why is `13` being returned when `12` is the expected one?

When you create a new string (char array), this is what you see:
```c
char input[] = "string";
```
But this is what `C` does:
```
+- variable -+- memory data ---+--------+--------+--------+--------+---------+
|   input    | 0: 's' | 1: 't' | 2: 'r' | 3: 'i' | 4: 'n' | 5: 'g' | 6: '\0' |
+------------+--------+--------+--------+--------+--------+--------+---------+
```

The `C` compiler will place a `\0` char at the end of the char
sequence to represent where the string ends. So, the length of a
string (as char array) will ever be:
```c
sizeof(input) // total input size
    / sizeof(input[0]) // divided by the first char size
    - 1; // remove string terminator count
```

### Other ways to get a string length

You can also use the `strlen()` function provided by the `string.h`
header. It will works both with pointers and arrays. You can create
your own `strlen` util, btw:
```c
int string_length(char *string) {
    int counter = 0;
    while (string[counter] != '\0') counter++;
    return counter;
}
```

> [!CAUTION]
>
> The code above will only works considering that the string contains
> a null terminator (`\0`), otherwise, it'll fall into an infinite
> loop and/or invalid memory access _(segfault)_. Same behavior when
> passing a null char pointer:
> ```c
> // null terminator problem
> char str1[4] = "str"; // str1 = {'s', 't', 'r', '\0'}
> str1[3] = 'a';        // str = {'s', 't', 'r', 'a'} - no null terminator
> int len1 = string_length(str1); // undefined behavior
>
> // null pointer
> char *str2 = NULL;
> int len2 = string_length(str2); // undefined behavior
> ```

## Example 4: String char change

Since string is an array of chars, we can change its content by
accessing chars at specific indexes:
```c
void example_04() {
    char string[] = "string";
    printf("Original String: \"%s\"\n", string);
    string[3] = 'o';
    printf("Modified String: \"%s\"\n", string);
}
```

> [!WARNING]
>
> This will only work for char arrays since char pointers points to
> read-only data. Overriding strings from `char *` can leads to
> undefined behavior.
