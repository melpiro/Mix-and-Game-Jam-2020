#pragma once
#include <vector>

namespace O{
namespace math
{
	
template <typename T>
class GraphNode{
public:
    GraphNode();
	GraphNode(const T& value);

	T getValue() const;
	void addAdjNode(GraphNode<T>* node,const double& dist);
	void rmAdjNode(const GraphNode<T>* node);
	int findNode(const GraphNode<T>* node) const;
	std::vector<std::pair<GraphNode<T>*, double>> getAdjNodes() const;

private:

	std::vector<std::pair<GraphNode<T>*, double>> adjNodes;
	T value;
};


template <typename T>
bool operator<(GraphNode<T> g, GraphNode<T> g2);

template <typename T>
std::ostream& operator<<(std::ostream& os, GraphNode<T> g2);
}}

#include "GraphNode.ipp"