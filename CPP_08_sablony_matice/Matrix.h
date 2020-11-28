#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <stdexcept>
#include <iostream>

template <typename T>
class Matrix {
public:
	Matrix(int rows, int columns);
	Matrix(const Matrix<T>& matrix);
	~Matrix();
	void Set(int row, int column, T value);
	void SetFromArray(T* array);
	T& Get(int row, int column);
	const T& Get(int row, int column) const;
	template<typename R> 
	Matrix<R>convert() const;
	Matrix<T> Transposition() const;
	Matrix<T> Multiplication(const Matrix<T>& m) const;
	Matrix<T> Multiplication(T scalar) const;
	Matrix<T> Sum(const Matrix<T>& m) const;
	Matrix<T> Sum(T scalar) const;
	void CoutMatrix() const;
	bool IsMatch(const Matrix& m) const;


private:
	T** matrix;
	int rows;
	int columns;
};
template <typename T>
Matrix<T>::Matrix(int rows, int columns) {
	this->rows = rows;
	this->columns = columns;
	matrix = new T* [this->rows]{0};
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new T[this->columns]{0};
	}
}
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix) {
	this->rows = matrix.rows;
	this->columns = matrix.columns;
	this->matrix = new T* [this->rows];
	for (int i = 0; i < rows; i++)
	{
		this->matrix[i] = new T[this->columns];
		for (int j = 0; j < this->columns; j++)
		{
			this->matrix[i][j] = matrix.matrix[i][j];
		}
	}

}
template <typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < rows; i++)
	{
		 delete[] matrix[i];
	}
	delete[] matrix;
}
template <typename T>
void Matrix<T>::Set(int row, int column, T value) {
	matrix[row][column] = value;
}
template <typename T>
void Matrix<T>::SetFromArray(T* array) {
	int row = 0;
	int column = 0;
	for (int i = 0; i < rows*columns; i++)
	{
		
		if (column == this->columns)
		{
			column = 0;
			row++;
		}
		matrix[row][column] = array[i];
		column++;
	}
}
template <typename T>
T& Matrix<T>::Get(int row, int column) {
	if (row >= rows || column >= columns)
		throw std::out_of_range("Index is out of range");
	return matrix[row][column];
}
template <typename T>
const T& Matrix<T>::Get(int row, int column) const {
	if (row >= rows || column >= columns)
		throw std::out_of_range("Index is out of range");
	return matrix[row][column];
}
template<typename T>
inline Matrix<T> Matrix<T>::Transposition() const
{
	Matrix<T> matrixT{ columns, rows };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrixT.Set(j, i, matrix[i][j]);
		}
	}

	return matrixT;
}
template<typename T>
inline Matrix<T> Matrix<T>::Multiplication(const Matrix<T>& m) const
{
	if (columns != m.rows)
		throw std::length_error("Number of columns in first matrix doesnt match number of rows in the second one.");
	Matrix<T> matrixM{ rows, m.columns };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < m.columns; j++)
		{
			for (int k = 0; k < columns; k++)
			{
				matrixM.Set(i, j, matrixM.matrix[i][j] + (matrix[i][k] * m.matrix[k][j]));
			}
		}
	}
	return matrixM;
	
}
template<typename T>
inline Matrix<T> Matrix<T>::Multiplication(T scalar) const
{
	Matrix<T> matrixM{ rows, columns };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrixM.Set(i,j,matrix[i][j] * scalar);
		}
	}
	return matrixM;
}
template<typename T>
inline Matrix<T> Matrix<T>::Sum(const Matrix<T>& m) const
{
	if (this->rows != m.rows || this->columns != m.columns)
		throw std::length_error("Columns or rows doesnt match");
	Matrix<T> matrixS{ rows, columns };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrixS.Set(i, j, matrix[i][j] + m.matrix[i][j]);
		}
	}
	return matrixS;
}
template<typename T>
inline Matrix<T> Matrix<T>::Sum(T scalar) const
{
	Matrix<T> matrixS{ rows, columns };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrixS.Set(i, j, matrix[i][j] + scalar);
		}
	}
	return matrixS;
}
template<typename T>
inline void Matrix<T>::CoutMatrix() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
template<typename T>
inline bool Matrix<T>::IsMatch(const Matrix& m) const
{
	if (this->rows != m.rows || this->columns != m.columns)
		return false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (this->matrix[i][j] != m.matrix[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
template<typename T>
template<typename R>
inline Matrix<R> Matrix<T>::convert() const
{
	Matrix<R> matrixR{ rows,columns };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrixR.Set(i, j, (R)this->matrix[i][j]);
		}
	}

	return matrixR;
}


#endif // MATRIX_H


