
#include <iostream>
#include <queue>
using namespace std;
int arr[301][301] = {0,};
int memo[301][301] = {0,};

int nx[4] = { -1, 0,1 ,0};
int ny[4] = { 0,1 ,0, -1};
int iceburg = 0;

void chkMinus(int n,int m){
    for( int i=0 ; i< 4 ; i++){
        if( n + nx[i] < 0 or m +ny[i] < 0 or m + nx[i] > 300 or n+ ny[i] >300)
            continue;
        if( arr[n + nx[i]][ m + ny[i]] == 0  ){
            memo[n][m]++;
        }
    }
}

void dfs(int m,int n){
    int visited[301][301] ={0,};
}

int main(int argc, const char * argv[]) {
    int n,m;
    cin>> n >> m ;
    
    for(int i=0; i<n;i++){
        for( int j=0 ; j< m ; j++){
            cin>> arr[i][j] ;
            if( arr[i][j] != 0 )
                iceburg++;
        }
    }
    
    int result=0 ;
    while( true){
        
        result++;
    
        
        for(int i=0; i< n ; i++){
            for(int j=0; j<m ; j++){
                if( arr[i][j] != 0 ){
                    chkMinus(i,j);
                }
            }
        }
        
        for(int i=0; i< n ; i++){
            for(int j=0; j<m ; j++){
                if(arr[i][j] - memo[i][j] >0 )
                    arr[i][j] -= memo[i][j];
                else{
                    arr[i][j] = 0;
                    iceburg=0;
                }
            }
        }
        
        
        
        
        for(int i=0; i< n ; i++){
            for(int j=0; j<m ; j++){
                memo[i][j] =0;
            }
        }
        
        
        
        
    }
    
    
    
    
    return 0;
}
