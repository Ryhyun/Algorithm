
#include <iostream>
#include <queue>
using namespace std;
int arr[301][301] = {0,};
int memo[301][301] = {0,};
int visited[301][301] ={0,};
int nx[4] = { -1, 0,1 ,0};
int ny[4] = { 0,1 ,0, -1};
int iceburg = 0;
int tempIceburg ;
int n,m;
void chkMinus(int n,int m){
    for( int i=0 ; i< 4 ; i++){
        if( n + nx[i] < 0 or m +ny[i] < 0 or m + nx[i] > 300 or n+ ny[i] >300)
            continue;
        if( arr[n + nx[i]][ m + ny[i]] == 0  ){
            memo[n][m]++;
        }
    }
}

void recursive(int nn,int mm){
    
    
    for( int i=0; i< 4; i++){
        int nextX = nn+ nx[i];
        int nextY = mm+ ny[i];
        if( nextX < 0 or nextX > n or nextY < 0 or nextY > m ){
            return;
        }
        if( arr[nextX][nextY] != 0 and visited[nextX][nextY] != 1){
           // cout<< nextX << " " <<nextY<<endl;
            tempIceburg++;
            visited[nextX][nextY] = 1;
            recursive( nextX,nextY);
        }
        
    }
}

int main(int argc, const char * argv[]) {

    cin>> n >> m ;
    
    for(int i=0; i<n;i++){
        for( int j=0 ; j< m ; j++){
            cin>> arr[i][j] ;
            if( arr[i][j] != 0 )
                iceburg++;
        }
    }
    
    int result=0 ;
    tempIceburg = iceburg;
    while( iceburg == tempIceburg){
        
        result++;
    
        
        for(int i=0; i< n ; i++){
            for(int j=0; j<m ; j++){
                if( arr[i][j] != 0 ){
                    chkMinus(i,js);
                }
            }
        }
        
        for(int i=0; i< n ; i++){
            for(int j=0; j<m ; j++){
                if( arr[i][j] != 0 ){
                    if(arr[i][j] - memo[i][j] >0 )
                        arr[i][j] -= memo[i][j];
                    else{
                        arr[i][j] = 0;
                        iceburg--;
                    
                    }
                }
            }
        }
        
        //cout<< "iceburg "<< iceburg<<endl;
        bool chk = false;
        for(int i=0; i< n ; i++){
            for(int j=0; j<m ;j++){
                visited[i][j] = 0 ;
            }
        }
        tempIceburg = 0 ;
        for(int i=0; i< n ; i++){
            for(int j=0; j<m ; j++){
                if( arr[i][j] != 0 ){
                    recursive(i,j);
                    chk =true;
                    break;
                }
            }
            if( chk == true)
                break;
        }
//        cout<< tempIceburg<<endl;
        
        
        
        
        for(int i=0; i< n ; i++){
            for(int j=0; j<m ; j++){
                memo[i][j] =0;
            }
        }
    }
    cout<< result<<endl;
    
    
    
    return 0;
}
