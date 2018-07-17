
#include <algorithm>
#include <string>
#include <iostream>


using namespace std;

int arr[6] = { 0,};

void combination(int ind, int n, int k, int target){
    if( k ==  0 ){
        
        for( int i=0 ;i< ind ; i++){
            cout<< arr[i] << " ";
        }
        cout<< endl;
    }
    else if( n == target){
        return;
    }
    else{
        arr[ind] = target;
        combination( ind+1, n, k-1 ,  target +1 ) ;
        combination( ind ,  n  ,  k , target +1 );
    }
}

int main(int argc, const char * argv[]) {
    
    
    combination(0,5,3,0);
    
    return 0;
}
