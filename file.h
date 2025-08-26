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
    void (*ptr)(const char*);
    const char *instruction;

};

int Input(struct ParametersOfTheEquation*);//в разные f.h
double SquareRoot(double);
void FindSolution(struct ParametersOfTheEquation*);
void Output(struct ParametersOfTheEquation*);
bool GetAnswerAboutTheExit();
int ComparisonDouble(double, double);
void CopyBufferInput(char*);
void CleanBuffer();
void RunTests(const char *);
double Mod(double);
int OneTest(struct ParametersOfTheEquation*);
int InputValidate();
int UseFlags(const char *, const char*, struct ParametersOfFlags*);
void Help(const char *);
void ReadFile(const char *);
int InputFile(struct ParametersOfTheEquation*, FILE*);
void Solver(const char *);

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