class MyQueue {
public:
    shared_ptr<stack<int>>S1;
    shared_ptr<stack<int>>S2;
    MyQueue() {
        this->S1=make_shared<stack<int>>();
        this->S2=make_shared<stack<int>>();
    }
    
    void push(int x) {
        if(S2->empty())
        {
            S1->push(x);
        }
        else
        {
            while(!S2->empty())
            {
                S1->push(S2->top());
                S2->pop();
            }
            S1->push(x);
        }
    }
    
    int pop() {
        int ans;
        if(S1->empty())
        {
            ans=S2->top();
            S2->pop();
        }
        else
        {
            while(!S1->empty())
            {
                S2->push(S1->top());
                S1->pop();
            }
            ans=S2->top();
            S2->pop();
        }
        return ans;
    }
    
    int peek() {
        if(S1->empty())
        {
           return S2->top();
        }
        else
        {
            while(!S1->empty())
            {
                S2->push(S1->top());
                S1->pop();
            }
            return S2->top();
        }
    }
    
    bool empty() {
        return S1->empty()&&S2->empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */