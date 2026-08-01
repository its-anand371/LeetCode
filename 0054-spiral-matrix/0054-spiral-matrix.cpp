class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int srow=0;
        int scol=0;
        int erow=m-1;
        int ecol=n-1;
        vector<int>result;
        while(erow>=srow && ecol>=scol){
            for(int i=scol;i<=ecol;i++){
                result.push_back(matrix[srow][i]);
            }
            for(int i=srow+1;i<=erow;i++){
                result.push_back(matrix[i][ecol]);
            }
            for(int i=ecol-1;i>=scol;i--){
                if(srow==erow){
                    break;
                }
                result.push_back(matrix[erow][i]);
            }
            for(int i =erow-1;i>srow;i--){
                if(scol==ecol){
                    break;
                }
                result.push_back(matrix[i][scol]);
            }
            srow++;
            scol++;
            erow--;
            ecol--;
        }
        return result;
    }
};