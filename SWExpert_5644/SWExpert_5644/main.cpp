
#include <iostream>
#include <vector>
using namespace std;

int result = 0 ;
int M,A;
int routeA[101] ={0,};
int routeB[101] ={0,};
int arr[10][10] = {0,};
int ni[4] = {0,1,0,-1};
int nj[4] = {-1,0,1,0};

vector<pair<pair<int,int>,pair< int,int> > > vec;

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    for(int casei= 1; casei<= T; casei++){
        result =0 ;
        cin >> M >> A;
        vec.clear();
        for( int i=0; i< M; i++){
            cin>> routeA[i];
        }
        for( int i=0; i< M; i++){
            cin>> routeB[i];
        }
        for( int i=0; i< A; i++){
            int ti,tj,tc,tp;
            cin>> ti>> tj>> tc>> tp;
            //installAP(ti,tj,tc,tp);
            vec.push_back(make_pair( make_pair(ti-1,tj-1),make_pair( tc,tp) ));
        }
        int aSi = 0; int aSj = 0;
        int bSi = 9; int bSj = 9;
        int aResult = 0 ; int bResult = 0 ;int dResult=0;
        for(int t=0; t<= M; t++){
            // ap check
            vector<int> apA;
            int aV=0;
            vector<int> apB;
            int bV=0;
            vector<int> apDouble;
            for(int i=0; i< A; i++){
                int api = vec[i].first.first;  int apj = vec[i].first.second;
                int apc = vec[i].second.first; int app = vec[i].second.second;
                if(  abs( aSi - api) + abs( aSj - apj) <= apc){
                    apA.push_back(i);
                    aV = ( aV > app )? aV: app;
                    if(  abs( bSi - api) + abs( bSj - apj) <= apc){
                        apDouble.push_back(i);
                    }
                }
                if(  abs( bSi - api) + abs( bSj - apj) <= apc){
                    apB.push_back(i);
                    bV = ( bV > app )? bV: app;
                }
            }
            if(apDouble.empty() ){
                aResult += aV; bResult += bV;
            }
            else{
                int tempR=0 ;
                for(int i=0 ; i< apA.size();i++){
                    for(int j=0; j< apB.size();j++){
                        if( apA[i] == apB[j] ){
                            tempR = (tempR > vec[apA[i]].second.second) ? tempR : vec[apA[i]].second.second;
                        }
                        else{
                            int ta =  vec[apA[i]].second.second;
                            int tb =  vec[apB[j]].second.second;
                            tempR = ( tempR > ta+ tb) ? tempR: ta+tb;
                        }
                    }
                }
                dResult += tempR;
            }
            // next step
            if( routeA[t] != 0){
                aSi = aSi + ni[ routeA[t]-1];
                aSj = aSj + nj[ routeA[t]-1];
            }
            if( routeB[t] != 0){
                bSi = bSi + ni[ routeB[t]-1];
                bSj = bSj + nj[ routeB[t]-1];
            }
        }
        cout<<"#"<<casei<<" "<< aResult+bResult+dResult<<endl;
    }
    
    
    return 0;
}
