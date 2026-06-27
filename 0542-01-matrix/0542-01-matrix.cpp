class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> dist(n,vector<int>(m,-1));

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int newRow=row+delRow[k];
                int newCol=col+delCol[k];

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m &&
                dist[newRow][newCol]==-1){
                    dist[newRow][newCol]=dist[row][col]+1;
                    q.push({newRow,newCol});
                }
            }
        }
        return dist;
    }
};