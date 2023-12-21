#include<stdio.h>
#include <string.h>  //My beloved lib that let's me use string functions
#include<stddef.h> //Standard def Lib- provides def for types like "Size_t"

#define MAX_FINGERPRINTS 10
//setting max number of finger prints for the system

// Structure to store fingerprint information
typedef struct {
    char name[20];
    char fingerprint[100];     //I declare arrys in my structure
} Fingerprint;

// Global array fingerprints of type "Fingerprint" to store registered fingerprints
Fingerprint fingerprints[MAX_FINGERPRINTS];

// Function to register a new fingerprint
void register_fingerprint(char *name, char *fingerprint) {
    for (int i = 0; i < MAX_FINGERPRINTS; i++) {
        if (fingerprints[i].name[0] == '\0') {
            strcpy(fingerprints[i].name, name);               //using strcpy to copy the input into the respective arrays
            strcpy(fingerprints[i].fingerprint, fingerprint);
            printf("Fingerprint for %s registered successfully!\n", name);
            return;
        }
    }
    printf("Maximum number of fingerprints reached!\n");
}

// Function to verify a fingerprint
int verify_fingerprint(char *fingerprint) {
    for (int i = 0; i < MAX_FINGERPRINTS; i++) {
        if (strcmp(fingerprints[i].fingerprint, fingerprint) == 0) {  //using strcmp to compare the fingerprint input with the stored ones
            printf("Welcome back, %s!\n", fingerprints[i].name);     //if match, return true and print "I know this guy"
            return 1;
        }
    }
    printf("Fingerprint not recognized.\nStranger Danger!!! \n");  //if mismatch, I don't know this person
    return 0;
}

int main() {
    int option;
    char name[20];
    char fingerprint[100];
    //register_fingerprint("Admin","123");  //Empty database doesn't look good 
    //register_fingerprint("Piyush","789");

    while (1) { //infinite loop
        printf("\nBiometric Authentication System\n");      
        printf("1. Register Fingerprint\n");
        printf("2. Verify Fingerprint\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) { 
            case 1: //Case 1 you register you Fingerprint
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your fingerprint: ");
                scanf("%s", fingerprint);
                register_fingerprint(name, fingerprint);  //I call register function cause I should
                break;
            case 2: //You check if the system knows you or not
                printf("Enter your fingerprint: ");
                scanf("%s", fingerprint);
                if (verify_fingerprint(fingerprint)) {    //I call verifying authorities to take action
                    // Grant access
                } else {
                    // Deny access
                }
                break;
            case 3:  //Oh man I've had enough of this program
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
return 0;
}

