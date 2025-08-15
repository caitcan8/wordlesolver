#include <getopt.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
using namespace std;

extern string filename;

void getOptions(int argc, char **argv);

void printHelp(char *command);

struct Green{
    char letter;
    size_t pos;
};
struct Yellow{
    char letter;
    size_t pos;
};
class Solver{
    public: 
    void read();
    void solve();
    
    private:
    vector<string> wordlist;
    vector<Green> greenletters;
    vector<char> grayletters;
    vector<Yellow> yellowletters;
};