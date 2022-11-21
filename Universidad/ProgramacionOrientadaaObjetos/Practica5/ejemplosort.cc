#include <iostream>
#include <algorithm> //sort
#include <vector>
#include <string>

using namespace std;

const int SIZE = 7;
struct Person{
    // Left out making a constructor for simplicity's sake.
    string name;
    int age;
    string favoriteColor;
};
// Sort Container by name function
bool sortByName(const Person &lhs, const Person &rhs) { return lhs.name < rhs.name; }
// Sort Container by age function
bool sortByAge(const Person &lhs, const Person &rhs) { return lhs.age < rhs.age; }
// Sort Container by favorite color
// We can just sort alphabetically and then it will group the
// color together.
bool sortByColor(const Person &lhs, const Person &rhs) { return lhs.favoriteColor < rhs.favoriteColor; }
// A global const variable to hold how many people to ask for input for.
const unsigned numberOfPeople=2;
// We need this function to define how to sort
// the vector. We will pass this function into the
// third parameter and it will tell it to sort descendingly.
bool wayToSort(int i, int j){return i>j;}
int main(){
    int intArray[SIZE] = {5, 3, 32, -1, 1, 104, 53};
    //Now we call the sort function
    sort(intArray, intArray + SIZE);
    cout << "Sorted Array looks like this." << endl;
    for (size_t i = 0; i != SIZE; ++i)
        cout << intArray[i] << " ";
    // Warning this type of initialization requires a C++11 Compiler
    vector<int> intVec = {56, 32, -43, 23, 12, 93, 132, -154};
    vector<string> stringVec = {"John", "Bob", "Joe", "Zack", "Randy"};
    // Sorting the int vector
    sort(intVec.begin(), intVec.end());
    for (vector<int>::size_type i = 0; i != intVec.size(); ++i)
        cout << intVec[i] << " ";
    cout << endl;
    // Sorting the string vector
    sort(stringVec.begin(), stringVec.end());
    // Ranged Based loops. This requires a C++11 Compiler also
    // If you don't have a C++11 Compiler you can use a standard
    // for loop to print your vector.
    for (string &s : stringVec)
        cout << s << " ";
    vector<int> intVec2 = {56, 32, -43, 23, 12, 93, 132, -154};
    // Do not include the () when you call wayToSort
    // It must be passed as a function pointer or function object
    sort(intVec2.begin(), intVec2.end(), wayToSort);
    for (int i : intVec2)
        cout << i << " ";
    // Make a vector that holds 5 blank Person Objects
    vector<Person> people(numberOfPeople);

    // This will ask for user input to populate the container
    // with 5 different indivuals.
    for (vector<Person>::size_type i = 0; i != numberOfPeople; ++i)
    {
        cout << "Person #" << i + 1 << " name: ";
        cin >> people[i].name;

        cout << "Person #" << i + 1 << " age: ";
        cin >> people[i].age;

        cout << "Person #" << i + 1 << " favorite color: ";
        cin >> people[i].favoriteColor;
    }

    cout << "\n\n";

    // Sort by name
    sort(people.begin(), people.end(), sortByName);
    for (Person &n : people)
        cout << n.name << " ";

    cout << endl;

    // Sory by age
    sort(people.begin(), people.end(), sortByAge);
    for (Person &n : people)
        cout << n.age << " ";

    cout << endl;

    // Sort by color
    sort(people.begin(), people.end(), sortByColor);
    for (Person &n : people)
        cout << n.favoriteColor << " ";

    return 0;
}
/*
Example 1 ~ std::sort(myvector.begin(), myvector.end())
Example 2 ~ std::sort(myvector.begin(), myvector.end(), myCompFunction*/