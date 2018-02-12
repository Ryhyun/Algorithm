
#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    unsigned long long n;
    scanf("%d",&n);
    unsigned int fArray[3];
    fArray[0] = 0;
    fArray[1] = 1;
    
    n = n% 1500000;
    for(int i=0; i<n-1 ;i++){
        fArray[(i+2)%3] = (fArray[(i+1)%3] + fArray[(i)%3] ) % 1000000;
    }
    cout<< fArray[(n)%3]% 1000000 <<endl;
    return 0;
}
