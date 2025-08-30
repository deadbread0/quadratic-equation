
int CompareFlagsAndRunFunction(const char*, const char*, const char*, const struct ParametersOfFlags*);

void RunTests(const char*, const char*);
void Help(const char*, const char*);
void SolveEquationFromFile(const char*, const char*);
void Solver(const char*, const char*);
void Joker(const char*, const char*);

struct ParametersOfFlags {
    const char *flag;
    const char *flg;
    void (*ptr)(const char*, const char*);
    const char *instruction;

};

const struct ParametersOfFlags struct_flags[] = {{"--test", "-t", RunTests, "a flag for testing the program. the program will output errors if there are any."},
                                                 {"--help", "-h", Help, "the flag will show all flags and their purpose."},  
                                                 {"--file", "-f", SolveEquationFromFile, "flag for inputting values from a file."},
                                                 {"--solve", "-s", Solver, "flag for solving quadratic equations"},
                                                 {"--jokes", "-j", Joker, "top jokes in the humble opinion of Kira Vostrikova"}};
