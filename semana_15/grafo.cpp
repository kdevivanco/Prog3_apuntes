//
// Created by MacBookPro on 4/07/23.
//
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <forward_list>

using namespace std;
template <typename ValueType, typename WeightType, typename KeyType>
class grafo{
    using VertexType = size_t;
    using AdjacentType = pair<VertexType,WeightType>;
    using ItemType = pair<VertexType, ValueType>;

    unordered_map<KeyType, ItemType > vertices;

    vector<forward_list<AdjacentType>> adjacents;

public:
    grafo() = default;
    bool add_vertex(pair<KeyType,ValueType> node) {
        if (vertices.find(node.first) == end(vertices)) {
            auto item = pair{size(adjacents, node.second)};
            vertices.emplace(node.first, item);
            adjacents.emplace_back();
//            return true;
        }
    }


};