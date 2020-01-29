// PlayerList.h

#ifndef _PlayerList_h_
#define _PlayerList_h_

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "PlayerInfo.h"

class PlayerList
{
public:
    PlayerList() : itr_current_entry_(m_entries_.end()) {}

    void add(const std::string & name, const int & yearofbirth, const std::string & status, const int current_year);
    void display_current_entry() const;
    void move_to_next();
    void move_to_previous();
    void edit_current(const std::string & new_number, const int & new_DOB, const std::string & new_status);
    void find(const std::string & name);
    void find_age(const int & age_group);
    void find_year(const int & year);
    void find_status(const std::string & status);
    bool empty() const { return m_entries_.empty(); }
    int read_file(const std::string & file_name);
    void write_file(const std::string & cs_file_name) const;
    void clear_entries();
    void delete_entry();
    void display_stats();
    void print_entries(const std::string & print_file);

private:
    std::map<std::string, PlayerInfo> m_entries_;
    std::map<std::string, PlayerInfo>::iterator
        itr_current_entry_;
//    std::map<std::string, PlayerInfo> search_map;
};

inline void PlayerList::add(const std::string & name, const int & yearofbirth, const std::string & status, const int current_year)
{
    auto result = m_entries_.insert({name, {name, yearofbirth, status, current_year}});
    itr_current_entry_ = result.first;
}

inline void PlayerList::display_current_entry() const
{
    if (m_entries_.empty())
        return;
    std::cout << itr_current_entry_->second;
}

inline void PlayerList::move_to_next()
{
    if (m_entries_.empty())
        return;
    ++itr_current_entry_;
    if (itr_current_entry_ == m_entries_.end())
        itr_current_entry_ = m_entries_.begin();
}

inline void PlayerList::move_to_previous()
{
    if(m_entries_.empty())
	return;
    auto itr = itr_current_entry_;
    if(itr == m_entries_.begin()){
	itr = m_entries_.end();
        --itr;
    }
    else{
	--itr;
    }
    itr_current_entry_ = itr;
/*
    itr++;
    while(next(itr) != itr_current_entry_){
	if(itr == m_entries_.end())
		itr = m_entries_.begin();
	else
		itr++;
    }
    itr_current_entry_ = itr;
*/
}

inline void PlayerList::edit_current(
        const std::string & new_name, const int & new_DOB, const std::string & new_status)
{
    itr_current_entry_->second.name = new_name;
    itr_current_entry_->second.yearofbirth = new_DOB;
    itr_current_entry_->second.status = new_status;
}

inline void PlayerList::find(const std::string & name)
{
    auto itr = m_entries_.find(name);
    if (itr != m_entries_.end())
        itr_current_entry_ = itr;
}

void PlayerList::find_year(const int & year)
{
//    auto itr = m_entries.begin();
    for(auto itr = m_entries_.begin(); itr != m_entries_.end(); itr++)
    {
	auto player = (*itr).second;
	if(player.yearofbirth == year){
	    itr_current_entry_ = itr;
//	    search_map.insert(itr_current_entry_, player);
	    break;
	}
    }
}

void PlayerList::find_status(const std::string & status)
{
    for(auto itr = m_entries_.begin(); itr != m_entries_.end(); itr++)
    {
	auto player = (*itr).second;
        if(player.status == status){
            itr_current_entry_ = itr;
	    break;
	}
    }
}

void PlayerList::find_age(const int & age_group)
{
    for(auto itr = m_entries_.begin(); itr != m_entries_.end(); itr++)
    {
	auto player = (*itr).second;
        if(player.category == age_group){
            itr_current_entry_ = itr;
	    break;
	}
    }
}

inline void PlayerList::clear_entries()
{
    m_entries_.clear();
    //make itr null? it wont let me?
}

inline void PlayerList::delete_entry()
{
    itr_current_entry_ = m_entries_.erase(itr_current_entry_);
    if(itr_current_entry_ == m_entries_.end())
        itr_current_entry_ = m_entries_.begin();
}
/*
inline void PlayerList::print_entries(const std::string & print_file)
{
    std::ofstream out;
    out.open(print_file);
    for(auto t : m_entries_)
        out << t.second << std::endl;
    out.close();
}
*/

void PlayerList::write_file(const std::string & cs_file_name)const
{
    std::ofstream out;
    out.open(cs_file_name);
     
    for(auto t : m_entries_)
	out << t.second << std::endl;
    out.close();
}

#endif
