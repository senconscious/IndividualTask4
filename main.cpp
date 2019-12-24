#pragma once
#include "STLMethods.h"


int main()
{
	string s;
	cout << "Enter string of even length" << endl;
	cin >> s;

	try
	{
		cout << "Source string:\n" << s << endl;
		s = swapFirstLast(s);
		cout << "String after swapping first and last element:\n" << s << endl;
		s = swapMiddleElements(s);
		cout << "String after swapping middle element:\n" << s << endl;

	}
	catch (invalid_argument e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown Error"<< endl;
	}


	vector<int> v;
	
	try 
	{
		cout << "Source vector:\n";
		for_each(v.begin(), v.end(), print<int>);
		cout << endl;

		insertFiveElementsMiddle(v);

		cout << "Vector after insertation 5 elements to the middle:\n";
		for_each(v.begin(), v.end(), print<int>);
		cout << endl;
	
	}
	catch (invalid_argument e)
	{
		cout << e.what() << endl;

	}
	catch (...)
	{
		cout << "Unknown Error" << endl;
	}



	system("pause");

}