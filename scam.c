#include <stdio.h>
#include <string.h>

void checkDrivingMode(float speed) {
    if (speed > 30.0) {
        printf("Driving mode enabled.\n");
    } else {
        printf("Driving mode disabled.\n");
    }
}

int isScamNumber(const char *number) {
    const char *scamNumbers[] = {"+1234567890", "+0987654321"};
    int totalScamNumbers = 2;
    for (int i = 0; i < totalScamNumbers; i++) {
        if (strcmp(number, scamNumbers[i]) == 0) {
            return 1; // Scam detected
        }
    }
    return 0; // Not a scam
}

void sendAutoReply(const char *number) {
    printf("Sending auto-reply to %s: 'I'm currently driving. Please text if urgent.'\n", number);
}

int main() {
    float speed;
    char incomingNumber[15];

    // Input speed
    printf("Enter current speed in km/h: ");
    scanf("%f", &speed);

    // Check driving mode
    checkDrivingMode(speed);

    // Input incoming call number
    printf("Enter incoming call number: ");
    scanf("%s", incomingNumber);

    // Check if the call is a scam and respond
    if (isScamNumber(incomingNumber)) {
        printf("Scam call detected from %s! Blocking...\n", incomingNumber);
    } else {
        printf("Call allowed from: %s\n", incomingNumber);
        if (speed > 30.0) { // If driving, send auto-reply
            sendAutoReply(incomingNumber);
        }
    }

    return 0;
}