
#include <iostream>
#include <vector>
using namespace std;

// ex) 6C3 -> 5C2 + 4C2 + 3C2 + 2C2
//
int arr[17][17] = { 0,};
vector<int>::iterator vi;
vector<int>::iterator vii;

int result ;
void cal_synergy(vector<int> a, vector<int> b){
    
    int aT =0 ;
    int bT =0;
    for( vi = a.begin(); vi!= a.end(); vi++){
        for( vii = vi+1; vii!= a.end(); vii++){
            //cout<< "at: "<< *vi<<" "<< *vii<<" "<< ( arr[*vi][*vii] + arr[*vii][*vi])<<endl;;
            aT += ( arr[*vi][*vii] + arr[*vii][*vi]);
        }
    }
    //cout<< aT<<endl;
    
    for( vi = b.begin(); vi!= b.end(); vi++){
        for( vii = vi+1; vii!= b.end(); vii++){
            //cout<< "bt: "<< *vi<<" "<< *vii<<" "<< ( arr[*vi][*vii] + arr[*vii][*vi])<<endl;;
            bT += ( arr[*vi][*vii] + arr[*vii][*vi]);
        }
    }
    //cout<< bT<<endl;
    //cout<<abs( aT - bT) <<endl;
    if( result >  abs( aT - bT)){
        result = abs( aT - bT);
    }
    
}

void calculate(int n,vector<int> vec){
    vector<int> a;
    
    for(int i=0; i< n; i++){
        a.push_back(i);
    }
    
    int m=0;
    for( vi = vec.begin(); vi!= vec.end(); vi++){
        //cout<< *vi<<" ";
        a.erase( a.begin() + *vi - m);
        m++;
    }
    //cout<<endl;
    
    for( vi = a.begin(); vi!= a.end(); vi++){
      //  cout<< *vi<<" ";
    }
    //cout<<endl;
    
    cal_synergy(vec, a);

}


void combination( int n , int c,int start, int index ,vector<int> tVec){
    
    
    if( c == index){
        calculate( n, tVec);
        return;
    }
    for( int i=start ;i< n ; i++){
        vector<int> vec = tVec;
        vec.push_back( i);
        combination( n, c, i+1, index+1, vec);
    
    }
}

int main(int argc, const char * argv[]) {

    int T ;
    cin>> T;
    for( int t= 1; t<= T ; t++){
        
        result = 1000 ;
        int N;
        cin >> N ;
        
        
        for( int i =0 ; i< N ; i++){
            for( int j=0 ;j< N ; j++){
                cin>> arr[i][j];
            }
        }

        vector<int> tV;
        combination( N, N/2 ,0,0,tV);
    
        
        cout<< "#" <<t<< " "<<  result<<endl;
    }

    return 0;
}







