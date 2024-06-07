#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

float count(float a, float b, char* type) {
    if (type == "+") {
        return a + b;
    } else if (type == "-") {
        return a - b;
    } else if (type == "*") {
        return a*b;
    } else if (type == "/") {
        return a/b;
    }
}

char* substring(const char *str, int start, int end) {
    // Get the length of the main string
    int str_len = strlen(str);

    // Validate the start and end positions
    if (start < 0 || end >= str_len || start > end) {
        printf("Invalid start or end positions.\n");
        return NULL;
    }

    // Calculate the length of the substring
    int substr_len = end - start + 1;

    // Allocate memory for the new substring
    char *extracted_substr = (char *)malloc((substr_len + 1) * sizeof(char));

    if (!extracted_substr) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Copy the substring into the new memory
    strncpy(extracted_substr, str + start, substr_len);
    extracted_substr[substr_len] = '\0';  // Null-terminate the string

    return extracted_substr;
}

void removeSpaces(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];

    str[count] = '\0';
}

int main() {
    using_history();

    while (1) {
        char *expression = readline("Enter expression (press ctrl c for exit): ");
        add_history(expression);

        // delete all spaces
        removeSpaces(expression);

        int start = 0;
        int length = strlen(expression) - 1;

        int id = 0;
        char* type;

        for (int i = 0; i < strlen(expression); i++){
            if (expression[i] == '+') {
                id = i;
                type = "+";
            }
            else if (expression[i] == '-') {
                id = i;
                type = "+";
            }
            else if (expression[i] == '*') {
                id = i;
                type = "*";
            }
            else if (expression[i] == '/') {
                id = i;
                type = "/";
            }
        }

        char* a = substring(expression, start, id-1);
        char* b = substring(expression, id+1, length);

        float a1 = atof(a);
        float b1 = atof(b);

        printf("Result: %f\n", count(a1, b1, type));
    }

    return 0;
}