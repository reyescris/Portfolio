#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;
constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};
char choice (void)
{
    char ch;
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return static_cast<char>(toupper(ch));

}
int main ()
{
    char yes_no;
    char yes_no_again;
    char wash_cho;

    short top = rand() % (999-100+1) + 100, bottom = rand() % 1000;
    long final = top * 1000L + bottom; 
    srand(static_cast<unsigned>(time(nullptr)));
    final = rand();

    cout << "Would you like to get your car washed?  ";
    cin >> yes_no;
    cin.ignore(INF_FLAG, '\n');
    cout << "You have selected:  " << yes_no << "\n"
            "\nAnswer remains the same?\n";
    cin >> yes_no_again;

    while ( toupper (yes_no_again) == 'N')
    {
        return 0;
    }
    cin.ignore(INF_FLAG, '\n');
    while ( toupper (yes_no) != 'N')
    {
        cout << "Super, Premium, or Ultra?  ";
        cin >> wash_cho;
        cin.ignore(INF_FLAG, '\n');
    
    if (wash_cho == 'S')
{
     cout << "Your total is $6.00 \n";
}
else if (wash_cho == 'P')
{
    cout << "Your total is $9.00 \n";
}
else if (wash_cho == 'U')
{
    cout << "Your total is $12.00 \n";
}
else
{
    cout << "Invalid choice please select again '\n'";
}
cout << "Would you like to go through the wash again?  ";
        cin >> yes_no;
        cin.ignore(INF_FLAG, '\n');
    

cout << "\nThank you for using Spotless Car Wash!!!\n"
        "Here is your wash code:  " << final << "\n"
        "\nPlease come again!!!\n";
    }

cout << "\nThank you for using Spotless Car Wash!!!\n"
        "\nPlease come again!!!\n";
        
        return 0;







}
