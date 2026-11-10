// Lab Assignment 7 - Electric and Magnetic Field classes
//
// Creates fields three ways (default constructor, component constructor,
// default constructor + setters), then prints each field's magnitude plus
// the class-specific result:
//   Electric_Field -> inner product  E . E
//   Magnetic_Field -> unit vector    B / |B|

#include <iomanip>   // std::setprecision
#include <iostream>
#include <string>

#include "electric_field.h"
#include "magnetic_field.h"

// Print one electric field: components, magnitude, and inner product E . E.
// Takes a const reference: no copy is made, and the function promises not to 
// modify the field. That only compiles because every method called here
// is marked const in the class.
void reportElectric(const std::string &name, const Electric_Field &field)
{
    std::cout << name << " = ";
    field.print();
    std::cout << " V/m\n";
    std::cout << "    |E|   = " << field.calculateMagnitude() << " V/m\n";
    std::cout << "    E . E = " << field.innerProduct() << " (V/m)^2\n";
}

// Print one magnetic field: components, magnitude, and unit vector.
void reportMagnetic(const std::string &name, const Magnetic_Field &field)
{
    std::cout << name << " = ";
    field.print();
    std::cout << " T\n";
    std::cout << "    |B|   = " << field.calculateMagnitude() << " T\n";

    // unitB is its own object with its own heap array; its destructor runs 
    // automatically at the end of this function.
    Magnetic_Field unitB = field.calculateUnitVector();
    std::cout << "    B_hat = ";
    unitB.print();
    std::cout << "\n";
}

int main()
{
    std::cout << std::setprecision(8);

    // Electric fields

    // 1 Default constructor -> (0, 0, 0)
    Electric_Field E_default;

    // 2 Component constructor
    Electric_Field E_components(1e5, 10.9, 1.7e2);

    // 3 Default constructor, then fill in with the setters
    Electric_Field E_set;
    E_set.setX(3.0);
    E_set.setY(4.0);
    E_set.setZ(12.0);

    std::cout << "=============== Electric Fields ===============\n";
    reportElectric("E_default   ", E_default);
    reportElectric("E_components", E_components);
    reportElectric("E_set       ", E_set);

    // Inner product of two different fields
    std::cout << "E_components . E_set = "
              << E_components.innerProduct(E_set) << " (V/m)^2\n\n";

    // Magnetic fields

    // 1 Default constructor -> (0, 0, 0)
    Magnetic_Field B_default;

    // 2 Component constructor
    Magnetic_Field B_components(2e-5, 3e-5, 6e-5);

    // 3 Default constructor, then fill in with the setters
    Magnetic_Field B_set;
    B_set.setX(0.3);
    B_set.setY(0.4);
    B_set.setZ(1.2);

    std::cout << "=============== Magnetic Fields ===============\n";
    reportMagnetic("B_default   ", B_default);
    reportMagnetic("B_components", B_components);
    reportMagnetic("B_set       ", B_set);

    return 0;
}
