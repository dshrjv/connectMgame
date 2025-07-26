#include "board.hpp"
#include "game.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 4) {
        cout << "Usage: ./connectM N M H" << endl;
        return -1;
    }
   
   int N = stoi(argv[1]); 
   int M = stoi(argv[2]);
   bool humanFirst = stoi(argv[3]) == 1;

if (N < 3 || N > 10 || M < 2 || M > N || (stoi(argv[3]) != 0 && stoi(argv[3]) != 1)) {
    cout << "Invalid input. Ensure: " << endl << "- 3 ≤ N ≤ 10\n- 2 ≤ M ≤ N\n- H is 0 or 1\n";
    return -1;
    
}


   Game game(N, M, humanFirst);
   game.play();
   return 0;
}
