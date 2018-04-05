
#include <iostream>
#include <queue>
using namespace std;
int n,k;
int nx[4] = { -1, 0,1 ,0};
int ny[4] = { 0,1 ,0, -1};


int longest;
int dfs(int ni , int nj, int result , int tempArr[9][9]){
    if( longest < result )
        longest = result ;
    
    for(int i=0; i< 4; i++){
        int nexti = ni + nx[i];
        int nextj = nj + ny[i];
        
        
        if( nexti >= n or nextj >= n or nexti < 0 or nextj < 0 ){
            continue;
        }
        if(  tempArr[nexti][nextj] < tempArr[ni][nj]  ){
            
            dfs( nexti, nextj , result+1  , tempArr);
            
        }
    }

    return result;
}



int main(int argc, const char * argv[]) {

    int total;
    cin>> total;
    for(int t = 1; t <= total; t++){
        cin>> n >> k ;
        int arr[9][9] = {0,};
        int bigV = 0 ;
        queue<int> bigi;
        queue<int> bigj;
        longest = 0 ;
        
        for( int i =0 ;i< n ; i++){
            for(int j=0; j< n ; j++){
                cin>> arr[i][j];
                if( arr[i][j] > bigV){
                    bigi = queue<int>();
                    bigj = queue<int>();
                    
                    bigV = arr[i][j];
                    bigi.push(i);
                    bigj.push(j);
                }
                else if(arr[i][j] == bigV){
                    bigi.push(i);
                    bigj.push(j);
                }
                else{
                    continue;
                }
            }
        }
        while( !bigi.empty() ){
            //cout<<"!!!!"<<endl;
            int starti = bigi.front();
            int startj = bigj.front();
            
            bigi.pop();
            bigj.pop();
            
            
            for(int i=0 ; i<= k ; i++){
                for(int j=0; j<n ; j++){
                    for(int kk = 0 ;kk < n; kk++){
                        
                        
                        int tempArr[9][9] ={0,};
                        for(int ii=0; ii< n ; ii++){
                            for(int jj=0; jj<n;jj++){
                                tempArr[ii][jj] = arr[ii][jj];
                            }
                        }
                        if( tempArr[j][kk] - i > 0 )
                            tempArr[j][kk] -= i;
                        else
                            tempArr[j][kk] = 0 ;
                        
                        dfs( starti, startj, 1  , tempArr );
                    }
                }
            }
        }
        cout<<"#"<<t<<" "<<longest<<endl;
        
    }
    
    return 0;
}
