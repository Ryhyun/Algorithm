#include <iostream>

#include <queue>



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



void bfs(int sN, int sM, int depth) {

    for (int i = 0; i < 4; i++) {
        int nextN = sN + moveN[i];
        int nextM = sM + moveM[i];
        if (nextN < 0 || nextN >= N || nextM < 0 || nextM >= M) {
            continue;
        }
        
        if (arr[nextN][nextM] != 0 && isConnect(arr[sN][sM], i) && isConnect(arr[nextN][nextM], (i + 2) % 4) && visited[nextN][nextM] == 0 && depth < L) {
            visited[nextN][nextM] = depth;
            //cout << depth << " : " << nextN << " " << nextM << endl;
            result++;
            
            bfs(nextN, nextM, depth + 1);
            
        }
        else if(arr[nextN][nextM] != 0 && isConnect(arr[sN][sM], i) && isConnect(arr[nextN][nextM], (i + 2) % 4) && visited[nextN][nextM] > 0 && depth < L){
            if( visited[nextN][nextM] > depth){
                visited[nextN][nextM] = depth;
                bfs(nextN, nextM, depth + 1);
                
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
        
        bfs(R, C, 1);
        
        
        
        cout << "#" << casei << " " << result << endl;
        
        
        
        
        
        
        
    }
    
    
    
    return 0;
    
}
