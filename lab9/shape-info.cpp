#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>

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

    Point(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }

    double getx(){
        return x;
    }

    double gety(){
        return y;
    }

    void reset(){
        x = 0;
        y = 0;
    }

    void setxy(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }

    bool operator==(Point &rhs) {
        return (rhs.x == x && rhs.y == y);
    }

    bool CircleCheck(Point Pr){
        return !(getx() == Pr.getx() && gety() == Pr.gety());
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
    double x,y;
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

    Line(double in_x1, double in_y1, double in_x2, double in_y2){
        P1.setxy(in_x1, in_y1);
        P2.setxy(in_x2, in_y2);
    }

    void setLine(double in_x1, double in_y1, double in_x2, double in_y2){
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

    double Area(){
        return pow(Length(), 2) * M_PI;
    }

    double Circumference(){
        return (Length() * 2) * M_PI;
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

    Triangle(double in_x1, double in_y1, double in_x2, double in_y2, double in_x3, double in_y3){
        P1.setxy(in_x1, in_y1);
        P2.setxy(in_x2, in_y2);
        P3.setxy(in_x3, in_y3);
        x1=in_x1; y1=in_y1; x2=in_x2; y2=in_y2; x3=in_x3; y3 =in_y3;
        L1.setLine(in_x1, in_y1, in_x2, in_y2);
        L2.setLine(in_x1, in_y1, in_x3, in_y3);
        L3.setLine(in_x2, in_y2, in_x3, in_y3);
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

    Line getL1(){
        return L1;
    }

    Line getL2(){
        return L2;
    }
    Line getL3(){
        return L3;
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
    double x1, y1, x2, y2, x3, y3;
};

void displayTriangle(Line L1, Line L2, Line L3){
    cout << "Triangle: " << !L1.Colinear(L2, L3) << endl;
    cout << "Area: " << L1.Area(L2, L3) << endl;
    cout << "Perimeter: " << L1.Perimeter(L2, L3) << endl;
    cout << "Equilateral: " << L1.Equilateral(L2, L3) << endl;
    cout << endl;
}

class Circle {
public:
    Circle(){
        PC.setxy(0, 0);
        Pr.setxy(0, 0);
        R.setLine(0, 0, 0, 0);
    }

    Circle(double ixC, double iyC, double ixr, double iyr){
        PC.setxy(ixC, iyC);
        Pr.setxy(ixr, iyr);
        xC = ixC; yC = iyC; xr = ixr; yr = iyr;
        R.setLine(ixC, iyC, ixr, iyr);
    }

    Point getPC(){
        return PC;
    }

    Point getPr(){
        return Pr;
}
    double getxC(){
        return xC;
    }
    double getyC(){
        return yC;
    }
    double getxr(){
        return xr;
    }
    double getyr(){
        return yr;
    }

    Line getR(){
        return R;
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

//        bool operator==(const Circle& C) {

//            return (xC == C.xC && yC == C.yC && R.Length() == C.R.Length());
//    }


private:
    Point PC, Pr;
    double xC, yC, xr, yr;
    Line R;

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
    Quad(double ix1, double iy1, double ix2, double iy2, double ix3, double iy3, double ix4, double iy4){
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
    double x1, y1, x2, y2, x3, y3, x4, y4;
};

void displayCircle(Point PC, Point Pr){
    Line R(PC.getx(), PC.gety(), Pr.getx(), Pr.gety());
    cout << endl << "Circle: " << PC.CircleCheck(Pr) << endl;
    cout << "Radius: " << R.Length() << endl;
    cout << "Diameter: " << R.Length() * 2 << endl;
    cout << "Area: " << R.Area() << endl;
    cout << "Circumference: " << R.Circumference() << endl;

}

void displayQuad(Point P1, Point P2, Point P3, Point P4){
    cout << endl << "Quadrilateral: " << P1.QuadCheck(P2, P3, P4) << endl;
    cout << "Area: " << P1.Area(P2, P3, P4) << endl;
}

vector<double> breakupstring(string str){
    vector<double> numdata;
    stringstream ss;     //requires sstream library included
    ss << str;

    while(!ss.eof()){
        double temp;
        ss >> temp;
        numdata.push_back(temp);
    }

    return numdata;
}

int main(){

    ofstream out;
    out.open("shapes-info.txt");
    cout << "Opened other file" << endl;

    ifstream in;
    in.open("shapes.txt");
    cout << "Open File" << endl;

    string input;
    vector<double> coordinates;

    getline(in, input);

    while (input != ""){
        coordinates = breakupstring(input);
        if (coordinates.size() != 4 && coordinates.size() != 6 && coordinates.size() != 8){
            out << "Sufficient coordinates NOT input." << endl << endl;
            cout << "Sufficient coordinates NOT input." << endl << endl;
        }
        else if (coordinates.size() == 4){
            Circle C1(coordinates.at(0), coordinates.at(1), coordinates.at(2), coordinates.at(3));
            out << "Sufficient coordinates input.";
            cout << "Sufficient coordinates input." << endl << endl;
            displayCircle(C1.getPC(), C1.getPr());


            out << endl << "Circle: " << C1.getPC().CircleCheck(C1.getPr()) << endl;
            out << "Radius: " << C1.getR().Length() << endl;
            out << "Diameter: " << C1.getR().Length() * 2 << endl;
            out << "Area: " << C1.getR().Area() << endl;
            out << "Circumference: " << C1.getR().Circumference() << endl << endl;
        }
        else if (coordinates.size() == 6){
            Triangle T1(coordinates.at(0), coordinates.at(1), coordinates.at(2), coordinates.at(3), coordinates.at(4), coordinates.at(5));
            out << "Sufficient coordinates input." << endl;
            cout << "Sufficient coordinates input." << endl << endl;
            displayTriangle(T1.getL1(), T1.getL2(), T1.getL3());

            out << "Triangle: " << !T1.getL1().Colinear(T1.getL2(), T1.getL3()) << endl;
            out << "Area: " << T1.getL1().Area(T1.getL2(), T1.getL3()) << endl;
            out << "Perimeter: " << T1.getL1().Perimeter(T1.getL2(), T1.getL3()) << endl;
            out << "Equilateral: " << T1.getL1().Equilateral(T1.getL2(), T1.getL3()) << endl;
            out << endl;
        }
        else if (coordinates.size() == 8){
            Quad Q1(coordinates.at(0), coordinates.at(1), coordinates.at(2), coordinates.at(3), coordinates.at(4), coordinates.at(5), coordinates.at(6), coordinates.at(7));
            out << "Sufficient coordinates input";
            cout << "Sufficient coordinates input" << endl;
            displayQuad(Q1.getP1(), Q1.getP2(), Q1.getP3(), Q1.getP4());

            out << endl << "Quadrilateral: " << Q1.getP1().QuadCheck(Q1.getP2(), Q1.getP3(), Q1.getP4()) << endl;
            out << "Area: " << Q1.getP1().Area(Q1.getP2(), Q1.getP3(), Q1.getP4()) << endl << endl;
        }
        getline(in, input);
    }
    in.close();
    out.close();


    return 0;
}
