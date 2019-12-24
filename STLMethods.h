#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <vector>


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
