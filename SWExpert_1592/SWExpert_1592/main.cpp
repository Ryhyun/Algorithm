
#include <iostream>
using namespace std;


/*
 1일 이용권 - 1일 이용
 1달 이용권 - 1일부터 시작
 3달 이용권 - 1일부터 시작   ( 11월 12월도 사용 가능)
 1년 이용권 - 1월1일부터 시작
 */
int result =0 ;
int d,m,tm,y;
int plan[13];


int main(int argc, const char * argv[]) {
    int T ;
    cin>> T;
    
    for( int t = 1; t<= T ; t++){
        cin>> d >> m>> tm >> y ;
        int dp[3][13] = {0,};
    
        for( int i =0 ; i< 12; i++){
            cin>> plan[i];
        }
        dp[0][0] = plan[0] * d ;
        if( dp[0][0] > m ){
            dp[1][0] = m;
            dp[2][0] = m ;
        }
        else{
            dp[1][0] = dp[0][0];
            dp[2][0] = dp[0][0];
        }
        for( int i=0; i< 3 ; i++){
            for( int j=1; j< 13; j++){
                dp[i][j] = dp[i][j-1] +   plan[j] * d;
            
                if( i >= 1 ){
                    if( dp[i][j-1] + m < dp[i][j ]   ){
                        dp[i][j] = dp[i][j-1] + m ;
                    }
                }
                if( i == 2  ) {
                    if( j == 2){
                        if( tm  < dp[i][j]  ){
                            dp[i][j] = tm;
                        }
                    }
                    else if( j > 2){
                        if( dp[i][j-3] + tm  < dp[i][j]  ){
                            dp[i][j] = tm + dp[i][j-3];
                        }
                    }
                }
            }
            
        }
        if( dp[2][12] > y ){
            result = y;
        }
        else{
            result = dp[2][12];
        }
        cout<<"#"<<t<<" "<< result<<endl;
    }
    
    
    
    return 0;
}
