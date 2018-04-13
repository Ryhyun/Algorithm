// BFS

#include <iostream>

#include <queue>
#include <algorithm>



using namespace std;

int N, M, R, C, L;

int result;

int arr[51][51];

int visited[51][51];

int moveN[4] = { 0, 1, 0,  -1 };
int moveM[4] = { 1 , 0 , -1 ,0 };







bool isConnect(int k, int v) {
    
    // v =>  0 - 우,  1 - 하 2- 좌 3 - 상
    switch (k) {
        case 1:
            if (v == 0)
                return true;
            
            else if (v == 1)
                return true;
            
            else if (v == 2)
                return true;
            else
                return true;
            break;
        case 2:
            if (v == 0)
                return false;
            else if (v == 1)
                return true;
            else if (v == 2)
                return false;
            else
                return true;
            break;
        case 3:
            if (v == 0)
                return true;
            else if (v == 1)
                return false;
            else if (v == 2)
                return true;
            else
                return false;
            break;
        case 4:
            if (v == 0)
                return true;
            else if (v == 1)
                return false;
            else if (v == 2)
                return false;
            else
                return true;
            break;
        case 5:
            if (v == 0)
                return true;
            
            else if (v == 1)
                return true;
            else if (v == 2)
                return false;
            else
                return false;
            
            break;
        case 6:
            if (v == 0)
                return false;
            else if (v == 1)
                return true;
            else if (v == 2)
                return true;
            else
                return false;
            break;
            
        case 7:
            if (v == 0)
                return false;
            else if (v == 1)
                return false;
            
            else if (v == 2)
                return true;
            else
                return true;
            
            break;
            
        default:
            return false;
            break;
            
            
            
    }
    
}



void bfs(int sN, int sM) {
    int depth = 1;
    queue<pair<int,int> > q;
    q.push(make_pair(sN,sM));
    q.push(make_pair(100,100));
    
    while( !q.empty()){
    
        int n =q.front().first;
        int m =q.front().second;
        
        if( n == 100 && m ==100 && q.back().first != 100){
            depth++;
            q.pop();
            q.push(make_pair(100,100));
            //cout<<depth<<endl;
        }
        else{
            q.pop();
        }
        
        
        for (int i = 0; i < 4; i++) {
            int nextN = n + moveN[i];
            int nextM = m + moveM[i];
            if (nextN < 0 || nextN >= N || nextM < 0 || nextM >= M) {
                continue;
            }
        
            if (arr[nextN][nextM] != 0 && isConnect(arr[n][m], i) && isConnect(arr[nextN][nextM], (i + 2) % 4) && visited[nextN]  [nextM] == 0 && depth < L ) {
                //cout<< nextN<<" "<< nextM <<endl;
                visited[nextN][nextM] = 1;
                q.push(make_pair(nextN,nextM));
            
                result++;

            }
        
        }
        
    }
    
}



int main(void) {
    
    int total_c;
    
    cin >> total_c;
    
    for (int casei = 1; casei <= total_c; casei++) {
        result = 1;
        arr[51][51] = { 0, };
        
        cin >> N >> M >> R >> C >> L;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> arr[i][j];
                visited[i][j] = 0;
            }
        }
        
        visited[R][C] = 1;
        
        bfs(R, C);
        
        
        
        cout << "#" << casei << " " << result << endl;
        
        
        
        
        
        
        
    }
    
    
    
    return 0;
    
}
