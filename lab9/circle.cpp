#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdlib>

using namespace std;

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

    bool operator==(Point &rhs) {
        return (rhs.x == x && rhs.y == y);
    }
    bool CircleCheck(Point Pr){
        return !(getx() == Pr.getx() && gety() == Pr.gety());
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

    bool Vertical(){
        return P1.getx() == P2.getx();
    }

    double Slope(){
        if (Vertical()){return 99999.9;}
        else if (Horizontal()) {return 0;}
        else {return (P2.gety() - P1.gety()) / (P2.getx() - P1.getx());}
    }

//    double Area(Line L2, Line L3){  // Heron's Formula
//        double S = (Length() + L2.Length() + L3.Length()) / 2;
//        return pow((S * (S-Length()) * (S-L2.Length()) * (S-L3.Length())), 0.5);
//    }

    double Area(){
        return pow(Length(), 2) * M_PI;
    }

    double Circumference(){
        return (Length() * 2) * M_PI;
    }

    double Length(){
        double len = pow((P2.getx() - P1.getx()), 2) + pow((P2.gety() - P1.gety()), 2);
        len = pow(len, 0.5);
        return len;
    }

    double Perimeter(Line L2, Line L3){
        double x = Length();
        double y = L2.Length();
        double z = L3.Length();
        return x+y+z;
    }

    bool Equilateral(Line L2, Line L3){
        if (Length() == L2.Length()){
            if (Length() == L3.Length()){
                return true;
            }
        }
        return false;
    }

    bool Horizontal(){
        return P1.gety() == P2.gety();
    }

    bool Colinear(Line L2, Line L3){
        if (((abs(Slope() - L2.Slope())) > 0.0001) || ((abs(Slope() - L3.Slope())) > 0.0001) || ((abs(L2.Slope() - L3.Slope())) > 0.0001)){
            return false;
        }
        return true;
    }

private:
    Point P1, P2;
};

class Circle {
public:
    Circle(){
        PC.setxy(0, 0);
        Pr.setxy(0, 0);
    }

    Circle(int ixC, int iyC, int ixr, int iyr){
        PC.setxy(ixC, iyC);
        Pr.setxy(ixr, iyr);
        xC = ixC; yC = iyC; xr = ixr; yr = iyr;
    }

    Point getPC(){
        return PC;
    }

    Point getPr(){
        return Pr;
}
    int getxC(){
        return xC;
    }
    int getyC(){
        return yC;
    }
    int getxr(){
        return xr;
    }
    int getyr(){
        return yr;
    }

    double Length(){
        double len = pow((xr - xC), 2) + pow((yr - yC), 2);
        len = pow(len, 0.5);
        return len;
    }

    friend istream &operator>>(istream &input, Circle &C){
            input >> C.PC >> C.Pr;
            return input;
        }

        friend ostream &operator<<(ostream &output, Circle &C){
            output << C.PC << C.Pr;
            return output;
        }

        bool operator==(const Circle& C) {

            return (xC == C.xC && yC == C.yC && R.Length() == C.R.Length());
    }


private:
    Point PC, Pr;
    int xC, yC, xr, yr;
    Line R;

};

void displayCircle(Point PC, Point Pr){
    Line R(PC.getx(), PC.gety(), Pr.getx(), Pr.gety());
    cout << endl << "Circle: " << PC.CircleCheck(Pr) << endl;
    cout << "Radius: " << R.Length() << endl;
    cout << "Diameter: " << R.Length() * 2 << endl;
    cout << "Area: " << R.Area() << endl;
    cout << "Circumference: " << R.Circumference() << endl;

}

int main(){
    Circle C1(0, 0, 1, 1);

    displayCircle(C1.getPC(), C1.getPr());
}
