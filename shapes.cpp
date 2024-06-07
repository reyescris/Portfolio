#include <iostream>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include "shapes.h"

using namespace std;

string good_word (const string& shape_choice)
{
    string lowercase_shape = shape_choice;

    transform(lowercase_shape.begin(), lowercase_shape.end(), 
    lowercase_shape.begin(), :: tolower);

    return lowercase_shape;
}
int main ()
{
    char choice;
    bool done = false;
   
    vector<Shape*> shapes;

   Shape *shapePtr = nullptr;

    while (! done)
    {
        cout << "Main Menu: \n"
        "1) Enter shape \n"
        "2) Delete shape \n"
        "3) Print current shapes \n"
        "4) Quit \n"
        "Choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        choice = static_cast<char>(toupper(choice));

        if (choice == '1' || choice == 'E')
        {
        
            bool sub_menu_done = false;
            while (! sub_menu_done)
            {
                cout << "Which shape? : \n"
                "1) Line \n"
                "2) Curve \n"
                "3) Circle \n"
                "4) Rectangle \n"
                "5) Sphere \n"
                "6) Cube \n"
                "7) Cone \n"
                "8) Back to Main Menu \n"
                "Choice: ";

                string shape_choice;

                cin >> shape_choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                shape_choice = good_word(shape_choice);

                if (shape_choice.substr(0,3) == "lin" || shape_choice
                == "1")
                {
                    cout << "You've selected line \n";
                    Point start, end;
                    start.Input();
                    cout << "Enter end point: \n";
                    end.Input();
                    shapes.push_back(new Line(start, end));
                    
                }
                else if (shape_choice.substr(0,3) == "cur" || shape_choice
                == "2")
                {
                    cout << "You've selected curve \n";
                    Point start, midpoint, end;
                    start.Input();
                    cout << "Enter midpoint: \n";
                    midpoint.Input();
                    cout << "Enter end point: \n";
                    end.Input();
                    Curve curve(start, midpoint, end);
                    shapes.push_back(new Curve(start, midpoint, end));
                }
                else if (shape_choice.substr(0,3) == "cir" || shape_choice
                == "3")
                {
                    cout << "You've have selected circle \n";
                    Point center;
                    double radius;
                    cout << "Enter center point: \n";
                    center.Input();
                    cout << "Enter radius of circle: \n";
                    cin >> radius;
                    shapes.push_back(new Circle(radius));
                }
                else if (shape_choice.substr(0,3) == "rec" || shape_choice
                == "4")
                {
                    cout << "You've selected rectangle \n";
                    double length, width;
                    cout << "Enter length of rectangle: \n";
                    cin >> length;
                    cout << "Enter width of rectangle: \n";
                    cin >> width;
                    shapes.push_back(new Rectangle(length, width));
                }
                else if (shape_choice.substr(0,3) == "sph" || shape_choice
                == "5")
                {
                    cout << "You've selected sphere \n";
                    double radius;
                    cout << "Enter radius: \n";
                    cin >> radius;
                    shapes.push_back(new Sphere(radius));
                }
                else if (shape_choice.substr(0,3) == "cub" || shape_choice
                == "6")
                {
                    cout << "You've selected cube \n";
                    double len_side;
                    cout << "Enter length of a side: \n";
                    cin >> len_side;
                    shapes.push_back(new Cube(len_side));
                }
                else if (shape_choice.substr(0,3) == "con" || shape_choice
                == "7")
                {
                    cout << "You've selected cone \n";
                    double radius, height;
                    cout << "Enter radius: \n";
                    cin >> radius;
                    cout << "Enter height: \n";
                    cin >> height;
                    shapes.push_back(new Cone(radius,height));
                    
                }
                else if (shape_choice.substr(0,3) == "bac" || shape_choice
                == "8")
                {
                    sub_menu_done = true;
                }
       
                else
                {
                    cout << "Invalid choice! \n";
                }
            }

        }
        else if (choice == '2' || choice == 'D')
        { 
            cout << "Here are the current shapes: \n";
            for (const auto& ptr : shapes)
            {
                ptr->print(std::cout);
                cout << "\n";
            }

            string delete_shape;
            
            cout << "Which shape do you want to delete? \n";
            getline(cin, delete_shape);

            bool shape_deleted = false;

            delete_shape = good_word(delete_shape);

            for (auto i = shapes.begin(); i != shapes.end(); ++i)
            {
                string shape_name = good_word((*i)->get_name());
                if (shape_name == delete_shape)
                {
                    delete *i;
                    shapes.erase(i);
                    shape_deleted = true;
                    break;
                }
            }
            if (shape_deleted)
            {
                cout << "Shape " << delete_shape << " deleted" << endl;
                delete shapePtr;
            }
            else
            {
                cout << "Shape " << delete_shape << " not found" << endl;
            }
        }

        else if (choice == '3' || choice == 'P')
        {
            if (shapes.empty())
            {
                cout << "Empty!" << endl;
            }
            else
            {
                cout << "Current shapes: \n";
                for (const auto& ptr : shapes)
                {
                    ptr->print(std::cout);
                    cout << "\n" << endl;
                }
            }
        }
        else
        {
            cout << "Thank you for using the Shapes Program!!!";
            return 0;
        }
    };


for (auto& shape : shapes)
{
    delete shape;
    shape = nullptr;
}

shapes.clear();

return 0;


}
