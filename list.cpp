#include <bits/stdc++.h>
using namespace std;

// Function to check if a string is a palindrome using a list
bool checkPalindrome(const string& str) {
    list<char> charDeque(str.begin(), str.end()); // Initialize list with string characters

    // Compare characters from the beginning and the end
    return equal(charDeque.begin(), charDeque.end(), charDeque.rbegin());
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    // Call the modified function
    if (checkPalindrome(input)) {
        cout << input << " is a palindrome." << endl;
    } else {
        cout << input << " is not a palindrome." << endl;
    }
    return 0;
}
