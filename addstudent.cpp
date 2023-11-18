#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    int Rollno;
    int marks;
    Node *next;

    Node()
    {
        name = " ";
        Rollno = 0;
        marks = 0;
        next = NULL;
    }
};

void insert(Node **head, int size)
{
    Node *temp = new Node(); // Allocate memory for the head node
    *head = temp;

    cout << "Enter the Name of Student:" << endl;
    cin >> temp->name;
    cin.ignore();
    cout << "Enter the Roll no of the Student:" << endl;
    cin >> temp->Rollno;
    cout << "Enter the Marks of the Student:" << endl;
    cin >> temp->marks;

    for (int i = 1; i < size; i++) // Start the loop from 1 since the head is already created
    {
        Node *n = new Node();
        cout << "Enter the Name of Student:" << endl;
        cin >> n->name;
        cin.ignore();
        cout << "Enter the Roll no of the Student:" << endl;
        cin >> n->Rollno;
        cout << "Enter the Marks of the Student:" << endl;
        cin >> n->marks;
        temp->next = n;
        temp = n;
        n->next = NULL;
    }
}

int Highest(Node *head)
{
    Node *temp = new Node();
    temp = head;
    int max;
    while (temp != NULL)
    {
        if (temp->marks > max)
        {
            max = temp->marks;
        }
        temp = temp->next;
    }
    return max;
}

int lowest(Node *head)
{
    Node *temp = new Node();
    temp = head;
    int min = 0;
    while (temp != NULL)
    {
        if (temp->marks < min)
        {
            min = temp->marks;
        }
        temp = temp->next;
    }
    return min;
}

bool searchbyname(Node *head)
{
    string Name;
    cout << "Enter the Name you want to search:" << endl;
    cin >> Name;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->name == Name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Display(Node *head)
{
    Node *temp = head;
    cout << "The data is shown as:" << endl;
    while (temp != NULL)
    {
        cout << "The name of student is as:" << endl;
        cout << temp->name << endl;
        cout << "The marks of the student is as:" << endl;
        cout << temp->marks << endl;
        cout << "The Roll no of student is as:" << endl;
        cout << temp->Rollno << endl;
        temp = temp->next;
    }
}

int main()
{
    
    int op, s, h;
    Node *head = NULL;
    cout << "Enter the number of nodes you want to create:" << endl;
    cin >> op;
while(1)
{
    int in;
    cout << "1 to add the details:" << endl;
    cout << "2 to display the student:" << endl;
    cout << "3.show highets marks:" << endl;
    cout << "4.show lowest marks:" << endl;
    cout << "ENter the option you want to select:" << endl;
    cin >> in;
    
    switch (in)
    {

    case 1:

        insert(&head, op);
        break;
    case 2:
        Display(head);
        break;
    case 3:
        s = Highest(head);
        cout << "The highest marks are as :" << s << endl;
        break;
    case 4:
        h = lowest(head);
        cout << "The lowest marks of student is as" << h << endl;
        break;
    case 5:
        if (searchbyname(head))
        {
            cout << "the Name is as:" << head->name << endl;
        }
        else
        {
            cout << "name does not exist:" << endl;
        }
        break;
   case 0:
   break;
    }
}
    return 0;
}
