// Works pretty well. Not perfect

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This prototype is complete
class stringManip {
    public:
        stringManip(); // done
        stringManip(string input); // done
        string retrieve(); // done
        void setString(string input); // done
        void chop(); // done
        void padString(int n); // done
        void center(int length); // done
        void truncate(int n); // done
        void removeNonAlpha(); // done
        void convertToUpperCase(); // done
        void convertToLowerCase(); // done
    private:
        string tobeEdited;
};

// Default Constructor
stringManip::stringManip(){
    tobeEdited = "";
}

// Overloaded Constructor
stringManip::stringManip(string in_string){
    tobeEdited = in_string;
}

// retrieve function
string stringManip::retrieve(){
    return tobeEdited;
}

// padString() function
void stringManip::padString(int length){
    while (tobeEdited.size() < length){
        tobeEdited.append(" ");
    }
}

void stringManip::setString(string input){
    tobeEdited = input;
}

void stringManip::chop(){
    for (int i = 0; i < tobeEdited.size(); i++){
        if (!isspace(tobeEdited.at(i))){
            break;
        }
        else {
            tobeEdited.erase (i, 1);
            i--;
        }
    }
    for (int i = tobeEdited.size() - 1; i > 0; i--){
        if (!isspace(tobeEdited.at(i))){
            break;
        }
        else {
            tobeEdited.erase (i, 1);
        }
    }
}

void stringManip::center(int length){
    chop();
    More:
    if (tobeEdited.size() < length){
        tobeEdited.push_back (' ');
    }
    if (tobeEdited.size() < length){
        tobeEdited.insert (0, " ");
    }
    goto More;
}

void stringManip::truncate(int n){
    while (tobeEdited.size() >= n){
        tobeEdited.pop_back();
    }
}

void stringManip::removeNonAlpha(){
    for (int i = 0; i < tobeEdited.size(); i++){
        if (!isalpha(tobeEdited.at(i))){
            tobeEdited.erase (i, 1);
            i--;
        }
    }
}

void stringManip::convertToLowerCase(){
    for (int i = 0; i < tobeEdited.size(); i++){
        tobeEdited.at(i) = tolower(tobeEdited.at(i));
    }
}

void stringManip::convertToUpperCase(){
    for (int i = 0; i < tobeEdited.size(); i++){
        tobeEdited.at(i) = toupper(tobeEdited.at(i));
    }
}

int main(){
    stringManip S0;
    cout << S0.retrieve() << endl;
    S0.setString("hello");
    cout << S0.retrieve() << endl;

    cout << endl;
    stringManip Schop("   hello   ");
    cout << "Before: " << Schop.retrieve() << endl;
    Schop.chop();
    cout << "After: <" << Schop.retrieve() << ">" << endl;
    cout << "Goal:  <hello>" << endl;

    cout << endl;
    stringManip Spad("hello");
    cout << "Before: " << Spad.retrieve() << endl;
    Spad.padString(9);
    cout << "After: <" << Spad.retrieve() << ">" << endl;
    cout << "Goal:  <hello    >" << endl;

    cout << endl;
    stringManip Scenter("xyz");
    cout << "Before: " << Scenter.retrieve() << endl;
    Scenter.center(20);
    cout <<"After 1: <" << Scenter.retrieve() << ">" << endl;
    cout <<"Goal 1:  <        xyz         >" << endl;
    Scenter.center(21);
    cout <<"After 2: <" << Scenter.retrieve() << ">" << endl;
    cout <<"Goal 2:  <         xyz         >" << endl;

    cout << endl;
    stringManip Strunc("hello there");
    cout << "Before: " << Strunc.retrieve() << endl;
    Strunc.truncate(4);
    cout << "After: <" << Strunc.retrieve() << ">" << endl;
    cout << "Goal:  <hell>" << endl;

    cout << endl;
    stringManip Snonal("123  ta#$@c  os!  ");
    cout << "Before: " << Snonal.retrieve() << endl;
    Snonal.removeNonAlpha();
    cout << "After: <" << Snonal.retrieve() << ">" << endl;
    cout << "Goal:  <tacos>" << endl;

    cout << endl;
    stringManip Sup("hElLo");
    cout << "Before: " << Sup.retrieve() << endl;
    Sup.convertToUpperCase();
    cout << "After: <" << Sup.retrieve() << ">" << endl;
    cout << "Goal:  <HELLO>" << endl;

    cout << endl;
    stringManip Slo("HeLlO");
    cout << "Before: " << Slo.retrieve() << endl;
    Slo.convertToLowerCase();
    cout << "After: <" << Slo.retrieve() << ">" << endl;
    cout << "Goal:  <hello>" << endl;

    return 0;
}
