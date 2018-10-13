
#include <iostream>
#include <vector>
using namespace std;

vector<string> vec ;
int spinN;
int result ;
int changed[4] = {0,0,0,0};
//2 , 6
void spin(int topni, int v){
    changed[topni] = 1;
    /*
    for( int i=0; i< 4; i++){
        cout<< changed[i]<<" ";
    }
    cout<<endl;
    cout<< topni<< v<<endl;
    */
    if( topni > 3 || topni <0 ){
        return;
    }
    if ( topni == 0 ){
        //cout<< topni<<endl;
        if( changed[topni+1] ==0 ){
            if( vec[topni][2] == vec[topni+1][6] ){
                spin( topni+1,0);
            }
            else{
                spin( topni+1,v*-1);
            }
        }
    }
    else if ( topni == 3 ){
        //cout<<topni<<endl;
        if( changed[topni-1] ==0 ){
            if( vec[topni][6] == vec[topni-1][2] ){
                spin( topni-1,0);
            }
            else{
                spin( topni-1,v*-1);
            }
        }
    }
    else{
        if( changed[topni+1] ==0 ){
            if( vec[topni][2] == vec[topni+1][6] ){
                spin( topni+1,0);
            }
            else{
                spin( topni+1,v*-1);
            }
        }
        if( changed[topni-1] == 0  ){
            if( vec[topni][6] == vec[topni-1][2] ){
                spin( topni-1,0);
            }
            else{
                spin( topni-1,v*-1);
            }
        }
    }
    if(  v == 1 ){
        //cout<< "v 1 "<< topni<< " "<<endl;
        char tempChar = vec[topni].back();
        for( int i=7; i>0;i--){
            vec[topni][i] = vec[topni][i-1];
        }
        vec[topni][0] = tempChar;
        
        //string tempa = strcpy(vec[topni], tempa);
        
    }
    else if( v== -1){
        //cout<< "v 2 "<<topni<<" "<<endl;
        char tempChar = vec[topni].front();
        for( int i=0; i<7;i++){
            vec[topni][i] = vec[topni][i+1];
        }
        vec[topni][7] = tempChar;
        
    }
    
}

int main(int argc, const char * argv[]) {
    result =0 ;
    for(int i=0; i< 4 ; i++){
        string tempString;
        cin>> tempString;
        vec.push_back(tempString);
    }
    cin >> spinN;
    for(int s=0; s< spinN; s++){
        int topni, v;
        for( int i=0;i< 4; i++){
            changed[i] = 0;
        }
        cin>> topni >> v;
        spin( topni-1,v);
    }
    
    for( int i=0; i<4; i++){
        //cout<< vec[i]<<endl;
        if( vec[i][0] == '1' ){
            if( i == 0 )
                result+= 1;
            else if( i== 1)
                result+= 2;
            else if( i == 2 )
                result +=4;
            else
                result +=8;
        }
    }
    cout<<  result<<endl;
    
    return 0;
}
