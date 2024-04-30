#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100; 

class Stack {
private:
    int elements[MAX_SIZE]; 
    int top_index; 

public:
    Stack() : top_index(-1) {
        
        for (int i = 0; i < MAX_SIZE; ++i) {
            elements[i] = 0;
        }
    } 
    void push(int value) {
        if (top_index == MAX_SIZE - 1) {
            cerr << "Error: Stack is full." << endl;
            return;
        }
        elements[++top_index] = value;
    }

    int pop() {
        if (empty()) {
            cerr << "Error: Stack is empty." << endl;
            return -1;
        }
        return elements[top_index--];
    }

    bool empty() const {
        return top_index == -1;
    }

    int top() const {
        if (empty()) {
            cerr << "Error: Stack is empty." << endl;
            return -1;
        }
        return elements[top_index];
    }
};

void readNumbersFromFile(Stack& numberStack, const string& filename) {
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

void printStack(const Stack& numberStack) {
    Stack tempStack = numberStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}

void printNumbersInReverseOrderSkippingMultiples(const Stack& numberStack, int divisor) {
    Stack tempStack = numberStack;
    while (!tempStack.empty()) {
        int num = tempStack.top();
        if (num % divisor != 0)
            cout << num << " ";
        tempStack.pop();
    }
    cout << endl;
}

int main() {
    Stack numberStack;
    string filename = "numbers.txt";

    
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return 1; 
    }

    
    int num;
    while (file >> num) {
        if (num > 0)
            numberStack.push(num);
    }

    file.close(); 

    cout << "Stack of numbers read from file:" << endl;
    printStack(numberStack);

    int divisor;
    cout << "Enter a number, multiples of which will be skipped: ";
    cin >> divisor;

    cout << "Numbers of the stack in reverse order, skipping multiples of " << divisor << ":" << endl;
    Stack tempStack = numberStack;
    while (!tempStack.empty()) {
        int num = tempStack.top();
        if (num % divisor != 0)
            cout << num << " ";
        tempStack.pop();
    }
    cout << endl;

    return 0;
}
