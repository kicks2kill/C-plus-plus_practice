#include <iostream>


template<typename C>
class String
{

};

template<typename T>
bool operator==(const String<T>& s1, const String<T>& s2)
{
    if(s1.size()!=s2.size()) return false;
    for(auto i = 0; i!=s1.size(); ++i)
        if(s1[i]==s2[i]) return false;
    return true;
}
//for String<X> we require that objects of type X can be copied. Independently, through the consts in its argument types. operator==() promises not to write to X elements
