#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSafe(int row,int col,vector<string> &board,int n){
    int duprow=row;
    int dupcol=col;
    while(row>=0 && col>=0){
        if (board[row][col]=='Q') return false;
        row--;
        col--;
    }
    col=dupcol;
    row=duprow;
    while(col>=0){
        if (board[row][col]=='Q') return false;
        col--;
    }
    row=duprow;
    col=dupcol;
    while(row<n && col>=0){
        if (board[row][col]=='Q') return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col,int n,vector<vector<string>>& ans,vector<string> &board){
    if (col==n){
        ans.push_back(board);
        return;
    }
    for (int i=0;i<n;i++){
        if (isSafe(i,col,board,n)){
            board[i][col]='Q';
            solve(col+1,n,ans,board);
            board[i][col]='.';
        }
    }
}

int main(){
    int n;
    cout<<"Enter  the size of chessboard: ";
    cin>>n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string a(n,'.');
    for (int i=0;i<n;i++){
        board[i]=a;
    }
    solve(0,n,ans,board);
    for (int i=0;i<ans.size();i++) {
        for (int j=0;j<n;j++) {
            cout << ans[i][j]<<endl;
        }
    }
    return 0;
}