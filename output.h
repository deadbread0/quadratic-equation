
enum RootsAmount {
    INF, 
    ONE,
    TWO, 
    ZERO
};

/*! \file
* \brief
*/

//--------------------------------------------------------------------
//! displays the answer to the user's screen
//!
//! @param [in] struct_ptr pointer to the equation parameter structure
//!
//--------------------------------------------------------------------

void Output(struct ParametersOfTheEquation*);

struct ParametersOfTheEquation {
    double a;
    double b;
    double c;
    int amount_of_solutions;
    double x1;
    double x2;
};
