# SingleLinkedlistalloperationinc-
https://github.com/Ekrashzahid123/SingleLinkedlistalloperationinc-/commit/f4129ee81a75e11d3447125913c8b18fc6614cd8#r132758311
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void create(Node **head, int size)
{    *head=new Node();
    Node *temp = *head;
    cout << "Enter the value at the head:" << endl;
    cin >> temp->data;
    temp->next = NULL;

    for (int i = 1; i < size; i++)
    {
        Node *n = new Node();
        cin >> n->data;
        temp->next = n;
        temp = n;
        n->next = NULL;
    }
}

void Display(Node *head)
{
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void AddinLink(Node **head)
{
    Node *start = new Node();
    cout << "Enter the Node at the start:" << endl;
    cin >> start->data;
    start->next = *head;
    *head = start;
}

void ADDatLast(Node **head)
{
    Node *end = new Node();
    cout << "Enter the Element at the last:" << endl;
    cin >> end->data;
    Node *temp = NULL;
    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = end;
}

void AnyLoct(Node **head, int loc)
{
    Node *n = new Node();
    cout << "ENter the data at any location:" << endl;
    cin >> n->data;
    Node *temp = NULL;
    temp = *head;
    for (int i = 1; i < loc; i++)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        n->next = temp->next;
        temp->next = n;
    }
}

bool search(Node **head, int ser)
{
    Node *curr;
    curr = *head;
    while (curr != NULL)

    {
        if (curr->data == ser)
        {
            return true;
        }

        curr = curr->next;
    }
    return false;
}

int count(Node *head)
{
    int cou = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cou++;
        temp = temp->next;
    }
    return cou;
}

int Max(Node **head)
{
    Node *temp = NULL;
    temp = *head;
    int max = 0;
    while (temp != NULL)
    {
        if (temp->data >= max)
        {
            max = temp->data;
            temp=temp->next;
        }
    }
    return max;
}
int Min(Node **head)
{
    int min=0;
    Node *temp=NULL;
    temp=*head;
    while(temp!=NULL)
    {
        if(temp->data<min)
        {
            min=temp->data;
            temp=temp->next;
        }
    }
return min;
}

int main()
{
    int s;
    int op;

    cout << "How many nodes do you want to create:" << endl;
    cin >> s;

    Node *head = NULL; // Initialize head to NULL

    while (1)
    {
        cout << "0 to terminate the Program:" << endl;
        cout << "1. Add The Element in the linked list:" << endl;
        cout << "2. Add at the front in the linked list:" << endl;
        cout << "3.add the Element at the last:" << endl;
        cout << "4.press to enter element at any location:" << endl;
        cout << "5. search the ELement in the linked list:" << endl;
        cout << "6.check element in the linked list:" << endl;
        cout << "7.check the max in linked list:" << endl;
        cout<<"  8.check the min in the linked list:"<<endl;

        cout << "Enter the Option :" << endl;
        cin >> op;

        switch (op)
        {
        case 0:
            return 0; // Terminate the program

        case 1:
            create(&head, s);
            cout << "Display the Given Linked list:" << endl;
            Display(head);
            break;

        case 2:
            AddinLink(&head);
            cout << "Display the Updated Linked list:" << endl;
            Display(head);
            break;

        case 3:
            ADDatLast(&head);
            cout << "Display the last added list:" << endl;
            Display(head);

        case 4:
            int loc;
            cout << "Enter the loc of link to add Element:" << endl;
            cin >> loc;
            AnyLoct(&head, loc);
            cout << "Display:" << endl;
            Display(head);

        case 5:
            int sea;
            cout << "Enter the Element you want to search in the link list:" << endl;
            cin >> sea;
            if (search(&head, sea))
            {
                cout << "the ELement is found:" << endl;
            }
            else
            {
                cout << "element is not found:" << endl;
            }
            break;
        case 6:
            int rec;
            rec = count(head);
            cout << "The Element in the linked list is as:" << rec << endl;
            break;

        case 7:
        int recmax;
        recmax=Max(&head);
        cout<<"The maximum no in the linked list is as:" << recmax <<endl;
        break;
        case 8:
        int minr;
        minr=Min(&head);
        cout<<"the min no is as"<<minr<<endl;
        break;;
        }
    }

    return 0;
}
