/*
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

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int find_smallest(int pows[16][16], vector<int> cand, int n){
    int smallest = pows[0][0];
    int smallest_ind = 0;
    int flag=0;
    
    for(int j=0;j<cand.size();++j){
        for(int i=0;i<n;++i){
            for(int f=0;f<n;++f){
                if(i==cand[f]) flag = 1;
            }
            if(flag != 1 and smallest > pows[cand[j]][i]){
                smallest = pows[cand[j]][i];
                smallest_ind = i;
            }
            flag=0;
        }
    }
    return smallest_ind+1;
}

int main() {
    int n, tofixx, temp;
    vector<int> cand;
    int costs=0;
    int counts=0;
    cout << "ends";
    cin >> n ;
    
    //	int **pows = new int*[n];
    //	for(int i = 0; i < n; ++i){
    //		pows[i] = new int[n];
    //		memset(pows[i], 0, sizeof(int)*n); // 메모리 공간을 0으로 초기화
    //	}
    int pows[16][16];
    
    
    char *active = new char[n];
    
    
    
    for(int i=0; i<n;++i){
        for(int j=0; j<n;++j){
            cin >> pows[i][j];
        }
    }
    
    for(int i=0; i<n;++i) {
        cout << i <<endl;
        cin >> active[i];
        cout << active[i] << " ";
    }
    cout << active ;
    cin >> tofixx;
    cout << "ends";
    for(int i=0;i<n;++i){
        if(active[i]=='Y') cand.push_back(i+1);
    }
    cout <<"ends";
    int size = cand.size();
    while(cand.size()!=tofixx){
        for(int i=0;i<size;++i){
            temp=find_smallest(pows, cand, n);
            
            costs+=pows[i][temp-1];
            cand.push_back(temp);
        }
        counts++;
        if(counts == 10000){
            costs = -1;
            break;
        }
    }
    
    cout << costs;
    cout <<"ends";
    
    return 0;
}
