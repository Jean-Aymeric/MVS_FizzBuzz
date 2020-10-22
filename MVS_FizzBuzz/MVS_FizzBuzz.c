#include <stdio.h>
#include <stdlib.h>
#include "MVS_FizzBuzz.h"

typedef struct DividerMessage {
    int divider;
    const char* message;
    struct DividerMessage* next;
} DividerMessage;

typedef struct DividerMessages {
    struct DividerMessage* start;
} DividerMessages;

static DividerMessages* initializeDividerMessage ();
static unsigned int addDividerMessage (DividerMessages* dividerMessages, int divider, const char* message);

DividerMessages* initializeDividerMessage () {
    DividerMessages* dividerMessages = malloc (sizeof (DividerMessages));
    if (dividerMessages == NULL) {
        return NULL;
    }
    dividerMessages->start = NULL;
    return dividerMessages;
}

unsigned int addDividerMessage (DividerMessages* dividerMessages, int divider, const char* message) {
    if (dividerMessages == NULL) {
        return 0;
    }
    DividerMessage* newDividerMessage = NULL;

    newDividerMessage = malloc (sizeof (DividerMessage));
    if (newDividerMessage == NULL) {
        return 0;
    }
    newDividerMessage->divider = divider;
    newDividerMessage->message = message;
    newDividerMessage->next = NULL;

    if (dividerMessages->start == NULL) {
        dividerMessages->start = newDividerMessage;
    } else {
        DividerMessage* dividerMessage = NULL;
        dividerMessage = dividerMessages->start;
        while (dividerMessage->next != NULL) {
            dividerMessage = dividerMessage->next;
        }
        dividerMessage->next = newDividerMessage;
    }
    return 1;
}

unsigned int FizzBuzz () {
    DividerMessages* dividerMessages = initializeDividerMessage ();
    if (dividerMessages == NULL) {
        return 0;
    }
    addDividerMessage (dividerMessages, 3, "Fizz");
    addDividerMessage (dividerMessages, 5, "Buzz");
    for (unsigned int i = 1; i <= 100; i++) {
        char atLeastOneDivider = 0;
        DividerMessage* dividerMessage = dividerMessages->start;
        while (dividerMessage != NULL) {
            if (i % dividerMessage->divider == 0) {
                printf ("%s", dividerMessage->message);
                if (dividerMessage->message != NULL) {
                    atLeastOneDivider = 1;
                }
            }
            dividerMessage = dividerMessage->next;
        };
        if (!atLeastOneDivider) {
            printf ("%u", i);
        }
        printf ("\n");
    }

}

