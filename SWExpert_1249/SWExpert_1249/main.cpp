#include <iostream>
using namespace std;

int arr[101][101] = {0,};

int road(int x,int y, int N){
    
    if( x >=N or y >= N or x <0 or y <0 ){
        return 0;
    }
    
    return min( road( x,y,N),);
}
int main(int argc, const char * argv[]) {
    int totalCase;
    int N;
    cin>> totalCase;
    
    
    
    
    for( int caseI = 1; caseI <= totalCase ; caseI ++){
        cin>>N;
        string line;
        for( int i=0; i<N ; i++){
            cin>> line;
            for( int j=0; j< N ; j++){
                arr[i][j] = int( line[j] - '0');
            }
        }
        
        
        //dp( N-1, N-1,N);
        
        
        for( int i=0; i<N ; i++){
            for(int j =0 ; j<N; j++){
                arr[i][j] = 0;
            }
        }
    }
    
    
    return 0;
}
