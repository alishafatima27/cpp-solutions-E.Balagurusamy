#include <iostream>
#include <iomanip> // For setting precision of output

using namespace std;

// Recursive Function to calculate the value of V using the investment equation
double calculateValue(double P, double r, int n) {
    double V = P;
    for (int i = 1; i <= n; i++) {
        V = V * (1 + r);
    }
    return V;
}

int main() {
    // Define the ranges for P, r, and n
    int P_min = 1000, P_max = 10000, P_step = 1000;
    double r_min = 0.10, r_max = 0.20, r_step = 0.01;
    int n_min = 1, n_max = 10;

    // Print the table headers
    cout << "P\t\tr\t\tn\t\tV" << endl;

    // Iterate through each combination of P, r, and n
    for (int P = P_min; P <= P_max; P += P_step) {
        for (double r = r_min; r <= r_max; r += r_step) {
            for (int n = n_min; n <= n_max; n++) {
                // Calculate the value of V using the investment equation
                double V = calculateValue(P, r, n);

                // Print the values in the table with proper formatting
                cout << fixed << setprecision(2);
                cout << P << "\t\t" << r << "\t\t" << n << "\t\t" << V << endl;
            }
        }
    }

    return 0;
}
