
 
#include <iostream>
#include <vector> 

using namespace std;
int N;
int totalV;
int result;
int tempC;
int arr[13][13];


vector<pair<int, int> > vec;


void recursion(int pArr[13][13], int c, int count, vector<pair<int ,int> > tV){
    int tempArr[13][13] ={0,};
    vector<pair<int, int> >::iterator veci;
    vector<pair<int, int> > tempV;
    
    
    
    for(int i=0 ;i< N;i++){
        for( int j=0; j<N;j++){
            tempArr[i][j] = pArr[i][j];
            
        }
    }

    for( veci = tV.begin(); veci != tV.end(); veci++){
        tempArr[ veci->first][veci->second] = 2;
        count++;
    }
    tV.clear();
    
    if( c == totalV){
        if(  tempArr[vec[0].first][vec[0].second] <= tempC   ){
            tempC = tempArr[vec[0].first][vec[0].second];
            if( count < result   ){
                result = count;

            }
            
        }
        
        return;
    }
    /*

    cout<< c<<" "<< vec[c].first<<" "<<vec[c].second<<" "<<count<<endl;
    for( int i = 0 ; i<N ;i++){
        for(int j=0; j<N;j++){
            cout<< tempArr[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
*/
    bool edgeChk = false;
    if( vec[c].first == 0 || vec[c].second ==0 || vec[c].first == N- 1 || vec[c].second == N-1 ){
        edgeChk = true;
    }
    
    if(edgeChk == true){
        tempV.clear();
        recursion( tempArr, c+1, count, tempV);
    }
    
    else{
        bool chkR = false;  //Right
        bool chkD = false;  //Down
        bool chkL = false;  //Left
        bool chkT = false ; //Top
        
        
        // Right
        for(int i= vec[c].second +1  ;  i< N; i++) {
            if( tempArr[vec[c].first][i] != 0  ){
                chkR = true;
                break;
             
            }
            else
                tempV.push_back(make_pair(vec[c].first, i));
        }
        // Right
        if(chkR == true ){
            tempV.clear();
            
        }
        else{
            recursion(tempArr, c+1, count, tempV);
            tempV.clear();
        }

        // Down
        for(int i= vec[c].first+1  ;  i< N; i++) {
            if( tempArr[i][vec[c].second] != 0  ){
                chkD = true;
                break;
                
            }
            else{
                tempV.push_back(make_pair(i,vec[c].second));
            }

        }
        // down
        if(chkD == true){
            tempV.clear();
            
        }
        else{
            recursion(tempArr, c+1, count, tempV);
            tempV.clear();
        }
        
        // Left
        for(int i= vec[c].second -1   ;  i >= 0 ; i--) {
            if( tempArr[vec[c].first][i] != 0  ){
                chkL = true;
                break;
            }
            else
                tempV.push_back(make_pair(vec[c].first, i));

        }
        // Left
        if(chkL == true){
            tempV.clear();
            
        }
        else{
            recursion(tempArr, c+1, count, tempV);
            tempV.clear();
        }
        // Top
        for(int i= vec[c].first -1   ;  i >= 0 ; i--) {
            if( tempArr[i][vec[c].second] != 0  ){
               chkT = true;
                break;
                
            }
            else
                tempV.push_back(make_pair(i,vec[c].second));
            
        }

        // Top
        if(chkT == true){
            tempV.clear();
        }
        else{
            recursion(tempArr, c+1, count, tempV);
            tempV.clear();
        }
      
       
        if( chkR == true && chkD==true && chkL ==true && chkT == true){
            tempArr[vec[0].first][vec[0].second]+= 2;
            recursion(tempArr,c+1,count,tempV);
        }
     
    }
    
    
    
    
}



int main(void){
    int total_cnt;
    
    cin>>total_cnt;
    
    
    for(int casei =1 ;casei<= total_cnt; casei++){
        totalV = 0 ;
        vec.clear();
        result = 1000 ;
        tempC = 1000;
        cin>> N;
        for( int i=0 ; i<N; i++){
            for(int j=0; j< N; j++){
                arr[i][j] = 0 ;
                cin >> arr[i][j];
                if( arr[i][j] == 1 ){
                    vec.push_back(make_pair(i,j));
                    totalV++;
                }
            }
        }
        vector<pair<int, int> >::iterator veci;
        /*
        for( veci = vec.begin(); veci != vec.end(); veci++){
            cout<< veci->first<<" "<<veci->second<<endl;
        }
*/
  //      cout<< totalV<<endl;
        vector<pair<int,int> > a;
        recursion(arr, 0, 0, a);
        
        
        
        cout<<"#"<<casei<<" "<<result<<endl;
        
    }
    
    
    
    return 0;
}
