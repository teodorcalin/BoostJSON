#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

using namespace std;
namespace pt = boost::property_tree;

int main()
{
    pt::ptree t;
    t.put("sw ver", "2031788");
    t.put("fw ver", "1260090");
    t.put("model", "XRPAD3");
    t.put("gen", 2);

    cout << t.get_child("sw ver").get_value<string>() << endl;
    cout << t.get<int>("gen") << endl;
    ostringstream oss;
    pt::write_json(oss, t);
    cout << oss.str() << endl;


    vector<string> fruits {"apple", "raspberry", "orange"};
    map<string, string> animals { {"rabbit", "white"}, {"dog", "brown"}, {"cat", "grey"} };

    pt::ptree root_node;

    pt::ptree animals_node;
    for(auto& animal : animals)
        animals_node.put(animal.first, animal.second);
    root_node.add_child("animals", animals_node);

    pt::ptree fruits_node;
    for(auto& fruit : fruits)
    {
        pt::ptree fruit_node;
        fruit_node.put("", fruit);
        fruits_node.push_back(make_pair("",fruit_node));
    }
    root_node.add_child("fruits", fruits_node);

    pt::ptree fish_node;
    auto fishes =  {"bream", "pike", "trout", "salmon"};
    for (auto& fish : fishes)
    {
        fish_node.push_back(make_pair("fish", pt::ptree(fish)));
    }
    root_node.add_child("fish", fish_node);

    pt::write_json(cout, root_node);

    return 0;
}
