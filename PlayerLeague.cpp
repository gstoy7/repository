// PhoneBook.cpp

#include "PlayerLeague.h"

using namespace std;

void PlayerLeague::run()
{
    current_year_ = entry_list_.read_file(cs_file_name);
    bool done = false;
    if(current_year_ == 0)
        done = true;
    browsing_view_ = true;
    while (!done) {
        display_entry_and_menu();
        cout << "choice: ";
        char command;
        cin >> command;
        cin.get(); // new line char
        execute(command, done);
        cout << endl;
    }
}

void PlayerLeague::display_entry_and_menu() const {
    string long_separator(50, '-');
    string short_separator(8, '-');

    system(clear_command);

    cout << current_year_ << " Season" << endl
        << "rank goes here? x/x" << endl
        << short_separator << endl;

    entry_list_.display_current_entry();

    cout << long_separator << endl
         << "  previous(p)   next(n)    edit(e)    quit(q)\n"
         << "  add(a)   delete(d)   search(s)\n"
         << (browsing_view_ ? "  start new season(y)   display stats(t)\n" : "  exit search(x)\n")
         << short_separator << endl;
}

void PlayerLeague::execute(char command, bool & done)
{
    switch (command) {
        case 'n': {
            entry_list_.move_to_next();
            break;
         }
        case 'p': {
            // Not yet implemented
	    // bet
	    entry_list_.move_to_previous();
            break;
         }
        case 'e': {
            // Not yet implemented
            if (entry_list_.empty())
                return;
            cout << "New name: ";
            string new_name;
            getline(cin, new_name);
//            entry_list_.edit_current(new_name);
	    
	    cout << "New Date of Birth: ";
	    int new_DOB;
	    cin >> new_DOB;
	    cin.get();
//	    entry_list_.edit_current(new_DOB);
	    
	    cout << "New status: ";
   	    string new_status;
	    getline(cin, new_status);
//	    entry_list_.edit_current(new_status);
	    entry_list_.edit_current(new_name, new_DOB, new_status);
            break;
        }
        case 's': {
            // Not yet implemented
	    //is MOSTLY funtional
            cout << "Criteria (name(n), birth year(b), registration(r), category(c)): ";
            char choice;
	    cin >> choice;
	    cin.get();
            if(choice == 'n'){
		cout << "Name: ";
		string name;
		getline(cin, name); 
	        entry_list_.find(name);
	    }
	    else if(choice == 'b'){
	        cout << "Birth Year: ";
		int year;
		cin >> year;
		cin.get();
		entry_list_.find_year(year);
	    }
	    else if(choice == 'r'){
		cout << "Registration status (Paid/Not Paid): ";
		string status;
		getline(cin, status);
		entry_list_.find_status(status);
	    }
	    else if(choice == 'c'){
		cout << "Age Group 12, 14, etc.): ";
		int age_group;
		cin >> age_group;
		entry_list_.find_age(age_group);
	    }
	    else{
		cout << "Invalid selection";
	    }
            break;
        }
        //SEARCH VIEW?
        case 'a': {
            cout << "Name: ";
            string new_name;
            getline(cin, new_name);
            cout << "Year of birth: ";
            int new_yearofbirth;
            cin >> new_yearofbirth;
            cin.get();
            cout << "Paid/not paid: ";
            string new_status;
            getline(cin, new_status);
            if (current_year_ - new_yearofbirth > 3 && current_year_ - new_yearofbirth < 17)
                entry_list_.add(new_name, new_yearofbirth, new_status, current_year_);
            if (current_year_ - new_yearofbirth <= 3)
            {
                cout << "The child is too young. Press enter to continue";
                cin.get();
            }
            if (current_year_ - new_yearofbirth >= 17)
            {
                cout << "The person is too old. Press enter to continue";
                cin.get();
            }
            break;
        }
        //SEARCH VIEW?
        case 'd': {
            cout << "Are you sure you want to delete this players? (y/n): ";
            char choice;
            cin.get(choice);
            cin.get();
            if(choice == 'y')
            {
                entry_list_.delete_entry();
            }
            break;
        }
        case 'q': {
            cout << "Filename: ";
	    string cs_file_name;
	    getline(cin, cs_file_name);
            entry_list_.write_file(cs_file_name);
            done = true;
            break;
        }
        case 'y': {
            if(!browsing_view_)
            {
                cout << "Invalid command. Press enter to continue.";
                cin.get();
                break;
            }
            cout << "Are you sure you want to delete all existing players? (y/n): ";
            char choice;
            cin.get(choice);
            cin.get();
            if(choice == 'y')
            {
                cout << "Enter year of new season: ";
                cin >> current_year_;
                cin.get();
                entry_list_.clear_entries();
            }
            break;
        }
        case 'w': {
	    cout << "Filename: ";
	    std::string file_name;
	    cin >> file_name;  
            entry_list_.write_file(file_name);
	    //THIS IS THE EXACT SAME AS PRINT?
            break;
        }
        case 't': {
            if(!browsing_view_)
            {
                cout << "Invalid command. Press enter to continue.";
                cin.get();
                break;
            }
            entry_list_.display_stats();
            break;
        }
        case 'x': {
            browsing_view_ = true;
            break;
        }
/*	case 'z': {
	    cout << "Filename: ";
	    string print_file;
	    getline(cin, print_file);
	    entry_list_.print_entries(print_file);
	    break; 
	}
*/
        default: {
            cout << "Invalid command. Press enter to continue.";
            cin.get();
        }
    }
}

