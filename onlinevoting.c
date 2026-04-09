#include <stdio.h>
#include <string.h>

#define MAX 5

struct Candidate {
    char name[50];
    int votes;
};


struct Candidate candidates[MAX];
int candidateCount = 0;

void addCandidate() {
    char tempName[50];

    printf("Enter number of candidates (max %d): ", MAX);
    scanf("%d", &candidateCount);

    if(candidateCount > MAX)
        candidateCount = MAX;

    for(int i = 0; i < candidateCount; i++) {

        printf("Enter full name of candidate %d: ", i + 1);
        scanf(" %[^\n]", tempName); 

        
        if(strlen(tempName) == 0) {
            printf("Name cannot be empty! Enter again.\n");
            i--;
            continue;
        }

        strcpy(candidates[i].name, tempName); 
        candidates[i].votes = 0;
    }
}



void displayCandidates() {
    printf("\n- Candidate List -\n");

    for(int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}
void vote() {
    int choice;

    displayCandidates();

    printf("Enter your vote (1-%d): ", candidateCount);
    scanf("%d", &choice);

    if(choice >= 1 && choice <= candidateCount) {
        candidates[choice - 1].votes++;
        printf("Vote cast successfully!\n");
    } else {
        printf("Invalid vote!\n");
    }
}



void showResults() {
    printf("\n--- Voting Results ---\n");

    for(int i = 0; i < candidateCount; i++) {
        printf("%s - %d votes\n", candidates[i].name,candidates[i].votes);
    }
}



void showWinner() {
    int maxVotes = -1;
    int winnerIndex = 0;

    for(int i = 0; i < candidateCount; i++) {
        if(candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    printf("\n Winner: %s with %d votes\n",candidates[winnerIndex].name,candidates[winnerIndex].votes);
}



int main() {
    int choice;

    addCandidate();

    while(1) {
        printf("\n--- Online Voting System ---\n");
        printf("1. Vote\n");
        printf("2. Show Results\n");
        printf("3. Show Winner\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                vote();
                break;

            case 2:
                showResults();
                break;

            case 3:
                showWinner();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}