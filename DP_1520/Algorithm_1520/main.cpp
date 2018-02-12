#include <iostream>


using namespace std;
/*
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10
*/
int M,N;
int inputArray[501][501] ={0,};
int dp[501][501] = {0,};
int visited[501][501]={0,};
int directionX[4] = { 1,-1,0,0};
int directionY[4] = { 0, 0,1,-1};


int memoCount(int m,int n){
    if( m==0 and n==0 )
        return 1;
    
    for(int i=0; i< 4;i++){
        int nextX = m - directionX[i];
        int nextY = n - directionY[i];
        if(nextX >= 0  and nextX< N and nextY >= 0  and nextY < M){
            if( inputArray[m][n] < inputArray[nextX][nextY] ){
                if(visited[nextX][nextY] == 0 ){
                    dp[m][n] += memoCount(nextX,nextY);
                    visited[nextX][nextY] = 1 ;
                }
                else
                    dp[m][n] += dp[nextX][nextY];
            }
        }
    }
    return dp[m][n];
}

int main() {
    cin>>N>>M;
    for(int i=0; i< N; i++){
        for(int j=0; j<M;j++){
            scanf("%d", &inputArray[i][j]);
        }
    }
    dp[0][0] =1 ;
    cout<<memoCount(N-1,M-1);

    return 0;
}
