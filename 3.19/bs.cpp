#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<bool>v({true,false,true});

    for (size_t i = 0; i < 6; i++)
    {
        v.push_back(false);
    }
    

    vector<vector<bool>>bs(10,v);

    for (size_t i = 0; i < bs.size(); i++)
    {
        for (size_t j = 0; j < bs[i].size(); j++)
        {
            cout << bs[i][j];
        }
        cout<<endl;
    }
    return 0;
}
