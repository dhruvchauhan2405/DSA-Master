#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &grid){
    for(auto i:grid){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

void KnightTour(vector<vector<int>> & grid , int currRow, int currCol,int upcomingVal, int n){
    if(upcomingVal==n*n){
        display(grid);
        cout<<"\n";
        return;
    }

    if(currRow<0 || currRow>=n || currCol<0 || currCol>=n || grid[currRow][currCol]!=0){
        return;
    }

    grid[currRow][currCol] = upcomingVal;

    KnightTour(grid,currRow-2,currCol-1,upcomingVal+1,n);
    KnightTour(grid,currRow-2,currCol+1,upcomingVal+1,n);
    KnightTour(grid,currRow+2,currCol-1,upcomingVal+1,n);
    KnightTour(grid,currRow+2,currCol+1,upcomingVal+1,n);
    KnightTour(grid,currRow-1,currCol-2,upcomingVal+1,n);
    KnightTour(grid,currRow-1,currCol+2,upcomingVal+1,n);
    KnightTour(grid,currRow+1,currCol-2,upcomingVal+1,n);
    KnightTour(grid,currRow+1,currCol+2,upcomingVal+1,n);

    grid[currRow][currCol] = 0;
    return;
}

int main() {
   int n;
   cin>>n;
   vector<vector<int>> grid(n,vector<int>(n,0));
   KnightTour(grid,0,0,1,n);
   return 0;
}