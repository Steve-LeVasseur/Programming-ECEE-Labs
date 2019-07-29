#include <iostream>

using namespace std;

class Cube {
public:
    Cube(){
        setE(0);
    }

    Cube(double in_E){
        setE(in_E);
    }

    double getE(){
        return E;
    }

    void setE(double in_E){
        E = in_E;
    }

    void display(){
        cout << "Cube Parameter: " << endl;
        cout << "Edge: " << getE() << endl;
        cout << "Surface Area: " << getArea() << endl;
        cout << "Volume: " << getVolume() << endl << endl;
    }

private:
    double getArea(){
        return 6*E*E;
    }

    double getVolume(){
        return E*E*E;
    }

    double E;
};


int main(){

    Cube cube1;
    cube1.display();

    Cube cube2(2);
    cube2.display();

    cube2.setE(3);
    cube2.display();

    return 0;
}
