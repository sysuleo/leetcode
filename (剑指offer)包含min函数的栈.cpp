/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

//若用int保存，当出栈后就找不到最小了  ------用一个辅助栈保存最小数

class Solution {
public:
    stack<int> Stack,MinStack;
    
    void push(int value) {
        Stack.push(value);
        if(MinStack.empty()){
            MinStack.push(value);
        }
        //if(value<=MinStack.top()){
        //   MinStack.push(value);
        //}
        else {
            int min=MinStack.top();
            value<=min ?MinStack.push(value):MinStack.push(min);
        }
    }
    
    void pop() {
        //if(MinStack.top()==Stack.top())  MinStack.pop();
        MinStack.pop();
        Stack.pop();
    }
    int top() {
        return Stack.top();
    }
    int min() {
        return MinStack.top();
    }
};
