#include <stdio.h>

void vulnerable_function(char *user_input) {
    printf(user_input);  // Vulnerable to format string attacks
}

int main() {
    char buffer[256];

    printf("Enter input: ");
    fgets(buffer, sizeof(buffer), stdin);

    buffer[strcspn(buffer, "\n")] = '\0';

    vulnerable_function(buffer);

    return 0;
}
