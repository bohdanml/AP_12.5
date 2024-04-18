#include <iostream>
#include <fstream>
#include <stack>

using namespace std;


void readNumbersFromFile(stack<int>& numberStack, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    int num;
    while (file >> num) {
        if (num > 0)
            numberStack.push(num);
    }

    file.close();
}


void printStack(const stack<int>& numberStack) {
    stack<int> tempStack = numberStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}


void printNumbersInReverseOrderSkippingMultiples(const stack<int>& numberStack, int divisor) {
    stack<int> tempStack = numberStack;
    while (!tempStack.empty()) {
        int num = tempStack.top();
        if (num % divisor != 0)
            cout << num << " ";
        tempStack.pop();
    }
    cout << endl;
}

int main() {
    stack<int> numberStack;
    string filename = "numbers.txt"; 

    readNumbersFromFile(numberStack, filename);

    cout << "Stack of numbers read from file:" << endl;
    printStack(numberStack);

    int divisor;
    cout << "Enter a number, multiples of which will be skipped: ";
    cin >> divisor;

    cout << "Numbers of the stack in reverse order, skipping multiples of " << divisor << ":" << endl;
    printNumbersInReverseOrderSkippingMultiples(numberStack, divisor);

    return 0;
}
