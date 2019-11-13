#include <iostream>
#include <sstream>
#include <string>
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
    return 0;
}
