
#include <iostream>
#include <algorithm>


using namespace std;
int numberVector[5000000];
int n,k;
/*
5 2
4 1 2 3 5
*/

int median(int a, int b, int c){
    return max( min(a,b),min(max(a,b),c));
    
}
void DAC( int start, int end ){
    
    int mid= (start + end) / 2 ;
    int pivotValue = median(numberVector[start],numberVector[mid],numberVector[end]);
    int i = start;
    int j = end;
    while( i < j  ){
        if( numberVector[i] < pivotValue){
            i++;
            continue;
        }
        if( numberVector[j] >pivotValue){
            j--;
            continue;
        }
        if( numberVector[i] >= pivotValue and numberVector[j] <= pivotValue){

            int temp;
            temp = numberVector[i];
            numberVector[i] = numberVector[j];
            numberVector[j]= temp;
            
        }
    }

    if( i - start !=0  and k <= i  )
        DAC(start,i);
    if( end -i !=0  and  k >= i )
        DAC(i+1 , end);
    
    
    
    
}


int main() {

    scanf("%d %d",&n,&k);
    
    for(int i=0; i< n;i++){
        scanf("%d",&numberVector[i]);
    }
    //DAC( 0, n-1);
    nth_element(numberVector,numberVector + k -1  , numberVector+ n);
    cout<< numberVector[k-1];
    
    
    
    return 0;
}
