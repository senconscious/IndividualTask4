#include "STLMethods.h"

string swapFirstLast(string o)
{
	if (o.length() < 4 || o.length() % 2 == 1)
	{
		throw invalid_argument("Invalid string format. String must be of even length greater that 4");
	}
	else
	{
		iter_swap(o.begin(), o.rbegin());
	}

	return o;
}

string swapMiddleElements(string o)
{
	if (o.length() < 4 || o.length() % 2 == 1)
	{
		throw invalid_argument("Invalid string format. String must be of even length greater that 4");
	}
	else
	{
		iter_swap(o.begin() + o.length() / 2 - 1, o.begin() + o.length() / 2);
	}

	return o;
}
