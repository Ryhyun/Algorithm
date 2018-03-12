

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[10];
    for( int i=0; i< 10; i++){
        cin >> arr[i];
    }
    int result =0 ;
    int preResult = 0;
    for( int i=0; result < 100 ; i++){
        preResult = result ;
        result += arr[i];
    }
    if( 100 - preResult  >= result - 100 ){
        cout<< result<<endl;
    }
    else{
        cout<< preResult<<endl;
    }
    
    return 0;
}
