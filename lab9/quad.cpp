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

    double Area(Point P2, Point P3, Point P4){
        double A = (getx()*P2.gety() + P2.getx()*P3.gety() + P3.getx()*P4.gety() + P4.getx()*gety() - P2.getx()*gety() - P3.getx()*P2.gety() - P4.getx()*P3.gety() - getx()*P4.gety());
        return abs(A)/2;
    }

    bool QuadCheck(Point P2, Point P3, Point P4){
        if ( getx()*(P2.gety()-P3.gety()) + P2.getx()*(P3.gety()-gety()) + P3.getx()*(gety()-P2.gety()) == 0){
            return false;
        }
        if ( P2.getx()*(P3.gety()-P4.gety()) + P3.getx()*(P4.gety()-P2.gety()) + P4.getx()*(P2.gety()-P3.gety()) == 0){
            return false;
        }
        if ( getx()*(P3.gety()-P4.gety()) + P3.getx()*(P4.gety()-gety()) + P4.getx()*(P3.gety()-gety()) == 0){
            return false;
        }
        if ( getx()*(P2.gety()-P4.gety()) + P2.getx()*(P4.gety()-gety()) + P4.getx()*(gety()-P2.gety()) == 0){
            return false;
        }
        return true;
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

class Quad{
public:
    Quad(){
        P1.setxy(0, 0);
        P2.setxy(0, 0);
        P3.setxy(0, 0);
        P4.setxy(0, 0);
        x1 = 0; x2=0; x3=0; x4=0; y1=0; y2=0; y3=0; y4=0;
    }
    Quad(int ix1, int iy1, int ix2, int iy2, int ix3, int iy3, int ix4, int iy4){
        P1.setxy(ix1, iy1);
        P2.setxy(ix2, iy2);
        P3.setxy(ix3, iy3);
        P4.setxy(ix4, iy4);

        x1 = ix1;
        x2 = ix2;
        x3 = ix3;
        y1 = iy1;
        y2 = iy2;
        y3 = iy3;
        x4 = ix4;
        y4 = iy4;
    }

    Point getP1(){
        return P1;
    }
    Point getP2(){
        return P2;
    }
    Point getP3(){
        return P3;
    }
    Point getP4(){
        return P4;
    }

    friend istream &operator>>(istream &input, Quad &Q){
        input >> Q.P1 >> Q.P2 >> Q.P3 >> Q.P4;
        return input;
    }

    friend ostream &operator<<(ostream &output, Quad &Q){
        output << Q.P1 << Q.P2 << Q.P3 << Q.P4;
        return output;
}

private:
    Point P1, P2, P3, P4;
    int x1, y1, x2, y2, x3, y3, x4, y4;
};

void displayQuad(Point P1, Point P2, Point P3, Point P4){
    cout << endl << "Quadrilateral: " << P1.QuadCheck(P2, P3, P4) << endl;
    cout << "Area: " << P1.Area(P2, P3, P4) << endl;
}

int main(){
    Quad Q(0, 0, 2, 0, 2, 2, 0, 2);
    displayQuad(Q.getP1(), Q.getP2(), Q.getP3(), Q.getP4());
    return 0;
}
