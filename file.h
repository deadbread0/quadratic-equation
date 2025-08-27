

const int MAX_LEN_OF_WORD = 100;

const double ACCURACY = 1e-12;

int Input(struct ParametersOfTheEquation*);//в разные f.h
double SquareRoot(double);
void FindSolution(struct ParametersOfTheEquation*);
void Output(struct ParametersOfTheEquation*);
bool GetAnswerAboutTheExit();
int ComparisonDouble(double, double);
void CopyBufferInput(char*);
void CleanBuffer();
double Mod(double);
int OneTest(struct ParametersOfTheEquation*);
int InputValidate();
int UseFlags(const char*, const char*,const struct ParametersOfFlags*, int);
int InputFile(struct ParametersOfTheEquation*, FILE*);

