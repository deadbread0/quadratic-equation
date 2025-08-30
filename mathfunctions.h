
const double ACCURACY = 1e-12;

enum NumIs {
    FIRST_EQUAL_TO_SECOND,
    FIRST_GREATER_THAN_SECOND,
    FIRST_LESS_THAN_SECOND
};

enum RootsAmount {
    INF, 
    ONE,
    TWO, 
    ZERO
};

struct ParametersOfTheEquation {
    double a;
    double b;
    double c;
    int amount_of_solutions;
    double x1;
    double x2;
};

double SquareRoot(double);

/*! \file
* \brief
*/

//---------------------------------------------------------------------------------------------------
//! determines the number of solutions depending on the coefficients, finds the roots of the equation
//!
//! @param [in] struct_ptr pointer to the equation parameter structure
//!
//---------------------------------------------------------------------------------------------------


void FindSolution(struct ParametersOfTheEquation*);
int ComparisonDouble(double, double);
double Mod(double);
