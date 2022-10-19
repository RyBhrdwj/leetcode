#include<iostream>
#include<vector>
using namespace std;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
private:

    class Node
    {
        public:
            int data;
            int min;
            Node* next;
            Node(int data)
            {
                this->data = data;
                next = nullptr;
            }
    };

    Node* Top;
public:
    
    MinStack() {
        Top = nullptr;
    }
    
    void push(int val) {
        Node* node = new Node(val);
        node->min = val;
        if(Top)
        {
            node->min = Top->min < val ? Top->min : val;
        }
        node->next = Top;
        Top = node;
    }
    
    void pop() {
        // Add a function to fetch min
        Node* temp = Top;
        Top = Top->next;
        temp = nullptr;
    }
    
    int top() {
        return Top->data;
    }
    
    int getMin() {
        return Top->min;
    }
};