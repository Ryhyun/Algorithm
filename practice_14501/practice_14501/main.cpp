
#include <iostream>
using namespace std;

int N;
int tArr[16];
int pArr[16];

int dpArr[17];

int main(int argc, const char * argv[]) {
    cin>>N;
    for( int i=0; i<N; i++){
        cin>> tArr[i] >> pArr[i];
        dpArr[i] = 0 ;
    }
    
    int result = 0 ;
    for(int i=0; i<N+1; i++){
        if( i + tArr[i] > N+1)
            continue;
        if( dpArr[i + tArr[i] ] < dpArr[i] + pArr[ i]){
            dpArr[i+ tArr[i] ] = dpArr[i] + pArr[ i];
            for(int j=i + tArr[i]; j<N+1; j++){
                if( dpArr[j] < dpArr[i+ tArr[i]])
                    dpArr[j] =dpArr[i+ tArr[i] ];
            }
            //cout<<endl;
            //result = (dpArr[i+ tArr[i]]  > result)? dpArr[i+ tArr[i]] : result;
        }
    }
    /*
    for(int i=0; i<N+1; i++){
        cout<< dpArr[i]<<" ";
    }
    cout<<endl;
    */
    cout<<dpArr[N]  <<endl;
    
    return 0;
}
/*
 1 1 1 1 1 1 1 1 1 1
 1 2 3 4 5 6 7 8 9 10
 
 
 */
