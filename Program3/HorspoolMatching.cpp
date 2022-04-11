#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <sstream>
#include <cstring>

using std::clock;
using std::clock_t;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;



void getInput(string filename, vector<string> &searchString, vector<string> &searchPattern){
    ifstream file(filename);
    string line;
    if(file.good()){
        getline(file, line);
        searchString.push_back(line);
    }
    file.close();
    std::chrono::milliseconds timespan(10);
    std::this_thread::sleep_for(timespan);

    ifstream file2(filename);
    string line2;
    while(getline(file2, line2)){
        searchPattern.push_back(line2);
    }
    file2.close();
    searchPattern.erase(searchPattern.begin());

}

void ShiftTable(vector<char> &shiftTableTop, vector<int> &shiftTableBottom){
    
    for(unsigned i = 0; i<(shiftTableBottom).size(); i++){ 
        cout << (shiftTableBottom).at(i) << endl;
    }
}

void horspoolMatching(){
    
}

void printOutput(vector<string> &searchString, vector<string> &searchPattern){
    const string filename = "output.txt";
    ofstream file(filename);
    for(unsigned i = 0; i<(searchString).size(); i++){ 
        file << (searchString).at(i) << " ";
    }
    file << endl;
    for(unsigned i = 0; i<(searchPattern).size(); i++){ 
        file << (searchPattern).at(i) << " ";
    }
    file.close();
}

int main(int argc, char** argv){
    clock_t start, end;  

    
    vector<string> searchString;
    vector<string> searchPattern;
    // vector<char> shiftTableTop;
    // vector<int> shiftTableBottom;
    int size = 150;
    int table[size];
    // char searchPattern[100], searchString[27];
    //const char *SearchString = searchString.at(0).c_str();
    cout << "Here" << endl;
    //int num = searchString.at(0).length();
    // for(int i = 0; i < 27; i++){
    //     cout << i << endl;
    //     shiftTableBottom.push_back(num);
    // }

    // shiftTableTop.push_back('A');
    // shiftTableTop.push_back('B');
    // shiftTableTop.push_back('C');
    // shiftTableTop.push_back('D');
    // shiftTableTop.push_back('E');
    // shiftTableTop.push_back('F');
    // shiftTableTop.push_back('G');
    // shiftTableTop.push_back('H');
    // shiftTableTop.push_back('I');
    // shiftTableTop.push_back('J');
    // shiftTableTop.push_back('K');
    // shiftTableTop.push_back('L');
    // shiftTableTop.push_back('M');
    // shiftTableTop.push_back('N');
    // shiftTableTop.push_back('O');
    // shiftTableTop.push_back('P');
    // shiftTableTop.push_back('Q');
    // shiftTableTop.push_back('R');
    // shiftTableTop.push_back('S');
    // shiftTableTop.push_back('T');
    // shiftTableTop.push_back('U');
    // shiftTableTop.push_back('V');
    // shiftTableTop.push_back('W');
    // shiftTableTop.push_back('X');
    // shiftTableTop.push_back('Y');
    // shiftTableTop.push_back('Z');
    // shiftTableTop.push_back(' ');

    string input;
    if(argc != 2) {
       cout << "Usage for " << argv[0] << ":" << endl;
       cout << argv[0] << " <InputFileName> " << endl;
       exit(0);
    }
    input = argv[1];
    
    getInput(input, searchString, searchPattern);
    
    cout << "Here" << endl;
    start = clock();
    
    //ShiftTable(shiftTableTop, shiftTableBottom);

    end = clock();
    cout << "Execution time: " << (double(end - start) / double(CLOCKS_PER_SEC / 1000)) << " milliseconds"<< endl;

    printOutput(searchString, searchPattern);
    return 0;
}