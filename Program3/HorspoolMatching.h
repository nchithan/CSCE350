#ifndef HORSPOOLMATCHING_H_
#define HORSPOOLMATCHING_H_

#include <vector>
#include <string>

using std::string;
using std::vector;

void getInput(string file_name, vector<float> *input);
void horspoolMatching(vector<float> *list, int left, int right);
void print(vector<float> output, string file_name);
void output(vector<float> output);

#endif