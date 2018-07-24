
#include <iostream>
#include <queue>
#include <map>

using namespace std;


int nx[4] = { 1,-1, -1, 1  };
int ny[4] = { 1 ,1, -1 ,-1   };
int arr[21][21] = {0,};
int desert[101] = {0,};
int n ;
int result;

void DFS( int si, int sj ,int ti, int tj, int v, int turn, int cnt){
    if( v == 4){
        return;
    }
    int nextI = ti + nx[v];
    int nextJ = tj + ny[v];
    
    if( si == nextI && sj == nextJ ){
        if( result < cnt){
            result = cnt;
        //    cout<< result<<endl;
        }
        return;
        
    }
    if( nextI < 0 || nextI >= n || nextJ <0 || nextJ >= n   ){
        return;
    }
    else if( desert[ arr[nextI][nextJ]]  == 1 ){
        return;
    }
    else{
        //cout<< nextI<<" "<< nextJ<<endl;
        
        desert[ arr[nextI][nextJ]]  = 1;
        DFS( si,sj, nextI,nextJ,  v  ,turn, cnt+ 1 );
        DFS( si,sj, nextI,nextJ, (v +1) ,turn, cnt +1 );
        
        desert[ arr[nextI][nextJ]]  = 0;
        
    }
}

int main(int argc, const char * argv[]) {
    int T;
    cin>> T;
    for( int t=1; t<= T ;t++){
        cin>> n;
        result= 0 ;
        
        
        for( int i=0; i< n; i++){
            for( int j=0 ; j < n ;j++){
                cin>> arr[i][j];
            }
        }
        for( int i=0; i< n; i++){
            for( int j=0 ; j < n ;j++){
                for( int k=0 ; k< 101; k++){
                    desert[k] = 0 ;
                }
                
                if(  (i == 0&& j==0  ) || (i == n-1 && j == n-1 ) || ( i ==0 && j ==n -1 )|| ( i== n-1 && j ==0 )){
                    continue;
                }
                
                desert[ arr[i][j] ] = 1 ;
                DFS(i,j,i,j,  0, 1, 1 );
                
                //DFS(i,j,i,j,  k, -1, 1);
                desert[ arr[i][j] ] = 0 ;
            }
        }
    
        if( result ==0 ){
            result = -1 ;
        }
        cout<< "#"<<t<<" "<< result<<endl;
        
        
        
        
        
    }
    
    
    
    return 0;
}
