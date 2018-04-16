#include <iostream>
#include <vector>


using namespace std;

int result;
int N,M,K;
//. (상: 1, 하: 2, 좌: 3, 우: 4)
int moveN[4] = { -1 , 1, 0,0 };
int moveM[4] = { 0,  0 , -1,1};

vector<pair< pair<int,int>, pair<int,int> > >::iterator vi;

int recursion( vector<pair< pair<int,int>, pair<int,int> > > tempV ,int misang ,int hour){
    
    //cout<< "hour" << hour<<endl;
    if( hour == M ){
        return misang;
    }
    else{
    // move
        for(vi = tempV.begin();vi != tempV.end(); vi++){
        
            int nextN = vi->first.first + moveN[ vi->second.second -1];
            int nextM = vi->first.second + moveM[ vi->second.second -1];
        
            if( nextN == 0 || nextM == 0 || nextN == N-1 || nextM == N-1){
    
              
                vi->second.first /= 2;
                
                if( vi->second.second == 1){
                    vi->second.second = 2;
                }
                else if( vi->second.second == 2){
                    vi->second.second = 1;
                }
                else if( vi->second.second == 3){
                    vi->second.second = 4;
                }
                else if( vi->second.second == 4){
                    vi->second.second = 3;
                }
                
                vi->first.first = nextN;
                vi->first.second = nextM;
            }
            else{
                vi->first.first = nextN;
                vi->first.second = nextM;
            }
        }
    
        vector<pair< pair<int,int>, pair<int,int> > > memoV;
        // merge
        vector<pair< pair<int,int>, pair<int,int> > >::iterator vj;
        int pC = 0;
        for(vi = tempV.begin();vi != tempV.end(); vi++){
            int temp =vi->second.first;
            int bigV = vi->second.first ;
            int totalV = vi->second.first;
            int vV  = vi->second.second;
            int chk = true;
            for( vj = tempV.begin() ; vj!= tempV.end(); vj++){
                if( vi == vj ){
                    continue;
                }
                else{
                    if( vi->first.first == vj->first.first && vi->first.second == vj->first.second){
                        totalV += vj->second.first;
                        if( bigV < vj->second.first){
                            bigV = vj->second.first;
                            vV = vj->second.second;
                        }
                        
                    }
                }
            }
            if( temp == bigV){
                pC += totalV;
                memoV.push_back( make_pair( make_pair( vi->first.first, vi->first.second) , make_pair( totalV,vV)));
            }
        }
        return recursion( memoV, pC, hour +1);
    }

 
}

int main(int argc, const char * argv[]) {
    int case_total;
    cin>> case_total;
    
    vector<pair< pair<int,int>, pair<int,int> > >vec;
    
    
    for(int casei = 1 ; casei <= case_total; casei++){

        vec.clear();
        
        
        cin>> N>>M>>K;
        int tm,tn, tc, tv ;
        int misang = 0 ;
        for( int i =0 ; i < K; i++){
            cin>> tn>> tm>> tc>> tv;
            misang+= tc;
            vec.push_back(make_pair(make_pair(tn,tm), make_pair(tc,tv)));
            
            //arr[tn][tm] = tc;
            //varr[tn][tm] = tv;
        }
        
        
        
        cout<<"#"<<casei<<" "<< recursion( vec, misang, 0)<<endl;
    }
    
    
    
    return 0;
}
