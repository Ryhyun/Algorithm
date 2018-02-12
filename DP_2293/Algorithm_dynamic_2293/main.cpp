#include <iostream>

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int coinArray[100] ={0,};
    
    for(int i=0; i< n; i++){
        cin>> coinArray[i];
    }
    
    int dp[10001] ={0,};
    for(int i=0; i<n;i++){
        for(int j=1 ; j<=k ;j++){
            if( j > coinArray[i]  ){
                dp[j] = dp[j] + dp[j-coinArray[i]];
            }
            if( j == coinArray[i]  ){
                dp[j] += 1;
            }
        }
    }
    cout<< dp[k];
    
    
    
    return 0;
}
