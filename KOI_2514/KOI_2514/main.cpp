
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {

    int m, k ;
    cin>> m >> k ;
    
    int arr[8][8];
    
    for( int i=0; i< 8 ; i++){
        for( int j=0; j< 8 ; j++){
            int tempV;
            cin >> tempV;
            arr[i][j] = m -  tempV;
        }
    }
    
    for( int i=0; i< 8 ; i++){
        for( int j=0; j< 8 ; j++){
            cout<< arr[i][j] <<" ";
        }
        cout<< endl;
    }
    
    
    return 0;
}
