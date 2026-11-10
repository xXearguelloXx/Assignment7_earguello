#ifndef MAGNETIC_FIELD_H
#define MAGNETIC_FIELD_H

class Magnetic_Field
{
  private:
    double *B;   // points to a heap array of 3 doubles

  public:
    // Constructors / destructor
    Magnetic_Field();                                        // (0, 0, 0)
    Magnetic_Field(double x, double y, double z);            // (x, y, z)
    Magnetic_Field(const Magnetic_Field &other);             // deep copy
    Magnetic_Field &operator=(const Magnetic_Field &other);  // deep copy assign
    ~Magnetic_Field();                                       // delete[] B

    // Getters
    double getX() const;
    double getY() const;
    double getZ() const;

    // Setters
    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);

    // Math
    double calculateMagnitude() const;        // |B|
    Magnetic_Field calculateUnitVector() const;  // B / |B|  (length 1)

    // Output
    void print() const;   // prints "(x, y, z)"
};

#endif
