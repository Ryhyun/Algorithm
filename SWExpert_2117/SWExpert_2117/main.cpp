#include <iostream>

using namespace std;
int N;
int arr[21][21];
int cntHouse(int tn, int tm, int k) {
    int cnt = 0;
    
    for (int i = tn - k + 1; i <= tn + k - 1; i++) {
        for (int j = tm - k + 1; j <= tm + k - 1; j++) {
            if (i < 0 || j < 0 || i >= N || j >= N) {
                continue;
            }
            else if ( arr[i][j] == 1 && abs(i - tn) + abs(j - tm) < k) {
                cnt++;
            }
        }
    }
    return cnt;
}


int main(void) {
    int total_case;
    cin >> total_case;
    
    for (int casei = 1; casei <= total_case; casei++) {
        int M;
        cin >> N >>M ;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin>> arr[i][j];
            }
        }
        
        int bigH = 0;
        for (int k = 1; k <= N+1; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    //  cout << cntHouse(i, j,k) << " ";
                    int house = cntHouse(i, j, k);
                    int money = house * M;
                    int cost = k * k + (k - 1)*(k - 1);
                    if (money >= cost) {
                        if (bigH < house) {
                            bigH = house; 
                            //cout << i <<" "<< j << endl;
                            //cout << bigH<<" "<<k << " " << money << " " << cost << endl;
                        }
                    }
                }
                //cout << endl;
            }
            //cout << endl;
        }
        cout <<"#"<<casei<<" "<< bigH << endl;
    }
    
    
    
    return 0;
}
