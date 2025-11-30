#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char history[5][100];
    int count = 0;

    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) break;
        if (strcmp(input, "history") == 0) {
            for (int i = 0; i < count; i++) printf("%s\n", history[i]);
            continue;
        }

        double a, b, r;
        char op;
        if (sscanf(input, "%lf %c %lf", &a, &op, &b) != 3) {
            printf("Invalid\n");
            continue;
        }

        if (op == '+') r = a + b;
        else if (op == '-') r = a - b;
        else if (op == '*') r = a * b;
        else if (op == '/') r = b == 0 ? 0 : a / b;
        else { printf("Invalid\n"); continue; }

        printf("= %.2f\n", r);

        snprintf(history[count % 5], 100, "%s = %.2f", input, r);
        if (count < 5) count++;
    }
    return 0;
}