#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Hashing
{
    int no_hashbucket; // number of buckets

    // pointer to an array containing buckets
    list<int> *table;

    public:
    Hashing(int V); // constructor

    void item_insert(int x); // inserts a key into hash table

    void item_delete(int key); // deletes a key from hash table

    // hash function to map values to key
    int hash_function(int x)
    {
        return (x % no_hashbucket);
    }

    void display_hash();
};

Hashing::Hashing(int b)
{
    this->no_hashbucket = b;
    table = new list<int>[no_hashbucket];
}

void Hashing::item_insert(int key)
{
    int index = hash_function(key);
    table[index].emplace_back(key);
}

void Hashing::item_delete(int key)
{
    int index = hash_function(key);

    // find the key in (index)th list
    list <int> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); ++i)
    {
        if (*i == key)
        break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
    table[index].erase(i);
}

// function to display hash table
void Hashing::display_hash()
{
    for(int i = 0; i < no_hashbucket; ++i)
    {
        cout << i;
        for (auto &x : table[i])
        cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    int a[] = {34, 114, 42, 56, 21, 68};
    int n = sizeof(a)/sizeof(a[0]);

    Hashing h(7);

    for (int i = 0; i < n; ++i)
    h.item_insert(a[i]);

    //h.item_delete(114);

    h.display_hash();

    return 0;
}
