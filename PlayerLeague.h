// PlayerLeague.h

#ifndef _PlayerLeague_h_
#define _PlayerLeague_h_

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "PlayerList.h"

//const char clear_command[] = "cls"; // for Windows
const char clear_command[] = "clear"; // for Linux and possibly Mac's

const char cs_file_name[] = "players.txt";

class PlayerLeague
{
public:
    void run();

private:
    void display_entry_and_menu() const;
    void execute(char command, bool & done);

    PlayerList entry_list_;
    int current_year_;
    bool browsing_view_;
};

#endif

