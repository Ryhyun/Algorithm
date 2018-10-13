#include <iostream>
using namespace std;
long dp[10000000] ;
long func(int n, int k){
    long answer= 0 ;
    
    dp[0] =0 ;

    for(int i= 1; i <= n; i++)
    {
        for(int j= 0; j < k; j++)
        {
            if( dp[j] != -1 )
            {
                if( dp[ j+ i] < dp[j] + i && j+i != k)
                {
                    dp[j +i] = dp[j] + i ;
                    answer = ( answer <dp[j +i]   )? dp[j+i] : answer;
                }
                
            }
            else{
                break;
            }
        }
    }
    return answer;
}

/*
 
 n, k
 2
 1
 2번 뛰어야 하는데
 1번은 밟으면 안돼
 
 
 */

int main(int argc, const char * argv[]) {

    for(int i=0; i < 10000000 ;i++){
        dp[i] = -1;
    }
    int n,k;
    cin>> n>>k;
    cout<< func(n,k);

    return 0;
}
