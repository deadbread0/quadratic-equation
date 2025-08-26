#define MAX_LEN_OF_WORD 100

struct ParametersOfTheEquation {
    double a;
    double b;
    double c;
    int amount_of_solutions;
    double x1;
    double x2;
};

struct ParametersOfFlags {
    const char *flag;
    const char *flg;
    void (*ptr)(void);

};

int Input(struct ParametersOfTheEquation*);
double SquareRoot(double);
void FindSolution(struct ParametersOfTheEquation*);
void Output(struct ParametersOfTheEquation*);
bool GetAnswerAboutTheExit();
int ComparisonDouble(double, double);
void CopyBufferInput(char*);
void CleanBuffer();
void RunTests();
double Mod(double);
int OneTest(struct ParametersOfTheEquation*);
int InputValidate();
int UseFlags(const char*, struct ParametersOfFlags*);
void Help();
void ReadFile();

enum RootsAmount {
    INF, 
    ONE,
    TWO, 
    ZERO
};
enum NumIs {
    FIRST_EQUAL_TO_SECOND,
    FIRST_GREATER_THAN_SECOND,
    FIRST_LESS_THAN_SECOND
};
enum Flags {
    TESTING,
    HELP, 
    READFILE,
    STANDARD
};