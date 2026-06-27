class Solution {
private:
    void dfs(int row, int  col, vector<vector<int>>& image, int initialColor, int newColor){
        image[row][col]=newColor;

        int n=image.size();
        int m=image[0].size();

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+delCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==initialColor){
                dfs(nRow,nCol,image,initialColor,newColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor=image[sr][sc];
        if(initialColor==color) return image;

        dfs(sr,sc,image,initialColor,color);

        return image;
    }
};