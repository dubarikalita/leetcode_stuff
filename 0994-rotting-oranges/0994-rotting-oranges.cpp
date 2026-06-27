class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pair<int,int>>q;
        int freshOranges=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshOranges++;
                }
            }
        }
        if(freshOranges==0) return 0;

        int minutes=0;
        int directions[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            int levelSize=q.size();
            bool rottedThisMinute=false;

            for(int i=0;i<levelSize;++i){
                pair<int,int>current=q.front();
                q.pop();

                for(auto& dir:directions){
                    int r=current.first+dir[0];
                    int c=current.second+dir[1];

                    if(r>=0 && r<rows && c>=0 && c<cols && grid[r][c]==1){
                        grid[r][c]=2;
                        freshOranges--;
                        q.push({r,c});
                        rottedThisMinute=true;
                    }
                }
            }
            if (rottedThisMinute) minutes++;
        }
        return (freshOranges==0)? minutes:-1;
    }
};