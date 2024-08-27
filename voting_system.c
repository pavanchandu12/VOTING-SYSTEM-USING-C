#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
    char name[50];
    int votes;
    int number; // Candidate number
    struct Candidate* next;
} Candidate;

Candidate* createCandidate(char name[50], int number) {
    Candidate* newCandidate = (Candidate*)malloc(sizeof(Candidate));
    strncpy(newCandidate->name, name, sizeof(newCandidate->name));
    newCandidate->votes = 0;
    newCandidate->number = number;
    newCandidate->next = NULL;
    return newCandidate;
}

Candidate* addCandidate(Candidate* head, char name[50], int number) {
    Candidate* newCandidate = createCandidate(name, number);
    if (head == NULL) {
        return newCandidate;
    }
    Candidate* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newCandidate;
    return head;
}

void displayCandidates(Candidate* head) {
    Candidate* current = head;
    printf("List of Candidates:\n");
    while (current != NULL) {
        printf("%d. %s\n", current->number, current->name);
        current = current->next;
    }
}

void castVote(Candidate* head, int number) {
    Candidate* current = head;
    while (current != NULL) {
        if (current->number == number) {
            current->votes++;
            printf("You've voted for %s.\n", current->name);
            return;
        }
        current = current->next;
    }
    printf("Candidate with number %d not found. Please enter a valid number.\n", number);
}

void displayWinner(Candidate* head) {
    Candidate* winner = head;
    Candidate* current = head->next;

    while (current != NULL) {
        if (current->votes > winner->votes) {
            winner = current;
        }
        current = current->next;
    }

    printf("The winning candidate is: %s with %d votes.\n", winner->name, winner->votes);
}

// Function to delete a candidate by number
Candidate* deleteCandidate(Candidate* head, int number) {
    Candidate* current = head;
    Candidate* prev = NULL;

    while (current != NULL) {
        if (current->number == number) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            printf("Candidate with number %d has been deleted.\n", number);
            return head;
        }
        prev = current;
        current = current->next;
    }

    printf("Candidate with number %d not found.\n", number);
    return head;
}

int main() {
    Candidate* candidates = NULL;
    char name[50];
    int number;
    int choice;

    while (1) {
        printf("\nMini Voting System Menu:\n");
        printf("1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Delete Candidate\n");
        printf("5. Display Winner and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the candidate: ");
                scanf("%s", name);
                printf("Enter a number for the candidate: ");
                scanf("%d", &number);
                candidates = addCandidate(candidates, name, number);
                break;
            case 2:
                displayCandidates(candidates);
                break;
            case 3:
                printf("Enter the number of the candidate you want to vote for: ");
                scanf("%d", &number);
                castVote(candidates, number);
                break;
            case 4:
                printf("Enter the number of the candidate you want to delete: ");
                scanf("%d", &number);
                candidates = deleteCandidate(candidates, number);
                break;
            case 5:
                displayCandidates(candidates);
                displayWinner(candidates);
                while (candidates != NULL) {
                    Candidate* temp = candidates;
                    candidates = candidates->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}