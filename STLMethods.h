#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <vector>



string swapFirstLast(string o);

string swapMiddleElements(string o);

template<typename T>
void insertFiveElementsMiddle(vector<T>& o);

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
