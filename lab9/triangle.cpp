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

    double Area(Line L2, Line L3){  // Heron's Formula
        double S = (Length() + L2.Length() + L3.Length()) / 2;
        return pow((S * (S-Length()) * (S-L2.Length()) * (S-L3.Length())), 0.5);
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

class Triangle{

public:
    Triangle(){
        P1.setxy(0, 0);
        P2.setxy(0, 0);
        P3.setxy(0, 0);

        x1=0; y1=0; x2=0; y2=0; x3=0; y3 = 0;
    }

    Triangle(int in_x1, int in_y1, int in_x2, int in_y2, int in_x3, int in_y3){
        P1.setxy(in_x1, in_y1);
        P2.setxy(in_x2, in_y2);
        P3.setxy(in_x3, in_y3);
        x1=in_x1; y1=in_y1; x2=in_x2; y2=in_y2; x3=in_x3; y3 =in_y3;
    }

//    Triangle(Point P1, Point P2, Point P3){

//    }

    Point getP1(){
        return P1;
    }

    Point getP2(){
        return P2;
    }

    Point getP3(){
        return P3;
    }

    friend istream &operator>>(istream &input, Triangle &T){
        input >> T.P1 >> T.P2 >> T.P3;
        return input;
    }

    friend ostream &operator<<(ostream &output, Triangle &T){
        output << T.P1 << T.P2 << T.P3;
        return output;
    }

    bool operator==(const Triangle& T) {
        if (L1.Colinear(L2, L3)){
            return 0;
        }
//        if (!T.L1.Colinear(T.L2, T.L3)){
//            return 0;
//        }
        return (x1 == T.x1 && y1 == T.y1 && x2 == T.x2 && y2 == T.y2 && x3 == T.x3 && y3 == T.y3);
//        return (P1 == T.getP1() && P2 == T.getP2() && P3 == T.getP3());
    }

private:
    Line L1, L2, L3;
    Point P1, P2, P3;
    int x1, y1, x2, y2, x3, y3;
};

void displayTriangle(Line L1, Line L2, Line L3){
    cout << "Triangle: " << !L1.Colinear(L2, L3) << endl;
    cout << "Area: " << L1.Area(L2, L3) << endl;
    cout << "Perimeter: " << L1.Perimeter(L2, L3) << endl;
    cout << "Equilateral: " << L1.Equilateral(L2, L3) << endl;
    cout << endl;
}

int main(){
    int x1, y1, x2, y2, x3, y3;
    x1 = 0; y1 = 0; x2 = 10; y2 = 0; x3 = 2; y3 = 2;
    Line L1(0, 0, 10, 0);
    Line L2(10, 0, 2, 2);
    Line L3(0, 0, 2, 2);

    displayTriangle (L1, L2, L3);

    Triangle Tri1(x1, y1, x2, y2, x3, y3);

    return 0;
}
