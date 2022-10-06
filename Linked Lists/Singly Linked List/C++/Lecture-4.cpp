#include <bits/stdc++.h>
#include "Lecture-1.cpp"
using namespace std;

class Search : public Node
{
public:
    int searchKey(Node *head, int key)
    {
        int i = 0;
        while (i < c)
        {
            if (key == head->data)
                return i + 1;
            head = head->next;
            i++;
        }
        return -1;
    }

    int searchRecursive(Node *head,int key){
        if(head==NULL)
            return -1;
        if(head->data == key)
            return 1;
        int res=searchRecursive(head->next,key);
        if(res==-1)
            return -1;
        else
            return res+1;
    }
};

int main()
{
    Search obj = Search();
    Node *head = obj.create();
    int key;
    cout << "Enter the key to search : ";
    cin >> key;
    if (obj.searchKey(head, key) != -1)
        cout << "Key found at positon " << obj.searchKey(head, key) << endl;
    else
        cout << "Key not found" << endl;
    return 0;
}