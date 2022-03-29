#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
//using namespace std;

using std::clock;
using std::clock_t;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;



void getInput(string filename, vector<int> *list){
    //const char delimiter = ' ';
    ifstream file(filename);
    string line;
    int counter = 0;
    while(getline(file, line)){
        std::stringstream ss(line);
        while(getline(ss, line, ' ')){
            if(counter > 0){
                //cout << line << endl;
                (*list).push_back(std::stoi(line));
                counter++;
            }
            counter++;
        }
    }
    file.close();

}

// void heapSort(vector<int> *list, vector<int> *list2){
//     int n = (int) (*list).size();
//     n = n-1;
//     for(int i = n, j =0; i > 0; i--, j++){
//         swep((*&list), i);
//         (*list2).push_back((*list).at(i));
//         (*list).pop_back();
//         heapify(*&list,i);
//     }
// }

// void swep(vector<int> *list, int index2){
//     std::iter_swap((*list).begin(), (*list).begin()+ index2);
//  }

void heapify(vector<int> *list, int n){
    //cout << "size n: " << n << endl;
    for(int i = n/2; i >= 0; i=i-1){
        int k = i;
        //cout << "Outside i: " << i << endl;
        int v = (*list).at(k);
        //cout << "Outside v: " << v << endl;
        bool heap = false;
        while(!heap && 2*k <= n){
            int j = 2*k;
            //cout << "Inside j: " << j << endl;
            //cout << "Inside i: " << i << endl;
            if(j < n){
                //cout << "Inside First if: " << j << endl;
                if((*list).at(j) < (*list).at(j+1)){
                    j = j+1;
                    //cout << "Inside Nested if: " << j << endl;
                }
            }
            if(v >= (*list).at(j)){
                //cout << "Inside Second if: " << j << endl;
                heap = true;
            } else {
                (*list).at(k) = (*list).at(j);
                k = j;
                //cout << "Inside Else : " << k << endl;
            }
        }
        (*list).at(k) = v;
    }
}

void printOutput(vector<int> *list, vector<int> *list2){
    const string filename = "output.txt";
    ofstream file(filename);
    for(unsigned i = 0; i<(*list).size(); i++){ 
        file << (*list).at(i) << " ";
    }
    cout << endl;
    for(unsigned i = 0; i<(*list2).size(); i++){ 
        file << (*list2).at(i) << " ";
    }
    file.close();
}

int main(int argc, char** argv){
    struct timeval start, end;
    long mtime, secs, usecs;    

    
    vector<int> list;
    vector<int> list2;
    string input;
    if(argc != 2) {
       cout << "Usage for " << argv[0] << ":" << endl;
       cout << argv[0] << " <InputFileName> " << endl;
       exit(0);
    }
    input = argv[1];
    
    getInput(input, &list);
    
    //cout << "size: " << list.size() << endl;
    int n = (int) list.size();
    n = n-1;
    gettimeofday(&start, NULL);
    heapify(&list, n);
    gettimeofday(&end, NULL);
    secs  = end.tv_sec  - start.tv_sec;
    usecs = end.tv_usec - start.tv_usec;
    mtime = ((secs) * 1000 + usecs/1000.0) + 0.5;
    cout << "Execution time: " << mtime << " milliseconds"<< endl;
    //heapSort(&list, &list2);
    printOutput(&list, &list2);
    return 0;
}