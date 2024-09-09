/*
Lab4 (Color) - Create a vector of structs to hold a random number of colors with various RGB values, then output to console in formatted list.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>

using namespace std;

// Spacing for output, only using extra small for this project
const int SPACING_EXTRA_LARGE = 40;
const int SPACING_LARGE = 25;
const int SPACING_SMALL = 15;
const int SPACING_EXTRA_SMALL = 10;

// Color struct
struct Color
{
    int red;
    int green;
    int blue;
};

void OutputColorHeader();                    // Outputs header for color data
void OutputColorList(const vector<Color> &); // Outputs individual color data

int main()
{
    // Random number generators for creating data to populate vector of restaurants for testing
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 255);  // For creating colors
    uniform_int_distribution<> dist1(25, 50); // # of colors to be created
    // Temp color object
    Color c;
    vector<Color> Colors = {};
    int n = dist1(gen);

    // Loop to populate color data and vector
    for (size_t i = 0; i < n; i++)
    {
        c.red = dist(gen);
        c.green = dist(gen);
        c.blue = dist(gen);

        Colors.push_back(c); // Add restaurant to vector
    }

    // Output header and color info to console
    OutputColorHeader();
    OutputColorList(Colors);

    return 0;
}

// Output header for data
void OutputColorHeader()
{
    cout << endl
         << string((4 * SPACING_EXTRA_SMALL), '=')
         << endl
         << left << setw(SPACING_EXTRA_SMALL) << "Color #" << setw(SPACING_EXTRA_SMALL) << "R value" << setw(SPACING_EXTRA_SMALL) << "G value" << setw(SPACING_SMALL) << "B value"
         << endl
         << string((4 * SPACING_EXTRA_SMALL), '=')
         << endl;
};

// Output function to cout restaurant info in formatted form
void OutputColorList(const vector<Color> &Colors)
{
    // Output color info to console
    for (size_t i = 0; i < Colors.size(); i++)
    {
        cout << left << setw(SPACING_EXTRA_SMALL) << (i + 1) << setw(SPACING_EXTRA_SMALL) << Colors.at(i).red << setw(SPACING_EXTRA_SMALL) << Colors.at(i).green << setw(SPACING_SMALL) << Colors.at(i).blue
             << endl;
    }
};