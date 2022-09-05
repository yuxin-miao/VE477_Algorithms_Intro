/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

#define MAX 10000

class StackOverflow{};

class ArrStack {
    int top;
    char stack[MAX];
public:
    ArrStack() { top = 0; }
    bool isEmpty() { return top == 0; }
    bool isFull() { return top >= MAX - 1; }
    void push(char val);
    char pop();
};

void ArrStack::push(char val) {
    if (isFull()) throw StackOverflow(); 
    top++;
    stack[top] = val;
}

char ArrStack::pop() {
    if (isEmpty()) return NULL;
    char val = stack[top];
    top--;
    return val;
}
class Solution {

public:
    bool isValid(string s) {
        ArrStack stack;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            } else {
                char topVal = stack.pop();
                switch (s[i])
                {
                case ')':
                    if (topVal != '(') return false;
                    break;
                
                case '}':
                    if (topVal != '{') return false;
                    break;

                case ']':
                    if (topVal != '[') return false;
                    break;
                default:
                    return false;
                    break;
                }
            }
        }
        if (stack.isEmpty()) return true;
        return false;
    }
};
// @lc code=end

