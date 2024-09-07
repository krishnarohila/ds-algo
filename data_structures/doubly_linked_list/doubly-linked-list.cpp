#include <bits/stdc++.h>
using namespace std;

//double Linked List struct
struct ListStruct {
	int value;
	struct ListStruct *Next;
	struct ListStruct *Prev;
};

struct ListStruct *HEAD = NULL, *TAIL;

string placeholderPrompt = "Enter number after which you want to insert: ";
string userPrompt = "Enter number to insert: ";
string findPrompt = "Enter number to find: ";
string removePrompt = "Enter number to remove: ";

void printOperationOptions() {
    cout << "Select operation number: " << endl;
    cout << "1. Add number" << endl;
    cout << "2. Add number to start" << endl;
    cout << "3. Add number to end" << endl;
    cout << "4. Add number after" << endl;
    cout << "5. Find position of number" << endl;
    cout << "6. Remove number" << endl;
    cout << "7. Reverse list" << endl;
    cout << "8. Print list" << endl;
    cout << "9. Print list both ways" << endl;
    cout << "10. End" << endl;
    cout << ">> ";
}

int getUserInput(string prompt) {
    int userInput;
    cout << prompt;
    cin >> userInput;
    return userInput;
}

void insertNum(int value) {
    struct ListStruct *temp = (struct ListStruct*)malloc(sizeof(struct ListStruct));
    struct ListStruct *iterator = HEAD;
    temp->value = value;
    temp->Next = NULL;
    temp->Prev = NULL;
    if (HEAD == NULL) {
        HEAD = temp;
    }
    else {
        while (iterator->Next != NULL) {
            iterator = iterator->Next;
        }
	temp->Prev = iterator;
        iterator->Next = temp;
    }
    return;
}

void insertNumAtStart(int value) {
    struct ListStruct *temp = (struct ListStruct*) malloc(sizeof(struct ListStruct));
    temp->value = value;
    temp->Next = NULL;
    temp->Prev = NULL;
    if (HEAD == NULL) {
        HEAD = temp;
    }
    else {
        HEAD->Prev = temp;
        temp->Prev = NULL;
        temp->Next = HEAD;
        HEAD = temp;
    }
    return;
}

void insertNumAfter(int placeholder, int value) {
    struct ListStruct *temp = (struct ListStruct*) malloc(sizeof(struct ListStruct));
    struct ListStruct *iterator = HEAD;
    temp->value = value;
    temp->Next = NULL;
    bool isPositionFound = false;
    while (iterator != NULL) {
        if (iterator->value == placeholder) {
            temp->Prev = iterator;
            temp->Next = iterator->Next;
            iterator->Next->Prev = temp;
            iterator->Next = temp;
            isPositionFound = true;
            break;
        }
        iterator = iterator->Next;
    }
    if (!isPositionFound) {
        cout << "Number " << placeholder << " not found to insert after." << endl;
    }
    return; 
}

void findPosition(int value) {
    int positionCount = 0;
    bool isPositionFound = false;
    struct ListStruct *iterator = HEAD;
    while(iterator != NULL) {
        if (iterator->value == value) {
            isPositionFound = true;
            positionCount++;
            break;
        }
        else {
            positionCount++;
            iterator = iterator->Next;
        }
    }
    if (isPositionFound) {
        cout << "Position for the number " << value << " in linked list is: " << positionCount << endl;
        }
    else {
        cout << "Number " << value << " not found in linked list" << endl;
    }
    return;
}

void removeNumber(int value) {
    struct ListStruct *iterator1 = HEAD, *iterator2 = HEAD;
    bool isNumberDeleted = false;
    if (iterator2 != NULL && iterator2->value == value) {
        HEAD = HEAD->Next;
        free(iterator1);
        isNumberDeleted = true;
    }
    if (!isNumberDeleted && iterator2->Next != NULL) {
        iterator2 = iterator2->Next;
    }
    while (!isNumberDeleted && iterator2 != NULL) {
        if (iterator2->value == value) {
            iterator1->Next = iterator2->Next;
            iterator2->Next->Prev = iterator1;
            free(iterator2);
            isNumberDeleted = true;
            break;
        }
        iterator1 = iterator1->Next;
        iterator2 = iterator2->Next;
    }
    if (!isNumberDeleted) {
        cout << "Number " << value << " to be deleted not found" << endl;
    }
    return;
}

void reverseList() {
    struct ListStruct *curr = HEAD, *prev = NULL, *next = NULL;
    while( curr != NULL) {
        prev = curr->Prev;
        next = curr->Next;

        curr->Next = prev;
        curr->Prev = next;

        prev = curr;
        curr = next;
    }
    HEAD = prev;
}

void printList() {
    struct ListStruct *iterator = HEAD;
    cout << "HEAD";
    while (iterator != NULL) {
        cout << "->" << iterator->value;
        iterator = iterator->Next;
    }
    cout << "->NULL" << endl;
}

void printListBothWays() {
    printList();
    struct ListStruct *iterator = HEAD;
    while(iterator->Next != NULL) {
        iterator = iterator->Next;
    }
    cout << "NULL";
    while(iterator != NULL) {
         cout << "->" << iterator->value;
        iterator = iterator->Prev;
    }
    cout << "->HEAD" << endl;
}

int main()
{
    while (1) {
        int operationNumber, value;
        printOperationOptions();
        cin >> operationNumber;
        switch(operationNumber) {
            case 1:
                value = getUserInput(userPrompt);
                insertNum(value);
                break;
            case 2:
                value = getUserInput(userPrompt);
                insertNumAtStart(value);
                break;
            case 3:
                value = getUserInput(userPrompt);
                insertNum(value);
                break;
            case 4:
                int placeholderNumber;
                placeholderNumber = getUserInput(placeholderPrompt);
                value = getUserInput(userPrompt);
                insertNumAfter(placeholderNumber, value);
                break;
            case 5:
                value = getUserInput(findPrompt);
                findPosition(value);
                break;
            case 6:
                value = getUserInput(removePrompt);
                removeNumber(value);
                break;
            case 7:
                reverseList();
                break;
            case 8:
                printList();
                break;
            case 9:
                printListBothWays();
                break;
            case 10:
                return 0;
        }
    }

    return 0;
}
