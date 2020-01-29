// PlayerList.cpp

#include "PlayerList.h"

#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::pair;
#include <string>
using std::string;

int PlayerList::read_file(const std::string & file_name)
{
    ifstream ifs(file_name);
    if (!ifs) // no file
    {
        cout << "file does not exist";
        return 0;
    }
    int current_year;
    ifs >> current_year;
    cout << current_year;
    ifs.get();
    int num_entries;
    ifs >> num_entries;
    ifs.get(); // \n
    for (int i = 0; i < num_entries; i++) {
        PlayerInfo new_entry;
        ifs >> new_entry;
        new_entry.setcategory(current_year);
        m_entries_.insert(m_entries_.end(),
                          {new_entry.name, new_entry});
    }
    itr_current_entry_ = m_entries_.begin();
    return current_year;
}

void PlayerList::display_stats()
{
    int numbers[14] = { };
    for(auto x : m_entries_)
    {
        if (x.second.status == "paid" )
        {
            ++numbers[0];
            switch (x.second.category)
            {
                case 6: {
                    ++numbers[2];
                    break;
                }
                case 8: {
                    ++numbers[4];
                    break;
                }
                case 10: {
                    ++numbers[6];
                    break;
                }
                case 12: {
                    ++numbers[8];
                    break;
                }
                case 14: {
                    ++numbers[10];
                    break;
                }
                case 17: {
                    ++numbers[12];
                    break;
                }
            }
        }
        if (x.second.status == "not paid")
        {
            ++numbers[1];
            switch (x.second.category)
            {
                case 6: {
                    ++numbers[3];
                    break;
                }
                case 8: {
                    ++numbers[5];
                    break;
                }
                case 10: {
                    ++numbers[7];
                    break;
                }
                case 12: {
                    ++numbers[9];
                    break;
                }
                case 14: {
                    ++numbers[11];
                    break;
                }
                case 17: {
                    ++numbers[13];
                    break;
                }
            }
        }
    }

    std::cout << "category / paid / not paid / total" << std::endl
         << "all players: " << numbers[0] << " / " << numbers[1] << " / " << numbers[1] + numbers[0] << std::endl
        << "U6: " << numbers[2] << " / " << numbers[3] << " / " << numbers[3] + numbers[2] << std::endl
        << "U8: " << numbers[4] << " / " << numbers[5] << " / " << numbers[4] + numbers[5] << std::endl
        << "U10: " << numbers[6] << " / " << numbers[7] << " / " << numbers[6] + numbers[7] << std::endl
        << "U12: " << numbers[8] << " / " << numbers[9] << " / " << numbers[8] + numbers[9] << std::endl
        << "U14: " << numbers[10] << " / " << numbers[11] << " / " << numbers[10] + numbers[11] << std::endl
        << "U17: " << numbers[12] << " / " << numbers[13] << " / " << numbers[12] + numbers[13] << std::endl;

        std::cout << "Press enter to continue";
        std::cin.get();
}
/*
void PlayerList::write_file(const std::string & file_name) const
{
    cout << "Saving not yet implemented\n";
}
*/
