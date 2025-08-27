


struct ParametersOfFlags {
    const char *flag;
    const char *flg;
    void (*ptr)(const char*);
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

void RunTests(const char*);
void Help(const char*);
void ReadFile(const char*);
void Solver(const char*);

const struct ParametersOfFlags struct_flags[] = {{"--test", "-t", RunTests, "a flag for testing the program. the program will output errors if there are any."},
                                               {"--help", "-h", Help, "the flag will show all flags and their purpose."},  
                                               {"--file", "-f", ReadFile, "flag for inputting values from a file."},
                                                {"--solve", "-s", Solver, "flag for solving quadratic equations"}};






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
