#include <iostream>
#include <cmath>

using namespace std;

bool compareDelta(double Comp1, double Comp2, double Delta){
    if ((Comp1 - Comp2 > 0) && (Comp1 - Comp2 <= Delta)){
        return true;
    }
    else if ((Comp2 - Comp1 > 0) && (Comp2 - Comp1 <= Delta)){
        return true;
    }
    else {
        return false;
    }
}

int main() {

   /* Type your code here. */

    double Number1 = 1.205;
    double Number2 = 1.305;
    double Delta = 0.100;

    cout << "CompareDelta() Number1: " << Number1 << " Number2: " << Number2 << " Delta " << Delta << " returned: "
         << compareDelta(Number1, Number2, Delta) << " should be 1 " << endl;
    Number1 = 1;
    Number2 = 2;
    cout << "CompareDelta() Number1: " << Number1 << " Number2: " << Number2 << " Delta " << Delta << " returned: "
         << compareDelta(Number1, Number2, Delta) << " should be 0 " << endl;
    Number1 = 2;
    Number2 = 4;
    Delta = 2.5;
    cout << "CompareDelta() Number1: " << Number1 << " Number2: " << Number2 << " Delta " << Delta << " returned: "
         << compareDelta(Number1, Number2, Delta) << " should be 1 " << endl;
    Number1 = 1.3058;
    Number2 = 1.3059;
    Delta   = 0.00001;
    cout << "CompareDelta() Number1: " << Number1 << " Number2: " << Number2 << " Delta " << Delta << " returned: "
         << compareDelta(Number1, Number2, Delta) << " should be 0 " << endl;

   return 0;
}
