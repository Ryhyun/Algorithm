//
//  main.cpp
//  SWExpert_1949_2
//
//  Created by ChoiChang hyun on 2018. 7. 19..
//  Copyright © 2018년 ChoiChang hyun. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int arr[21][21] ;
int nx[4] = { -1, 0,1 ,0};
int ny[4] = { 0,1 ,0, -1};
int n;
int result;
vector<pair<int,int> > vec;
vector<pair<int,int> >::iterator vi;


void BFS(int ti,int tj,int tk){
    int tarr[21][21] ;
    for( int i=0; i < n; i ++){
        for( int j =0 ; j < n ; j++ ){
            tarr[i][j] = arr[i][j];
        }
    }
    tarr[ti][tj] -= tk;
    
    for(vi = vec.begin(); vi != vec.end(); vi++ ){
        
        queue<pair< int, int> > dq;
        int si = vi->first;
        int sj = vi->second;
        int depth= 1;
        dq.push(make_pair( si, sj));
        dq.push(make_pair( 100,100));
        
        while( !dq.empty()){
            int ni = dq.front().first;
            int nj = dq.front().second;
            if( ni == 100 && nj == 100 && dq.back().first != 100){
                depth ++;
                dq.pop();
                dq.push(make_pair( 100,100));
            }
            else{
                dq.pop();
            }
    
            
            for( int i=0; i< 4; i++){
                int nextI  = ni + nx[i];
                int nextJ  = nj + ny[i];
                if ( nextI <0 || nextI >= n || nextJ <0 ||  nextJ >= n){
                    continue;
                }
                if(   tarr[ni][nj] > tarr[nextI][nextJ]   ){
                    dq.push( make_pair(nextI, nextJ));
                }
            }
            
        }

        if( result < depth ){
            result = depth;
        }
        
        
        
    }
    
    
}

void minus_k(int n, int tk){
    for(int  k=0 ; k<=tk; k++){
        for(int i=0; i< n; i++){
            for( int j =0; j< n; j++){
                BFS( i,j,k);
            }
        }
    }
}

/*
 5 0
 9 3 2 3 2
 6 3 1 7 5
 3 4 8 9 9
 2 3 7 7 7
 7 6 5 5 8
 
 
 5 1
 9 3 2 3 2
 6 3 1 7 5
 3 4 8 9 9
 2 3 7 7 7
 7 6 5 5 8
 */
int main(int argc, const char * argv[]) {

    int T;
    cin>> T;
    for( int t = 1; t<= T ; t++ ){
        
        result =0 ;
        
        int k;
        int biggest=0 ;
        vec.clear();
        cin>> n >> k ;
        
        for( int i=0; i < n; i ++){
            for( int j =0 ; j < n ; j++ ){
                cin>> arr[i][j];
                if( arr[i][j] > biggest){
                    vec.clear();
                    biggest = arr[i][j];
                    vec.push_back( make_pair(i, j));
                }
                else if( arr[i][j] == biggest){
                    vec.push_back( make_pair(i, j));
                }
            }
        }
        minus_k(n,k);
        
        cout<< "#"<< t <<" "<< result<<endl;
    }
    
    
    return 0;
}
