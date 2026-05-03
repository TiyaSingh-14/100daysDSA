#include <stdio.h>

char firstRepeated(char *s) {
    
    int freq[26] = {0};

    for(int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if(freq[idx] == 1) {
            return s[i];  // second occurrence found
        }

        freq[idx]++;
    }

    return '-';  // no repeated character
}
