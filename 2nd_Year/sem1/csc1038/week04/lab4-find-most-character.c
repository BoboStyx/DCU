/*
Author: Seyi Adu
Program: lab4-find-most-character.c
Input: A string argument e.g "abcxyzbcc"
Output: The character that appears the most e.g "c"
 */

#include <stdio.h>


int main(int argc, char *argv[]) {

    char *str = argv[1];          
    int freq[26] = {0}; 
    char *pstr = str;            

    while (*pstr != '\0') {        
        if (*pstr >= 'a' && *pstr <= 'z') { 
            freq[*pstr - 'a']++;  
        }
        pstr++;                  
    }

    int max_freq = 0;            
    char most_frequent_char = '\0';

    for (int i = 0; i < 26; i++) { 
        if (freq[i] > max_freq) { 
            max_freq = freq[i];    
            most_frequent_char = (char)(i + 'a');
        }
    }

    if (most_frequent_char != '\0') {
        printf("%c\n", most_frequent_char);
    }

    return 0;
}
