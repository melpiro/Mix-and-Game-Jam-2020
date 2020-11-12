#include "Math/EnsembleFunctions.h"

namespace O{
namespace math {
namespace set {

	template<typename T>
	std::vector<std::vector<T>> getCombinationsWithReapeat(const std::vector<T>& vector, const int& nbElements)
	{
		if (nbElements < 0) 
		{
			std::cerr << "[O::math::set::getCombinationsWithReapeat] paramètre nbMaxElements invalide ! \n";
			return std::vector<std::vector<T>>(0);
		}
		if (nbElements == 0 || vector.size() == 0) return std::vector<std::vector<T>>(0);

		std::vector<std::vector<T>> res;

		std::vector<int> combin = vector::createVector(nbElements, 0);

		bool run = true;

		while (run)
		{
			res.push_back(std::vector<T>(nbElements));
			for (size_t i = 0; i < nbElements; i++)
			{
				res.back()[i] = vector[combin[i]];
			}


			int indexLast = combin.size() - 1;
			combin[indexLast]++;

			while (indexLast > 0 && combin[indexLast] >= vector.size())
			{
				combin[indexLast - 1]++;
				combin[indexLast] = 0;

				indexLast--;
			}

			if (indexLast <= 0 && combin[indexLast] >= vector.size()) return res;

		}

	}

	template<typename T>
	std::vector<std::vector<T>> getCombinations(const std::vector<T>& vector, const int& nbElements)
	{
		if (nbElements < 0 || nbElements > vector.size()) 
		{
			std::cerr << "[O::math::set::getCombinations] paramètre nbElements invalide ! \n";
			return std::vector<std::vector<T>>(0);
		}
		if (nbElements == 0 || vector.size() == 0) return std::vector<std::vector<T>>(0);

		std::vector<std::vector<T>> res;

		std::vector<int> combin = vector::createVector(nbElements, 0, 1);

		bool run = true;

		while (run)
		{
			res.push_back(std::vector<T>(nbElements));
			for (size_t i = 0; i < nbElements; i++)
			{
				res.back()[i] = vector[combin[i]];
			}


			int indexLast = combin.size() - 1;
			combin[indexLast]++;

			while (indexLast > 0 && combin[indexLast] > vector.size() + indexLast - nbElements)
			{
				combin[indexLast - 1]++;
				indexLast--;
			}

			if (indexLast == 0 && combin[indexLast] > vector.size() - nbElements) return res;

			for (size_t i = indexLast; i < combin.size() - 1; i++)
			{
				combin[i + 1] = combin[i] + 1;
			}
		}
	}
	template<typename T>
	std::vector<std::vector<T>> getAllCombinationsWithReapeat(const std::vector<T>& vector, const int& nbMaxElements)
	{
		if (nbMaxElements < 0) 
		{
			std::cerr << "[O::math::set::getAllCombinationsWithReapeat] paramètre nbMaxElements invalide ! \n";
			return std::vector<std::vector<T>>(0);
		}
		if (nbMaxElements == 0 || vector.size() == 0) return std::vector<std::vector<T>>(0);

		std::vector<std::vector<T>> res(0);

		for (size_t i = 1; i <= nbMaxElements; i++)
		{
			vector::pushBack(res, getCombinationsWithReapeat(vector, i));
		}
		return res;
	}
	template<typename T>
	std::vector<std::vector<T>> getAllCombinationsWithReapeat(const std::vector<T>& vector)
	{
		std::vector<std::vector<T>> res(0);

		for (size_t i = 1; i <= vector.size(); i++)
		{
			vector::pushBack(res, getCombinationsWithReapeat(vector, i));
		}
		return res;
	}
	template<typename T>
	std::vector<std::vector<T>> getAllCombinations(const std::vector<T>& vector, const int& nbMaxElements)
	{
		if (nbMaxElements < 0 || nbMaxElements > vector.size()) 
		{
			std::cerr << "[O::math::set::getAllCombinations] paramètre nbMaxElements invalide ! \n";
			return std::vector<std::vector<T>>(0);
		}
		if (nbMaxElements == 0 || vector.size() == 0) return std::vector<std::vector<T>>(0);
		std::vector<std::vector<T>> res(0);

		for (size_t i = 1; i <= nbMaxElements; i++)
		{
			vector::pushBack(res, getCombinations(vector, i));
		}
		return res;
	}
	template<typename T>
	std::vector<std::vector<T>> getAllCombinations(const std::vector<T>& vector)
	{
		std::vector<std::vector<T>> res(0);

		for (size_t i = 1; i <= vector.size(); i++)
		{
			vector::pushBack(res, getCombinations(vector, i));
		}
		return res;
	}
	template<typename T>
	std::vector<std::vector<T>> getPermutations(const std::vector<T>& vector)
	{
		std::vector <std::vector<T>> res;
		std::vector<T> v = vector;
		_getPermutationsRecur(v, vector.size(), vector.size(), res);
		return res;
	}
	template<typename T>
	void _getPermutationsRecur(std::vector<T>& vector, const int& size, const int& n, std::vector <std::vector<T>>& res)
	{
		if (size == 1)
		{
			res.push_back(vector);
			return;
		}
		for (int i = 0; i < size; i++)
		{
			_getPermutationsRecur(vector, size - 1, n, res);

			if (size % 2 == 1)
				vector::swap(&vector, 0, size - 1);
			else
				vector::swap(&vector, i, size - 1);
		}
	}
	template<typename T>
	std::vector<std::vector<T>> getArrengements(const std::vector<T>& vector, const int& size)
	{
		if (size < 0 || size > vector.size()) 
		{
			std::cerr << "[O::math::set::getArrengements] paramètre size invalide ! \n";
			return std::vector<std::vector<T>>(0);
		}
		if (size == 0 || vector.size() == 0) return std::vector<std::vector<T>>(0);
		// on récupère toutes les combinaisons sans répétion
		std::vector<std::vector<T>> comb = getCombinations(vector, size);

		// et ensuite pour chaques combinaisons on récupère les permutation de cet
		// combinaisons
		std::vector<std::vector<T>> res;
		for (size_t i = 0; i < comb.size(); i++)
		{
			std::vector<std::vector<T>> permut = getPermutations(comb[i]);
			O::vector::pushBack(res, permut);
		}
		return res;
	}
	template<typename T>
	std::vector< std::vector< T >> getAllArrengements(const std::vector<T>& vector)
	{
		
		if (vector.size() == 0) return std::vector<std::vector<T>>(0);
		// on récupère toutes les combinaisons sans répétion
		std::vector<std::vector<T>> comb = getAllCombinations(vector);

		// et ensuite pour chaques combinaisons on récupère les permutation de cet
		// combinaisons
		std::vector<std::vector<T>> res;
		for (size_t i = 0; i < comb.size(); i++)
		{
			std::vector<std::vector<T>> permut = getPermutations(comb[i]);
			O::vector::pushBack(res, permut);
		}
		return res;
	}
	
	template<typename T>
	std::vector< std::vector< T >> getAllArrengements(const std::vector<T>& vector, const int& sizeMax)
	{
		if (sizeMax < 0 || sizeMax > vector.size()) 
		{
			std::cerr << "[O::math::set::getAllArrengements] paramètre sizeMax invalide ! \n";
			return std::vector<std::vector<T>>(0);
		}
		if (sizeMax == 0 || vector.size() == 0) return std::vector<std::vector<T>>(0);

		// on récupère toutes les combinaisons sans répétion
		std::vector<std::vector<T>> comb = getAllCombinations(vector, sizeMax);

		// et ensuite pour chaques combinaisons on récupère les permutation de cet
		// combinaisons
		std::vector<std::vector<T>> res;
		for (size_t i = 0; i < comb.size(); i++)
		{
			std::vector<std::vector<T>> permut = getPermutations(comb[i]);
			O::vector::pushBack(res, permut);
		}
		return res;
	}

}}}