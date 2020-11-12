#pragma once

#include "Vector/VectorFunctions.h"

namespace O{
namespace math {
namespace set {

	///////////////////////////////////////////////////////////////
	// récupère tous les possibilités de vector de taille size
	// contenant des éléments du vector initial
	// note : les éléments peuvent etre pris plusieurs plusieurs fois
	template<typename T>
	std::vector< std::vector< T >> getCombinationsWithReapeat(const std::vector<T>& vector, const int& nbElements);

	///////////////////////////////////////////////////////////////
	// récupère toutes les combinaisons de taille size
	// note : les élément ne se répétes pas !
	template<typename T>
	std::vector< std::vector< T >> getCombinations(const std::vector<T>& vector, const int& nbElements);

	///////////////////////////////////////////////////////////////
	// récupère tous les possibilités de vector de taille allant de
	// 0 à nbMaxElements contenant des éléments du vector initial
	// note : les éléments peuvent etre pris plusieurs plusieurs fois
	template<typename T>
	std::vector< std::vector< T >> getAllCombinationsWithReapeat(const std::vector<T>& vector, const int& nbMaxElements);
	
	///////////////////////////////////////////////////////////////
	// récupère tous les possibilités de vector de taille allant de
	// 0 à la taille du vector initial, contenant des éléments du vector 
	// initial
	// note : les éléments peuvent etre pris plusieurs plusieurs fois
	template<typename T>
	std::vector< std::vector< T >> getAllCombinationsWithReapeat(const std::vector<T>& vector);
	
	///////////////////////////////////////////////////////////////
	// récupère toutes les combinaisons de taille allant de 0 à
	// nbMaxElements
	// note : les élément ne se répétes pas !
	template<typename T>
	std::vector< std::vector< T >> getAllCombinations(const std::vector<T>& vector, const int& nbMaxElements);
	
	///////////////////////////////////////////////////////////////
	// récupère toutes les combinaisons de taille allant de 0 à
	// a la taille du vector
	// note : les élément ne se répétes pas !
	template<typename T>
	std::vector< std::vector< T >> getAllCombinations(const std::vector<T>& vector);

	///////////////////////////////////////////////////////////////
	// récupère toutes les permutation du vector
	// (tous les ordres possibles)
	template<typename T>
	std::vector< std::vector< T >> getPermutations(const std::vector<T>& vector);
	template<typename T>
	void _getPermutationsRecur(std::vector<T>& vector, const int& size, const int& n, std::vector <std::vector<T>>& res);


	///////////////////////////////////////////////////////////////
	// récupère toutes les arengement d'un vector
	// (toutes les permutation de sous vector de taille size)
	template<typename T>
	std::vector< std::vector< T >> getArrengements(const std::vector<T>& vector, const int& size);


	template<typename T>
	std::vector< std::vector< T >> getAllArrengements(const std::vector<T>& vector);
	
	template<typename T>
	std::vector< std::vector< T >> getAllArrengements(const std::vector<T>& vector, const int& sizeMax);



}
}
}


#include "EnsembleFunction.ipp"