#include "VectorFunctions.h"


namespace O{
namespace vector {

	std::vector<int> createRandomVector(int size, int min, int max)
	{
		std::vector<int> vec;
		for (int i = 0; i < size; i++)
		{
			vec.push_back(math::rdm::randInt(min, max));
		}
		return vec;
	}
	std::vector<float> createRandomVector(int size, float min, float max)
	{
		std::vector<float> vec;
		for (int i = 0; i < size; i++)
		{
			vec.push_back(math::rdm::randFloat(min, max));
		}
		return vec;
	}
	std::vector<double> createRandomVector(int size, double min, double max)
	{
		std::vector<double> vec;
		for (int i = 0; i < size; i++)
		{
			vec.push_back(math::rdm::randFloat(min, max));
		}
		return vec;
	}
	std::vector<std::vector<int>> createRandom2DVector(int sizeX, int sizeY, int min, int max)
	{
		std::vector<std::vector<int>> vec;
		for (int i = 0; i < sizeX; i++)
		{
			vec.push_back(vector::createRandomVector(sizeY,min, max));
		}
		return vec;
	}
	std::vector<std::vector<float>> createRandom2DVector(int sizeX, int sizeY, float min, float max)
	{
		std::vector<std::vector<float>> vec;
		for (int i = 0; i < sizeX; i++)
		{
			vec.push_back(vector::createRandomVector(sizeY, min, max));
		}
		return vec;
	}
	std::vector<std::vector<double>> createRandom2DVector(int sizeX, int sizeY, double min, double max)
	{
		std::vector<std::vector<double>> vec;
		for (int i = 0; i < sizeX; i++)
		{
			vec.push_back(vector::createRandomVector(sizeY, min, max));
		}
		return vec;
	}
	void initRandomVector(std::vector<int>& source, int size, int min, int max)
	{
		source.clear();
		for (int i = 0; i < size; i++)
		{
			source.push_back(math::rdm::randInt(min, max));
		}
	}
	void initRandomVector(std::vector<float>& source, int size, float min, float max)
	{
		source.clear();
		for (int i = 0; i < size; i++)
		{
			source.push_back(math::rdm::randFloat(min, max));
		}
	}
	void initRandomVector(std::vector<double>& source, int size, double min, double max)
	{
		source.clear();
		for (int i = 0; i < size; i++)
		{
			source.push_back(math::rdm::randFloat(min, max));
		}
	}
	std::vector<int> toInt(std::vector<std::string> vector)
	{
		std::vector<int> res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(atoi(vector[i].c_str()));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	std::vector<double> toDouble(std::vector<std::string>vector)
	{
		std::vector<double> res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(atof(vector[i].c_str()));
		}
		return res;
	}
	std::vector<long double> toLongDouble(std::vector<std::string>vector)
	{
		std::vector<long double> res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(atof(vector[i].c_str()));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	std::vector<float> toFloat(std::vector<std::string>vector)
	{
		std::vector<float> res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(atof(vector[i].c_str()));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	std::vector< std::vector<int> > toInt(std::vector< std::vector<std::string> >vector)
	{
		std::vector< std::vector<int> > res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(toInt(vector[i]));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	std::vector< std::vector<double> > toDouble(std::vector<std::vector<std::string> >vector)
	{
		std::vector< std::vector<double> > res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(toDouble(vector[i]));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	std::vector< std::vector<long double> > toLongDouble(std::vector<std::vector<std::string> >vector)
	{
		std::vector< std::vector<long double> > res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(toLongDouble(vector[i]));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	std::vector< std::vector<float> > toFloat(std::vector<std::vector<std::string> >vector)
	{
		std::vector< std::vector<float> > res;
		for (size_t i = 0; i < vector.size(); i++)
		{
			res.push_back(toFloat(vector[i]));
		}
		return res;
	}
	///////////////////////////////////////////////////////////////
	std::vector<long double> normalize(std::vector<long double> vector, long double min, long double max)
	{
		normalize(&vector, min, max);
		return vector;
	}

	///////////////////////////////////////////////////////////////
	void normalize(std::vector<long double>* vector, long double min, long double max)
	{
		long double _max = vector::max(*vector);
		long double _min = vector::min(*vector);
		long double length = _max - _min;

		long double lengthBornes = max - min;

		for (size_t i = 0; i < vector->size(); i++)
		{
			vector->at(i) = ((vector->at(i) - _min) / length) * lengthBornes + min;
		}
	}

	///////////////////////////////////////////////////////////////
	std::vector<double> normalize(std::vector<double> vector, double min, double max)
	{
		normalize(&vector, min, max);
		return vector;
	}
	void normalize(std::vector<double>* vector, double min, double max)
	{
		double _max = vector::max(*vector);
		double _min = vector::min(*vector);
		double length = _max - _min;

		double lengthBornes = max - min;

		for (size_t i = 0; i < vector->size(); i++)
		{
			vector->at(i) = ((vector->at(i) - _min) / length) * lengthBornes + min;
		}
	}
	///////////////////////////////////////////////////////////////
	std::vector<float> normalize(std::vector<float> vector, double min, double max)
	{
		normalize(&vector, min, max);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	void normalize(std::vector<float>* vector, double min, double max)
	{
		double _max = vector::max(*vector);
		double _min = vector::min(*vector);
		double length = _max - _min;

		double lengthBornes = max - min;

		for (size_t i = 0; i < vector->size(); i++)
		{
			vector->push_back(((vector->at(i) - _min) / length) * lengthBornes + min);
		}

	}
	///////////////////////////////////////////////////////////////


	std::vector < std::vector<long double>> normalize(std::vector < std::vector<long double>> vector, long double min, long double max)
	{
		normalize(&vector, min, max);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	void normalize(std::vector <std::vector<long double>>* vector, long double min, long double max)
	{
		if (vector->size() == 0)
		{
			std::cout << "vector invalide !" << std::endl;
			return;
		}
		for (size_t i = 0; i < vector->size(); i++)
		{
			if (vector->at(0).size() != vector->at(i).size())
			{
				std::cout << "vector invalide !" << std::endl;
				return;
			}
		}

		for (size_t i = 0; i < vector->at(0).size(); i++) // pour chaques colones
		{
			// on recup�re la colone
			std::vector<long double> colone = vector::getCol(*vector, i);
			// on la normalise
			vector::normalize(&colone, min, max);
			// on l'insert
			vector::setCol(*vector, colone, i);
		}
	}
	///////////////////////////////////////////////////////////////
	std::vector< std::vector<double>>normalize(std::vector<std::vector<double>> vector, double min, double max)
	{
		normalize(&vector, min, max);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	void normalize(std::vector<std::vector<double>>* vector, double min, double max)
	{
		if (vector->size() == 0)
		{
			std::cout << "vector invalide !" << std::endl;
			return;
		}
		for (size_t i = 0; i < vector->size(); i++)
		{
			if (vector->at(0).size() != vector->at(i).size())
			{
				std::cout << "vector invalide !" << std::endl;
				return;
			}
		}

		for (size_t i = 0; i < vector->at(0).size(); i++) // pour chaques colones
		{
			// on recup�re la colone
			std::vector<double> colone = vector::getCol(*vector, i);
			// on la normalise
			vector::normalize(&colone, min, max);
			// on l'insert
			vector::setCol(*vector, colone, i);
		}
	}
	///////////////////////////////////////////////////////////////
	std::vector< std::vector<float>> normalize(std::vector<std::vector<float>> vector, double min, double max)
	{
		normalize(&vector, min, max);
		return vector;
	}
	///////////////////////////////////////////////////////////////
	void normalize(std::vector<std::vector<float>>* vector, double min, double max)
	{
		if (vector->size() == 0)
		{
			std::cout << "vector invalide !" << std::endl;
			return;
		}
		for (size_t i = 0; i < vector->size(); i++)
		{
			if (vector->at(0).size() != vector->at(i).size())
			{
				std::cout << "vector invalide !" << std::endl;
				return;
			}
		}

		for (size_t i = 0; i < vector[0].size(); i++) // pour chaques colones
		{
			// on recup�re la colone
			std::vector<float> colone = vector::getCol(*vector, i);
			// on la normalise
			vector::normalize(colone, min, max);
			// on l'insert
			vector::setCol(*vector, colone, i);
		}
	}
	

}}