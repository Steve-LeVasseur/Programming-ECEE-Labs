#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int rollDie(){ // Function to roll dice.
    int Roll = (rand() % 6) + 1;
    return Roll;
}

bool playOneGame(int guess){   // Plays the game. Returns True for victory and False for defeat.
    for (int i = 0; i < 3; i++){
        int Roll = rollDie();
        if (guess == Roll){
            cout << "Roll #" << i + 1 << " is " << Roll << endl;
            return true;
        }
        else {
            cout << "Roll #" << i + 1 << " is " << Roll << endl;
            continue;
        }
    }
    return false;
}

void WinLoss (double Win, double Loss){           // Calculates Win/Loss Ratio at the end.
    double Ratio = Win / (Win + Loss);
    cout << "You won " << Win << " times." << endl << "You lost " << Loss << " times." << endl << "For a win ratio of: " << Ratio << endl;

}

int BigBankBoy (bool Game, int Balance, int Wager){    //   For tracking the balance based on game results.
    if (Game == true){
       cout << "Victory. ";
       Balance += Wager;
       cout << "Balance: $" << Balance;
}
    else {
        cout << "Failure. ";
        Balance -= Wager;
        cout << "Balance: $" << Balance;
    }
    return Balance;
}

double WinCounter(double Win, bool Game){  // Function to count wins.
    if (Game == true){
        Win++;
        return Win;
    }
    else {
        return Win;
    }
}

double LossCounter(double Loss, bool Game){  // Function to count losses.
    if (Game == false){
        Loss++;
        return Loss;
    }
    else {
        return Loss;
    }
}

int main() {
    srand(time(NULL));  // Seed the random number
    int Balance = 100;  // Declaring Variables and such
    int Wager;
    double Win = 0.0;
    double Loss = 0.0;
    Anchor1:    // GoTo Ancher. I had to try this at least once.
    cout << "Enter wager: ";
    cin >> Wager;
    while (Wager > Balance || Wager <= 0){  // Checks validity of the wager.
        cout << endl << "Invalid. Enter new wager: ";
        cin >> Wager;
    }
    cout << "Enter guess: "; // Guess input
    int guess;
    cin >> guess;
    char Again = 'x';

        bool Result = playOneGame (guess);
        Balance = BigBankBoy(Result, Balance, Wager);  // Functions where perfectly fine code used to be.
        Win = WinCounter(Win, Result);
        Loss = LossCounter(Loss, Result);
        if (Balance == 0){     // If they run out of money, game over.
            cout << endl << "That wasn't very cash money of you. GAME OVER" << endl;
            WinLoss(Win, Loss);
            return 0;
            }
        cout << " Enter x to play again. Any other key to exit." << endl; // Ask if they want to play again
        cin >> Again;

        if (Again == 'x'){ // If they want to play again
            goto Anchor1;  //  GoTo command. I really wanted to see if this worked. I promise not to use it in future labs.
        }
        else {  // If they don't want to play again
            WinLoss(Win, Loss);
            return 0;
        }
}
