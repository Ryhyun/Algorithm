
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream input("2.inp");
    ofstream output("test.out");
    int s,d,t,w;
    input >> s>> d>> t>> w;
    int n;
    input>>n;
    
    
    int date[366] = {0,};
    int dp[366] = {0,};
    
    int tempd=0;
    int tempr;
    for( int i=1; i<= n ; i++){
        input >> tempd>>tempr;
        date[tempd] = tempr;
    }
    
    for( int i=1; i<= tempd; i++){
        // single
        dp[i] = dp[i-1] + date[i] * s;
        
        // date
        if( dp[i] > dp[i-1] + d){
            dp[i] = dp[i-1] + d;
        }
        // triple
        if( i > 3 and dp[i] > dp[i-3] + t){
            dp[i] = dp[i-3] + t;
            
        }
        // week
        if( i % 7 == 0  and dp[i] > dp[i-7] + w){
            dp[i] = dp[i-7] + w ;
        }
        
        //cout<< dp[i]<<" ";
    }
    cout<< dp[tempd];

    return 0;
}
