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

vector<vector<double>> ReadMatrix(string file)
{
	vector<vector<double>> v;
	ifstream ifs(file);
	string tempstr;
	string temp;

	while (getline(ifs, tempstr))
	{
		istringstream iss(tempstr);
		vector<double> tempv;
		while (iss >> temp) 
		{
			tempv.push_back(stod(temp));
		}
		v.push_back(tempv);
	}

	return v;
}

int matrixRank(vector<vector<double>> A)
{
	int n = A.size();
	int m = A[0].size();

	int rank = 0;
	vector<bool> row_selected(n, false);
	for (int i = 0; i < m; ++i) {
		int j;
		for (j = 0; j < n; ++j) {
			if (!row_selected[j] && abs(A[j][i]) > DBL_EPSILON)
				break;
		}

		if (j != n) {
			++rank;
			row_selected[j] = true;
			for (int p = i + 1; p < m; ++p)
				A[j][p] /= A[j][i];
			for (int k = 0; k < n; ++k) {
				if (k != j && abs(A[k][i]) > DBL_EPSILON) {
					for (int p = i + 1; p < m; ++p)
						A[k][p] -= A[j][p] * A[k][i];
				}
			}
		}
	}
	return rank;
}

bool hasOnlySolution(vector<vector<double>> A)
{
	return matrixRank(A) == A[0].size();
}

vector<double> solve(vector<vector<double>> A)
{
	vector<double> solution;

	for (int i = 0; i < A.size(); i++)
	{
		double _row = i;

		for (int j = i; j < A.size(); j++)
			if (A[j][i] > A[_row][i])
				_row = j;

		if (i != _row)
			iter_swap(A.begin() + i, A.begin() + _row);

		//normalizeAt(A, i);
		for (int j = i; j < A.size(); j++)
		{
			double _temp = A[j][i];
			transform(A[j].begin(), A[j].end(), A[j].begin(), [&_temp](double& c) {return c / _temp; });
		}

	/*	printM(A);
		cout << endl << endl;*/

		for (int j = 0; j < A.size(); j++)
		{
			if (i != j)
				transform(A[j].begin(), A[j].end(), A[i].begin(), A[j].begin(), minus<double>());
				//Minus(A.begin() + j; A.begin() + i);
		}

		/*printM(A);
		cout << endl << endl;*/

	}


	/*for (int i = 0; i < A.size(); i++)
		solution.push_back(A[i][A[i].size()-1]);*/

	for (int i = A.size() - 1; i >= 0; i--)
	{
		solution.push_back(A[i][A[i].size() - 1]);

		/*for (int j = 0; j < i; j++)
			A[j][A.size() - 1] -= A[j][i] * solution[A.size() - 1 - i];*/

		for (int j = A[i].size() - 2; j > i; j--)
		{
			solution[j-i] -= A[i][j] * solution[j-i-1];
		}

	}

	reverse(solution.begin(), solution.end());

	return solution;
}
