#include <iostream>
#include <string>
#include <map>
using namespace std;

enum foods
{
    flour,
    butter,
    sugar,
    rice,

};

map<string, foods>food;
void register_input()
{
    food["flour"] = flour;
    food["butter"] = butter;
    food["sugar"] = sugar;
    food["rice"] = rice;
}

int main()
{

    register_input();
    string input;

    cout
        << "please choose food which you want"
        << endl;
    cin >> input;

    switch (food[input])
    {
    case flour:
        cout << "food is flour";
        break;
    case butter:
        cout << "food is butter";
        break;
    case sugar:
        cout << "food is sugar";
        break;
    case rice:
        cout << "food is rice";
        break;
    default:
        cout << "there is no food";
    }

    return 0;
}

/*
#include <iostream>
#include <string>
#include <map>
using namespace std;

enum foods
{
    flour,
    butter,
    sugar,
    rice,

};

int main()
{

int f;   

    cout
        << "flour=0 butter=1 sugar=2 rice=4 \nplease choose food which you want"
        << endl;
    cin >> f;

    switch (f)
    {
    case flour:
        cout << "food is flour";
        break;
    case butter:
        cout << "food is butter";
        break;
    case sugar:
        cout << "food is sugar";
        break;
    case rice:
        cout << "food is rice";
        break;
    default:
        cout << "there is no food";
    }


    return 0;
}

*/