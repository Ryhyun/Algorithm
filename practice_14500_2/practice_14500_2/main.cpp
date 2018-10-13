//
//  main.cpp
//  practice_14500_2
//
//  Created by ChoiChang hyun on 2018. 10. 8..
//  Copyright © 2018년 ChoiChang hyun. All rights reserved.
//

#include <iostream>
using namespace std;
int N,M;
int arr[501][501];
int visited[501][501] ={0,};
int ni[4] = {1,0,0,-1};
int nj[4] = {0,1,-1,0};
int result= 0 ;
void dfs(int pi, int pj, int depth,int sum){
    //cout<< pi<<" "<< pj<<" "<< depth<< " "<< sum<<endl;
    if( depth == 3){
        result = (result > sum )? result: sum;
        //cout<< result<<endl;
        return;
    }
    for(int v=0; v< 3; v++){
        int nexti = pi + ni[v];
        int nextj = pj + nj[v];
        if( nexti >=  N || nextj >= M || nexti < 0 || nextj <0)
            continue;
        
        if( visited[nexti][nextj] != 1){
            visited[nexti][nextj] = 1;
            dfs( nexti,nextj,depth+1, sum+ arr[nexti][nextj]);
            visited[nexti][nextj] = 0;
        }

    }
    
}
void polyomino(int pi, int pj){
    if( pi+1 <N && pj +2 < M){
        result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi+1][pj+1] + arr[pi][pj+2])?
        result : arr[pi][pj] + arr[pi][pj+1] + arr[pi+1][pj+1] + arr[pi][pj+2];
    }
    if(pi+1 <N && pi > 0 ){
        result = ( result > arr[pi][pj] + arr[pi][pj+1] + arr[pi-1][pj+1] + arr[pi][pj+2])?
        result : arr[pi][pj] + arr[pi][pj+1] + arr[pi-1][pj+1] + arr[pi][pj+2];
    }
    
    if( pi+2 <N && pj +1 < M){
        result = ( result > arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj+1] + arr[pi+2][pj])?
        result : arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj+1] + arr[pi+2][pj];
    }
    if(pi+2 <N && pj > 0 ){
        result = ( result > arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj-1] + arr[pi+2][pj])?
        result : arr[pi][pj] + arr[pi+1][pj] + arr[pi+1][pj-1] + arr[pi+2][pj];
    }
}

int main(int argc, const char * argv[]) {
    
    cin>>N>>M;
    for( int i=0; i<N; i++){
        for(int j=0 ; j<M; j++){
            cin>> arr[i][j];
        }
    }
    for( int i=0; i<N; i++ ){
        for( int j=0; j<M; j++){
            visited[i][j]= 1;
            dfs( i, j , 0, arr[i][j]);
            visited[i][j] =0;
            polyomino(i,j);
            ////cout<<"---=-=-=-"<<endl;;
        }
    }
    cout<< result<<endl;
    return 0;
}
