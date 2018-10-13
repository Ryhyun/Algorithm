
#include <iostream>

#include <cstring>


using namespace std;
int result, N;
#define MAXSIZE 1000
int ni[4] = {1, -1, 0, 0 };
int nj[4] = {0,0 , -1, 1};
int arr[4001][4001] = {0,};
pair<int,int> pointVec[1000];
pair<int,int> infoVec[1000];
int front,back;
int qsize;
void push(int pi, int pj, int v, int k ){
    if( back+ 1 > MAXSIZE)
        return;
    pointVec[back] =  make_pair( pi,pj);
    infoVec[back] = make_pair(v,k);
    qsize++;
    back = (back+1) % MAXSIZE;
}
void pop(){
    
    qsize--;
    front = ( front +1) % MAXSIZE;
}
void move(){
    //cout<<"-=-=--=-=-=-="<<endl;

    while(front != back){
        int len = qsize;
        for( int i=0; i < len; i++){
            int tv = infoVec[front].first;
            int tk = infoVec[front].second;
            int nowi = pointVec[front].first ;
            int nowj = pointVec[front].second ;
            
            int nexti = nowi + nj[tv] ;
            int nextj = nowj + ni[tv] ;
            //cout<< front<<endl;
            pop();
            
            if( arr[nowi][nowj] > tk){
                result += arr[nowi][nowj];
                //cout<< arr[nowi][nowj]<<endl;
                arr[nowi][nowj] = 0 ;
                continue;
            }
            if( nexti  > 4000 || nextj > 4000 || nexti < 0 || nextj < 0){
                continue;
            }
            if( arr[nexti][nextj] == 0 ){
                
                arr[nexti][nextj] = tk;
                push(nexti,nextj,tv,tk);
                
            }
            else{
                
                arr[nexti][nextj] += tk;
                
            }
            arr[nowi][nowj] = 0;

        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for( int casei = 1 ; casei <= T; casei++){
        result = 0 ;
        qsize= 0 ;
        front =0;
        back = 0 ;
        memset(arr,0,sizeof(arr));
        cin>> N;
        for(int i=0; i<N; i++){
            int ti,tj,tv,te;
            cin >> ti >> tj >>tv >> te;
            push( (ti + 1000) * 2,( tj+1000) * 2, tv,te);
        }

        move();
        cout<< "#"<< casei<<" "<< result<<endl;
    }
    return 0;
}


