class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        bool isPositive=true;
        for(i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                continue;
            }
            else if(s[i]=='-')
            {
                isPositive=false;
                i++;
                break;
            }
            else if(s[i]=='+')
            {
                i++;
                break;
            }
            else
            {
                break;
            }
        }
        long long ans=0;
        if(isPositive)
        {
            for(;i<s.size();i++)
            {
                if(s[i]<'0'||s[i]>'9')
                {
                    break;
                }
                ans*=10;
                ans+=(int)(s[i]-'0');
                if(ans>=INT_MAX)
                {
                    return INT_MAX;
                }
            }
        }
        else
        {
            for(;i<s.size();i++)
            {
                if(s[i]<'0'||s[i]>'9')
                {
                    break;
                }
                ans*=10;
                ans-=(int)(s[i]-'0');
                if(ans<=INT_MIN)
                {
                    return INT_MIN;
                }
            }
        }
        return ans;
    }
};