class Solution {
public:
    void mkVisit(int x,int y,vector<vector<bool>> &visit,vector<vector<char>>&grid, queue<pair<int,int>> &bq)
    {
            if(x>=0&&y>=0&&x<visit.size()&&y<visit[x].size()&&!visit[x][y]&&grid[x][y]=='1')
            {
                bq.push(make_pair(x,y));
                visit[x][y]=true;

                cout<<x<<','<<y<<endl;
            }
    }

    void bfs(pair<int,int>xy,vector<vector<bool>> &visit,vector<vector<char>>&grid)
    {
        queue<pair<int,int>> bq;
        bq.push(xy);
        this->mkVisit(xy.first,xy.second,visit,grid,bq);


        while(!bq.empty())
        {
            auto currentXY=bq.front();
            bq.pop();
            int x=currentXY.first,y=currentXY.second;

            this->mkVisit(x-1,y,visit,grid,bq);
            this->mkVisit(x+1,y,visit,grid,bq);
            this->mkVisit(x,y-1,visit,grid,bq);
            this->mkVisit(x,y+1,visit,grid,bq);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()<=0)
        {
            return 0;
        }

        vector<bool>b(grid[0].size(),false);
        vector<vector<bool>>visit(grid.size(),b);

        int ans=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(!visit[i][j]&&grid[i][j]=='1')
                {
                    // bfs
                    this->bfs(make_pair(i,j),visit,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};