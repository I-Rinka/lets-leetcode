class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end(),
        [](vector<int>&a,vector<int>&b)->bool{return a[1]<b[1];}
        );

        for(int i=intervals.size()-1;i>0;i--)
        {
            int start=intervals[i][0];
            int end=intervals[i-1][1];

            if(start<=end)
            {
                
                intervals[i-1][1]=intervals[i][1];

                if(intervals[i][0]<intervals[i-1][0])
                {
                    intervals[i-1][0]=intervals[i][0];
                }
                
                intervals.erase(intervals.begin()+i);
            }
        }

        return intervals;
    }
};