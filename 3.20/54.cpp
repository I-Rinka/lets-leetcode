class Solution {
public:
    vector<int>ans;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        this->recur(make_pair(0,0),make_pair(matrix.size()-1,matrix[0].size()-1),matrix);
        return this->ans;
    }
    void recur(pair<int,int> leftTop,pair<int,int> rightBottom,vector<vector<int>>& matrix)
    {
        for(int i=leftTop.second;i<=rightBottom.second;i++)
        {
            ans.push_back(matrix[leftTop.first][i]);
        }

        for(int i=leftTop.first+1;i<=rightBottom.first;i++)
        {
            ans.push_back(matrix[i][rightBottom.second]);
        }

        // bottom
        for(int i=rightBottom.second-1;i>=leftTop.second&&rightBottom.first!=leftTop.first;i--)
        {
            ans.push_back(matrix[rightBottom.first][i]);
        }

        for(int i=rightBottom.first-1;i>leftTop.first&&leftTop.second!=rightBottom.second;i--)
        {
            ans.push_back(matrix[i][leftTop.second]);
        }

        if(leftTop.first+1<=rightBottom.first-1&&leftTop.second+1<=rightBottom.second-1)
        {
            this->recur(make_pair(leftTop.first+1,leftTop.second+1),make_pair(rightBottom.first-1,rightBottom.second-1),matrix);
        }
        return;
    }
};