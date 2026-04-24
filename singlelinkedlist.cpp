#include <iostream>
using namespace std;

class node
{
public:
    int noMhs;
    node *next;
};

class Linkedlist
{
    node *START;

public:
    Linkedlist()
    {
        START = NULL;
    }
}