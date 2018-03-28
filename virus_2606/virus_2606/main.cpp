
 #include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int v,e;
    cin>> v>> e;
    
    int arr[101][101] ={0,};
    int visited[101] = {0,};
    int from,to;
    queue<int> que;
    int top;
    int result =0 ;
    for(int i=0; i<e ; i++){
        cin>> from>>to;
        arr[from][to] = 1;
        arr[to][from] =1;
    }
    que.push(1);
    visited[1] = 1;
    
    while( !que.empty()){
        top = que.front();
        que.pop();
        for(int i=1; i<= v; i++){
            if( arr[top][i] == 1 and visited[i] == 0){
                que.push(i);
                result++;
                visited[i] = 1;
            }
        }
    }
    cout<< result<<endl;
    
    
    
    return 0;
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
