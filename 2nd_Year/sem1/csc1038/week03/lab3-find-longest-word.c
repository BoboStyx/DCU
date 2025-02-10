/*
Author: Seyi Adu
Program: lab3-find-longest-word.c
Input: 
Output:
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Check if the sentence is givend
    if (argc != 2) {
        printf("One sentence needed");
        return 1;
    }

    // Create an array to store the sentence (copy argv[1] into the array)
    char sentence[256];
    strncpy(sentence, argv[1], sizeof(sentence) - 1);
    sentence[255] = '\0';  // Null-terminate the string

    int length = strlen(sentence);
    int max_length = 0;
    char longest_word[100] = {0};
    char current_word[100] = {0};
    int current_length = 0;

    // Loop through the sentence character by character
    for (int i = 0; i <= length; i++) {
        // If it's a space or the end of the sentence,  check the current word
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            if (current_length > max_length) {
                max_length = current_length;
  		strncpy(longest_word, current_word, current_length);
                longest_word[current_length] = '\0';  // Null-terminate the longest_word
            }
            current_length = 0;  // Reset current word length
        }
       	else {
            // Add character to current word and increase length
            current_word[current_length] = sentence[i];
            current_length++;
        }
    }

    // Print the longest word followed by a newline
    printf("%s\n", longest_word);

    return 0;
}
