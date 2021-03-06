#pragma once
#include <vector>
using namespace std;

//連立一次方程式を解くクラス
class EquationsSolver {
public:
	void GaussEliminationPivoting(vector<vector<double>>& a, double x[], int n);
	void GaussEliminationPivoting(vector<vector<double>>& a, double x[], int n,const int first, const int last);
	void LU();
};