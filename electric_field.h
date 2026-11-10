#ifndef ELECTRIC_FIELD_H
#define ELECTRIC_FIELD_H

class Electric_Field
{
  private:
    double *E;   // points to a heap array of 3 doubles

  public:
    // Constructors / destructor
    Electric_Field();                                        // (0, 0, 0)
    Electric_Field(double x, double y, double z);            // (x, y, z)
    Electric_Field(const Electric_Field &other);             // deep copy
    Electric_Field &operator=(const Electric_Field &other);  // deep copy assign
    ~Electric_Field();                                       // delete[] E

    // Getters
    double getX() const;
    double getY() const;
    double getZ() const;

    // Setters
    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);

    // Math
    double calculateMagnitude() const;                        // E Magnitude
    double innerProduct() const;                              // E . E
    double innerProduct(const Electric_Field &other) const;   // E . other

    // Output
    void print() const;   // prints "(x, y, z)"
};

#endif
