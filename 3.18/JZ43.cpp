class Solution {
public:
    int countDigitOne(int n) {
        string number=std::to_string(n);
        int len=number.size();
        size_t ans=0;
        for(int i=0;i<len;i++)
        {
            int p=len-i-1;
            int base=1;
            if(p==0)
            {
                base=0;
            }
            for(int j=0;j<p-1;j++)
            {
                base*=10;
            }
            int nBase=base*p;

            int now_nu=((int)(number[i]-'0'));
            
            ans+=now_nu*nBase;
            if(now_nu>1)
            {
                if(base==0)
                {
                    ans+=1;
                }
                ans+=base*10;
            }
            else if(now_nu==1)
            {
                if(base==0)
                {
                    ans+=1;
                }
                else{
                    ans+=n%(base*10)+1;
                }
            }
        }
        return ans;
    }
};