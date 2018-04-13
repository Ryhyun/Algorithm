#include <iostream>
#include <vector>
using namespace std;
int N;
int bigP;
int totalP;
int smallV;
vector<pair<int,int> > a;


typedef int(*tempA)[13];

int chkline(int arr[13][13], int pi, int pj, int pk) {
    
    if (pk == 0) {
        for (int i = pi + 1; i < N ; i++) {
            if (arr[i][pj] != 0) {
                return 0;
            }
        }
        return 1;
    }
    
    else if (pk == 1) {
        for (int j = pj + 1; j < N ; j++) {
            if (arr[pi][j] != 0) {
                return 0;
            }
        }
        return 1;
    }
    
    else if (pk == 2) {
        for (int i = pi - 1; i >= 0 ; i--) {
            if (arr[i][pj] != 0) {
                return 0;
            }
        }
        return 1;
    }
    
    else {
        for (int j = pj - 1; j >=0 ; j--) {
            if (arr[pi][j] != 0) {
                return 0;
            }
        }
        return 1;
    }
    
    return 0;
}

tempA drawline(int arr[13][13], int pi, int pj, int pk) {
    
    int ttemparr[13][13] = { 0, };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ttemparr[i][j] = arr[i][j];
        }
    }
    
    // æ∆∑°
    if (pk == 0) {
        for (int i = pi + 1; i < N; i++) {
            ttemparr[i][pj] = 2;
        }
    }
    //ø¿∏•¬
    else if (pk == 1) {
        for (int j = pj + 1; j < N; j++) {
            ttemparr[pi][j] = 2;
        }
        
    }
    //¿ß
    else if (pk == 2) {
        for (int i = pi - 1; i >= 0; i--) {
            ttemparr[i][pj] = 2;
        }
    }
    //øﬁ¬
    else {
        for (int j = pj - 1; j >= 0; j--) {
            ttemparr[pi][j] = 2;
        }
    }
    return ttemparr;
}


void recursion(int arr[13][13] , int visited[13][13],int cnt) {
    int temparr[13][13] = { 0, };
    int tempvisited[13][13] = { 0, };
    vector<pair<int,int> >::iterator ai;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temparr[i][j] = arr[i][j];
            tempvisited[i][j] = visited[i][j];
        }
    }
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << temparr[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
     */
    if ( bigP <= cnt  and cnt > totalP-1) {
        bigP = cnt;
        int dcnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //cout << temparr[i][j] << " ";
                if (temparr[i][j] == 2) {
                    dcnt++;
                }
                
            }
            //cout << endl;
        }
        //cout << dcnt << endl;
        if (smallV > dcnt) {
            smallV = dcnt;
        }
        
        
    }
    //cout << endl;
    //for (int i = 0; i < N; i++) {
     //   for (int j = 0; j < N; j++) {
    for( ai = a.begin(); ai != a.end(); ai++){
        int i = ai->first;
        int j=  ai->second;
            if ( i == 0 || j == 0 || i == (N - 1) || j == (N - 1)) {
                if (temparr[i][j] == 1 && tempvisited[i][j] != 1) {
                    tempvisited[i][j] = 1;
                    cnt++;
                    continue;
                }
            }
            else {
                if (temparr[i][j] == 1 && tempvisited[i][j] != 1) {
                    tempvisited[i][j] = 1;
                    //cout << i << " " << j << " " << cnt << endl;
                    bool chk = false;
                    for (int k = 0; k < 4; k++) {
                        if (chkline(temparr, i, j, k)== 1 ){
                            chk = true;
                            tempA a = drawline(temparr, i, j, k);
                            int ta[13][13] ={0, };
                            for (int ii = 0; ii < N; ii++) {
                                for (int jj = 0; jj < N; jj++) {
                                    ta[ii][jj] = a[ii][jj];
                                }
                            }
                            recursion(ta, tempvisited, cnt + 1);
                        }
                        else {
                            continue;
                        }
                    }
                    if (chk == false) {
                        return;
                    }
                    
                }
            }
            
        }
    
    
}


int main(void) {
    int totalN;
    
    cin >> totalN;
    
    
    for (int c = 1; c <= totalN; c++) {
        cin >> N;
        totalP = 0;
        bigP = 0 ;
        
        a.clear();
        int arr[13][13] = { 0, };
    
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                a.push_back(pair<int,int>(i,j));
                if (arr[i][j] == 1) {
                    totalP++;
                }
            }
        }
        int visited[13][13] = { 0, };
    
        smallV = 100;
        recursion(arr, visited, 1);
    
        if (smallV == 100)
            cout <<"#"<<c<< " 0" << endl;
        else {
            cout <<"#"<<c<<" "<< smallV << endl;
        }
    }
    return 0;
}
