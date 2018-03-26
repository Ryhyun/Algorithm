
#include <iostream>

using namespace std;
int arr[1001] = {0,};

int light( int i){
    
    if( arr[i] < arr[i-2] or arr[i] < arr[i-1] or arr[i] < arr[i+1] or arr[i] <arr[i+2])
        return 0;
    
    int smallest  = 1000;
    for( int j = -2 ; j <= 2; j++){
        if( j == 0 )
            continue;
        if( arr[i] - arr[i + j ] < smallest)
            smallest = arr[i] - arr[i + j ];
    }
    return smallest;
}


int main(int argc, const char * argv[]) {

    int results[10] ={0,};
    
    for(int i= 1; i<= 2; i++){
        int n;
        cin>> n ;
        int result =0 ;

        
        for(int j=0; j< n; j++){
            cin>> arr[j];
        }
        for( int j = 2; j< n-3 ; j++){
            result += light(j);
        }
        results[i-1] = result;
    }
    
    
    for(int j =1 ; j <= 2 ; j++){
        cout<< "#"<<j<<" "<< results[j-1]<<endl;
    }
    
    return 0;
}
