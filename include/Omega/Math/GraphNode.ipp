#include "GraphNode.h"


namespace O{
namespace math
{
	

template <typename T>
GraphNode<T>::GraphNode() {this->value = T();}

template <typename T>
GraphNode<T>::GraphNode(const T& value) {this->value = value;}

template <typename T>
inline T GraphNode<T>::getValue() const
{
    return value;
}
template <typename T>
inline void GraphNode<T>::addAdjNode(GraphNode<T>* node, const double& dist)
{
    int i = findNode(node);
    if (i != -1) return;
    
    GraphNode<T>* n = node;
    double d = dist;
    adjNodes.push_back(std::make_pair(n, d));
    
}
template <typename T>
inline void GraphNode<T>::rmAdjNode(const GraphNode<T>* node)
{
    int i = findNode(node);
    if (i == -1) return;
    adjNodes.erase(adjNodes.begin() + i);
}
template <typename T>
inline int GraphNode<T>::findNode(const GraphNode<T>* node) const
{
    for (size_t i = 0; i < adjNodes.size(); i++)
    {
        if (node == adjNodes[i].first)
        {
            return i;
        }
    }
    return -1;
}
template <typename T>
inline std::vector<std::pair<GraphNode<T>*, double>> GraphNode<T>::getAdjNodes() const
{
    return adjNodes;
}



template <typename T>
inline bool operator<(GraphNode<T> g, GraphNode<T> g2)
{
	return (g.getValue() < g2.getValue());
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, GraphNode<T> g2)
{
    os << g2.getValue();
    return os;
}

}}