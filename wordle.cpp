#include "solver.h"

int main(int argc, char *argv[]) {
    //speed things up 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
  
    //process command line 
    getOptions(argc, argv);
    //string command;
    cout<<"hi\n";
    Solver solver;
    solver.read();
    solver.solve();
}