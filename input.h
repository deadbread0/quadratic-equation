
const int MAX_LEN_OF_WORD = 100;

struct ParametersOfTheEquation {
    double a;
    double b;
    double c;
    int amount_of_solutions;
    double x1;
    double x2;
};

/*! \file
* \brief
*/

//---------------------------------------------------------------------------------
//! accepts coefficients entered by the user, returns the number of numbers entered
//!
//! @param [in] struct_ptr pointer to the equation parameter structure
//!
//! @return amount of coefficients
//!
//---------------------------------------------------------------------------------

int Input(struct ParametersOfTheEquation*);
bool GetAnswerAboutTheExit();
void CopyBufferInput(char*);
void CleanBuffer();
int InputValidate();
