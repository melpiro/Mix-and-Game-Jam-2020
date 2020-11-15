#include "Tilemap.h"


void Tilemap::initGraph(JsonData& j)
{
    m_mapGraph = O::math::Graph<int>();

   

    JsonData graph = j["graph"];
    std::vector<JsonData> nodes = *(std::vector<JsonData>*) graph["nodes"].getValue();
    std::vector<JsonData> edges = *(std::vector<JsonData>*) graph["edges"].getValue();

    for (size_t i = 0; i < nodes.size(); i++)
    {
       
        sf::Vector2i podnode(
            *(double*)nodes[i]["x"].getValue(),
            *(double*)nodes[i]["y"].getValue()
        );
        m_graphNodePos[i] = podnode;

        m_mapGraph.addNode(i);

        m_nodesDebug.push_back(sf::CircleShape(10));
        m_nodesDebug.back().setOrigin(10,10);
        m_nodesDebug.back().setFillColor(sf::Color::Red);
        m_nodesDebug.back().setPosition((sf::Vector2f) podnode * 64.f + sf::Vector2f(32.f, 32.f));
    }


    for (size_t i = 0; i < edges.size(); i++)
    {
        std::vector<JsonData> edge = *(std::vector<JsonData>*)edges[i].getValue();


        auto n1 = sf::Vector2i(
                *(double*)edge[0]["x"].getValue(),
                *(double*)edge[0]["y"].getValue());
        auto n2 = sf::Vector2i(
                *(double*)edge[1]["x"].getValue(),
                *(double*)edge[1]["y"].getValue());

        int idN1 = -1;
        int idN2 = -1;

        for (auto node:m_graphNodePos)
        {
            if (node.second == n1)
            {
                idN1 = node.first;
            }
            if (node.second == n2)
            {
                idN2 = node.first;
            }
            if (idN1 != -1 && idN2 != -1) break;
        }
        

        m_mapGraph.addEdges(
            idN1, idN2, O::math::getDistance((sf::Vector2f) n1,(sf::Vector2f) n2)
        );
        m_mapGraph.addEdges(
            idN2, idN1, O::math::getDistance((sf::Vector2f) n1,(sf::Vector2f) n2)
        );

        m_edgeDebug.push_back( O::graphics::Line(
            m_fen, (sf::Vector2f)n1 * 64.f + sf::Vector2f(32.f, 32.f), (sf::Vector2f)n2  * 64.f + sf::Vector2f(32.f, 32.f), 4
        ));
        m_edgeDebug.back().setFillColor(sf::Color(0,0,0,70));
    }


}

std::map<int, sf::Vector2i>* Tilemap::getGraphNodePos()
{
    return &m_graphNodePos;
}
O::math::Graph<int>* Tilemap::getGraph()
{
    return &m_mapGraph;
}