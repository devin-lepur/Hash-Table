/* Devin Lepur
   Red ID: 825148526
   CS-496
   Prof Kraft
*/

#include <string>
#include "LinkedList.h"
#include "HashTable.h"
#ifndef HASHTABLE_CPP

using namespace LinkedListNS;
using namespace HashTableNS;

HashTable::HashTable()    {
    for (int i = 0; i < SIZE; i++)
    {
        hashArray[i] = NULL;
    }
   }

HashTable::~HashTable()    {
    for (int i = 0; i < SIZE; i++)
    {
        Node<string>* next = hashArray[i];
        while (next != NULL)
        {
            Node<string>* discard = next;
            next = next->getLink();
            delete discard;
        }
    }
}

int HashTable::computeHash(string s)
{
    int hash = 0;
    for (int i = 0; i < s.length(); i++)
    {
        hash += s[i];
    }
    return hash % 10;
    }

bool HashTable::containsString(string target) const
{
    int hash = this->computeHash(target);
    Node<string>* result = LinkedListNS::search(hashArray[hash], target);
    if (result == NULL) {
        return false;
    }
    else
        return true;
}

void HashTable::put(string s)    {
    int hash = computeHash(s);
    if (LinkedListNS::search(hashArray[hash], s) == NULL)
    {
        LinkedListNS::headInsert(hashArray[hash], s);
    }
}

#endif // HASHTABLE_CPP