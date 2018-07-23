/*
 
 정수 배열(int array)이 주어지면 두번째로 큰 값을 프린트하시오.

 예제)
 Input: [10, 5, 4, 3, -1]
 Output: 5
 
 Input: [3, 3, 3]
 Output: Does not exist.
 
 */
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin>> n;
    
    int *arr = new int[n];
    
    for( int i=0; i< n ; i++){
        cin>> arr[i];
    }
    
    int big= 0;
    int secondbig = 0;
    for( int i=0; i< n ; i++){
        if( big <= arr[i] ){
            big = arr[i];
            
        }
        else if( secondbig < arr[i] && big > secondbig){
            secondbig = arr[i];
        }
    }
    
    if( secondbig != 0){
        cout<< big<< endl << secondbig<<endl;
    }
    else{
        cout<< big<< endl << "Don't have second Big"<<endl;
    }
    
    
    
    
    return 0;
}
