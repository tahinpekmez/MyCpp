#include <iostream>
#include <list> 
#include <iterator> 
using namespace std;

class Hash
{
    int hashbucket; // No. of hashbuckets

    // pointer to an array containing hashbuckets
    list<int> *table;

    public:
    Hash(int V); //Constructor

    // inserts a key into hash table
    void InsertItem(int x);

    // deletes a key from hash table
    void DeleteItem(int key);

    // hash func map to values to key
    int HashFunction(int x)
    {
        return(x % hashbucket);
    }

    void DisplayHash();
}; 

Hash::Hash(int b)
{
    this->hashbucket = b;
    table = new list<int>[hashbucket];
}

void Hash::InsertItem(int key)
{
    int index = HashFunction(key);
    table[index].emplace_back(key);
}

void Hash::DeleteItem(int key)
{
    // get the hash index(th) of key
    int index = HashFunction(key);

    list<int> :: iterator i;
    for(i = table[index].begin(); i != table[index].end(); ++i)
    {
        if(*i == key)
        break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
    {
        table[index].erase(i);
    }
}

    // function to display hash table
    void Hash::DisplayHash()
    {
        for(int i = 0; i < hashbucket; ++i)
        {
            cout << i;
            for (auto x : table[i])
            {
                cout << " ---> " << x;
            }
            cout << endl;
        }
    }

    int main()
    {
        int a[] = {45, 13, 35, 78, 33};
        int n = sizeof(a) / sizeof(a[0]);
        
        // insert a key into hash table, 7 is count of hashbuckets in hash table
        Hash h(6); 

        for(int i = 0; i < n; ++i)
        {
            h.InsertItem(a[i]);
        }

        // delete 12 from hash table
        h.DeleteItem(13);

        h.DisplayHash();

        return 0;
    }