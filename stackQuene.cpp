#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool isPalindrome(const string& str) {
    stack<char> charStack;
    queue<char> charQueue;

    for (char ch : str) {
        if (isalnum(ch)) {  
            char lowerCh = tolower(ch); 
            charStack.push(lowerCh);
            charQueue.push(lowerCh);
        }
    }

    while (!charStack.empty() && !charQueue.empty()) {
        if (charStack.top() != charQueue.front()) {
            return false; // Not a palindrome
        }
        charStack.pop();
        charQueue.pop();
    }

    return true; 
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // To handle spaces in the input

    if (isPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}
