#pragma once
#include "Matrix.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>

int main() {
	Matrix<int> m{ 3,3 };
	int array[] = { 0,1,2,3,4,5,6,7,8 };
	int size = (sizeof(array) / sizeof(*array));
	m.SetFromArray(array);

	Matrix<int> mt = m.Transposition();
	//m.CoutMatrix();
	//mt.CoutMatrix();
	Matrix<int> mmt = m.Multiplication(mt);
	//Matrix<int> mmt = m.Sum(mt);
	//Matrix<int> mmt = m.Sum(1);
	//Matrix<int> mmt = m.Multiplication(2);
	mmt.CoutMatrix();
	Matrix<double> mmt_d = mmt.convert<double>();
	Matrix<double> n_d{ 3,3 };
	double jednodpole_d[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.SetFromArray(jednodpole_d);
	Matrix<double> mmtn_d = mmt_d.Multiplication(n_d);
	Matrix<int> r = mmtn_d.convert<int>();
	Matrix<int> t{ 3,3 };
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.SetFromArray(tpole);
	std::cout << "r==t ? " << (r.IsMatch(t) ? "true" : "false") << std::endl;



	//std::cout << "Hello" << std::endl;
	//Memory LEAK Check start
	//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	//_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	//_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	//_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	//_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	//_CrtDumpMemoryLeaks();
	//Memory Leak Check end
	return 0;
}
