// Added a couple bits to the Point class to make it play nicer with Line

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

// Replaced and added bits to zero out an undeclared line and set x and y
class Point {

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }

public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }

    int getx(){
        return x;
    }

    int gety(){
        return y;
    }

    void reset(){
        x = 0;
        y = 0;
    }

    void setxy(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }

private:
    int x,y;
};

class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

public:
    // Add your functions/methods here
    Line(){
        P1.reset();
        P2.reset();
    }

    Line(int in_x1, int in_y1, int in_x2, int in_y2){
        P1.setxy(in_x1, in_y1);
        P2.setxy(in_x2, in_y2);
    }

    void setLine(int in_x1, int in_y1, int in_x2, int in_y2){
        P1.setxy(in_x1, in_y1);
        P2.setxy(in_x2, in_y2);
    }

    Point getP1(){
        return P1;
    }

    Point getP2(){
        return P2;
    }

    double Slope(){
        if (Vertical()){return INFINITY;}
        else if (Horizontal()) {return 0;}
        else {return (P2.gety() - P1.gety()) / (P2.getx() - P1.getx());}
    }

    double Length(){
        double len = pow((P2.getx() - P1.getx()), 2) + pow((P2.gety() - P1.gety()), 2);
        len = pow(len, 0.5);
        return len;
    }

    double YIntercept(){
        double YInt = P1.gety() - (P1.getx() * Slope());
        return YInt;
    }

    bool Vertical(){
        return P1.getx() == P2.getx();
    }

    bool Horizontal(){
        return P1.gety() == P2.gety();
    }

    bool Parallel(Line &L){
        return (Slope() - L.Slope()) < 0.0001;
    }

private:
    Point P1, P2;
};

void displayLine(Line &L1){
    cout << "Slope: "      << L1.Slope()      << endl;
    cout << "Length: "     << L1.Length()     << endl;
    cout << "Y-int: "      << L1.YIntercept() << endl;
    cout << "Vertical: "   << L1.Vertical()    << endl;
    cout << "Horizontal: " << L1.Horizontal()  << endl;
    cout << endl;
}

int main(){
    Line L1;
    Line L2(5,6,7,8);
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;

    cout << "Enter Two Points For Line: ";
    cin >> L1;
    cout << L1 << endl;

    displayLine(L1);

    cout << "Parallel: " << L1.Parallel(L2) << endl;

    return 0;
}
