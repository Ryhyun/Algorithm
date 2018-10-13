
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


long func(int n,int p){
    vector<int> factorSpace;
    long answer = 0;
    size_t size = 0;
    
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ++answer;
            factorSpace.emplace_back(i);
            
            if (answer == p)
                return i;
        }
    }
    size = factorSpace.size();
    bool squareNum = ( factorSpace[answer-1] * factorSpace[answer-1] == n) ? true:false;
    if ( squareNum == false && p > answer*2)
    {
        answer = 0;
    }
    else if(squareNum == true  && p > answer*2 -1 )
    {
        answer = 0 ;
    }
    else if (squareNum == false)
    {
        if( size - (p - answer)  >= 0)
            answer = n / factorSpace[size - (p - answer)];
        else
            answer = 0;
    }
    else
    {
        if( size - (p - answer + 1)  >= 0 )
            answer = n / factorSpace[size - (p - answer +1)];
        else
            answer= 0 ;
    }
    return answer;
}


/*
 1
 2
 5    N / numVec[ numVec.size() -1 ]
 10   N /  numVec[numVec.size() -2 ]
 
 N -cnt
 */
// 1 2 4 8 16
//  answer = 3 ,
// 1 2 5 10
// answer = 2

// 1 5 25
// answer = 2

// 1 2 3 4 6 9 12 18 36
// 총 9개  , answer =5
int main(int argc, const char * argv[]) {
    
    int n,c;
    cin>>n>>c;
    
    cout<< func(n,c)<<endl;;
    
    
    
    return 0;
}
