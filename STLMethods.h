#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>



//Swaps first and Last elements in the string and returns it. String must be of event length
string swapFirstLast(string o);

//Swaps middle elements in the string and returns it. String must be of even length
string swapMiddleElements(string o);

//Inserts Five Default Value Elements in middle of the Vector. Vector must be of even length
template<typename T>
void insertFiveElementsMiddle(vector<T>& o);

//Lambda Function to cout elements
template<typename T>
auto print = [](const T& o) {cout << " " << o; };

//Read Matrixes from file
vector<vector<double>> ReadMatrix(string file);


//Prints Matrix
template<typename T>
void printM(vector<vector<T>> o);

//Returns rank of matrix
int matrixRank(vector<vector<double>> A);

// Returns if a system has the only solution
bool hasOnlySolution(vector<vector<double>> A);

// Returns solution of system
vector<double> solve(vector<vector<double>> A);




template<typename T>
void insertFiveElementsMiddle(vector<T>& o)
{
	if (o.size() % 2 == 1)
	{
		throw invalid_argument("Invalid vector size. Must be even");
	}
	else
	{
		o.insert(o.begin() + o.size() % 2, 5, T());
	}
}

template<typename T>
void printM(vector<vector<T>> o)
{
	for (auto _temp : o)
	{
		for_each(_temp.begin(), _temp.end(), print<T>);
		cout << endl;
	}

}
