#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

//This is infinity
#define INF 99999



void printOutput(float **fDistance, int r, int c){
    const string filename = "output.txt";
    ofstream file(filename);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            file << fDistance[i][j] << ' ';
        }
        file << endl;
    }
    
    file.close();
}

int main(int argc, char** argv){
    int colSize =0;
    int rowSize =0;
    float** array;


    string input;
    if(argc != 2) {
       cout << "Usage for " << argv[0] << ":" << endl;
       cout << argv[0] << " <InputFileName> " << endl;
       exit(0);
    }
    input = argv[1];
    //Getting the input array and putting it into an 2d vector
    ifstream file(input);
    int i=0, j=0, n=0;
    string line;
    vector<vector<float>> a;

    for(;;)
    {
        getline(file, line);
        if (! file) break; // test eof after read
        a.push_back(vector<float>());
        std::istringstream fline(line);
        j = 0;
        for(;;) {
            float val;
            fline >> val;
            if (!fline) break;
            a[i].push_back(val);
            j++;
        }
        i++;
        if (n == 0) n = j;
        else if (n != j) {
            std::cerr << "Error line " << i << " - " << j << " values instead of " << n << endl;
        }
    }
    if (i != n) {
        std::cerr << "Error " << i << " lines instead of " << n << endl;
    }

    file.close();
    rowSize = a.size();
    colSize = a.size();
    
    array = new float*[rowSize];
    for(i=0; i<rowSize; i++){
        array[i] = new float[colSize];
    }

    //Copying the 2d vector into a regular 2d array
    for (long unsigned int i = 0; i < a.size(); i++)
    {
        for (long unsigned int j = 0; j < a.size(); j++)
        {
            array[i][j] = a[i][j];
            if(a[i][j] > 100){
                array[i][j] = INF;
            }
        }  
    }
    //This was used for testing for bugs
    // for (int i = 0; i < rowSize; i++)
    // {
    //     for (int j = 0; j < colSize; j++)
    //     {
    //         cout << array[i][j] << " ";
    //     }   
    //     cout << endl;
    // }

    int x,y,z;

    for (z = 0; z < rowSize; z++) {
        // Pick all vertices as source one by one
        for (x = 0; x < rowSize; x++) {
            // Pick all vertices as destination for the
            // above picked source
            for (y = 0; y < rowSize; y++) {
                // If vertex z is on the shortest path from
                // x to y, then update the value of
                // array[x][y]
                if (array[x][y] > (array[x][z] + array[z][y])
                    && (array[z][y] != INF
                        && array[x][z] != INF))
                    array[x][y] = array[x][z] + array[z][y];
            }
        }
    }



    printOutput(array, rowSize, colSize);
    return 0;
}