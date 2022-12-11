#include <iostream>
#include <set>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

ostream& operator<<(ostream& out, pair<const string, const string> p)
{
    out << p.first << " " << p.second;
    return out;
}

class User
{
    string name;
    int age;
public:
    User(string name, int age) : name{ name }, age{ age } {}
    string& Name(){ return name; }
    int& Age() { return age; }
    friend ostream& operator<<(ostream& out, const User& user)
    {
        out << "name: " << user.name << ", age: " << user.age;
        return out;
    }
    friend bool operator<(const User& user1, const User& user2)
    {
        return user1.name < user2.name;
    }
};


class UserComp
{
public:
    bool operator()(User& user1, User& user2)
    {
        return user1.Name() < user2.Name();
    }
};

template <class Iterator>
void PrintContainer(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        cout << *begin << " ";
        begin++;
    }
    cout << "\n";
}

template <class Iterator>
void PrintContainerEol(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        cout << *begin << "\n";
        begin++;
    }
    cout << "\n";
}




int main()
{
    srand(time(nullptr));
    
    set<int> set1;
    for(int i = 0; i < 10; i++)
        set1.insert(rand() % 100);
    
    PrintContainer(set1.begin(), set1.end());

    /*int key;
    cin >> key;
    auto range = set1.equal_range(key);
    cout << *range.first << " " << *range.second << "\n";*/

    UserComp comp();
    set<User> usersSet;
    usersSet.insert(User("Tim", 23));
    usersSet.insert(User("Jim", 35));
    usersSet.emplace("Bob", 18);
    
    PrintContainerEol(usersSet.begin(), usersSet.end());


    map<string, string> map1;
    map1.insert(make_pair("one", "january"));
    map1.emplace("two", "february");
    map1.emplace("three", "march");
    map1.emplace("fore", "april");

    map1.insert_or_assign("oneday", "monday");
    //PrintContainerEol(map1.begin(), map1.end());
    //cout << map1["one"];

    for (auto item : map1)
        cout << item << "\n";

    unordered_set<int> unset;
    for (int i = 0; i < 10; i++)
    {
        int r = rand() % 100;
        auto hash = unset.hash_function();
        cout << r << " " << hash(r) << "\n";
        unset.insert(r);
    }
    cout << "\n";
    PrintContainer(unset.begin(), unset.end());
    
}
