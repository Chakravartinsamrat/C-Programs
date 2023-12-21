#include<stdio.h>
#include<string.h>

#define MAX_NAME_SIZE 20
#define MAX_FINGERPRINT_SIZE 100
#define MAX_FINGERPRINTS 10

// Structure to store fingerprint information
typedef struct {
    char name[MAX_NAME_SIZE];
    char fingerprint[MAX_FINGERPRINT_SIZE];
} Fingerprint;

// Global array to store registered fingerprints
Fingerprint fingerprints[MAX_FINGERPRINTS];

// Function to register a new fingerprint
void register_fingerprint(char *name, char *fingerprint) {
    for (int i = 0; i < MAX_FINGERPRINTS; i++) {
        if (fingerprints[i].name[0] == '\0') {
            strncpy(fingerprints[i].name, name, sizeof(fingerprints[i].name) - 1);
            strncpy(fingerprints[i].fingerprint, fingerprint, sizeof(fingerprints[i].fingerprint) - 1);
            fingerprints[i].name[sizeof(fingerprints[i].name) - 1] = '\0';
            fingerprints[i].fingerprint[sizeof(fingerprints[i].fingerprint) - 1] = '\0';
            printf("Fingerprint for %s registered successfully!\n", name);
            return;
        }
    }
    printf("Maximum number of fingerprints reached!\n");
}

// Function to verify a fingerprint
int verify_fingerprint(char *fingerprint) {
    for (int i = 0; i < MAX_FINGERPRINTS; i++) {
        if (strcmp(fingerprints[i].fingerprint, fingerprint) == 0) {
            printf("Welcome back, %s!\n", fingerprints[i].name);
            return 1;
        }
    }
    printf("Fingerprint not recognized.\n");
    return 0;
}

// Function to get user input safely
void getUserInput(char *prompt, char *input, size_t maxSize) {
    printf("%s", prompt);
    if (fgets(input, maxSize, stdin) == NULL) {
        // Handle input error
    }
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline
}

// Function to print the menu
void printMenu() {
    printf("\nBiometric Authentication System\n");
    printf("1. Register Fingerprint\n");
    printf("2. Verify Fingerprint\n");
    printf("3. Exit\n");
}

int main() {
    int option;
    char name[MAX_NAME_SIZE];
    char fingerprint[MAX_FINGERPRINT_SIZE];

    // Sample data for demonstration
    register_fingerprint("John Doe", "1234567890");
    register_fingerprint("Jane Doe", "0987654321");

    int exitFlag = 0;
    while (!exitFlag) {
        printMenu();

        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                getUserInput("Enter your name: ", name, sizeof(name));
                getUserInput("Enter your fingerprint: ", fingerprint, sizeof(fingerprint));
                register_fingerprint(name, fingerprint);
                break;
            case 2:
                getUserInput("Enter your fingerprint: ", fingerprint, sizeof(fingerprint));
                if (verify_fingerprint(fingerprint)) {
                    // Grant access
                } else {
                    // Deny access
                }
                break;
            case 3:
                printf("Exiting...\n");
                exitFlag = 1;
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}
