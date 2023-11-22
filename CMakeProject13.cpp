// CMakeProject13.cpp: определяет точку входа для приложения.
//

#include "CMakeProject13.h"
#include <math.h>

using namespace std;
int Jacobi(int N, double** A, double* b, double* X,double eps){
	double* temp = new double[N];
	double norm;
	int steps = -1;
	do{
		steps += 1;
		for (int i = 0; i < N; i++) {
			temp[i] = b[i];
			for (int j = 0; j < N; j++) {
				if (i != j)
					temp[i] -= A[i][j] * X[j];
			}
			temp[i] /= A[i][i];
		}
		norm = fabs(X[0] - temp[0]);
		for (int i = 0; i < N; i++) {
			if (fabs(X[i] - temp[i]) > norm)
				norm = fabs(X[i] - temp[i]);
			X[i] = temp[i];
		}
	} while (norm > eps);
	delete[] temp;
	return steps;
}

bool Convergence(int N, double** A) {
	system("chcp 65001");
	double sum1=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				sum1 += fabs(A[i][j]);
			}
		}
		if (fabs(A[i][i]) > sum1) {
			sum1 = 0;
			continue;
		}
		else {
			return false;
		}
		
	}
	return true;
}

int main()
{
	double eps;
	double* x, *b;
	double** A;
	int n;
	cin >> n >> eps;
	x = new double[n];
	b = new double[n];
	A = new double*[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		A[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	//if (!Convergence(n,A)) {
		//cout << "метод Якоби не сходится";
		//return 0;
	//}
	cout <<"steps:" << Jacobi(n, A, b, x, eps) << endl<<"x:"<<endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << endl;
	}
	return 0;
}
