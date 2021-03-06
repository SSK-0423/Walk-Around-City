#pragma once
#include <vector>

using namespace std;

class CubicSpline {
	public:
		void cubicSpline(vector<vector<double>> points, int n);
		double interpolation(double p,bool inverse);//โิlฬvZ
	private:

		int N;//โิฝฎฬย
		vector<vector<double>> coord;//_ฬภW

		vector<double> v_array;//v_j
		vector<double> h_array;//h_j
		vector<vector<double>> A;

		vector<vector<double>> keisu; //keisu[n][4]
		void InitVector();	// vector๚ป
		void calc_v();//vฬvZ
		void calc_h();//hฬvZ
		void make_array(vector<double> h);//z๑์ฌ

		void calc_keisu(double u_array[]);//WฬvZ
		double calc_a(double u_array[],int i);//Wa_jฬvZ
		double calc_b(double u_array[],int i);//Wb_jฬvZ
		double calc_c(double u_array[],int i);//Wc_jฬvZ
		double calc_d(int i);//Wd_jฬvZ
};