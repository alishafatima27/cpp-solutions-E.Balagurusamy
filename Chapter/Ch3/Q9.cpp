/*     variance = E(x^2) - (E(x))^2
Approach to Calculate Variance:

Break down the variance formula into two parts:

Calculate the expectation of squared data points, i.e., E(x^2).
Calculate the summation of data points and find the mean (expectation), i.e., (E(x))^2.
Take user input for the size of the dataset (n) and the data points.

Create a function called sum_n to calculate the summation of elements in an array. Pass the array data as an argument to this function.

Use the sum_n function twice:

First, to calculate the summation of the data points (E(x)).
Second, to calculate the summation of the squared data points (E(x^2)).
After obtaining the summation of data points and squared data points, calculate the mean (expectation) by dividing the summation by the number of data points (n).

Declare a variable called var to store the variance value.

Use the formula var = E(x^2) - (E(x))^2 to calculate the variance.

Display the variance value as the final result.
/*
// Note, Here I have used my own personal approach to solve the problem. I have not used the formula given in the book.
    
#include <iostream>
using namespace std;

// Function to calculate the sum of elements in an array
int sum_n(int x, int data[])
{
    int sum = 0;
    for (int i = 0; i < x; i++)
    {
        sum += data[i];
    }
    return sum;
}

int main()
{
    int n;

    // Step 1: Input the size of the dataset
    cout << "Enter the size of the dataset: ";
    cin >> n;

    // Declare arrays to store data and squared data
    int data[n], sq_data[n];

    // Step 2: Input the data points
    cout << "Enter " << n << " data points:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Data " << i + 1 << ": ";
        cin >> data[i];
        sq_data[i] = data[i] * data[i]; // Calculate squared data
    }

    // Step 3: Calculate the sum of the data points
    int sum = sum_n(n, data);

    // Step 4: Calculate the mean (expectation) of the numbers
    float exp = static_cast<float>(sum) / n;

    // Step 5: Display the mean (expectation) of the numbers
    cout << "Mean/expectation of the numbers: " << exp << endl;

    // Step 6: Calculate the sum of squared data points
    float exp_sq = sum_n(n, sq_data);

    // Step 7: Calculate the mean (expectation) of squared numbers
    float exp_sq_mean = exp_sq / n;

    // Step 8: Display the mean (expectation) of squared numbers
    cout << "Mean/expectation of squared numbers: " << exp_sq_mean << endl;

    // Step 9: Calculate the variance
    float var = exp_sq_mean - exp * exp;

    // Step 10: Display the variance
    cout << "Variance = " << var << endl;

    return 0;
}

