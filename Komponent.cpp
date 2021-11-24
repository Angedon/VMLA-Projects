#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, k = 0;
    cin >> n;
    int arr[n][n] = {};
    int c[n];
    for(int i = 0; i < n; ++i) c[i] = -1;
    c[0] = 0;
    int **a = new int*[n];
    for(int i = 0; i < n; ++i){
        a[i] = new int[n];
        bool k1 = 0;
        vector<int> b;
        b.push_back(i);
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
            if(a[i][j] == 1){
                for(int l = 0; l < i; ++l){
                    if(a[l][j] == 1){
                        if(c[l] != -1) c[i] = c[l];
                        k1 = 1;
                    }
                }
                if(k1 == 0) b.push_back(j);
            }
        }

        if(c[i] != -1 && !b.empty()){
            for(int j = 0; j < b.size(); ++j){
                arr[c[i]][b[j]] = 1;
                c[b[j]] = c[i];
            }
        }
        else if(!b.empty()){
            k++;
            for(int j = 0; j < b.size(); ++j){
                arr[k][b[j]] = 1;
                c[b[j]] = k;
            }
        }
        else{
            c[i] = k;
            arr[k][i] = 1;
            k++;
            continue;
        }
    }
    cout << "Count of components: " << k+1 << endl;
    for(int i = 0; i < k+1; ++i){
        for(int j = 0; j < n; ++j){
            if(arr[i][j] == 1) cout << j << " ";
        }
        cout << endl;
        delete a[i];
    }
    delete a;
}
/*
3
0 0 0
0 0 0
0 0 0
4
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0
5
0 1 0 0 0
1 0 0 0 0
0 0 0 0 0
0 0 0 0 1
0 0 0 1 0
6
0 1 0 0 0 1
1 0 1 0 0 0
0 1 0 1 0 0
0 0 1 0 1 0
0 0 0 1 0 1
1 0 0 0 1 0
8
0 0 0 0 0 1 1 0
0 0 1 0 1 0 1 0
0 1 0 0 1 0 0 0
0 0 0 0 0 1 0 0
0 1 1 0 0 0 0 1
1 0 0 1 0 0 0 0
1 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0
9
0 1 0 0 0 1 0 0 0
1 0 1 1 0 0 0 0 0
0 1 0 0 1 0 0 0 0
0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0
1 0 0 0 0 0 1 1 0
0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 1
0 0 0 0 0 0 0 1 0
*/
