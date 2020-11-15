#pragma once

#include <iostream>
#include "Data/triplet.h"
#include <map>
#include <queue>
#include <set>
#include <vector>
#include "Math/GraphNode.h"
#include "Vector/VectorFunctions.h"
#include "Operators/PrintFunctions.h"


namespace O{
namespace math
{

template <typename T>
class Graph
{
public:
	Graph();


	void addNode(const T& value);
	void addEdges(const T& from, const T& to, const double& distance);
	void removeEdges(const T& from, const T& to);
	void removeNode(const T& value);


	std::vector < O::data::triplet<T, T, double>> dijkstra(const T& from) const;
	std::vector <T> dijkstra(const T& from, const T& to) const;

	//std::pair<double, std::vector<std::vector< std::pair<bool, double> >> > fordFulkerson(T source, T puit, std::vector<std::pair<std::pair<T, T>, double>>  minConstraint = std::vector<std::pair<std::pair<T, T>, double>>(0));

	double getDistance(const std::vector<T>& path) const;

	///////////////////////////////////////////////////////////////
	// FONCTION BUGGEE NE PAS UTILISER !
	bool isConnexe() const;

	bool haveEdge(const T& from, const T& to) const;

	void print() const;


private:

	std::map<T,GraphNode<T>> m_nodes;

	//bool bfs(std::vector<std::vector< std::pair<bool, double> >>rGraph, int s, int t, std::vector<int>& parent);
	T minDistance(const std::map<T,double>& dist, const std::map<T,bool>& sptSet) const;
	T maxDistance(const std::map<T,double>& dist, const std::map<T,bool>& sptSet) const;


};

// namespace graph
// {
// 	Graph<int> loadFromFile(std::string fileName, bool isOriented=true);
// } // namespace graph

		
}
}

#include "Graph.ipp"