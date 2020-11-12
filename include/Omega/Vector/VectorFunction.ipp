#include "Vector/VectorFunctions.h"
namespace O{
namespace vector {

	template<typename T>
	void pushBack(std::vector<T>& source, std::vector<T> data)
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			source.push_back(data[i]);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T, typename J>
	void initVector(std::vector<T>& source, int size, T value, J increment)
	{
		source.clear();
		for (int i = 0; i < size; i++)
		{
			source.push_back(value);
			value += increment;
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T, typename J>
	std::vector<T> createVector(int size, T value, J increment)
	{
		std::vector<T> newVector;
		for (int i = 0; i < size; i++)
		{
			newVector.push_back(value);
			value += increment;
		}
		return newVector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void initVector(std::vector<T>& source, int size, T value)
	{
		source.clear();
		for (int i = 0; i < size; i++)
		{
			source.push_back(value);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<T> createVector(int size, T value)
	{
		std::vector<T> newVector;
		for (int i = 0; i < size; i++)
		{
			newVector.push_back(value);
		}
		return newVector;
	}
	/////////////////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<T> copyVectorWithout(const std::vector<T>& vector, int indexWithout )
	{
		std::vector<T> res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			if (i != indexWithout)
				res.push_back(vector[i]);
		}
		return res;
	}
	////////////////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<T> copyVectorWithAddedValue(std::vector<T> vector, T value)
	{
		vector.push_back(value);
		return vector;
	}
	////////////////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<T> createRandomVector(int size, std::vector<T> possibilite)
	{
		std::vector<T> vec;
		for (int i = 0; i < size; i++)
		{
			vec.push_back(possibilite[math::rdm::randInt(0, possibilite.size())]);
		}
		return vec;
	}
	template<typename T>
	std::vector<std::vector<T>> createRandom2DVector(int sizeX, int sizeY, std::vector<T> possibilite)
	{
		std::vector<std::vector<T>> vec;
		for (int i = 0; i < sizeX; i++)
		{
			vec.push_back(createRandomVector(sizeY, possibilite));
		}
		return vec;
	}
	template<typename T>
	T average(std::vector<T> v)
	{
		T moyenne = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			moyenne += v;
		}
		return v / (double)(v.size());
	}
	template<typename T>
	void initRandomVector(std::vector<T>& source, int size, std::vector<T> possibilite)
	{
		source.clear();
		for (int i = 0; i < size; i++)
		{
			source.push_back( possibilite[ math::rdm::randInt( 0, possibilite.size() ) ] );
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T, typename J>
	void init2DVector(std::vector<std::vector<T>>& source, int size, T value, J increment)
	{
		source.clear();
		for (double i = 0; i < std::sqrt(size); i++)
		{
			std::vector<T> v;
			for (double j = 0; j < std::sqrt(size); j++)
			{
				v.push_back(value);
				value += increment;	
			}
			source.push_back(v);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T, typename J>
	std::vector<std::vector<T>> create2DVector(int size, T value, J increment)
	{
		std::vector<T> newVector;
		for (double i = 0; i < std::sqrt(size); i++)
		{
			std::vector<T> v;
			for (double j = 0; j < std::sqrt(size); j++)
			{
				v.push_back(value);
				value += increment;
			}
			newVector.push_back(v);
		}
		return newVector;
	}
	template<typename T, typename J>
	std::vector<std::vector<T>> create2DVector(int size, T value, J increment, T without)
	{
		std::vector<std::vector<T>> newVector;
		for (size_t i = 0; i < std::sqrt(size); i++)
		{
			std::vector<T> v;
			for (size_t j = 0; j < std::sqrt(size); j++)
			{
				v.push_back(value);
				do {
					value += increment;
				} while (without == value);
			}
			newVector.push_back(v);
		}
		return newVector;
	}
	template<typename T, typename J>
	std::vector<std::vector<T>> create2DVector(int size, T value, J increment, std::vector<T> without)
	{
		std::vector<std::vector<T>> newVector;
		for (size_t i = 0; i < std::sqrt(size); i++)
		{
			std::vector<T> v;
			for (size_t j = 0; j < std::sqrt(size); j++)
			{
				v.push_back(value);
				do {
					value += increment;
				} while (vector::contains(without, value));
			}
			newVector.push_back(v);
		}
		return newVector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void init2DVector(std::vector<std::vector<T>>& source, int size, T value)
	{
		source.clear();
		for (size_t i = 0; i < size; i++)
		{
			std::vector<T> v;
			for (size_t j = 0; j < size; j++)
			{
				v.push_back(value);
			}
			source.push_back(v);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<std::vector<T>> create2DVector(int size, T value)
	{
		std::vector<std::vector<T>> newVector;
		for (size_t i = 0; i < size; i++)
		{
			std::vector<T> v;
			for (size_t j = 0; j < size; j++)
			{
				v.push_back(value);
			}
			newVector.push_back(v);
		}
		return newVector;
	}

	///////////////////////////////////////////////////////////////
	template<typename T, typename J>
	void init2DVector(std::vector<std::vector<T>>& source, int sizeX, int sizeY, T value, J increment)
	{
		source.clear();
		for (size_t i = 0; i < sizeX; i++)
		{
			std::vector<T> v;
			for (size_t j = 0; j < sizeY; j++)
			{
				v.push_back(value);
				value += increment;
			}
			source.push_back(v);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T, typename J>
	std::vector<std::vector<T>> create2DVector(int sizeX, int sizeY, T value, J increment)
	{
		std::vector<std::vector<T>>newVector;
		for (size_t i = 0; i < sizeX; i++)
		{
			std::vector<T> v;
			for (size_t j = 0; j < sizeY; j++)
			{
				v.push_back(value);
				value += increment;
			}
			newVector.push_back(v);
		}
		return newVector;
	}
	template<typename T, typename J>
	std::vector<std::vector<T>> create2DVector(int sizeX, int sizeY, T value, J increment, T without)
	{
		std::vector<std::vector<T>> newVector;
		for (size_t i = 0; i < sizeX; i++)
		{
			std::vector<T> v;
			for (size_t j = 0; j < sizeY; j++)
			{
				v.push_back(value);

				do {
					value += increment;
				} while (without == value);
			}
			newVector.push_back(v);
		}
		return newVector;
	}
	template<typename T, typename J>
	std::vector<std::vector<T>> create2DVector(int sizeX, int sizeY, T value, J increment, std::vector<T> without)
	{
		std::vector<std::vector<T>> newVector;
		for (size_t i = 0; i < sizeX; i++)
		{
			std::vector<T> v;
			for (size_t j = 0; j < sizeY; j++)
			{
				v.push_back(value);

				do {
					value += increment;
				} while (vector::contains(without, value));
			}
			newVector.push_back(v);
		}
		return newVector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void init2DVector(std::vector<std::vector<T>>& source, int sizeX, int sizeY, T value)
	{
		source.clear();
		for (int i = 0; i < sizeX; i++)
		{
			std::vector<T> v;
			for (int j = 0; j < sizeY; j++)
			{
				v.push_back(value);
			}
			source.push_back(v);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<std::vector<T>> create2DVector(int sizeX, int sizeY, T value)
	{
		std::vector<std::vector<T>> newVector;
		for (size_t i = 0; i < sizeX; i++)
		{
			std::vector<T> v;
			for (size_t j = 0; j < sizeY; j++)
			{
				v.push_back(value);
			}
			newVector.push_back(v);
		}
		return newVector;
	}



	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<T> subVector(std::vector<T> source, int start, int length)
	{
		std::vector<T> res(0);
		for (size_t i = start; i < length && i < source.size(); i++)
		{
			res.push_back(source[i]);
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::pair<std::vector<T>, std::vector<T>> split(std::vector<T> source, int indexStartSecondVector)
	{
		std::pair<std::vector<T>, std::vector<T>> res = std::make_pair(std::vector<T>(0), std::vector<T>(0));
		for (size_t i = 0; i < indexStartSecondVector && i < source.size(); i++)
		{
			res.first.push_back(source[i]);
		}
		for (size_t i = indexStartSecondVector; i < source.size(); i++)
		{
			res.second.push_back(source[i]);
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::pair<std::vector<T>, std::vector<T>> splitRatio(std::vector<T> source, double pourcentageFirst)
	{
		double index = ((double)source.size()) * pourcentageFirst;;
		return split(source, index);
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void removeRow(std::vector< std::vector<T> >* source, int index)
	{
		source->erase(source->begin() + index);
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void removeCol(std::vector< std::vector<T> >* source, int index)
	{
		for (size_t i = 0; i < source->size(); i++)
		{
			source->at(i).erase(source->at(i).begin() + index);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void removeCol(std::vector< std::vector<T> >* source, std::vector<int> index)
	{
		for (size_t i = 0; i < index.size(); i++)
		{
			removeCol(source, index[i]);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector< std::vector<T> > removeRow(std::vector< std::vector<T> > source, int index)
	{
		source.erase(source.begin() + index);
		return source;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector< std::vector<T> > removeCol(std::vector< std::vector<T> > source, int index)
	{
		for (size_t i = 0; i < source.size(); i++)
		{
			source[i].erase(source[i].begin() + index);
		}
		return source;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector< std::vector<T> > removeCol(std::vector< std::vector<T> > source, std::vector<int> index)
	{
		size_t size = index.size();
		for (size_t i = 0; i < size; i++)
		{
			removeCol(&source, index.back());
			index.pop_back();
		}
		return source;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void addRow(std::vector< std::vector<T> >* source, std::vector<T> row, int index)
	{
		source->insert(source->begin() + index, row);
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void addCol(std::vector< std::vector<T> >* source, std::vector<T> col, int index)
	{
		if (col.size() != source->size())
		{
			std::cout << "erreur : size col != size source << std::endl";
			return;
		}
		for (size_t i = 0; i < source->size(); i++)
		{
			source->at(i).insert(source->at(i).begin() + index, col[i]);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector< std::vector<T> > addRow(std::vector< std::vector<T> > source, std::vector<T> row, int index)
	{
		addRow(&source, row, index);
		return source;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector< std::vector<T> > addCol(std::vector< std::vector<T> > source, std::vector<T> col, int index)
	{
		addCol(&source, col, index);
		return source;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<T> getCol(std::vector< std::vector<T> >& source, int index)
	{
		std::vector<T> vec;
		for (size_t i = 0; i < source.size(); i++)
		{
			vec.push_back(source[i][index]);
		}
		return vec;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void setCol(std::vector< std::vector<T> >* source, std::vector<T> col, int index)
	{
		if (col.size() != source->size())
		{
			std::cout << "erreur size col invalide" << std::endl;
			return;
		}

		for (size_t i = 0; i < col.size(); i++)
		{
			source->at(i)[index] = col[i];
		}
	}
	template<typename T>
	void setCol(std::vector< std::vector<T> >& source, std::vector<T> col, int index)
	{
		if (col.size() != source.size())
		{
			std::cout << "erreur size col invalide" << std::endl;
			return;
		}

		for (size_t i = 0; i < col.size(); i++)
		{
			source[i][index] = col[i];
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<bool> equality(std::vector<T> source, std::vector<T> valeurs)
	{
		if (source.size() != valeurs.size())
		{
			std::cout << "les size des vector ne correspondent pas !" << std::endl;
			return std::vector<bool>(0);
		}

		std::vector<bool> res;
		for (size_t i = 0; i < source.size(); i++)
		{
			res.push_back((source[i] == valeurs[i]));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<bool> equality(std::vector<T> source, T valeur)
	{
		std::vector<bool> res;
		for (size_t i = 0; i < source.size(); i++)
		{
			res.push_back((source[i] == valeur));
		}
		return res;
	}
	template<typename T>
	bool allAreEquals(std::vector<T> source, T valeur)
	{
		for (size_t i = 0; i < source.size(); i++)
		{
			if (source[i] != valeur) return false;
		}
		return true;
	}
	template<typename T>
	bool allAreEquals(std::vector<T> source, std::vector<T> valeurs)
	{
		if (source.size() != valeurs.size())
		{
			std::cout << "les size des vector ne correspondent pas !" << std::endl;
			return NULL;
		}

		std::vector<bool> res;
		for (size_t i = 0; i < source.size(); i++)
		{
			if (source[i] != valeurs[i]) return false;
		}
		return true;
	}
	///////////////////////////////////////////////////////////////
	template<typename T, typename J>
	T max(std::pair<T, J> data)
	{
		if (data.first >= data.second) return data.first;
		return data.second;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	T max(std::vector< T > source)
	{
		if (source.size() == 0) return T();

		T _max = source[0];
		for (size_t i = 1; i < source.size(); i++)
		{
			if (_max < source[i]) _max = source[i];
		}
		return _max;
	}
	template<typename T>
	T max(std::vector< std::vector<T> > source)
	{
		if (source.size() == 0) return NULL;

		T _max = source[0];
		for (size_t i = 0; i < source.size(); i++)
		{
			for (size_t j = 0; j < source[i].size(); j++)
			{
				if (_max < source[i][j]) _max = source[i][j];
			}
		}
		return _max;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::pair<size_t,size_t> maxIndex(std::vector< std::vector<T> > source)
	{
		if (source.size() == 0) return std::make_pair(T(),T());

		std::pair<size_t,size_t> _max = std::make_pair(0,0);
		for (size_t i = 0; i < source.size(); i++)
		{
			for (size_t j = 0; j < source[i].size(); j++)
			{
				if (source[_max.first][_max.second] < source[i][j]) _max = std::make_pair(i,j);
			}
		}
		return _max;
	}
	template<typename T>
	size_t maxIndex(std::vector< T > source)
	{
		if (source.size() == 0) return -1;

		size_t _max = 0;
		for (size_t i = 1; i < source.size(); i++)
		{
			if (source[_max] < source[i]) _max = i;
		}
		return _max;
	}

	///////////////////////////////////////////////////////////////
	template<typename T, typename J>
	T min(std::pair<T, J> data)
	{
		if (data.first <= data.second) return data.first;
		return data.second;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	T min(std::vector<T> source)
	{
		if (source.size() == 0) return T();

		T _min = source[0];
		for (size_t i = 1; i < source.size(); i++)
		{
			if (_min > source[i]) _min = source[i];
		}
		return _min;
	}
	template<typename T>
	int minIndex(std::vector<T> source)
	{
		if (source.size() == 0) return -1;

		T _min = source[0];
		int res = 0;
		for (size_t i = 1; i < source.size(); i++)
		{
			if (_min > source[i]) _min = source[i], res = i;
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	T min(std::vector< std::vector<T> > source)
	{
		if (source.size() == 0) return T();
		T _min = source[0];
		for (size_t i = 1; i < source.size(); i++)
		{
			for (size_t j = 1; j < source[i].size(); j++)
			{
				if (_min > source[i][j]) _min = source[i][j];
			}
		}
		return _min;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<double> toDouble(std::vector<T>vector)
	{
		std::vector<double> res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back((double)vector[i]);
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector< std::vector<double> > toDouble(std::vector<std::vector<T> >vector)
	{
		std::vector< std::vector<double> > res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(toDouble(vector[i]));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<long double> toLongDouble(std::vector<T>vector)
	{
		std::vector<long double> res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back((long double)vector[i]);
		}
		return res;
	}
	template<typename T>
	std::vector< std::vector<long double> > toLongDouble(std::vector<std::vector<T> >vector)
	{
		std::vector< std::vector<long double> > res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(toDouble(vector[i]));
		}
		return res;

	}

	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<int> toInt(std::vector<T>vector)
	{
		std::vector<int> res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back((int)vector[i]);
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector< std::vector<int> > toInt(std::vector<std::vector<T> >vector)
	{
		std::vector< std::vector<int> > res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(toInt(vector[i]));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<float> toFloat(std::vector<T>vector)
	{
		std::vector<float> res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back((float)vector[i]);
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector< std::vector<float> > toFloat(std::vector<std::vector<T> >vector)
	{
		std::vector< std::vector<float> > res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(toFloat(vector[i]));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void sort(std::vector<T>* vector)
	{
		std::sort(vector->begin(), vector->end());
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	int find(std::vector<T>* vector, T data)
	{
		typename std::vector<T>::iterator it = std::find(vector->begin(), vector->end(), data);
		if (it == vector->end()) return -1;
		return it - vector.begin();
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	int find(std::vector<T>& vector, T data)
	{
		typename std::vector<T>::iterator it = std::find(vector.begin(), vector.end(), data);
		if (it == vector.end()) return -1;
		return it - vector.begin();
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<T> sort(std::vector<T> vector)
	{
		std::sort(vector.begin(), vector.end());
		return vector;
	}
	///////////////////////////////////////////////////////////////:
	template<typename T>
	bool isSorted(std::vector<T>& vector, bool croissent)
	{
		for (size_t i = 0; i < vector.size() - 1; i++)
		{
			if ((vector[i] > vector[i + 1]) == croissent) return false;
		}
		return true;
	}
	///////////////////////////////////////////////////////////////:
	template<typename T>
	int insertInSortedVector(std::vector<T>& vector, T value)
	{
		int inf = 0;
		int sup = vector.size();
		int m = (int)((inf + sup) / 2);
		int lm = m;

		while (inf < sup)
		{
			if (value < vector[m])
			{
				sup = m;
			}
			else
			{
				inf = m + 1;
			}
			lm = m;
			m = (int)((inf + sup) / 2);
		}
		vector.insert(vector.begin() + m, value);
		return m;
	}
	template<typename T>
	void insertInSortedVector(std::vector<T>& vector, std::vector<T> values)
	{
		for (size_t i = 0; i < vector.size(); i++)
		{
			insertInSortedVector(vector, values[i]);
		}
	}
	///////////////////////////////////////////////////////////////:
	template<typename T>
	int findInSortedVector(std::vector<T>& vector, T value)
	{

		if (vector.size() == 0) return -1;
		int inf = 0;
		int sup = vector.size() - 1;
		int m = (int)((inf + sup) / 2);

		while (vector[m] != value && inf < sup)
		{
			if (value < vector[m])
			{
				sup = m - 1;
			}
			else
			{
				inf = m + 1;
			}

			m = (int)((inf + sup) / 2);
		}

		if (vector[m] == value)
		{
			return m;
		}
		else return -1;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	bool removeInSortedVector(std::vector<T>& vector, T value)
	{
		int index = findInSortedVector(vector, value);
		if (index == -1) return false;
		vector.erase(vector.begin() + index);
		return true;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void removeInSortedVector(std::vector<T>& vector, int index)
	{
		vector.erase(vector.begin() + index);
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	bool removeInSortedVectorByElement(std::vector<T>& vector, T value)
	{
		int index = findInSortedVector(vector, value);
		if (index == -1) return false;
		vector.erase(vector.begin() + index);
		return true;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void removeInSortedVectorByIndex(std::vector<T>& vector, int index)
	{
		vector.erase(vector.begin() + index);
	}

	template<typename T>
	bool remove(std::vector<T>& vector, T value)
	{
		int index = find(vector, value);
		if (index == -1) return false;
		vector.erase(vector.begin() + index);
		return true;
	}

	template<typename T>
	void remove(std::vector<T>& vector, int index)
	{

		vector.erase(vector.begin() + index);
	}
	
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::pair<int, int> find(std::vector < std::vector<T> >& vector, T data)
	{
		for (size_t i = 0; i < vector.size(); i++)
		{
			for (size_t j = 0; j < vector.size(); j++)
			{
				if (vector[i][j] == data) return std::make_pair(i,j);
			}
		}
		return std::make_pair(-1, -1);
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	O::data::triplet<int, int, int> find(std::vector<std::vector < std::vector<T> >>& vector, T data)
	{
		for (int i = 0; i < vector.size(); i++)
		{
			for (int j = 0; j < vector[i].size(); j++)
			{
				for (int k = 0; k < vector[i][j].size(); k++)
				{
					if (vector[i][j][k] == data) return O::data::make_triplet(i,j,k);
				}
			}
		}
		return O::data::make_triplet(-1, -1, -1);
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	bool contains(std::vector<T>& vector, T data)
	{
		return (std::find(vector.begin(), vector.end(), data) != vector.end());
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	bool contains(std::vector<T>* vector, T data)
	{
		return (std::find(vector->begin(), vector->end(), data) != vector->end());
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void remplace(std::vector<T>* vector, T lastValue, T newValue)
	{
		for (size_t i = 0; i < vector->size(); i++)
		{
			if (vector[i] == lastValue) vector[i] = newValue;
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<T> remplace(std::vector<T> vector, T lastValue, T newValue)
	{
		remplace(&vector, lastValue, newValue);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void remplace(std::vector<T>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue)
	{
		for (size_t i = 0; i < allLastValue.size(); i++)
		{
			vector::remplace(vector, allLastValue[i], allNewValue[i]);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<T> remplace(std::vector<T> vector, std::vector<T> allLastValue, std::vector<T> allNewValue)
	{
		if (allLastValue.size() != allLastValue.size())
		{
			std::cout << "erreur : lastValue & newValue n'ont pas le meme nombre de lignes" << std::endl;
			return NULL;
		}
		remplace(&vector, allLastValue, allNewValue);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void remplaceInRow(std::vector<std::vector<T>>* vector, T lastValue, T newValue, int row)
	{
		if (row >= 0 && row < vector->size())
		{
			std::cout << "erreur : row invalide" << std::endl;
			return;
		}
		vector->at(row) = remplace(vector->at(row), lastValue, newValue);
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<std::vector<T>> remplaceInRow(std::vector<std::vector<T>> vector, T lastValue, T newValue, int row)
	{
		vector::remplaceInRow(&vector, lastValue, newValue, row);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void remplaceInRow(std::vector<std::vector<T>>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue, int row)
	{
		if (row >= 0 && row < vector->size())
		{
			std::cout << "erreur : row invalide" << std::endl;
			return ;
		}
		vector->at(row) = remplace(vector->at(row), allLastValue, allNewValue);
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<std::vector<T>> remplaceInRow(std::vector<std::vector<T>> vector, std::vector<T> allLastValue, std::vector<T> allNewValue, int row)
	{
		vector::remplaceInRow(&vector, allLastValue, allNewValue, row);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void remplaceInRow(std::vector<std::vector<T>>* vector, T lastValue, T newValue, std::vector<int> row)
	{
		for (size_t i = 0; i < row.size(); i++)
		{
			vector::remplaceInRow(vector, lastValue, newValue, row[i]);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<std::vector<T>> remplaceInRow(std::vector<std::vector<T>> vector, T lastValue, T newValue, std::vector<int> row)
	{
		for (size_t i = 0; i < row.size(); i++)
		{
			vector::remplaceInRow(&vector, lastValue, newValue, row[i]);
		}
		return vector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void remplaceInRow(std::vector<std::vector<T>>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue, std::vector<int> row)
	{
		for (size_t i = 0; i < row.size(); i++)
		{
			vector::remplaceInRow(vector, allLastValue, allNewValue, row[i]);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<std::vector<T>> remplaceInRow(std::vector<std::vector<T>> vector, std::vector<T> allLastValue, std::vector<T> allNewValue, std::vector<int> row)
	{
		for (size_t i = 0; i < row.size(); i++)
		{
			vector::remplaceInRow(&vector, allLastValue, allNewValue, row[i]);
		}
		return vector;
	}
	///////////////////////////////////////////////////////////////

	template<typename T>
	void remplaceInCol(std::vector<std::vector<T>>* vector, T lastValue, T newValue, int col)
	{
		for (size_t i = 0; i < vector->size(); i++)
		{
			if (col < 0 && col >= vector->at(i).size())
			{
				std::cout << "erreur : col invalide" << std::endl;
				return;
			}
			if (vector->at(i)[col] == lastValue)
			{
				vector->at(i)[col] = newValue;
			}

		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<std::vector<T>> remplaceInCol(std::vector<std::vector<T>> vector, T lastValue, T newValue, int col)
	{
		vector::remplaceInCol(&vector, lastValue, newValue, col);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void remplaceInCol(std::vector<std::vector<T>>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue, int col)
	{
		if (allLastValue.size() != allLastValue.size())
		{
			std::cout << "erreur : lastValue & newValue n'ont pas le meme nombre de lignes" << std::endl;
			return;
		}
		for (size_t i = 0; i < allLastValue.size(); i++)
		{
			vector::remplaceInCol(vector, allLastValue[i], allNewValue[i], col);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<std::vector<T>> remplaceInCol(std::vector<std::vector<T>> vector, std::vector<T> allLastValue, std::vector<T> allNewValue, int col)
	{
		vector::remplaceInCol(&vector, allLastValue, allNewValue, col);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void remplaceInCol(std::vector<std::vector<T>>* vector, T lastValue, T newValue, std::vector<int> col)
	{
		for (size_t i = 0; i < col.size(); i++)
		{
			remplaceInCol(vector, lastValue, newValue, col[i]);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector<std::vector<T>> remplaceInCol(std::vector<std::vector<T>> vector, T lastValue, T newValue, std::vector<int> col)
	{
		remplaceInCol(&vector, lastValue, newValue, col);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	void remplaceInCol(std::vector<std::vector<T>>* vector, std::vector<T> allLastValue, std::vector<T> allNewValue, std::vector<int> col)
	{
		for (size_t i = 0; i < col.size(); i++)
		{
			remplaceInCol(vector, allLastValue, allNewValue, col[i]);
		}
	}
	///////////////////////////////////////////////////////////////
	template<typename T>
	std::vector< std::vector<T> > remplaceInCol(std::vector<std::vector<T>> vector, std::vector<T> allLastValue, std::vector<T> allNewValue, std::vector<int> col)
	{
		remplaceInCol(&vector, allLastValue, allNewValue, col);
		return vector;
	}

	template<typename T>
	std::vector<T> reverse(std::vector<T> vector)
	{
		std::vector<T> v;
		for (int i = vector.size() - 1; i >= 0; i--)
		{
			v.push_back(vector[i]);
		}
		return v;

	}

	template<typename T>
	void reverse(std::vector<T>* vector)
	{
		std::vector<T> v;
		for (int i = vector.size() - 1; i >= 0; i--)
		{
			v.push_back(vector[i]);
		}
		vector = v;
	}

	template<typename T>
	std::vector<T> swap(std::vector<T> vector, int i, int j)
	{
		swap(&vector, i, j);
		return vector;
	}

	template<typename T>
	void swap(std::vector<T>* vector, int i, int j)
	{
		T temp = vector->at(i);
		vector->at(i) = vector->at(j);
		vector->at(j) = temp;
	}

	template<typename T>
	std::vector<T> shuffle(std::vector<T> vector)
	{
		shuffle(&vector);
		return vector;
	}

	template<typename T>
	void shuffle(std::vector<T>* vector)
	{
		std::random_shuffle(vector->begin(), vector->end());
	}
	template<typename T>
	T getSum(std::vector<T> vector)
	{
		if (vector.size() == 0) return T();
		T sum = vector[0];
		for (size_t i = 1; i < vector.size(); i++)
		{
			sum += vector[i];
		}
		return sum;
	}
	template<typename T,typename J>
	void add(std::vector<T>& vector, J value)
	{
		for (size_t i = 0; i < vector.size(); i++)
		{
			vector[i] += value;
		}
	}
	template<typename T,typename J,typename I>
	void add(std::vector<T>& vector, J value, I modulo)
	{
		for (size_t i = 0; i < vector.size(); i++)
		{
			vector[i] += value; 
			math::mod(vector[i], modulo);
		}
	}

	template<typename T>
	std::vector<T> add(const std::vector<T>& a, const std::vector<T>& b)
	{
		if (a.size() != b.size()) return std::vector<T>(0);

		std::vector<T> res = vector::createVector(a.size(), T());
		for (size_t i = 0; i < a.size() && i < b.size(); i++)
		{
			res[i] = a[i] + b[i];
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T, typename T_, typename R, typename R_>
	std::vector<R> applyFunction(const std::vector<T>& vec, R_ (*function)(T_))
	{
		std::vector<R> res;
		for (size_t i = 0; i < vec.size(); i++)
		{
			res.push_back(function(vec[i]));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T,typename T_, typename U,typename U_, typename R, typename R_>
	std::vector<R> applyFunction(const std::vector<T>& vec, R_ (*function)(T_, U_), U arg)
	{
		std::vector<R> res;
		for (size_t i = 0; i < vec.size(); i++)
		{
			res.push_back(function(vec[i], arg));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	template<typename T,typename T_, typename U,typename U_, typename V,typename V_, typename R,typename R_>
	std::vector<R> applyFunction(const std::vector<T>& vec, R_ (*function)(T_, U_, V_), U arg, V arg2)
	{
		std::vector<R> res;
		for (size_t i = 0; i < vec.size(); i++)
		{
			res.push_back(function(vec[i], arg, arg2));
		}
		return res;
	}
}
}