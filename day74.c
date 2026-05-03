#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[1000][50];

    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    char winner[50];
    int maxVotes = 0;

    for(int i = 0; i < n; i++) {
        int count = 0;

        // Count frequency of names[i]
        for(int j = 0; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }

        // Update winner
        if(count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        }
        else if(count == maxVotes) {
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
