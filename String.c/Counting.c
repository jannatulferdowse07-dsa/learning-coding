#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Character mismatch
        }
        left++;
        right--;
    }
    return true; 
}

int main() {
    char str1[] = "radar";
    char str2[] = "hello";

    printf("Is '%s' a palindrome? %s\n", str1, isPalindrome(str1) ? "Yes" : "No");
    printf("Is '%s' a palindrome? %s\n", str2, isPalindrome(str2) ? "Yes" : "No");

    return 0;
}
