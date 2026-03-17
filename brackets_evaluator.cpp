#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            else {
                // If we encounter a closing bracket but the stack is empty, 
                // it means there's no opening bracket to match it.
                if (st.empty()) return false;

                char top = st.top();
                
                // Check if the current closing bracket matches the last opening bracket
                if ((c == ')' && top == '(') || 
                    (c == ']' && top == '[') || 
                    (c == '}' && top == '{')) {
                    st.pop(); // Match found, remove the opening bracket
                } else {
                    return false; // Mismatch found
                }
            }
        }

        // If the stack is empty, all brackets were matched and closed in order
        return st.empty();
    }
};

int main() {
    Solution sol;
    string userInput;

    cout << "Enter a string of brackets (e.g., {([])}): ";
    
    // Using getline to handle the input string
    getline(cin, userInput);

    // Using boolalpha to print "true" or "false" instead of 1 or 0
    if (sol.isValid(userInput)) {
        cout << "Result: The string is VALID." << endl;
    } else {
        cout << "Result: The string is INVALID." << endl;
    }

    return 0;
}