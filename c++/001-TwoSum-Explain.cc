
/*********************************************************************
< unordered map >
--- kind of similar to dictionary, is an associative container 
--- that contains the key value and the corresponding mapped value

key value: usually to identify the value/element
mapped value: the value associated with the key

member function

capacity---------
indicies.empty();
indicies.size();
indicies.max_size()

iterator----------
indicies.begin();
indicies.end();   //  "returns a past-the-end element"
                        does not point to any element, 
                        NULL, should not be dereferenced
indicies.cbegin();
indicies.cend();

element lookup---------
indicies.find(Key value); 
indicies.count(Key value); // elements with a specific key
indicies.equal()

**********************************************************************/

#include <unordered_map>
#include <vector>
#include <iostream>


int main() {

    //begin, end demonstration
    unordered_map<string, string> mymap;
    mymap = {{"Australia", "Canberra"}, {"U.S.", "Washington"},
            {"France", "Paris"}};
    
    cout << "mymap contains:",
    for (auto it = mymap.begin(); it != mymap.end(); ++it){
        cout << " " << it->first << ":" << it->second;
    }
    cout << endl;
        // expected output :
        // mymap contains: France:Paris Australia:Canberra U.S.:Washington


    // find demonstration
    auto got = mymap.find("France"); 
        //auto = std::unordered_map<std::string, double>::const_iterator 
    if (got == mymap.end())
        cout << "not found";
    else 
        cout << "Capital of " << got->first() << " is " << got->second();
    cout << endl;
        // expected output:
        // Capital of France is Paris
}
