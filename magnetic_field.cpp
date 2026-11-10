#include "magnetic_field.h"

#include <cmath>     // std::sqrt
#include <iostream>  // std::cout

// Number of components in a 3D vector
static const int NUM_COMPONENTS = 3;

// Constructors / destructor
// Default constructor so allocate and zero all three components.
Magnetic_Field::Magnetic_Field()
    : B(new double[NUM_COMPONENTS]())
{
}

// Component constructor so allocate, then store x, y, z.
Magnetic_Field::Magnetic_Field(double x, double y, double z)
    : B(new double[NUM_COMPONENTS])
{
    B[0] = x;
    B[1] = y;
    B[2] = z;
}

// Copy constructor: new object gets its OWN array
Magnetic_Field::Magnetic_Field(const Magnetic_Field &other)
    : B(new double[NUM_COMPONENTS])
{
    for (int i = 0; i < NUM_COMPONENTS; i++)
    {
        B[i] = other.B[i];
    }
}

// Copy assignment: both arrays already exist and are the same size so copy
Magnetic_Field &Magnetic_Field::operator=(const Magnetic_Field &other)
{
    if (this != &other)
    {
        for (int i = 0; i < NUM_COMPONENTS; i++)
        {
            B[i] = other.B[i];
        }
    }
    return *this;
}

// Destructor: new[] pairs with delete[].
Magnetic_Field::~Magnetic_Field()
{
    delete[] B;
}

// Getters

double Magnetic_Field::getX() const { return B[0]; }
double Magnetic_Field::getY() const { return B[1]; }
double Magnetic_Field::getZ() const { return B[2]; }

// Setters

void Magnetic_Field::setX(double newX) { B[0] = newX; }
void Magnetic_Field::setY(double newY) { B[1] = newY; }
void Magnetic_Field::setZ(double newZ) { B[2] = newZ; }

// Math

// Magnitude
double Magnetic_Field::calculateMagnitude() const
{
    double sumOfSquares = 0.0;
    for (int i = 0; i < NUM_COMPONENTS; i++)
    {
        sumOfSquares += B[i] * B[i];
    }
    return std::sqrt(sumOfSquares);
}

// Unit vector is same direction as B but length 1
// Returns a NEW Magnetic_Field object by value
Magnetic_Field Magnetic_Field::calculateUnitVector() const
{
    double mag = calculateMagnitude();

    if (mag == 0.0)
    {
        return Magnetic_Field();   // (0, 0, 0)
    }

    return Magnetic_Field(B[0] / mag, B[1] / mag, B[2] / mag);
}


// Output

void Magnetic_Field::print() const
{
    std::cout << "(" << B[0] << ", " << B[1] << ", " << B[2] << ")";
}
