/* main and it's supporting extras
 * This is just for testing, and is not the graded part!
*/

#include "MyMap.h"


int main()
{
    std::string my_id[2];
    get_identity(my_id);
    std::cout <<  my_id[0] << "-" << my_id[1] << std::endl;

    MyMap<int, std::string> map_obj;

    map_obj.insert(MyPair<int, std::string>(3, "h"));
    map_obj[54].push_back('w');
    map_obj[34] = "x";
    map_obj[54] = "x";
    map_obj[154] = "p";
    map_obj[73] = "w";
    map_obj[5] = "a";
    map_obj[36] = "x";
    map_obj[32] = "x";
    map_obj[84] = "x";
    map_obj.at(34) = "y";

    const MyPair<int, std::string> *temp = map_obj.find(34);
    cout << temp->first << " " << temp->second << endl;

    map_obj.erase(34);
    cout << (map_obj.find(34) == nullptr) << endl;

    MyMap<int, std::string> map_obj2(map_obj);

    MyMap<int, std::string> map_obj3;
    map_obj3 = map_obj2 = map_obj; 

    cout << "==== printing tree ====" << endl;
    
    map_obj2.print();

    cout << "==== done printing tree ====" << endl;

    cout << "Size is: " << map_obj2.size() << endl;
    cout << "Count for 32 is: " << map_obj2.count(32) << endl << endl;

    map_obj.clear();

    cout << "==== printing tree ====" << endl;
    map_obj.print();
    cout << "==== done printing tree ====" << endl;

    cout << "Size is: " << map_obj.size() << endl;
    cout << "Count for 57 is: " << map_obj.count(57) << endl;

    try
    {
        map_obj.at(34) = "k";
    }
    catch(const std::out_of_range &e)
    {
        cout << e.what();
    }

    return 0;
}

