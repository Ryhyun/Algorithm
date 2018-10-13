
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int result;
int N,M,K;

int arr[500][500];
int memo[500][500];
int visited[500][500];
int ni[4] = {0,1,0,-1};
int nj[4] = {1,0,-1,0};
queue<pair<int,int> > que;
void infect(){
    for(int k =1; k< K; k++){
        //cout<<"-=-=-=-=-= "<< k<<endl;
        int length = que.size();
        for(int l = 0 ; l < length; l++){
            int nowi = que.front().first;
            int nowj = que.front().second;
            que.pop();
            if( memo[nowi][nowj] == k  ){
                if( visited[nowi][nowj] != -1 ){
                    if( arr[nowi][nowj] != 1){
                        que.push(make_pair(nowi,nowj ));
                        memo[nowi][nowj] = k + arr[nowi][nowj]-1;
                        visited[nowi][nowj] = -1;
                    }
                }
                else{
                    continue;
                }
                for(int i=0; i< 4 ; i++){
                    int nexti = nowi + ni[i];
                    int nextj = nowj + nj[i];
                    if( visited[nexti][nextj] == 0  || visited[nexti][nextj] == k+1){
                        if( arr[nexti][nextj] == 0 ){
                            //cout<<"Next "<< nexti<<" "<<nextj<<endl;
                            arr[nexti][nextj] = arr[nowi][nowj];
                            memo[nexti][nextj] = k + arr[nowi][nowj] + 1;
                            que.push(make_pair( nexti,nextj));
                            visited[nexti][nextj] = k+1;
                        }
                        else{
                            if(   arr[nexti][nextj] <  arr[nowi][nowj] ){
                                //cout<< "Change "<< nexti<< " " << nextj<<endl;
                                memo[nexti][nextj] = k+ arr[nowi][nowj]+1;
                                arr[nexti][nextj] = arr[nowi][nowj];
                            }
                        }
                    }
                    
                    
                }
            }
            else if( memo[nowi][nowj] > k ){
                que.push(make_pair(nowi,nowj ));
            }
        }
        
        
    }
    
}
/*
 1
 5 5 19
 3 2 0 3 0
 0 3 0 0 0
 0 0 0 0 0
 0 0 1 0 0
 0 0 0 0 2
 
 */
int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for( int casei = 1; casei <= T ; casei++){
        memset(arr, 0, sizeof(arr));
        memset(memo, 0, sizeof(memo));
        memset(visited,0, sizeof(visited));
        result = 0 ;
        cin>>N>>M>>K;
        int tempValue;
        for( int i=0; i<N; i++){
            for(int j=0; j<M ; j++){
                cin>> tempValue;
                if( tempValue !=0 ){
                    arr[i+250][j+250] = tempValue;
                    memo[i+250][j+250] = tempValue;
                    visited[i+250][j+250] = 1;
                    que.push(make_pair( i+250,j+250));
                }
            }
        }
        infect();
        int size = que.size();
        cout<<"#"<<casei<<" "<< size<<endl;
        
        for(int i=0; i< size; i++){
            que.pop();
        }
        
    }
    return 0;
}
