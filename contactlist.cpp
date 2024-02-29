#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void addContact();
void editContact();
void deleteContact();
void searchContact();
void viewContact();

class roloentry
{
    private:
    std::vector<roloentry> rolodex;
    string fname, lname;
    string search_name;
    private:
    string street, city, state;
    signed int zip;
    string phone, email;
    public:
        string get_fname()
        {
            return fname;
        }
       string get_num()
       {
            return phone;
       }
       string get_email()
       {
            return email;
       }

    void addContact()
    {
        cout << "Enter first name: \n";
        cin >> fname;
        cout << "Enter last name: \n";
        cin >> lname;
        cout << "Enter your house number and street: \n";
        ws(cin);
        getline(cin, street);
        cout << "Enter city: ";
        cin >> city;
        cout << "Enter state: ";
        cin >> state;
        cout << "Enter zip code: ";
        cin >> zip;
        cout << "Enter phone number: ";
        cin >> phone;
        cout << "Enter email: ";
        cin >> email;
        cout << fname << " " << lname << '\n';
        cout << street << '\n';
        cout << city << ", " << state << " " << zip << endl;
        cout << phone << "\n" << email << endl;

    }
    void editContact()
    {
     string answer;   
 cout << "What do you want to edit? ";
 getline(cin, answer);
    if (answer == "Phone number")
{
    cout << "Enter new number: ";
    cin >> phone;
}
    else if (answer == "Email")
{
    cout << "Enter new email: ";
    cin >> email;
}
    else if (answer == "Address")
{
    cout << "Enter street: ";
    ws(cin);
    getline(cin, street);
    cout << "Enter city: ";
    ws(cin);
    getline(cin, city);
    cout << "Enter state: ";
    cin >> state;
    cout << "Enter zip code: ";
    cin >> zip;
}
    else if (answer == "Name: ")
 {
    cout << "Enter first name: ";
    cin >> fname;
    cout << "Enter last name: ";
    cin >> lname;
 }   
    else
{
    cout << "\nQuit";
}

}
    void deleteContact()
    {
       char yesno;
       string search_name;
       size_t i = 0;
       cout << "Enter name of person you wish to delete: ";
       cin >> search_name;
       while (i != rolodex.size() && rolodex[i].get_fname()
       != search_name)
       {
        i++;
       }
       if (i < rolodex.size())
       {
            cout << "Name: \n" << search_name << "\n";
            cout << "Delete this contact? \n";
            cin >> yesno;
            yesno = static_cast<char>(toupper(yesno));
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (yesno == 'Y')
            {
                rolodex.pop_back();
            }
            else
            {
                cout << "Error";
            }
       }

    }

    void searchContact(std::vector<roloentry> & rolodex)
    {
        bool done;
        char subchoice;
        done = false;

        while (! done)
        {
            cout << " Search Sub-Menu: \n"
            " 1) Search by First Name\n"
            " 2) Search by Phone number\n"
            " 3) Search by Email\n"
            " 4) Quit\n"
            "Choice: \n";

            cin >> subchoice;

            subchoice = static_cast<char>(toupper(subchoice));
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (subchoice == '1' || subchoice == 'F')
            {
                cout << "Option 1 Search by First Name Chosen!\n\n";
                string search_name;
                size_t i = 0;
                cout << "Enter first name: ";
                cin >> search_name;
                while (i != rolodex.size()&& rolodex[i].get_fname()
                != search_name)
                {
                    i++;
                }
                if (i < rolodex.size())
                {
                    cout << "Name found: \n" << search_name << "\n";
                    viewContact();
                }
                else
                {
                    cout << "Name not found!\n";
                }
            }
            else if (subchoice == '2' || subchoice == 'P')
            {
                cout << "Option 2 Search by Phone Number Chosen!\n\n";
                string search_num;
                size_t i = 0;
                cout << "Enter phone number: ";
                cin >> search_num;
                while (i != rolodex.size() && rolodex[i].get_num()
                != search_num)
                {
                    i++;
                }
                if (i < rolodex.size())
                {
                    cout << "Number found: \n" << search_num << "\n";
                    viewContact();
                }
                else
                {
                    cout << "Number not found!\n";
                }
            }
            else if (subchoice == '3' || subchoice == 'E')
            {  
                cout << "Option 3 Search by Email Chosen!\n\n";
                string search_email;
                size_t i = 0;
                bool leaving;
                cout << "Enter email: ";
                cin >> search_email;
                while (i != rolodex.size() && rolodex[i].get_email()
                != search_email)
                {
                    i++;
                }
                if (i < rolodex.size())
                {
                    cout << "Email found: \n" << search_email << "\n";
                    viewContact();
                }
                else
                {
                    cout << "Email not found!\n";
                }
            }
            else
            {
                cout << "Option 4 || Quit\n\n";
                done = true;
            }

        }
        
    }
    void viewContact()
   {
    
        cout << "Name: " <<fname<< " "<<lname<<endl;
        cout << "Address: " <<street<< " "<<city<< " "<<state<< " "<<zip<<endl;
        cout << "Phone number: " <<phone<<endl;
        cout << "Email: " <<email<<endl;
        for (const auto& roloentry : rolodex)
        {
            std::cout << "Name: " <<fname<< " " <<lname;
   };

   }

};

int main ()
{
   
    roloentry r;
    vector<roloentry> rolodex;
    char choice;
    bool done = false;
    
    cout << "Address Book: \n";
    cout << "**************************** \n";

    while (! done)
    {
        cout << "Main Menu\n"
        "1) Add entry\n"
        "2) Edit entry\n"
        "3) Delete entry\n"
        "4) Search for entry\n"
        "5) Print all entries\n"
        "6) Quit\n"
        "Choice: ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        choice = static_cast<char>(toupper(choice));
        if (choice == '1' || choice == 'A')
        {
            cout << "\nOption 1 -- Add entry -- Chosen!\n\n";
            r.addContact();
            rolodex.push_back(r);
        }
        else if (choice == '2' || choice == 'E')
        {
            cout << "\nOption 2 -- Edit entry -- Chosen!\n\n";
            r.editContact();
        }
        else if  (choice == '3' || choice == 'D')
        {
            cout << "\nOption 3 -- Delete entry -- Chosen!\n\n";
            r.deleteContact();
        }
        else if (choice == '4' || choice == 'S')
        {
            cout << "\nOption 4 -- Search entry -- Chosen!\n\n";
           
            r.searchContact(rolodex);
            
        }
        else if (choice == '5' || choice == 'P')
        {
            cout << "\nOption 5 -- Print all entries -- Chosen!\n\n";
            
            for(size_t i = 0; i < rolodex.size(); i++) {
                rolodex[i].viewContact();
                r.viewContact();
            }

        }
        else
        {
            cout << "\nOption 6 || Quit\n\n";
            return 0;
        }


    }

}
