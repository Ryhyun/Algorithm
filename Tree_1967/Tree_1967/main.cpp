#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


vector<int> adjN[10001];
vector<int> adjW[10001];
vector<int> ::iterator ni;
vector<int> ::iterator wi;
int n;
int result;
/*
12
1 2 3
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
 */
int BFS(int start){
    queue<int> s;
    int visited[10001]= {0,};
    s.push(start);
    while( !s.empty()){
        int temp;
        temp = s.front();
        s.pop();
        for( ni = adjN[temp].begin() , wi = adjW[temp].begin() ; ni != adjN[temp].end(); ni++, wi++){
            if( *wi != 0 and visited[ *ni] ==0 and  *ni != start  ){
                visited[*ni] = *wi + visited[temp];
                s.push(*ni);
            }
        }
    }
    int max =0 ;
    int maxIndex =0 ;
    for( int i =1 ; i<=n ; i++){
        if( visited[i] > max  ){
            max = visited[i];
            maxIndex = i ;
        }
    }
    result = max;
    return maxIndex;
}

int main() {
    cin>> n ;
    int p,c,w;
    
    for( int i=0; i< n-1;i++){
        cin>> p>> c>> w ;
        adjN[p].push_back(c),adjN[c].push_back(p);
        adjW[p].push_back(w),adjW[c].push_back(w);
    }
    BFS(BFS( 1));

    cout<< result;
    return 0;
}
