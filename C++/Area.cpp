#include <iostream>
#include <iomanip>

using namespace std;


int square(){
    double side;
    cout << "Enter side of square(m): ";
    cin >> side;
    cout << "Area of square is: " << side * side << "m" <<endl;
    return 0;
}

int rectangle(){
    double length, breadth;
    cout << "Enter Length of rectangle(m): ";
    cin >> length;
    cout << "Enter Breath of rectangle(m): ";
    cin >> breadth;
    cout << "Area of rectangle is: " << length * breadth << "m" <<endl;
    return 0;
}

int circle(){
    double radius;
    cout << "Enter radius of circle(m): ";
    cin >> radius;
    cout << "Area of circle is: " << 2 * 3.14 * radius << "m" <<endl;
    return 0;
}

int triangle(){
    double base, height;
    cout << "Enter Base of triangle(m): ";
    cin >> base;
    cout << "Enter Height of triangle(m): ";
    cin >> height;
    cout << "Area of triangle is: " << 0.5 * base * height << "m" <<endl;
    return 0;
}

int main(){
    int choice;
    while (choice != 5)
    {
        cout << "1. Square" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Circle" << endl;
        cout << "4. Triangle" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            square();
            break;
        case 2:
            rectangle();
            break;
        case 3:
            circle();
            break;
        case 4:
            triangle();
            break;
        case 5:
            break;
        
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
    return 0;
}