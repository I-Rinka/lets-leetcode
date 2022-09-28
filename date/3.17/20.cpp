class Solution {
public:
    bool isValid(string s) {
        int l=s.size();
        stack<char>stk;
        for(int i=0;i<l;i++)
        {
            char c=s[i];
            if(c=='(')
            {
                stk.push(c);
            }
            else if(c=='{')
            {
                stk.push(c);
            }
            else if(c=='[')
            {
                stk.push(c);
            }

            else if(c==')')
            {
                if(stk.empty())
                {
                    return false;
                }
                else if(stk.top()=='(')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(c=='}')
            {
                if(stk.empty())
                {
                    return false;
                }
                else if(stk.top()=='{')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            else if(c==']')
            {
                if(stk.empty())
                {
                    return false;
                }
                else if(stk.top()=='[')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(stk.empty())
        {
            return true;
        }
        return false;
    }
};