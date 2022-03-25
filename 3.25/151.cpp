class Solution {
public:
    string reverseWords(string s) {
        int l=0;
        while(l<s.size()&&s[l]==' ')
        {
            l++;
        }
        s.erase(0,l);

        int r=s.size()-1;
        while(r>=0&&s[r]==' ')
        {
            r--;
        }
        s.erase(r+1);

        l=0;
        r=s.size()-1;

        while(l<r)
        {
            char t=s[l];
            s[l]=s[r];
            s[r]=t;
            l++;
            r--;
        }

        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                int t=0;
                while(i+t+1<s.size()&&s[i+t+1]==' ')
                {
                    t++;
                }
                s.erase(i,t);
            }
        }

        int curC=0;
        while(curC<s.size())
        {
            int spaceC=curC;
            while(spaceC<s.size()&&s[spaceC]!=' ')
            {
                spaceC++;
            }

            int t=spaceC+1;
            spaceC--;

            while(curC<spaceC)
            {
                char t=s[curC];
                s[curC]=s[spaceC];
                s[spaceC]=t;
                curC++;
                spaceC--;
            }

            curC=t;
        }

        return s;
    }
};