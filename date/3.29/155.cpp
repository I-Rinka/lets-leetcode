class MinStack {
public:
    stack<int>stk;
    stack<int>minStk;
    MinStack() {

    }
    
    void push(int val) {
        this->stk.push(val);
        if(this->minStk.empty() || val<=this->minStk.top())
        {
            this->minStk.push(val);
        }
    }
    
    void pop() {
        if(stk.top()==this->minStk.top())
        {
            this->minStk.pop();
        }
        this->stk.pop();
    }
    
    int top() {
        return this->stk.top();
    }
    
    int getMin() {
        return this->minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */