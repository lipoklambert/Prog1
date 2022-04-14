#include "Matrix.h"
#include "MatrixIO.h"
#include <iostream>
#include <cmath>
#include <cerrno>
#include <complex>
#include <iomanip>

using namespace std;   //std névtérben való használata
using namespace Numeric_lib;

int main(){
try{
	cout << "sizeof:\n";
	cout << "char\t" << sizeof(char) << endl;
	cout << "short\t" << sizeof(short) << endl;
	cout << "int\t" << sizeof(int) << endl;
	cout << "long\t" << sizeof(long) << endl;
	cout << "float\t" << sizeof(float) << endl;
	cout << "double\t" << sizeof(double) << endl;
	cout << "int*\t" << sizeof(int*) << endl;
	cout << "double*\t" << sizeof(double*) << endl;
	
	cout << "\nMatrix sizes:\n";
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);
	
	cout << "1D int, 10 elem\t\t" << sizeof(a) << endl;
	cout << "1D int, 100 elem\t" << sizeof(b) << endl;
	cout << "1D double, 10 elem\t" << sizeof(c) << endl;
	cout << "2D int, 10*10 elem\t" << sizeof(d) << endl;
	cout << "3D int, 10*10*10 elem\t" << sizeof(e) << endl;
		
	cout << "\nNumber of elements:\n";
	cout << "a:\t" << a.size() << endl;
	cout << "b:\t" << b.size() << endl;
	cout << "c:\t" << c.size() << endl;
	cout << "d:\t" << d.size() << endl;
	cout << "e:\t" << e.size() << endl;
	
	cout << "\nEnter an integer (outputs the sqrt() of it), if input is null, then exit:\n";
	int value;
	cin >> value;
	while(value != 0){
		if(value < 0){
			cout << "Enter a positive number!" << endl;
			cout << "Enter another integer (outputs the sqrt() of it), if input is null, then exit:\n";
			cin >> value;
		}
		else{
			cout << "Squareroot of " << value << " is: " << sqrt(value) << endl;
			cout << "Enter another integer (outputs the sqrt() of it), if input is null, then exit:\n";
			cin >> value;
		}
	}
	
	cin.clear(); //A cin.clear() törli a hibajelzőt (error flag) a cin-n (hogy a jövőbeni I/O műveletek megfelelően működjenek)
	cin.ignore(); //karakterek figyelmen kívül hagyására/törlésére szolgál a beviteli pufferből.
	
	cout << "\nEnter 10 floats:\n";
	Matrix<double> m(10);
	double d2;
	for(int i = 0; i < m.size(); ++i){
		cin >> d2;
		if(!cin) throw runtime_error("Problem reading from cin");
		m[i] = d2;
	}
	cout << "Matrix:\n" << m << '\n';
	
	int m2;
	int n;
	cout << "Multiplication table" << endl; 
	cout << "Enter n:";
	cin >> n;
	cout << "Enter m:";
	cin >> m2;
	
	Matrix<int, 2> mtable(n, m2);
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m2; ++j){
			mtable(i, j) = (i+1)*(j+1);
			cout << '\t' <<mtable(i, j);
		}
		cout << '\n';
	}
	/*Az std::complex<double> specializáció literáltípus komplex számok ábrázolására és kezelésére.*/
	Matrix<complex<double>> mcomp(10);
	cout << "\nEnter 10 complex numbers (re, im): ";
	complex<double> comp;
	for(int i = 0; i < 10; ++i){
		cin >> comp;
		if(!cin) throw runtime_error("Problem reading complex numbers");
		mcomp[i] = comp;
	}
	
	complex<double> sum;
	//Matrixnal most a long az az Index
	for(Index i = 0; i < mcomp.size(); ++i){
		sum += mcomp[i]; 
	}
	cout << "sum: " << sum << '\n';
	
	Matrix<int,2> m3(2,3);
	int in_int;
	cout << '\n';
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			cout << "Enter the (" << i+1 << ", " << j+1 << ") element of the 2*3 matrix: ";
			cin >> in_int;
			m3(i, j) = in_int;
		}
	}
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			cout << '\t' <<m3(i, j);
		}
		cout << '\n';
	}
}
catch(exception& e){
	cerr << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "Unknown exception!" << '\n';
	return 2;
}
}
