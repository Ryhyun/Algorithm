
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n ;
    int* arr = new int[n];
    int total = 0 ;
    int maxv=0;
    for( int i=0 ; i< n ; i++){
        cin>> arr[i];
        total += arr[i];
        if ( arr[i] >maxv ){
            maxv= arr[i];
            
        }
    }
   
    int max;
    cin >> max;
    int temp = max;
    for(int i=0; i< n ; i++){
        temp -= arr[i];
    }
    if( temp >= 0 ) {
        cout<< maxv<<endl;
        return 0;
    }
    
    int smallest;
    int left = max /( n) ;
    
    int right = maxv;
    
    while( left <= right){
        smallest =  ( left + right) /2 ;
        //cout<< smallest<<endl;
        
        int sum =0 ;
        for(  int j =0 ; j< n; j++){
            if(  smallest > arr[j] ){
                sum += arr[j];
            }
            else{
                sum += smallest ;
            }
        }
        //cout<< sum<<endl;
        if( sum > max ){
           
            right = smallest -1 ;
            
        }
        else if( sum < max){
            
            left = smallest+ 1;
        }
        
    }

    //cout<< smallest<<endl;
    cout<< left-1<<endl;
    
    
    
    return 0;
}
