#include <stdio.h>
#include <string.h>

int findSubstring(char text[], char pattern[]) {
    int textLen = strlen(text);
    int patLen = strlen(pattern);

    
    for (int i = 0; i <= textLen - patLen; i++) {
        int j;

        // Check if pattern matches starting from index i
        for (j = 0; j < patLen; j++) {
            if (text[i + j] != pattern[j]) {
                break; // Mismatch found, break inner loop
            }
        }

        // If we successfully checked the whole pattern
        if (j == patLen) {
            return i; // Substring found at index i
        }
    }

    return -1;
}

int main() {
    char text[] = "Data Structures and Algorithms";
    char pattern[] = "Structures";

    int index = findSubstring(text, pattern);

    if (index != -1) {
        printf("Substring found starting at index: %d\n", index);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
