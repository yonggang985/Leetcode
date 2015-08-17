/*118	Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
Hide Tags Array
Hide Similar Problems (E) Pascal's Triangle II

*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int> > vec(numRows);
        for(int i=0; i<numRows; i++)
        {
            vec[i].resize(i+1);
            vec[i][0] = 1;
            vec[i][i] = 1;
            for(int j=1; j<i;j++)
            {
                vec[i][j] = vec[i-1][j-1] + vec[i-1][j];
            }
        }
        return vec;
    }
};