#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Data/triplet.h"
#include "Math/MathFunctions.h"
#include "Math/RandomFunctions.h"


namespace O{
namespace vector {
	template<typename T>
	void pushBack(std::vector<T>& source, std::vector<T> data);

	template<typename T, typename J>
	void initVector(std::vector<T>& source, int size, T value, J increment);
	template<typename T, typename J>
	std::vector<T> createVector(int size, T value, J increment);

	template<typename T>
	void initVector(std::vector<T>& source, int size, T value);
	template<typename T>
	std::vector<T> createVector(int size, T value);

	std::vector<int> createRandomVector(int size, int min, int max);
	std::vector<float> createRandomVector(int size, float min, float max);
	std::vector<double> createRandomVector(int size, double min, double max);
	template<typename T>
	std::vector<T> createRandomVector(int size, std::vector<T> possibilite);

	template<typename T>
	std::vector<T> copyVectorWithout(const std::vector<T>& vector, int indexWithout );
	template<typename T>
	std::vector<T> copyVectorWithAddedValue(std::vector<T> vector, T value);

	std::vector<std::vector<int>> createRandom2DVector(int sizeX, int sizeY, int min, int max);
	std::vector<std::vector<float>>  createRandom2DVector(int sizeX, int sizeY, float min, float max);
	std::vector<std::vector<double>>  createRandom2DVector(int sizeX, int sizeY, double min, double max);
	template<typename T>
	std::vector<std::vector<T>>  createRandom2DVector(int sizeX, int sizeY, std::vector<T> possibilite);

	template<typename T>
	T average(std::vector<T> v);

	void initRandomVector(std::vector<int>& source, int size, int min, int max);
	void initRandomVector(std::vector<float>& source, int size, float min, float max);
	void initRandomVector(std::vector<double>& source, int size, double min, double max);
	template<typename T>
	void initRandomVector(std::vector<T>& source, int size, std::vector<T> possibilite);

	template<typename T, typename J>
	void init2DVector(std::vector< std::vector<T> >& source, int size, T value, J increment);
	template<typename T, typename J>
	std::vector < std::vector<T>> create2DVector(int size, T value, J increment);


	template<typename T, typename J>
	std::vector < std::vector<T>> create2DVector(int size, T value, J increment, T without);
	template<typename T, typename J>
	std::vector < std::vector<T>> create2DVector(int size, T value, J increment, std::vector<T> without);

	template<typename T>
	void init2DVector(std::vector<std::vector<T>>& source, int size, T value);
	template<typename T>
	std::vector < std::vector<T>> create2DVector(int size, T value);

	template<typename T, typename J>
	void init2DVector(std::vector< std::vector<T> >& source, int sizeX, int sizeY, T value, J increment);
	template<typename T, typename J>
	std::vector < std::vector<T>> create2DVector(int sizeX, int sizeY, T value, J increment);

	template<typename T, typename J>
	std::vector < std::vector<T>> create2DVector(int sizeX, int sizeY, T value, J increment, T without);
	template<typename T, typename J>
	std::vector < std::vector<T>> create2DVector(int sizeX, int sizeY, T value, J increment, std::vector<T> without);

	template<typename T>
	void init2DVector(std::vector<std::vector<T>>& source, int sizeX, int sizeY, T value);
	template<typename T>
	std::vector < std::vector<T>> create2DVector(int sizeX, int sizeY, T value);

	template<typename T>
	std::vector<T> subVector(std::vector<T> source, int start, int length);

	template<typename T>
	std::pair<std::vector<T>, std::vector<T>> split(std::vector<T> source, int indexStartSecondVector);
	template<typename T>
	std::pair<std::vector<T>, std::vector<T>> splitRatio(std::vector<T> source, double pourcentageFirst);

	template<typename T>
	void removeRow(std::vector< std::vector<T> >* source, int index);
	template<typename T>
	void removeCol(std::vector< std::vector<T> >* source, int index);
	template<typename T>
	// ALERT ! LES ELEMENTS DE INDEX DOIVENT ETES ORDONES !
	void removeCol(std::vector< std::vector<T> >* source, std::vector<int> index);
	template<typename T>

	std::vector< std::vector<T> > removeRow(std::vector< std::vector<T> > source, int index);
	template<typename T>
	std::vector< std::vector<T> > removeCol(std::vector< std::vector<T> > source, int index);
	template<typename T>
	std::vector< std::vector<T> > removeCol(std::vector< std::vector<T> > source, std::vector<int> index);

	template<typename T>
	void addRow(std::vector< std::vector<T> >* source, std::vector<T> row, int index);
	template<typename T>
	void addCol(std::vector< std::vector<T> >* source, std::vector<T> col, int index);
	template<typename T>
	std::vector< std::vector<T> > addRow(std::vector< std::vector<T> > source, std::vector<T> row, int index);
	template<typename T>
	std::vector< std::vector<T> > addCol(std::vector< std::vector<T> > source, std::vector<T> col, int index);

	template<typename T>
	std::vector<T> getCol(std::vector< std::vector<T> >& source, int index);
	template<typename T>
	void setCol(std::vector< std::vector<T> >* source, std::vector<T> col, int index);
	template<typename T>
	void setCol(std::vector< std::vector<T> >& source, std::vector<T> col, int index);

	template<typename T>
	std::vector<bool> equality(std::vector<T> source, std::vector<T> valeurs);
	template<typename T>
	std::vector<bool> equality(std::vector<T> source, T valeur);

	template<typename T>
	bool allAreEquals(std::vector<T> source, T valeur);
	template<typename T>
	bool allAreEquals(std::vector<T> source, std::vector<T> valeurs);

	template<typename T>
	void sort(std::vector<T>* vector);
	template<typename T>
	std::vector<T> sort(std::vector<T> vector);

	template<typename T>
	bool isSorted(std::vector<T>& vector, bool croissent = true);

	template<typename T>
	int insertInSortedVector(std::vector<T>& vector, T value);
	template<typename T>
	void insertInSortedVector(std::vector<T>& vector, std::vector<T> values);
	template<typename T>
	int findInSortedVector(std::vector<T>& vector, T value);
	template<typename T>
	bool removeInSortedVector(std::vector<T>& vector, T value);
	template<typename T>
	void removeInSortedVector(std::vector<T>& vector, int index);
	template<typename T>
	bool removeInSortedVectorByElement(std::vector<T>& vector, T value);
	template<typename T>
	void removeInSortedVectorByIndex(std::vector<T>& vector, int index);

	template<typename T>
	bool remove(std::vector<T>& vector, T value);
	template<typename T>
	void remove(std::vector<T>& vector, int index);

	template<typename T>
	int find(std::vector<T>* vector, T data);
	template<typename T>
	int find(std::vector<T>& vector, T data);
	template<typename T>
	std::pair<int, int> find(std::vector < std::vector<T> >& vector, T data);
	template<typename T>
	O::data::triplet<int, int, int> find(std::vector<std::vector < std::vector<T> >>& vector, T data);

	template<typename T>
	bool contains(std::vector<T>& vector, T data);
	template<typename T>
	bool contains(std::vector<T>* vector, T data);

	
	template<typename T, typename J>
	T max(std::pair<T, J> data);
	template<typename T>
	T max(std::vector<T> source);
	template<typename T>
	T max(std::vector< std::vector<T> > source);
	template<typename T>
	std::pair<size_t,size_t> maxIndex(std::vector< std::vector<T> > source);
	template<typename T>
	size_t maxIndex(std::vector< T > source);

	template<typename T, typename J>
	T min(std::pair<T, J> data);
	template<typename T>
	T min(std::vector<T> source);
	template<typename T>
	int minIndex(std::vector<T> source);
	template<typename T>
	T min(std::vector< std::vector<T> > source);

	std::vector<int> toInt(std::vector<std::string>vector);
	std::vector<double> toDouble(std::vector<std::string>vector);
	std::vector<long double> toLongDouble(std::vector<std::string>vector);
	std::vector<float> toFloat(std::vector<std::string>vector);
	std::vector< std::vector<int> > toInt(std::vector< std::vector<std::string> >vector);
	std::vector< std::vector<double> > toDouble(std::vector<std::vector<std::string> >vector);
	std::vector< std::vector<long double> > toLongDouble(std::vector<std::vector<std::string> >vector);
	std::vector< std::vector<float> > toFloat(std::vector<std::vector<std::string> >vector);

	template<typename T>
	std::vector<double> toDouble(std::vector<T>vector);
	template<typename T>
	std::vector< std::vector<double> > toDouble(std::vector<std::vector<T> >vector);
	template<typename T>
	std::vector<long double> toLongDouble(std::vector<T>vector);
	template<typename T>
	std::vector< std::vector< long double> > toLongDouble(std::vector<std::vector<T> >vector);
	template<typename T>
	std::vector<int> toInt(std::vector<T>vector);
	template<typename T>
	std::vector< std::vector<int> > toInt(std::vector<std::vector<T> >vector);
	template<typename T>
	std::vector<float> toFloat(std::vector<T>vector);
	template<typename T>
	std::vector< std::vector<float> > toFloat(std::vector<std::vector<T> >vector);

	template<typename T>
	void remplace(std::vector<T>* vector, T lastValue, T newValue);
	template<typename T>
	std::vector<T> remplace(std::vector<T> vector, T lastValue, T newValue);
	template<typename T>
	void remplace(std::vector<T>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue);
	template<typename T>
	std::vector<T> remplace(std::vector<T> vector, std::vector<T> allLastValue, std::vector<T> allNewValue);

	template<typename T>
	void remplace(std::vector<std::vector<T>>* vector, T lastValue, T newValue);
	template<typename T>
	std::vector<T> remplace(std::vector<std::vector<T>> vector, T lastValue, T newValue);
	template<typename T>
	void remplace(std::vector<std::vector<T>>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue);
	template<typename T>
	std::vector<T> remplace(std::vector<std::vector<T>> vector, std::vector<T> allLastValue, std::vector<T> allNewValue);

	template<typename T>
	void remplaceInRow(std::vector<std::vector<T>>* vector, T lastValue, T newValue, int row);
	template<typename T>
	std::vector<std::vector<T>> remplaceInRow(std::vector<std::vector<T>> vector, T lastValue, T newValue, int row);
	template<typename T>
	void remplaceInRow(std::vector<std::vector<T>>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue, int row);
	template<typename T>
	std::vector<std::vector<T>> remplaceInRow(std::vector<std::vector<T>> vector, std::vector<T> allLastValue, std::vector<T> allNewValue, int row);
	template<typename T>
	void remplaceInRow(std::vector<std::vector<T>>* vector, T lastValue, T newValue, std::vector<int> row);
	template<typename T>
	std::vector<std::vector<T>> remplaceInRow(std::vector<std::vector<T>> vector, T lastValue, T newValue, std::vector<int> row);
	template<typename T>
	void remplaceInRow(std::vector<std::vector<T>>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue, std::vector<int> row);
	template<typename T>
	std::vector<std::vector<T>> remplaceInRow(std::vector<std::vector<T>> vector, std::vector<T> allLastValue, std::vector<T> allNewValue, std::vector<int> row);

	template<typename T>
	void remplaceInCol(std::vector<std::vector<T>>* vector, T lastValue, T newValue, int col);
	template<typename T>
	std::vector<std::vector<T>> remplaceInCol(std::vector<std::vector<T>> vector, T lastValue, T newValue, int col);
	template<typename T>
	void remplaceInCol(std::vector<std::vector<T>>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue, int col);
	template<typename T>
	std::vector<std::vector<T>> remplaceInCol(std::vector<std::vector<T>> vector, std::vector<T> allLastValue, std::vector<T> allNewValue, int col);
	template<typename T>
	void remplaceInCol(std::vector<std::vector<T>>* vector, T lastValue, T newValue, std::vector<int> col);
	template<typename T>
	std::vector<std::vector<T>> remplaceInCol(std::vector<std::vector<T>> vector, T lastValue, T newValue, std::vector<int> col);
	template<typename T>
	void remplaceInCol(std::vector<std::vector<T>>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue, std::vector<int> col);
	template<typename T>
	std::vector<std::vector<T>> remplaceInCol(std::vector<std::vector<T>> vector, std::vector<T> allLastValue, std::vector<T> allNewValue, std::vector<int> col);

	std::vector < std::vector<long double>> normalize(std::vector < std::vector<long double>> vector, long double min, long double max);
	void normalize(std::vector<long double>* vector, long double min, long double max);
	std::vector< std::vector<double>>normalize(std::vector<std::vector<double>> vector, double min, double max);
	void normalize(std::vector<std::vector<double>>* vector, double min, double max);
	std::vector< std::vector<float>> normalize(std::vector<std::vector<float>> vector, double min, double max);
	void normalize(std::vector<std::vector<float>>* vector, double min, double max);

	std::vector < std::vector<long double>> normalize(std::vector < std::vector<long double>> vector, long double min, long double max);
	void normalize(std::vector <std::vector<long double>>* vector, long double min, long double max);

	std::vector<double> normalize(std::vector<double> vector, double min, double max);
	void normalize(std::vector<double>* vector, double min, double max);
	std::vector<float>  normalize(std::vector<float> vector, double min, double max);
	void normalize(std::vector<float>* vector, double min, double max);

	template<typename T>
	std::vector<T> reverse(std::vector<T> vector);
	template<typename T>
	void reverse(std::vector<T>* vector);

	template<typename T>
	std::vector<T> swap(std::vector<T> vector, int i, int j);
	template<typename T>
	void swap(std::vector<T>* vector, int i, int j);


	template<typename T>
	std::vector<T> shuffle(std::vector<T> vector);
	template<typename T>
	void shuffle(std::vector<T>* vector);

	template<typename T>
	T getSum(std::vector<T> vector);
	template<typename T,typename J>
	void add(std::vector<T>& vector, J value);
	template<typename T,typename J,typename I>
	void add(std::vector<T>& vector, J value, I modulo);
	template<typename T>
	std::vector<T> add(const std::vector<T>& a, const std::vector<T>& b);

	template<typename T, typename T_, typename R, typename R_>
	std::vector<R> applyFunction(const std::vector<T>& vec, R_ (*function)(T_));

	template<typename T,typename T_, typename U,typename U_, typename R, typename R_>
	std::vector<R> applyFunction(const std::vector<T>& vec, R_ (*function)(T_, U_), U arg);

	template<typename T,typename T_, typename U,typename U_, typename V,typename V_, typename R,typename R_>
	std::vector<R> applyFunction(const std::vector<T>& vec, R_ (*function)(T_, U_, V_), U arg, V arg2);

} 
}

#include "VectorFunction.ipp"