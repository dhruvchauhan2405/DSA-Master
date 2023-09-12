#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveUsingRec(vector<vector<int>>& triangle, int level,int index,vector<vector<int>>& dp){
        if(level==triangle.size()-1){
            if(triangle[level].size()-1==index)
            return triangle[level][index];
            else
            return min(triangle[level][index],triangle[level][index+1]);
             
        }
        if(dp[level][index]!=-1) return dp[level][index];
        // include index
        int same= triangle[level][index]+solveUsingRec(triangle,level+1,index,dp);
        // include index+1
        int notsame= INT_MAX;
        if(index+1<triangle[level].size())
        notsame= triangle[level][index+1]+solveUsingRec(triangle,level+1,index+1,dp);

        return dp[level][index]= min(same,notsame);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0) return 0;
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return solveUsingRec(triangle,0,0,dp);
    }
};
int main(){
    vector<vector<int>> triangle;
    Solution s;
    int ans = s.minimumTotal(triangle);
}