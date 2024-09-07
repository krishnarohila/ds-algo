#include <bits/stdc++.h>
using namespace std;

// Linked list
struct ListStruct {
    int value;
    struct ListStruct *Next;
};

struct ListStruct *HEAD = NULL;

string userPrompt = "Enter number to push: ";

void printOperationOptions() {
    cout << "Select operation number: " << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Front" << endl;
    cout << "4. IsEmpty" << endl;
    cout << "5. Size" << endl;
    cout << "6. End" << endl;
    cout << ">> ";
}

int getUserInput(string prompt) {
    int userInput;
    cout << prompt;
    cin >> userInput;
    return userInput;
}

void enqueue(int value) {
    struct ListStruct *temp = (struct ListStruct*)malloc(sizeof(struct ListStruct));
    temp->value = value;
    temp->Next = HEAD;
    HEAD = temp;
    return;
}

void dequeue() {
    struct ListStruct *iterator = HEAD, *temp;
    if (HEAD == NULL) {
        cout << "Empty queue" << endl;
        return;
    }
    if (HEAD->Next == NULL) {
        HEAD = NULL;
        free (iterator);
        return;
    }
    while(iterator->Next->Next != NULL) {
        iterator = iterator->Next;
    }
    temp = iterator->Next;
    iterator->Next = NULL;
    free(temp);
    return;
}

void printFront() {
    struct ListStruct *iterator = HEAD;
    if (HEAD == NULL) {
        cout << "Queue empty" << endl;
        return;
    }
    while(iterator->Next != NULL) {
        iterator = iterator->Next;
    }
    cout << "Top: " << iterator->value << endl;
    return;
}

void checkIfEmpty() {
   struct ListStruct *iterator = HEAD;
   if (HEAD == NULL) {
       cout << "Queue empty" << endl;
    }
    else {
        cout << "Queue not empty" << endl;
    }
    return;
}

void printSize() {
    struct ListStruct *iterator = HEAD;
    int size;
    if (HEAD == NULL) {
        cout << "Queue empty" << endl;
        return;
    }
    while(iterator != NULL) {
        size++;
        iterator = iterator->Next;
    }
    cout << "Size: " << size << endl;
    return;
}


int main() {
    while (1) {
        int operationNumber, value;
        printOperationOptions();
        cin >> operationNumber;
        switch(operationNumber) {
            case 1:
                value = getUserInput(userPrompt);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printFront();
                break;
            case 4:
                checkIfEmpty();
                break;
            case 5:
                printSize();
                break;
            case 6:
                return 0;
        }
    }

    return 0;
}

