
#include <iostream>

using namespace std;


unsigned int memoArray[1000][1000] = {0,};


unsigned int memorization(int n, int k){
    //cout<< "!! n:"<<n<<" k: "<<k<<endl;
    if( n >= k and k!=0  and  memoArray[n][k] == 0 ){
        for(int i=1 ; i<= n; i++){
            memoArray[n][k] += memorization( n-i, k-1);
        }
    }
    return memoArray[n][k] % 10007;
}


int main(int argc, const char * argv[]) {
    int N,K;
    scanf("%d %d",&N,&K);
    for(int i=0; i<= N;i++){
        memoArray[N-i][0] = 1;
    }
    printf("%u", memorization(N,K) );
    
    
    
    
   

    
    
    

    return 0;
}



#include <iostream>

using namespace std;



int factorial(int number,int limit){
    if( number != 0 and limit !=0 )
        return number * factorial( number-1, limit-1);
    else
        return 1;
    
}


int main(int argc, const char * argv[]) {
    int N,K;
    scanf("%d%d",&N,&K);
    
    
    cout<< factorial(N,K) / factorial(K,K)<<endl;;
    
    
    
    
    
    return 0;
}

