//
//  main.cpp
//  bitMasking
//
//  Created by ChoiChang hyun on 2018. 7. 26..
//  Copyright © 2018년 ChoiChang hyun. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    int N = 5;
    
    for( int i=1; i< ( 1<< N ) ;i ++){
        cout<< i <<endl;
        
        for( int j=0; j< N; j++){
            cout<< ( i & ( 1<< j )) << endl;
            if( i & ( 1 << j)){
                
            }
        }
    }
    return 0;
}
