class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1=0,i2=0;
        int ans=0;
        
        while(true)
        {
            if(i1>=version1.size()&&i2>=version2.size())
            {
                break;
            }

            int a=0,b=0;

            if(i1<version1.size())
            {
                while(i1<version1.size()&&version1[i1]=='0')
                {
                    i1++;
                }
                int e1=version1.find('.',i1);
                if(e1==-1)
                {
                    e1=version1.size();
                }
                if(e1==i1)
                {
                    a=0;
                }
                else
                {
                    string num=version1.substr(i1,e1-i1);
                    a=std::stoi(num);
                }
                i1=e1+1;
            }

            if(i2<version2.size())
            {
                while(i2<version2.size()&&version2[i2]=='0')
                {
                    i2++;
                }
                int e2=version2.find('.',i2);
                if(e2==-1)
                {
                    e2=version2.size();
                }

                if(e2==i2)
                {
                    b=0;
                }
                else
                {
                    string num=version2.substr(i2,e2-i2);
                    b=std::stoi(num);
                }
                i2=e2+1;
            }


            if(a<b)
            {
                return -1;
            }
            else if(a>b)
            {
                return 1;
            }
        }
        return 0;
    }
};