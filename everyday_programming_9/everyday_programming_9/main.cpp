/*
 정수 배열(int array)이 주어지면 0이 아닌 정수 순서를 유지하며 모든 0을 배열 오른쪽 끝으로 옮기시오. 단, 시간복잡도는 O(n), 공간복잡도는 O(1)여야 합니다.
 Given an integer array, move all the 0s to the right of the array without changing the order of non-zero elements.

 예제)
 
 Input: [0, 5, 0, 3, -1]
 Output: [5, 3, -1, 0, 0]
 
 Input: [3, 0, 3]
 Output: [3, 3, 0]
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin>>n;
    int* array= new int[n];
    
    int si = 0 ;
    int ei = n-1;
    for( int i=0; i< n; i++){
        int input ;
        cin>>input;
        if (input != 0 ) {
            array[si] = input;
            si++;
        }
        else{
            array[ei] = input;
            ei--;
        }
    
    }
    for(int i=0 ; i< n ; i++){
        cout<< array[i]<<endl; 
    }
    
    
    delete array;


    return 0;
}
