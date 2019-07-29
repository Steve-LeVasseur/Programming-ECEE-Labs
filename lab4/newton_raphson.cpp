#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const double TOLERANCE = 0.001;

double f(double x){
    return ((pow(x, 4.0)) + (2 * pow(x, 3.0)) - (31 * (pow(x, 2.0))) - (32 * x) + 60);
}
double fprime(double x){
    return ((4 * pow(x, 3.0)) + (6 * pow(x, 2.0)) - (62 * x) - 32);
}

double newtonRoot(double Guess){
    double rootDif = 1.0;
    double root = 0.0;
    while(TOLERANCE < (fabs(rootDif))){
        root = Guess - (f(Guess) / fprime(Guess));
        rootDif = root - Guess;
        Guess = root;
    }
    return root;
}

int main() {

    cout.precision(4);
    cout.setf(ios::fixed);                                      // Formatting outputs
    char Yesno = 'y';
    double Guess = 0.0;
    int Ans;

    while (Yesno == 'y') {
    cout << "Enter Guess: ";
    cin >> Guess;

    Ans = newtonRoot(Guess);
    cout << endl << "Root: " << Ans << endl;

    cout << "Enter Another Guess: y/n?";                 // Asking for another guess
    cin >> Yesno;
    cout << endl;
    }
}
