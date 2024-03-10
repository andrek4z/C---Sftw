#include <iostream>
#include <list>

using namespace std;

// Function to calculate the factorial of a number
int factorial(int n) 
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Class to represent a student
class Student 
{
    private:
        string name;
        int age;

    public:
        Student(string n, int a) : name(n), age(a) {}

        void display() 
        {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
};

int main() 
{
    // Variables
    int num1 ;
    int num2 ;
    int result;

    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter another number: ";
    cin >> num2;

    // Expressions
    result = num1 + num2;

    // Conditionals
    if (result > 10) 
    {
        cout << "Result is greater than 10." << endl;
    } 
    else 
    {
        cout << "Result is not greater than 10." << endl;
    }

    // Loops
    int fac;
    cout << "Enter how many number you want to Factorize: ";
    cin >> fac;

    for (int i = 1; i <= fac; ++i) 
    {
        cout << "Factorial of " << i << " is: " << factorial(i) << endl;
    }

    // Functions
    int factorialOf3 = factorial(3);
    cout << "Factorial of 3 is: " << factorialOf3 << endl;

    // Classes
    string fName;
    int sAge;
    cout << "Enter the name of a student: ";
    cin >> fName;
    cout << "Enter the age of the student: ";
    cin >> sAge;

    Student s1(fName, sAge);
    Student s2("John", 20);
    Student s3("Mary", 30);
    s1.display();
    s2.display();
    s3.display();

    // Data structure from STL
    list<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    cout << "Contents of list:" << endl;
    for (int item : myList) 
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}