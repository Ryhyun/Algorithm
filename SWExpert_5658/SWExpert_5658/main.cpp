#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int result ;
int N,K;
vector< string > vec;
int main(int argc, const char * argv[]) {

    int T;
    cin>>T;
    for( int casei= 1; casei <= T; casei++){
        result = 0;
        cin>> N>>K;
        vec.clear();
        string input, resultS;;
        cin>> input;
        int L = N/4;
        for(int i=0 ; i< N  ;i++){
            string tempS;
            for(int j= i; j< i+ L; j++){
                tempS+= input[ (j) % N];
            }
            vec.push_back(tempS);
        }
        sort( vec.begin(), vec.end(), greater<string>());
        int cnt = 1;
        resultS = vec[0];
        for(int i=1; i< vec.size(); i++){
            if( vec[i-1].compare(vec[i]) == 0 )
                continue;
            else{
                cnt++;
                if( cnt== K ){
                    resultS = vec[i];
                    break;
                }
            }
        }
        for( int i=0; i < L; i++){
            if( int(resultS[i] ) > 64)
                result +=  int( resultS[i] -'A' + 10)* pow( 16,L-1- i);
            else
                result +=  int( resultS[i] -'0')* pow( 16, L-1- i);
        }
        cout<< "#"<< casei<<" "<< result<<endl;
    }
    
    return 0;
}
