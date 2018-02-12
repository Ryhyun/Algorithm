#include <iostream>
using namespace std;
unsigned long long int  GCD(unsigned long long int a, unsigned long long int b){
    if( a % b ==0)
        return b;
    else
        return GCD(b, a%b);
}

int main() {
    unsigned long long int A,B;
    unsigned long long int result;
    scanf("%llu %llu",&A,&B);
    result = GCD(A,B);
    
    for( unsigned long long int i=0; i< result; i++){
        printf("1");
    }
    return 0;
}
