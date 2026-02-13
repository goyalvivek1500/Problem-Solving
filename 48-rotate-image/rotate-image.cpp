class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

       //90 degree rotation
       int rows=matrix.size();
       int cols=matrix[0].size();

       //first do transpose
       for(int i=0;i<rows-1;i++)
       {
        for(int j=i+1;j<cols;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
       }

       for(int i=0;i<rows;i++)
       {
        int start=0,end=cols-1;
        while(start<=end)
        {
            swap(matrix[i][start],matrix[i][end]);
            start++;
            end--;
        }
       }
    }
};