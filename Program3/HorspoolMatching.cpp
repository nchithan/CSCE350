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

void printOutput(int index){
    const string filename = "output.txt";
    ofstream file(filename);
    file << index << endl;
    
    file.close();
}

int main(int argc, char** argv){
    clock_t start, end;  

    
    vector<string> searchString;
    vector<string> searchPattern;

    string input;
    if(argc != 2) {
       cout << "Usage for " << argv[0] << ":" << endl;
       cout << argv[0] << " <InputFileName> " << endl;
       exit(0);
    }
    input = argv[1];
    
    getInput(input, searchString, searchPattern);

    
    
    int searchStringSize = searchString.at(0).length();
    int searchPatternSize = searchPattern.at(0).length();

    int searchPatternTestSize = searchPatternSize + 1;
    int searchStringTestSize = searchStringSize + 1;
    int tableSize = searchPatternTestSize + searchStringTestSize + 100;
    int table[tableSize];
    int n,i,k,j,m,flag=0;   //Setting up variables
    int index = -1;

    char searchPatternTest[searchPatternTestSize], searchStringTest[searchStringTestSize];  //turning strings into chars
    searchPattern.at(0).copy(searchPatternTest, searchPatternTestSize);
    searchPatternTest[searchPatternTestSize-1] = '\0';
    searchString.at(0).copy(searchStringTest, searchStringTestSize);
    searchStringTest[searchStringTestSize-1] = '\0';


    n=strlen(searchPatternTest);
    m=strlen(searchStringTest);
    


    
    start = clock();
    
    
    for(i=0;i<tableSize;i++)        //Generating table
        table[i]=m;
    for(j=0;j<=m-2;j++)
        table[(int)searchStringTest[j]]=m-1-j;
    i=m-1;  //position of the pattern's right end
    while(i<=n-1) {
        k=0;        //number of matched characters
        while(k<=m-1 && searchPatternTest[m-1-k] == searchStringTest[i-k])
            k++;
        if(k == m) {
            index = i-m+1; //returning the index if found
            flag=1;
            break;
        } else
            i=i+table[(int)searchPatternTest[i]];
    }

    if(!flag)
        index = -1; //setting index to -1

    end = clock();
    cout << "Execution time: " << (double(end - start) / double(CLOCKS_PER_SEC / 1000)) << " milliseconds"<< endl;

    printOutput(index);
    return 0;
}