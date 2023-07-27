/* 
An election is contested by five candidates. The candidates are numbered 1 to 5 and 
the voting is done by marking the candidate number on the ballot paper. 
Write a program to read the ballots and count the votes cast for each candidate using an array variable count. 
In case, a number read is outside the range 1 to 5, the ballot should be considered as a 'spoil ballot', and 
the program should also count the number of spoiled ballots. 
*/ 

/* This question took my four hours just to think how I should approach but the end result is indeed rewarding */

#include <iostream>
using namespace std;

int main() {
    // Initialize an array to store vote count for each candidate (all set to 0)
    /* initialized to 0 as it is essential to ensure that each element
       of the array starts with a value of zero before any votes are counted.
    */
    int count[5] = {0};

    // Variable to store the number of participants (ballots)
    int Participants;

    // Variable to store the candidate number entered by each participant
    int candidateNumber;

    // Variable to keep track of the number of spoilt ballots
    int spoilBallots = 0;

    // Welcome message for the election voting system
    cout << "----- Welcome to the Election Voting System -----\n";
    cout << "You can vote for any of the five candidates (Candidate 1 to 5).\n\n";

    // Read the number of participants (ballots) to be processed
    cout << "Enter the number of participants (ballots): ";
    cin >> Participants;

    // Instruction for participants to cast their votes
    cout << "\n----- Start Casting Your Vote -----\n";

    // Process each participant's vote
    for (int i = 0; i < Participants; i++) {
        // Prompt each participant to enter their candidate number
        cout << "Voter " << (i + 1) << ", please enter the candidate number you want to vote for: ";
        cin >> candidateNumber;

        // Check if the candidate number is valid (between 1 to 5)
        if (candidateNumber >= 1 && candidateNumber <= 5) {
            // Valid candidate number, increment the corresponding count for that candidate
            count[candidateNumber - 1]++;
            cout << "Thank you! Your vote for Candidate " << candidateNumber << " has been recorded.\n\n";
        } else {
            // Invalid candidate number, considered as a spoilt ballot
            spoilBallots++;
            cout << "Oops! This is a spoilt ballot. Your vote could not be recorded.\n\n";
        }
    }

    // Display the election results - vote count for each candidate
    cout << "\n----- Election Results -----\n";
    for (int i = 0; i < 5; i++) {
        cout << "Candidate " << (i + 1) << " received " << count[i] << " votes.\n";
    }

    // Display the number of spoilt ballots
    cout << "Number of spoilt ballots: " << spoilBallots << endl;

    return 0;
}
