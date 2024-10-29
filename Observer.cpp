// Observer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
using namespace std;

class ISubscriber 
{
public: 
    virtual void notify(string msg) = 0;
};

class User : public ISubscriber
{
    int UserId;
public:
    User(int uId)
    {
        UserId = uId;
    }
    void notify(string msg)
    {
        cout << "User" << UserId << " " << "Recieved msg " << msg << endl;

    }
};

class Group 
{
private:
    list<ISubscriber*> Users;
public: 
    void SubScribe(ISubscriber* user)
    {
        Users.push_back(user);
    }

    void UnSubScribe(ISubscriber* user)
    {
        Users.remove(user);
    }

    void Notify(string msg)
    {
        for (auto Usr : Users)
        {
            Usr->notify(msg);
        }
    }

};
int main()
{
    Group* group1 = new Group();
    User* User1 = new User(1);
    User* User2 = new User(2);
    User* User3 = new User(3);

    group1->SubScribe(User1);
    group1->SubScribe(User2);
    group1->SubScribe(User3);
    group1->Notify("hello C++");

    group1->UnSubScribe(User3);
    group1->Notify("Hello Java");

    std::cout << "Hello World!\n";
}
