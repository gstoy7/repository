// PlayerInfo.h

#ifndef _PlayerInfo_h_
#define _PlayerInfo_h_

#include <fstream>
#include <string>
#include<iostream>

class PlayerInfo
{
public:



    PlayerInfo() : name("no name"), yearofbirth(9999), status("not paid"), category(0) {}

    PlayerInfo(const std::string & name0,
                   int year0, const std::string & status0, int current_year) :
        name(name0), yearofbirth(year0), category(0), status(status0) {setcategory(current_year);}

    void setcategory(int current_year);

    std::string name;
    int yearofbirth;
    std::string status;
    int category;
};

inline void PlayerInfo::setcategory(int current_year)
{
    ((current_year - yearofbirth) % 2 == 1 ? category = current_year - yearofbirth + 1 : category = current_year - yearofbirth + 2);
    if(category == 16 || category == 18)
        category = 17;
}

inline std::istream & operator>>(std::istream & in, PlayerInfo & e)
{
    getline(in, e.name);
    in >> e.yearofbirth;
    in.get();
    getline(in, e.status);
    return in;
}

inline std::ostream & operator<<(std::ostream & out,
                                 const PlayerInfo & e)
{
    out << e.name << std::endl
        << e.yearofbirth << std::endl
        << "U" << e.category << std::endl
        << e.status << std::endl;
    return out;
}

#endif

