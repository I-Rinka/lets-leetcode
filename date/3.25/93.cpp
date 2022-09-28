class Solution {
public:
    void traverse(string remain,string current,int level,vector<string>&ans)
    {
        // cout<<remain<<" current:"<<current<<" level:"<<level<<endl;
        if(level<=0&&remain.size()>0)
        {
            return;
        }
        if(remain.size()==0&&level==0)
        {
            ans.push_back(current.substr(1));
            return;
        }

        if(remain[0]=='0')
        {
            if((level-1)*3>=remain.size()-1)
            {
                this->traverse(remain.substr(1),current+'.'+'0',level-1,ans);
            }
        }
        else{
            int i=1;
            while(i<=remain.size()&&i<=3)
            {
                if(remain[i-1]<='9'||remain[i-1]>='0')
                {
                    string curNumber=remain.substr(0,i);
                    if(std::stoi(curNumber)<=255&&(level-1)*3>=remain.size()-i)
                    {
                        this->traverse(remain.substr(i),current+'.'+curNumber,level-1,ans);
                    }
                    i++;
                }
                else
                {
                    return;
                }
            }
        }       
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;

        this->traverse(s,string(),4,ans);
        return ans;
    }
};