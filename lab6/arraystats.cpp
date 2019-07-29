#include <iostream>
#include <cmath>
#include <vector>
#include<time.h>
#include<cstdlib>

using namespace std;

int randGenerator (int max){  // Generates random number under the max
    int Number = rand()%max;
    return Number;
}

vector<int> createDataSet (int sampleSize, int max){  // Generates vector of random numbers as specified by user inputs
    vector<int> dataSet(sampleSize);
    for (unsigned i = 0; i < dataSet.size(); i++){
        int x = randGenerator(max);
        dataSet.at(i) = x;
    }

    return dataSet;
}

vector<int> frequencyCounter (int max, vector<int> dataSet){  // Generates vector that counts frequency of each numbers occurence in the dataset
    vector<int> frequencyCount(max, 0);
    for (unsigned i = 0; i < dataSet.size(); i++){
        int x = dataSet.at(i);
        frequencyCount.at(x) += 1;
    }
    return frequencyCount;
}

vector<int> frequencyScale (vector<int> frequencyCount){   // Scales the frequency count for the bar chart
    vector<int> scaledFrequency(frequencyCount.size());
    for (unsigned i = 0; i < frequencyCount.size(); i++){
        scaledFrequency.at(i) = frequencyCount.at(i) / 5;  // Adjust divisor as seems appropriate. 5 given
    }
    return scaledFrequency;
}

void calculations(vector<int> frequencyCount, int sampleSize){ // Calculate sum, mean, max and min of frequency data
    int sum = 0;
    double mean = 0.0;
    int max = 0;
    int min = 50000;

    for (unsigned i = 0; i < frequencyCount.size(); i++){ // Sum calculator
        sum = sum + frequencyCount.at(i);
    }
    cout << "Sum: " << sum << endl; // Sum output

    for (unsigned i = 0; i < frequencyCount.size(); i++){ // Mean calculator
        mean = mean + (frequencyCount.at(i) * i);
    }
    mean = mean / sampleSize;
    cout << "Mean: " << mean << endl; // Mean output

    for (unsigned i = 0; i < frequencyCount.size(); i++){ // Max calculator
        if (max <= frequencyCount.at(i)){
            max = frequencyCount.at(i);
        }
        else {
            continue;
        }
    }
    cout << "Max: " << max << endl; // Max output

    for (unsigned i = 0; i < frequencyCount.size(); i++){ // Min calculator
        if (min >= frequencyCount.at(i)){
            min = frequencyCount.at(i);
        }
        else {
            continue;
        }
    }
    cout << "Min: " << min << endl; // Min output
    return;
}

void barChart (vector<int> scaledFrequency){  // Displays the barchart
    for (unsigned i = 0; i < scaledFrequency.size(); i++){
        cout << endl << i << "   ";
        for (unsigned j = 0; j < scaledFrequency.at(i); j++){
            cout << "*";
        }
    }
    return;
}

int main(){
    srand(time(0));
    int SampleSize;
    cout << "Input number of samples: ";  // Getting inputs
    cin >> SampleSize;
    int Max;
    cout << "Input upper limit: ";
    cin >> Max;

    vector<int> dataSet = createDataSet(SampleSize, Max);  // Using functions

    vector<int> Frequency = frequencyCounter(Max, dataSet);

    vector<int> ScaledFrequency = frequencyScale(Frequency);

    barChart(ScaledFrequency);

    calculations(Frequency, SampleSize);


    return 0;
}
