#include <iostream>

using namespace std;


int main(void){
    int a,b,c,d,f,e;
    cin>> a>>b;
    
    c = a*a;
    d = c % b;
    f = d ;
    e = 10000;
    for(int i=0; d != e ; i++){
        e = f * a % b;
        f =e ;
        
        if( d== e){
            cout<< i;
        }
    }
    
    return 0;
}
