

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n ,p;
    cin>> n ;
    int plant[17][17] ={ 0, };
    int onPlant[16] = {0,};
    
    for( int i=0 ;i < n ; i++){
        for(int j=0; j< n; j++){
            cin>> plant[i][j];
        }
    }
    string onoff;
    cin>> onoff;
    cin>> p ;
    
    
    for( int i=0; i< n ; i++){
        if( onoff[i] == 'Y'){
            onPlant[i] = 1;
        }
    }
    
    
    
    /*
     5
     0 20 40 100 100
     100 0 100 35 100
     100 100 0 14 100
     100 100 100 0 100
     100 100 100 100 0
     YNNNN
     3
     
     */
    
    
    
    return 0;
}
