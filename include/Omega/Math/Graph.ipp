
namespace O{
namespace math
{

template<typename T>
inline Graph<T>::Graph():
	m_nodes()
{
}

template<typename T>
inline void Graph<T>::addNode(const T& value)
{
	GraphNode<T> newNode(value);
	auto it = m_nodes.find(value);

	if (it == m_nodes.end())
	{
		m_nodes[value] = newNode;
	}
	else
	{
		std::cerr << "[O::math::Graph::addNode] value deja présente" << std::endl;
	}
}

template<typename T>
inline void Graph<T>::addEdges(const T& from, const T& to, const double& distance)
{
	auto it1 = m_nodes.find(from);
	auto it2 = m_nodes.find(to);

	if (it1 != m_nodes.end() && it2 != m_nodes.end())
	{
		it1->second.addAdjNode(&it2->second, distance);
	}
	else
	{
		std::cerr << "[O::math::Graph::addEdges] edge deja présente" << std::endl;
	}
}


template<typename T>
inline void Graph<T>::removeEdges(const T& from, const T& to)
{

	auto it1 = m_nodes.find(from);
	auto it2 = m_nodes.find(to);

	if (it1 != m_nodes.end() && it2 != m_nodes.end())
	{
		it1->second.rmAdjNode(&it2->second);
	}
	else
	{
		std::cout << "[O::math::Graph::addEdges] edge deja présente" << std::endl;
	}
}

template<typename T>
inline void Graph<T>::removeNode(const T& value)
{
	auto it1 = m_nodes.find(value);
	if (it1 == m_nodes.end())
	{
		std::cout << "[O::math::Graph::removeNode] noeud inexistant" << std::endl;
		return;
	}
	
	for (auto it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
		it->second.rmAdjNode(&it1->second);
	}
	m_nodes.erase(it1);
}

template<typename T>
inline T Graph<T>::minDistance(const std::map<T,double>& dist, const std::map<T,bool>& sptSet) const
{
	double min = 10000000000;
	T min_value;

	for (auto n:m_nodes)
	{
		double distActu = dist.at(n.first);

	 	if (sptSet.at(n.first) == false && distActu <= min)
	 		min = distActu, min_value = n.first;
	}
	return min_value;
}

template<typename T>
inline T Graph<T>::maxDistance(const std::map<T,double>& dist, const std::map<T,bool>& sptSet) const
{
	double max = 0;
	T max_value;

	for (auto n:m_nodes)
	{
		double distActu = dist[n.first];

		if (sptSet[n.first] == false && distActu >= max)
			max = distActu, max_value = n.first;
	}
	return max_value;
}

template<typename T>
inline std::vector <O::data::triplet<T, T, double>> Graph<T>::dijkstra(const T& from) const
{
	auto it1 = m_nodes.find(from);

	if (it1 != m_nodes.end())
	{
		T src = from;

	 	std::map<T, double> dist;
	 	std::map<T,T> lastNodes;

	 	std::map<T,bool> sptSet;
	 	for (auto n:m_nodes)
	 		dist[n.first] = 10000000.0, sptSet[n.first] = false;

	 	dist[src] = 0;

	 	for (int count = 0; count < m_nodes.size() - 1; count++) {
	 		T indexMin = minDistance(dist, sptSet);
	 		sptSet[indexMin] = true;
			GraphNode<T> node = m_nodes.at(indexMin); 


	 		for (int v = 0; v < node.getAdjNodes().size(); v++) {

				T v_value = node.getAdjNodes()[v].first->getValue();
	 			if (!sptSet[v_value] 
					&& dist[indexMin] != 10000000.0 && dist[indexMin] + node.getAdjNodes()[v].second < dist[v_value]) {
	 				
					dist[v_value] = dist[indexMin] + node.getAdjNodes()[v].second;
	 				lastNodes[v_value] = indexMin;
				}
	 		}
	 	}

	 	
		std::vector<O::data::triplet<T, T, double >> res;
		for (auto n:m_nodes)
		{
			auto it = lastNodes.find(n.first);
			if (it == lastNodes.end()) res.push_back(O::data::make_triplet(n.first, n.first, dist[n.first]));
			else res.push_back(O::data::make_triplet(n.first, it->second, dist[n.first]));
		}
	 	return res;

	}
	return std::vector<O::data::triplet<T, T, double >>(0);

}

template<typename T>
inline bool  Graph<T>::haveEdge(const T& from, const T& to) const
{
	auto it1 = m_nodes.find(from);
	auto it2 = m_nodes.find(to);

	return (it1->second.findNode(&it2->second) != -1);
}


template<typename T>
inline void Graph<T>::print() const
{
	std::cout << "Nodes : " << std::endl;
	for (auto n:m_nodes)
	{
		std::cout << n.first << " ";
	}
	std::cout  <<std::endl;
	std::cout << "edges : " << std::endl;
	for (auto n:m_nodes)
	{
		for (size_t i = 0; i < n.second.getAdjNodes().size(); i++)
		{
			std::cout << n.first<<" -> "<<n.second.getAdjNodes()[i].first->getValue()<<" = "<< n.second.getAdjNodes()[i].second << std::endl;
		}
	}

}


template<typename T>
inline std::vector<T> Graph<T>::dijkstra(const T& from, const T& to) const
{
	typename std::map<T,GraphNode<T>>::const_iterator it1 = m_nodes.find(from);
	typename std::map<T,GraphNode<T>>::const_iterator it2 = m_nodes.find(to);

	if (it1 != m_nodes.end() && it2 != m_nodes.end())
	{
		T src = from;
		const GraphNode<T>* noeudDestination = &it2->second;

	 	std::map<T, double> dist;
	 	std::map<T,T> lastNodes;

	 	std::map<T,bool> sptSet;
	 	for (auto n:m_nodes)
	 		dist[n.first] = 10000000.0, sptSet[n.first] = false;

	 	dist[src] = 0;

	 	for (int count = 0; count < m_nodes.size() - 1; count++) {
	 		T indexMin = minDistance(dist, sptSet);
	 		sptSet[indexMin] = true;
			GraphNode<T> node = m_nodes.at(indexMin); 


	 		for (int v = 0; v < node.getAdjNodes().size(); v++) {

				T v_value = node.getAdjNodes()[v].first->getValue();
	 			if (!sptSet[v_value] 
					&& dist[indexMin] != 10000000.0 && dist[indexMin] + node.getAdjNodes()[v].second < dist[v_value]) {
	 				
					dist[v_value] = dist[indexMin] + node.getAdjNodes()[v].second;
	 				lastNodes[v_value] = indexMin;
				}
	 		}
	 	}

	 	std::vector<T> res;
		T d = to;
	 	res.push_back(d);
	 	while (d != src)
	 	{
	 		d = lastNodes[d];
	 		res.push_back(d);
	 	}


	 	return vector::reverse(res);

	}
	else
	{
		return std::vector<T>(0);
	}
	return std::vector<T>(0);
}

// template<typename T>
// inline bool Graph<T>::bfs(std::vector<std::vector< std::pair<bool, double> >>rGraph, int s, int t, std::vector<int>& parent)
// {
// 	// std::vector<bool> visited = vector::createVector(m_nodes.size(), false);

// 	// std::queue<int> q;
// 	// q.push(s);
// 	// visited[s] = true;
// 	// parent[s] = -1;

// 	// while (!q.empty())
// 	// {
// 	// 	int u = q.front();
// 	// 	q.pop();

// 	// 	for (int v = 0; v < m_nodes.size(); v++)
// 	// 	{
// 	// 		if (visited[v] == false && rGraph[u][v].first && rGraph[u][v].second > 0)
// 	// 		{
// 	// 			q.push(v);
// 	// 			parent[v] = u;
// 	// 			visited[v] = true;
// 	// 		}

// 	// 		else if (visited[v] == false && rGraph[v][u].first && rGraph[v][u].second < m_edges[v][u].second)
// 	// 		{
// 	// 			q.push(v);
// 	// 			parent[v] = u;
// 	// 			visited[v] = true;
// 	// 		}
// 	// 	}
// 	// }
// 	// return (visited[t] == true);
// 	return true;
// }

// template<typename T>
// inline std::pair<double, std::vector<std::vector< std::pair<bool, double> >> > Graph<T>::fordFulkerson(T source, T puit, std::vector<std::pair<std::pair<T, T>, double>> minConstraint)
// {
// 	typename std::vector<T>::iterator it1 = std::find(m_nodes.begin(), m_nodes.end(), source);
// 	typename std::vector<T>::iterator it2 = std::find(m_nodes.begin(), m_nodes.end(), puit);

// 	std::vector < std::pair < std::pair<int, int>, double> > minConstraintIndexed;

// 	if (it1 != m_nodes.end() && it2 != m_nodes.end())
// 	{
// 		int s = distance(m_nodes.begin(), it1);
// 		int t = distance(m_nodes.begin(), it2);

// 		int u, v;
// 		std::vector<std::vector< std::pair<bool, double> >> rGraph = m_edges;

// 		std::vector<int> parent(m_nodes.size());
// 		double max_flow = 0;

// 		while (bfs(rGraph, s, t, parent))
// 		{
// 			double path_flow = INT_MAX;
// 			for (v = t; v != s; v = parent[v])
// 			{
// 				u = parent[v];
// 				path_flow = std::min(path_flow, rGraph[u][v].second);
// 			}
// 			for (v = t; v != s; v = parent[v])
// 			{
// 				u = parent[v];

// 				rGraph[u][v].second -= path_flow;
// 				rGraph[v][u].second += path_flow;
// 			}
// 			max_flow += path_flow;
// 		}


// 		return std::make_pair( max_flow, rGraph);
// 	}
// 	return std::make_pair(0, std::vector<std::vector< std::pair<bool, double> >>(0) );
	
// }

template<typename T>
inline double Graph<T>::getDistance(const std::vector<T>& path) const
{
	double res = 0;
	for (size_t i = 0; i < path.size() - 1; i++)
	{
		auto it1 = m_nodes.find(path[i]);
		auto it2 = m_nodes.find(path[i+1]);

		int index_other = it1->second.findNode(&(it2->second));

		if (index_other == -1 )return 0;

		res += m_nodes.at(path[i]).getAdjNodes()[index_other].second;
	}
	return res;
}


template<typename T>
inline bool Graph<T>::isConnexe() const
{
	if (m_nodes.size() == 0)
		return true;
	// on verifie que tout les noeud sont biens conectés à l'ensemble du graph


	// on crée un tableau de bool (marqueurs) initialisées à false
	std::set<T> m_nodesOk;
	
	// on fait un parcours en profondeur du graphe en partant du noeud 0
	// à chaques fois qu'on atteint un noeud, on note qu'il à été visité
	// si à la fin, des noeuds sont non visité, le graph n'est pas connexe

	std::queue<T> file;
	file.push(m_nodes.begin()->first);
	while (file.size() > 0)
	{
		T sommet = file.front();
		file.pop();
		m_nodesOk.insert(sommet);

		auto node = m_nodes.at(sommet);

		for (size_t i = 0; i < node.getAdjNodes().size(); i++)
		{
			// si le neoud n'est pas marqué et que l'arête entre sommet et i existe
			if (m_nodesOk.find(node.getAdjNodes()[i].first->getValue()) == m_nodesOk.end())
			{
				file.push(node.getAdjNodes()[i].first->getValue());
				m_nodesOk.insert(node.getAdjNodes()[i].first->getValue());
			}
		}
	}

	return m_nodesOk.size() == m_nodes.size();
}

}}
	