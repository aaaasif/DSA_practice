#include <bits/stdc++.h>
using namespace std;


bool checkPalindromeWithStack(const string& str) 
    stack<char> charStack;
    for (char ch : str) {
        charStack.push(ch);
    }

    for (char ch : str) {
        if (ch != charStack.top()) { 
            return false;
        charStack.pop(); 
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (checkPalindromeWithStack(input)) {
        cout << input << " is a palindrome." << endl;
    } else {
        cout << input << " is not a palindrome." << endl;
    }
    return 0;
}
