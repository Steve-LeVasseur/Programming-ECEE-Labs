#include<iostream>
#include<cmath>
using namespace std;
double Efield(double r, double a = 1); // a = 1 needs to remain

const double Q = 1e-9;
const double ke = 9e9;

int main(){
    double r;
    cin >> r;

    double a;
    cin >> a;

    double Ans;
    Ans = Efield(r, a);
    cout << endl << "Efield: " << Ans << endl;

    return 0;

}

double Efield(double r, double a){
    double Field;
    if (r < a){
        Field = (ke * Q * r) / (pow(a, 3));
        return Field;
    }
    else if (r >= a){
        Field = (ke * Q) / (pow(r, 2));
        return Field;
    }
}
