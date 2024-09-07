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
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Top" << endl;
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

void pushNum(int value) {
    struct ListStruct *temp = (struct ListStruct*)malloc(sizeof(struct ListStruct));
    struct ListStruct *iterator = HEAD;
    temp->value = value;
    temp->Next = NULL;
    if (HEAD == NULL) {
        HEAD = temp;
        return;
    }
    while(iterator->Next != NULL) {
        iterator = iterator->Next;
    }
    iterator->Next = temp;
    return;
}

void popNum() {
    struct ListStruct *iterator = HEAD;
    if (HEAD == NULL) {
        cout << "Stack already empty" << endl;
        return;
    }
    if (iterator->Next == NULL) {
        HEAD = NULL;
        free(iterator);
        return;
    }
    while(iterator->Next->Next != NULL) {
       iterator = iterator->Next; 
    }
    struct ListStruct *temp = iterator->Next;
    iterator->Next = NULL;
    free(temp);
    return;
}

void printTopNum() {
    struct ListStruct *iterator = HEAD;
    if (HEAD == NULL) {
        cout << "Stack empty" << endl;
    }
    while(iterator->Next != NULL) {
       iterator = iterator->Next;
    }
    cout << "Top: " << iterator->value << endl;
    return;
}

void checkIfEmpty() {
    if (HEAD == NULL) {
        cout << "Stack empty" << endl;
    }
    else {
        cout << "Stack non empty" << endl;
    }
    return;
}

void printSizeofStack() {
    struct ListStruct *iterator = HEAD;
    if (HEAD == NULL) {
        cout << "Stack empty" << endl;
    }
    int size = 0;
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
                pushNum(value);
                break;
            case 2:
                popNum();
                break;
            case 3:
                printTopNum();
                break;
            case 4:
                checkIfEmpty();
                break;
            case 5:
                printSizeofStack();
                break;
            case 6:
                return 0;
        }
    }

    return 0; 
}
