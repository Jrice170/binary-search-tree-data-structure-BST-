/* A demo of a similar main with std::map and std::pair
 * Play around with the real one if you are curious.
 * A couple non-std:: things have been commented. The rest behaves similarly.
 */

#include <map>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    std::map<int, std::string> map_obj;

    map_obj.insert(std::pair<int, std::string>(3, "h"));
    map_obj[54].push_back('w');
    map_obj[34] = "x";
    map_obj.at(34) = "y";

    // What is the type of temp? std::pair templated how?
    auto temp = map_obj.find(34);
    cout << temp->first << " " << temp->second << endl;

    map_obj.erase(34);
    //cout << (map_obj.find(34) == nullptr) << endl;

    std::map<int, std::string> map_obj2(map_obj);

    std::map<int, std::string> map_obj3;
    map_obj3 = map_obj2 = map_obj; 

    //map_obj2.print();
    cout << "Size is: " << map_obj2.size() << endl;
    cout << "Count for 54 is: " << map_obj2.count(54) << endl << endl;

    map_obj.clear();

    //map_obj.print();
    cout << "Size is: " << map_obj.size() << endl;
    cout << "Count for 57 is: " << map_obj.count(57) << endl;

    try
    {
        map_obj.at(734) = "k";
    }
    catch(const std::out_of_range &e)
    {
        cout << e.what();
    }

    return 0;
}

