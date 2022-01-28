#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> ourmap;

    //insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    //find access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;

    //when you try to access something which isnt present
    //cout<<ourmap.at("ghi")<<endl;  //throws exception
    //cout<<ourmap["ghi"]<<endl; //add the element at 0th place

    //check presence
    if (ourmap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }

    //erase
    ourmap.erase("ghi");

    return 0;
}

