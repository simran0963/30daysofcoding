/*Qs. You are given an m x n binary matrix matrix.
You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
Return the maximum number of rows that have all values equal after some number of flips.

 

Example 1:

Input: matrix = [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.
*/
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        // vector<string> v;
        unordered_map<string, int> mp;
        int ans = INT_MIN, n = mat.size(), m = mat[0].size();

        for(int i=0;i<n;i++){
            string strFreq = "";
            int j = 0, freq = 0, ele = mat[i][0];
            while(j < m-1 && mat[i][j] == ele){
                freq++;
                j++;
                if(mat[i][j] != ele){
                    strFreq = strFreq + to_string(freq) + " ";
                    freq = 0;
                    ele = mat[i][j];
                }
            }
            mp[strFreq]++;
            ans = max(ans, mp[strFreq]);
            // v.emplace_back(strFreq);
        }
        return ans;
    }
};