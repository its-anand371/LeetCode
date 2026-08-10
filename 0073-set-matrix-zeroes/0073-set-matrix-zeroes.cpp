class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m =matrix.size();
        int n =matrix[0].size();
        bool firstrowimpacted=false;
        bool firstcolimpacted=false;
        for(int col=0;col<n;col++){
            if(matrix[0][col]==0){
                firstrowimpacted=true;
                break;
            }
        }
        for(int row=0;row<m;row++){
            if(matrix[row][0]==0){
                firstcolimpacted=true;
                break;
            }
        }
        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstrowimpacted){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(firstcolimpacted){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};