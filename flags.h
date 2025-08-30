
const int MAX_LEN_OF_WORD = 100;

struct ParametersOfFlags {
    const char *flag;
    const char *flg;
    void (*ptr)(const char*, const char*);
    const char *instruction;

};

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

//------------------------------------------------------------------------------------
//! depending on the entered flag, uses the function
//!
//! @param [in] input_file pointer to the input file
//! @param [in] input_flag pointer to the input flag
//! @param [in] struct_flags pointer to the structure of flags
//! @param [in] len amount of flags
//! 
//! @return num: if the entered flag matches the existing ones, returns 0, otherwise 1
//!
//------------------------------------------------------------------------------------


int CompareFlagsAndRunFunction(const char*, const char*, const char*, const struct ParametersOfFlags*);
int RunFunc(const char*, const char*, const struct ParametersOfFlags*, int);

void RunTests(const char*, const char*);

/*! \file
* \brief
*/

//--------------------------------------------------
//! lists available flags
//!
//! @param [in] input_flag pointer to the input flag
//! 
//--------------------------------------------------


void Help(const char*, const char*);

/*! \file
* \brief
*/

//--------------------------------------------------
//! solves equations with coefficients from the file
//!
//! @param [in] input_file pointer to the input file
//! 
//--------------------------------------------------


void SolveEquationFromFile(const char*, const char*);

/*! \file
* \brief
*/

//--------------------------------------------------
//! solves equations
//!
//! @param [in] input_file pointer to the input file
//! 
//--------------------------------------------------


void Solver(const char*, const char*);

/*! \file
* \brief
*/

//--------------------------------------------------
//! No, no, this is not a Joker trap!
//! 
//--------------------------------------------------

void Joker(const char*, const char*);

const struct ParametersOfFlags struct_flags[] = {{"--test", "-t", RunTests, "a flag for testing the program. the program will output errors if there are any."},
                                                 {"--help", "-h", Help, "the flag will show all flags and their purpose."},  
                                                 {"--file", "-f", SolveEquationFromFile, "flag for inputting values from a file, if you enter a second file, the answers will go into it."},
                                                 {"--solve", "-s", Solver, "flag for solving quadratic equations."},
                                                 {"--jokes", "-j", Joker, "top jokes in the humble opinion of Kira Vostrikova"}};
const int len = sizeof(struct_flags) / sizeof(struct_flags[0]);                                               
int Input(struct ParametersOfTheEquation*);
void FindSolution(struct ParametersOfTheEquation*);
void Output(struct ParametersOfTheEquation*);
bool GetAnswerAboutTheExit();

/*! \file
* \brief
*/

//-------------------------------------------------------------------------
//! reads input data from a file
//!
//! @param [in] struct_ptr_file pointer to the equation parameter structure
//! @param [in] fp pointer to the input file
//! 
//-------------------------------------------------------------------------


int ReadsCoefficientsFromFile(struct ParametersOfTheEquation*, FILE*);
void OutputInFile(struct ParametersOfTheEquation*, const char*);
void CopyBufferInput(char*);
void CleanBuffer();

enum RootsAmount {
    INF, 
    ONE,
    TWO, 
    ZERO
};
