
#include <iostream>

using namespace std;
int n;
int tArr[16] ={0,};
int pArr[16] ={0,};
int dp[16] ;


void recursive(int i){
    
    //for( int j=0; j<n ; j++){
    //    cout<< dp[j] <<" ";
    //}
    //cout<<endl;
    
    for( int j =  i + tArr[i] ; j < n;j++ ){
        if( dp[i] + pArr[j] > dp[j] and  j + tArr[j]  <= n ){
            //cout<<j<<endl;
            dp[j] =  dp[i] + pArr[ j];
            recursive( j) ;
        }
    }
    
    
}
int main(int argc, const char * argv[]) {
    
    cin>> n;
    for(int i=0; i< n ; i++){
        cin>> tArr[i] >> pArr[i];
        dp[i] = -1;
    }

    for(int i = 0 ; i< n  ; i++){
        //cout<<"!!"<<i<< " "<< dp[i]<<" " << tArr[i]<<" "<< pArr[i]<<endl;
        if( dp[i] == -1 and i +  tArr[i] <= n ){
            dp[i] = pArr[i];
            recursive(i);
        }
        if( dp[i] != -1  and i+ tArr[i]< n  ){
            
        }
    }
    
    int result =0;
    for(int i=0; i< n;i++){
        if( result < dp[i] and dp[i] != -1){
            result = dp[i];
        }
    }
    cout<< result;
    
    return 0;
}
