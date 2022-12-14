#include <iostream>
#include <string>
#include <vector>

using namespace std;

int transfer(string str) {
    int num = 0, index = 1;
    for (int i = 0; i < str.size() - 1; i++) {
        index *= 10;
    }

    for (int i = 0; i < str.size(); i++) {
        num += ((int) str[i] - 48) * index;
        index /= 10;
    }

    return num;
}


class Stack {
    int top;
    int size;
    int capacity;
    int *stack;
public:
    Stack(int capacity) {
        this->top = -1;
        this->size = 0;
        this->capacity = capacity;
        this->stack = new int(capacity);
    }

    void push(int value) {
        size++;
        stack[++top] = value;
    }

    int pop() {
        size--;
        return stack[top--];
    };

    void printStack() {
        cout << "Start" << endl;
        for (int i = top; i >= 0; i--) {
            cout << "|" << stack[i] << "|" << endl;
        }
        cout << "End" << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    int stackSize() {
        return size;
    }
};

int main() {
    string str;
    getline(cin, str);
    Stack stack(10000);

    int result = 0;

    string temp = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ' && str[i] != '+' && str[i] != '-') {
            temp += str[i];
        }
        else if (str[i] == ' ' && temp!=""){
            stack.push(transfer(temp));
            temp = "";
        }
        else if (str[i] == '+'){
            if (stack.stackSize() == 2){
                result += stack.pop();
                result += stack.pop();
            }
            else{
                result+=stack.pop();
            }
        }
        else if (str[i] == '-'){
            if (stack.stackSize() == 2){
                result -= stack.pop();
                result += stack.pop();
            }
            else{
                result-=stack.pop();
            }
        }
    }

    cout << result;

    return 0;
}
