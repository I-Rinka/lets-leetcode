class Solution {
public:
    string addStrings(string num1, string num2) {
        int offset=1;
        int carry=0;
        string ans;
        while(offset<=num1.size()||offset<=num2.size())
        {
            int n1=0;
            int n2=0;
            if(offset<=num1.size())
            {
                n1=(int)num1[num1.size()-offset]-(int)'0';

            }
            if(offset<=num2.size())
            {
                n2=(int)num2[num2.size()-offset]-(int)'0';
            }
            int now=n1+n2+carry;
            carry=now/10;
            now%=10;
            ans.push_back('0'+now);
            offset++;
        }
        if(carry>0)
        {
            ans.push_back('0'+carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};