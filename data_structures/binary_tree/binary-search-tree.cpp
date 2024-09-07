#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int value;
	struct TreeNode *Left;
	struct TreeNode *Right;
};

struct TreeNode *HEAD = NULL, *TAIL;

string placeholderPrompt = "Enter number after which you want to insert: ";
string userPrompt = "Enter number to insert: ";
string findPrompt = "Enter number to find: ";
string removePrompt = "Enter number to remove: ";

void printOperationOptions() {
    cout << "Select operation number: " << endl;
    cout << "1. Add node" << endl;
    cout << "2. Search node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Inorder traversal" << endl;
    cout << "5. Preorder traversal" << endl;
    cout << "6. Postorder traversal" << endl;
    cout << "7. Convert to Balanced Tree" << endl;
    cout << "8. End" << endl;
    cout << ">> ";
}

int getUserInput(string prompt) {
    int userInput;
    cout << prompt;
    cin >> userInput;
    return userInput;
}

struct TreeNode* insertNum(struct TreeNode *node, int value) {
	struct TreeNode *temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	temp->value = value;
	temp->Left = NULL;
	temp->Right = NULL;
	if(node == NULL) {
		return temp;
	}
	if (node->value > value) {
		node->Left = insertNum(node->Left, value);
	}
	if (node->value <= value) {
		node->Right = insertNum(node->Right, value);
	}
	return node;
}

void inorderTraversal(struct TreeNode *node) {
	if (node == NULL) {
		return;
	}
	inorderTraversal(node->Left);
	cout << node->value << " ";
	inorderTraversal(node->Right);
}

void preorderTraversal(struct TreeNode *node) {
	if(node == NULL) {
		return;
	}
	cout << node->value << " ";
	preorderTraversal(node->Left);
	preorderTraversal(node->Right);
}

void postorderTraversal(struct TreeNode *node) {
	if(node == NULL) {
		return;
	}
	postorderTraversal(node->Left);
	postorderTraversal(node->Right);
	cout << node->value << " ";
}

struct TreeNode* searchNum(struct TreeNode *node, int value) {
	if(node == NULL || node->value == value){
		return node;
	}
	if(node->value > value) {
		return searchNum(node->Left, value);
	}
	return searchNum(node->Right, value);
}

int main() {
	while (1) {
		int operationNumber, value;
	        printOperationOptions();
	        cin >> operationNumber;
	        switch(operationNumber) {
	            case 1:
	                value = getUserInput(userPrompt);
	                HEAD = insertNum(HEAD, value);
	                break;
	            case 2:
	                value = getUserInput(findPrompt);
	                struct TreeNode *result;
			result = searchNum(HEAD, value);
			if(result == NULL) {
				cout << "Number " << value << " not found" << endl;
			}
			else {
				cout << "Number " << value << " found" << endl;
			}
	                break;
	            case 3:
	                value = getUserInput(userPrompt);
	                deleteNum(value);
	                break;
	            case 4:
	                inorderTraversal(HEAD);
	                break;
	            case 5:
	                preorderTraversal(HEAD);
	                break;
	            case 6:
		        postorderTraversal(HEAD);
	                break;
	            case 7:
	          //      convertToBalanceTree();
	                break;
	            case 8:
	                return 0;
		}
	}
}
