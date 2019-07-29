#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const double pi = M_PI;

double Resist; // input
double L_induct; // input
double Capac;   // input
int nstep;          // input
double Eo_Voltage; // input
double freq;   // input
double Amp;
double Phi_angle;
double Omega_freq;
double AC;
double delta_t;

double Amplitude (double omega, double Eo, double L, double R, double C){
    double A;
    double squareFodder;
    double sqrtFodder;

    squareFodder = (L * pow(omega, 2.0)) - (1 / C);
    sqrtFodder = (pow(squareFodder, 2.0)) + ((pow(R, 2.0)) * (pow(omega, 2.0)));
    A = (omega * Eo) / sqrt(sqrtFodder);

    return A;
}

double Angle (double omega, double L, double R, double C){
    double Phi;
    Phi = atan(((L * omega) / R) - (1 / (R * C * omega)));

    return Phi;
}

double AppliedVoltage (double time, double omega, double Eo){
    double Vt;
    Vt = Eo * (sin(omega * time));

    return Vt;
}

double ResistorVoltage(double time, double omega, double A, double phi, double R){
    double Vr;
    Vr = R * A * (sin((omega * time) - phi));

    return Vr;
}

double TotalCurrent (double time, double omega, double A, double phi){
    double It;
    It = A * (sin((omega * time) - phi));

    return It;
}

double InductorVoltage (double time, double omega, double A, double phi, double L){
    double Vl;
    Vl = L * omega * A * (cos((omega * time)-phi));

    return Vl;
}

double CapacitorVoltage (double time, double omega, double A, double phi, double C){
    double Vc;
    Vc = ((-1) * A * (cos((omega * time) - phi))) / (C * omega);

    return Vc;
}


int main(){
    cout<<"Eo";cin >> Eo_Voltage;
    cout<<"R";cin >> Resist;
    cout<<"L";cin >> L_induct;
    cout<<"C";cin >> Capac;
    cout<<"freq";cin >> freq;
    cout<<"nstep";cin >> nstep;

    Omega_freq = 2 * pi * freq;
    AC = (1 / freq);

    delta_t = 0.0;

    Amp = Amplitude(Omega_freq, Eo_Voltage, L_induct, Resist, Capac);
    Phi_angle = Angle(Omega_freq, L_induct, Resist, Capac);
    double Phi_degrees = (Phi_angle * 180) / pi;

    cout << "RLC Circuit Summary:" << endl;
    cout << "\n\tVoltage:         " << Eo_Voltage << "-Volts @ " << freq << "-Hz" << endl;
    cout <<   "\tResistor Value:  " << Resist << "-ohms" << endl;
    cout <<   "\tInductor Value:  " << L_induct << "-H" << endl;
    cout <<   "\tCapacitor Value: " << scientific << Capac << fixed << "-F" << endl;
    cout << "\tnsteps: " << nstep << endl;

    cout << fixed << setprecision(3);

    cout << "\n\tCalculated Parameters:" << endl;
    cout << "\t    Current Amplitude: " << setw(8) << Amp << "-amps" << endl;
    cout << "\t    Phase Angle:       " << setw(8) << Phi_degrees << "-degrees\n" << endl;
    cout << "\tIter.Time\tAV\t I\tVR\tVL\tVC   Vdiff" << endl;

    for(int i = 0; i < (2 * nstep); i += 1){

        double AV = AppliedVoltage(delta_t, Omega_freq, Eo_Voltage);
        double Vr = ResistorVoltage(delta_t, Omega_freq, Amp, Phi_angle, Resist);
        double TC = TotalCurrent(delta_t, Omega_freq, Amp, Phi_angle);
        double Vl = InductorVoltage(delta_t, Omega_freq, Amp, Phi_angle, L_induct);
        double Vc = CapacitorVoltage(delta_t, Omega_freq, Amp, Phi_angle, Capac);

        double Vdiff = AV - Vr - Vl - Vc;

        cout << "\t" << setw(2) << i;
        cout << setw(8) << delta_t;
        cout << setw(8) << AV;
        cout << setw(8) << TC;
        cout << setw(8) << Vr;
        cout << setw(8) << Vl;
        cout << setw(8) << Vc;
        cout << setw(8) << Vdiff << endl;

        delta_t += (AC / nstep);
    }
    return 0;
}
