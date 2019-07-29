#include <iostream>

using namespace std;

class Cuboid {
public:
    Cuboid(){
        setL(0);
        setW(0);
        setH(0);
    }

    Cuboid(double in_L, double in_W, double in_H){
        setL(in_L);
        setW(in_W);
        setH(in_H);
    }

    double getL(){
        return L;
    }

    double getW(){
        return W;
    }

    double getH(){
        return H;
    }

    void setL(double in_L){
        L = in_L;
    }
    void setW(double in_W){
        W = in_W;
    }
    void setH(double in_H){
        H = in_H;
    }

    void display(){
        cout << "Cuboid Parameters: " << endl;
        cout << "Length: " << getL() << endl;
        cout << "Width: " << getW() << endl;
        cout << "Height: " << getH() << endl;
        cout << "Surface Area: " << getArea() << endl;
        cout << "Volume: " << getVolume() << endl << endl;
    }

private:
    double getArea(){
        return 2*W*L + 2*L*H + 2*H*W;
    }

    double getVolume(){
        return L*W*H;
    }

    double L;
    double W;
    double H;
};


int main(){

    Cuboid cuboid1;
    cuboid1.display();

    Cuboid cuboid2(1,2,3);
    cuboid2.display();

    cuboid2.setL(3);
    cuboid2.setW(4);
    cuboid2.setH(5);
    cuboid2.display();

    return 0;
}
