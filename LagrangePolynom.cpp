#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

vector<double> formPart(vector<double> x, vector<double> y, int n, int index)
{
    vector<double> arr;
    int p = 0;
    if(index != 0) arr.push_back(-x[0]); else {arr.push_back(-x[1]); p = 1;}
    arr.push_back(1);
    double denom = 1;
    double a = x[index];
    for(int i = 0; i < n; ++i)
    {
        if(i != index) {
            denom *= (a-x[i]);
            if(i != p){
                for(int j = arr.size()-1; j > 0; --j){
                    double b;
                    b = arr[j] * (-x[i]) + arr[j-1];
                    arr[j] = b;
                }
                arr[0] = (-x[i]) * arr[0];
                arr.push_back(1);
            }
        }
    }
    for(int i = 0; i < n; ++i) arr[i] = arr[i] / denom;
    return arr;
}

void formPolynom(vector<double> x, vector<double> y, double a, int n)
{
    vector<double> result;
    for(int i = 0; i < n; ++i) result.push_back(0);
    for(int i = 0; i < n; ++i)
    {
        vector<double> temp = formPart(x, y, n, i);
        for(int j = n-1; j > -1; --j)
        {
            result[j] += y[i] * temp[j];
        }
    }
    double res = 0;
    for(int i = n-1; i > -1; --i) {res += result[i] * pow(a, i); cout << setprecision(9) << result[i] << " ";}
    cout << endl << res << endl;
}

int main()
{
    int n;
    double a;
    cin >> a;
    cin >> n;
    vector<double> x; vector<double> y;
    for(int i = 0; i < n; ++i)
    {
        double x0, y0;
        cin >> x0 >> y0;
        x.push_back(x0); y.push_back(y0);
    }
    formPolynom(x, y, a, n);
}

//4
//0 1
//0.1 1.10517
//0.2 1.22140
//0.3 1.34986
