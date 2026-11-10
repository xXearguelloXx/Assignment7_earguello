#include "electric_field.h"

#include <cmath>     // std::sqrt
#include <iostream>  // std::cout

// Number of components in a 3D vector
static const int NUM_COMPONENTS = 3;

// Constructors / destructor

// Default constructor: allocate the array and zero every component.
Electric_Field::Electric_Field()
    : E(new double[NUM_COMPONENTS]())
{
}

// Component constructor: allocate, then store x, y, z.
Electric_Field::Electric_Field(double x, double y, double z)
    : E(new double[NUM_COMPONENTS])
{
    E[0] = x;
    E[1] = y;
    E[2] = z;
}

// Copy constructor: give the NEW object its OWN array, then copy values
Electric_Field::Electric_Field(const Electric_Field &other)
    : E(new double[NUM_COMPONENTS])
{
    for (int i = 0; i < NUM_COMPONENTS; i++)
    {
        E[i] = other.E[i];
    }
}

// Copy assignment: both objects ALREADY own a 3-element array, so there is nothing to allocate or free. 
// Just copy the values across.
Electric_Field &Electric_Field::operator=(const Electric_Field &other)
{
    if (this != &other)
    {
        for (int i = 0; i < NUM_COMPONENTS; i++)
        {
            E[i] = other.E[i];
        }
    }
    return *this;   // lets you chain: a = b = c;
}

// Destructor: free the heap array
// It was allocated with new[], so it MUST be released with delete[]
Electric_Field::~Electric_Field()
{
    delete[] E;
}


// Getters

double Electric_Field::getX() const { return E[0]; }
double Electric_Field::getY() const { return E[1]; }
double Electric_Field::getZ() const { return E[2]; }


// Setters

void Electric_Field::setX(double newX) { E[0] = newX; }
void Electric_Field::setY(double newY) { E[1] = newY; }
void Electric_Field::setZ(double newZ) { E[2] = newZ; }

// Math

double Electric_Field::innerProduct() const
{
    return innerProduct(*this);   // reuse the general version below
}

// Inner
double Electric_Field::innerProduct(const Electric_Field &other) const
{
    double sum = 0.0;
    for (int i = 0; i < NUM_COMPONENTS; i++)
    {
        sum += E[i] * other.E[i];
    }
    return sum;
}

// Magnitude
double Electric_Field::calculateMagnitude() const
{
    return std::sqrt(innerProduct());
}

// Output

void Electric_Field::print() const
{
    std::cout << "(" << E[0] << ", " << E[1] << ", " << E[2] << ")";
}
