/*
Lab4 (Color) - Create a vector of structs to hold a random number of colors with various RGB values, then output to console in formatted list.
*/

#include <iomanip>
#include <string>
#include <vector>
#include <random>

using namespace std; // Cause I definitely ain't gonna std:: each statement

// Spacing for output
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

void OutputRestaurantHeader(); // Outputs header for color data
void OutputColorInfo(const Color &); // Outputs individual color data

int main()
{
    // Random number generators for creating data to populate vector of restaurants for testing
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 9);
    uniform_int_distribution<> dist1(1900, 2024);
    uniform_int_distribution<> dist2(15, 100);
    uniform_int_distribution<> dist3(0, 1);
    // Temp restaurant object
    Color c;
    vector<Color> Colors = {};

    // Loop to populate color data and vector
    for (size_t i = 0; i < 5; i++)
    {
        r.name = NAME[dist(gen)];
        r.address = ADDRESS[dist(gen)];
        r.yearEstablished = dist1(gen);
        r.seatingCapacity = dist2(gen);
        if (dist3(gen) == 0)
        {
            r.acceptsReservations = false;
        }
        else
        {
            r.acceptsReservations = true;
        }

        Restaurants.push_back(r); // Add restaurant to vector
    }

    // Output header info to console
    OutputColorHeader();

    // Output restaurant info to console
    for (Restaurant r : Restaurants)
    {
        OutputRestaurantInfo(r);
    }

    return 0;
}

// Output header for data
void OutputColorHeader()
{
    cout << endl
         << left << setw(SPACING_LARGE) << "NAME" << setw(SPACING_EXTRA_LARGE) << "ADDRESS" << setw(SPACING_LARGE) << "YEAR ESTABLISHED" << setw(SPACING_SMALL) << "CAPACITY" << setw(SPACING_LARGE) << "ACCEPTS RESERVATIONS"
         << endl
         << string(125, '-')
         << endl;
};

// Output function to cout restaurant info in formatted form
void OutputColorInfo(const Color &c)
{
    string acceptingReservations = "";

    cout << left << setw(SPACING_LARGE) << r.name << setw(SPACING_EXTRA_LARGE) << r.address << setw(SPACING_LARGE) << r.yearEstablished << setw(SPACING_SMALL) << r.seatingCapacity;
    acceptingReservations = (r.acceptsReservations == 1) ? "Yes" : "No";
    cout << setw(SPACING_LARGE) << acceptingReservations << endl;
};