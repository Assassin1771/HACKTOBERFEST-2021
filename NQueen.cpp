#include<iostream>
#include<cstring>
using namespace std;

void printboard(bool **board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool ifSafe(bool **board,int n, int row,int col){
    for(int i=0;i<col;i++){
        if(board[row][i]) return false;
    }
    for(int i=row,j=col;i>=0 &&j>=0;i--,j--){
        if(board[i][j]) return false;
    }
    for(int i=row,j=col;i<n && j>=0;i++,j--){
        if(board[i][j]) return false;
    }
    return true;
}

bool solve(bool **board,int n,int col){
    if(col==n) {
        printboard(board,n);
        return true;
    }
    bool res = false;
    for(int i=0;i<n;i++){
        if(ifSafe(board,n,i,col)){
            board[i][col] = 1;
            res = solve(board,n,col+1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    bool **board;
    board = new bool*[n];
    for(int i = 0; i <n; i++)  board[i] = new bool[n];
    memset(board,0,sizeof(board));
    printboard(board,n);
    for(int i=0;i<n;i++) free(board[i]);
    free(board);
    return 0;
}
