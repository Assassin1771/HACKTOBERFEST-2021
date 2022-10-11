
#include<bits/stdc++.h>
using namespace std;

// class for linked list
class Node
{
public:
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;

    }
};

struct Test
{
    int position[1000];

};
void insertAtTail(Node* &head,int val);
void insertAtHead(Node* &head,int val);
void insertAtSpecificPosition(Node *head,int val,int pos);
int countLength(Node *head);
int searchByValueUnique(Node *head,int value);
void searchByValueDuplicate(Node *head,int value);
Test searchByValueDuplicateReturn(Node* head,int value);
void searchByValueUnique(Node* head,int search_value,int insert_number);
void searchByValueDuplicate(Node* head, int search_value,int insert_number);
void deletionAtHead(Node* &head);
void deletionAtTail(Node* &head);
void deletionAtSpecificPosition(Node* &head,int pos);
void deletionByValueUnique(Node* &head,int value);
void deletionByValueDuplicate(Node* &head,int value);
void display(Node *head);
void reverseDisplay(Node *head);
int findMid(Node* head);
Node* reverseNonRecursive(Node* head);
Node* reverseRecursive(Node* head);
void makeCycle(Node* &head,int pos);
bool detectCycle(Node *head);
void removeCycle(Node* head);





void insertAtTail(Node* &head,int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}



void insertAtHead(Node* &head,int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;

}



void insertAtSpecificPosition(Node *head,int val,int pos)
{
    Node* newNode = new Node(val);
    int cnt = 0;
    while(cnt < pos-2)
    {
        cnt++;
        head = head->next;
    }
    Node *temp = head;
    newNode->next = temp->next;
    temp->next = newNode;


}

int countLength(Node *head)
{
    int cnt = 0;
    while(head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}


int searchByValueUnique(Node *head,int value)
{
    int c = 1;
    while(head != NULL)
    {
        if(value == head->data)
        {
            return c;
        }
        else
        {
            c++;
        }

        head = head->next;
    }
    return -1;
}


void searchByValueDuplicate(Node *head,int value)
{
    Node* temp =head;
    int size = countLength(head);
    int position[size+1],k=1;
    int count = 1;
    int flag = 0;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            position[k]=count;
            k++;
            flag = 1;
        }
        count++;
        temp = temp->next;
    }
    if(flag == 0) cout<<"The search value is not yet in the list."<<endl;
    else
    {
        position[0] = k;
        cout<<"The value is found at position:";
        for(int i=1; i<position[0]; i++)
        {
            cout<<position[i];
            if(i<position[0]-1)
            {
                cout<<",";
            }

        }
        cout<<endl;
    }
}

Test searchByValueDuplicateReturn(Node* head,int value)
{
    Node* temp =head;
    int count = 1,k=1;
    Test T;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            T.position[k]=count;
            k++;
        }
        count++;
        temp = temp->next;
    }
    T.position[0] = k;
    return T;
}
void searchByValueDuplicate(Node* head, int search_value,int insert_number)
{
    // There can be two things happen before(-1) and after(+1)
    Test T = searchByValueDuplicateReturn(head,search_value);
    if(T.position[0] == 1 ) cout<<"No such value found"<<endl;
    else
    {
        for(int i=T.position[0]-1; i>0; i--)
        {
            // we are try to insert after a value
            insertAtSpecificPosition(head,insert_number,T.position[i]+1);
            //cout<<T.position[i]<<" ";
        }
    }
}
void searchByValueUnique(Node* head,int search_value,int insert_number)
{
    // Step 1: search the position of the search value
    int position = searchByValueUnique(head,search_value);
    cout<<position<<endl;
    // Step 2: insert the value at the position +1
    // This is used for after
    // if we want to enter before we can use position-1
    insertAtSpecificPosition(head,insert_number,position+1);
}

void deletionAtHead(Node* &head)
{
    if(head != NULL)
    {
        Node* temp = head;
        head = temp->next;
        delete temp;

    }
    else
    {
        cout<<"List is empty"<<endl;
    }
}

void deletionAtTail(Node* &head)
{
    /*
    int length = countLength(head);
    if(head == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(length<2)
    {
        head = NULL;
    }
    else
    {

        Node* temp = head;
        for(int i=1; i<length-1; i++)
        {
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    */
    // /*
    Node *temp = head;
    if(temp != NULL && temp->next != NULL)
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    else
    {
        // case 1 => head is NULL
        if(temp == NULL)
        {
            cout<<"List is Empty"<<endl;
        }
        // case 2 => head is Tail
        else
        {
            deletionAtHead(head);
        }

    }



    //*/
}
void deletionAtSpecificPosition(Node* &head,int pos)
{

    /*
    int length = countLength(head);

    if(pos == 1){
        deletionAtHead(head);
    }
    else if(pos == length){
        deletionAtTail(head);
    }
    else if(pos>length){
        cout<<"The position is not valid."<<endl;
    }
    else{
            Node *temp = head;
        for(int i=1;i<pos-1;i++){
            temp = temp->next;
        }
        Node* delNode = temp->next;
        Node* afterDelNode = temp->next->next;
        temp->next =afterDelNode;
        delete delNode;
    }
    */

    Node* temp = head;
    if(pos == 1)
    {
        deletionAtHead(head);

    }
    else if(pos == countLength(head))
    {
        deletionAtTail(head);
    }
    else
    {
        if(temp != NULL && pos <= countLength(head))
        {
            int i= 1;
            while(i<pos-1)
            {
                temp = temp->next;
                i++;
            }
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
        else
        {
            // Position is out of range
            if(pos>countLength(head))
            {
                cout<<"Position is out of range"<<endl;
            }
            // Linked List is NULL
            else
            {
                cout<<"There is no value in Linked List"<<endl;
            }

        }
    }


}

void deletionByValueUnique(Node* &head,int value)
{
    // find the position of the value
    int pos = searchByValueUnique(head,value);
    if(pos == -1)
    {
        cout<<"Value not found in Linked List"<<endl;
    }
    // delete the node at specific position
    else
    {
        deletionAtSpecificPosition(head,pos);
    }


}
Node* reverseNonRecursive(Node* head)
{
    Node* prev = NULL;
    Node* current = head;
    Node* next1;
    if(head == NULL)
    {
        cout<<"The list is empty"<<endl;
        return head;
    }
    else
    {
        next1 = head->next;
    }
    while(true)
    {
        current->next = prev;
        prev = current;
        current = next1;
        if(current == NULL)
        {
            break;
        }
        next1 = next1->next;

    }

    return prev;


}
Node* reverseRecursive(Node* head)
{

    // base call;
    if(head == NULL || head->next == NULL)
    {
        if(head == NULL) cout<<"The linked list is empty"<<endl;
        return head;
    }
    Node* newNode = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newNode;
}
void deletionByValueDuplicate(Node* &head,int value)
{
    Test t = searchByValueDuplicateReturn(head,value);
    if(t.position[0] == 1)
    {
        cout<<"No value found"<<endl;
    }
    else
    {
        int cnt = 0;
        for(int i=1; i<t.position[0]; i++)
        {
            deletionAtSpecificPosition(head,t.position[i]-cnt);
            cnt++;
        }
    }
}

int findMid(Node* head)
{
    // case 1: head is empty
    // case 2: if number of element is even
    if(head == NULL)
    {
        return -1;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast!= NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}
void display(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}


void reverseDisplay(Node *head)
{
    if(head != NULL)
    {
        reverseDisplay(head->next);
        cout<<head->data<<" ";
    }
    return;

}


//make cycle

void makeCycle(Node* &head,int pos)
{
    Node* temp = head;
    Node* startNode;
    int cnt = 1;
    while(temp->next != NULL)
    {
        if(cnt == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        cnt++;

    }
    temp->next = startNode;
}

// detect cycle
bool detectCycle(Node *head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast!= NULL && fast->next !=NULL)
    {
        //cout<<slow->data<<" "<<fast->data<<endl;
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}
// cycle removal

void removeCycle(Node* head)
{
    // step to remove cycle
    // 1. slow == fast
    // 2. fast = head
    // 3. fast->next == slow->next
    // 4. slow->next = NULL
    Node* slow = head;
    Node* fast = head;
    /*
    while(true){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            fast  = head;
            break;
        }
    }
    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
    */
    // step 1: fast = slow
    do
    {
        slow =  slow->next;
        fast = fast->next->next;
    }
    while(slow!=fast);

    // step 2: Re-initialization of fast
    fast = head;
    // step 3: fast->next != slow->next
    while(fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;


}

int main()
{
    Node* head = NULL;
    int choice,value;
    cout<<"1.Insertion at head"<<endl;
    cout<<"2.Insertion at tail"<<endl;
    cout<<"3.Insertion at specific position"<<endl;
    cout<<"4.Search in a Linked List(Unique Value)"<<endl;
    cout<<"5.Search in a Linked List(Duplicate Value)"<<endl;
    cout<<"6.Search in a Linked List(Duplicate Value(Return))"<<endl;
    cout<<"7.Insertion after a specific value(Unique List)"<<endl;
    cout<<"8.Insertion after a specific value(Duplicate List)"<<endl;
    cout<<"9.Deletion at Head"<<endl;
    cout<<"10.Deletion at Tail"<<endl;
    cout<<"11.Deletion at a Specific Position"<<endl;
    cout<<"12.Deletion by value(unique list)"<<endl;
    cout<<"13.Deletion by value(Duplicate list)"<<endl;
    cout<<"14.Reversal of a list(non-recursive)"<<endl;
    cout<<"15.Reversal of a list(recursive)"<<endl;
    cout<<"16.Finding the mid(Slow-fast Pointer)"<<endl;
    cout<<"17.Make a cycle in Linked list"<<endl;
    cout<<"18.Detect Cycle"<<endl;
    cout<<"19.Remove Cycle(if any)"<<endl;
    cout<<"100:Display"<<endl;
    cout<<"101:Reverse Display"<<endl;
    cout<<"102:Length of Linked List"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"Enter the choice:";
    cin>>choice;
    while(choice != 0)
    {

        switch(choice)
        {
        case 1:
            cout<<"Enter the value:";
            cin>>value;
            insertAtHead(head,value);
            break;
        case 2:
            cout<<"Enter the value:";
            cin>>value;
            insertAtTail(head,value);
            break;
        case 3:
            cout<<"Enter the value:";
            cin>>value;
            cout<<"Enter the position(1-index):";
            int pos;
            cin>>pos;
            insertAtSpecificPosition(head,value,pos);
            break;
        case 4:
            cout<<"Enter the value:";
            cin>>value;
            if(searchByValueUnique(head,value) == -1)
            {
                cout<<"NOT FOUND"<<endl;
            }
            else
            {
                cout<<"Found at: "<<searchByValueUnique(head,value)+1<<endl;
            }
            break;
        case 5:
            cout<<"Enter the value:";
            cin>>value;
            searchByValueDuplicate(head,value);
            cout<<endl;
            break;
        case 6:
        {
            cout<<"Enter the value:";
            cin>>value;
            Test T = searchByValueDuplicateReturn(head,value);
            if(T.position[0] == 1)
            {
                cout<<"Not Found"<<endl;
            }
            else
            {
                cout<<"The value is found at position:";
                for(int i=1; i<T.position[0]; i++)
                {
                    cout<<T.position[i];
                    if(i<T.position[0]-1)
                    {
                        cout<<",";
                    }
                }
                cout<<endl;
            }
            break;
        }
        case 7:
        {
            cout<<"Enter the search value:";
            cin>>value;
            cout<<"Enter the the value to insert:";
            int insert_number;
            cin>>insert_number;
            searchByValueUnique(head,value,insert_number);
            break;
        }
        case 8:
        {
            cout<<"Enter the search value:";
            cin>>value;
            cout<<"The upper value is used for search value."<<endl;
            cout<<"Enter the value to insert:";
            int insert_number;
            cin>>insert_number;
            searchByValueDuplicate(head,value,insert_number);
            break;
        }
        case 9:
        {
            deletionAtHead(head);
            break;
        }
        case 10:
        {
            deletionAtTail(head);
            break;
        }
        case 11:
        {
            if(head == NULL)
            {
                cout<<"There is no value in Linked List"<<endl;
            }
            else
            {
                cout<<"Enter the position:";
                int position;
                cin>>position;
                deletionAtSpecificPosition(head,position);
            }

            break;
        }
        case 12:
        {
            if(head == NULL)
            {
                cout<<"There is no value in linked list"<<endl;
            }
            else
            {
                cout<<"Enter the value to delete:";
                int delValue;
                cin>>delValue;
                deletionByValueUnique(head,delValue);

            }
            break;
        }
        case 13:
        {
            if(head == NULL)
            {
                cout<<"There is no value in linked list"<<endl;
            }
            else
            {
                cout<<"Enter the value to delete:";
                int delValue;
                cin>>delValue;
                deletionByValueDuplicate(head,delValue);
            }

            break;
        }
        case 14:
        {
            head = reverseNonRecursive(head);
            break;
        }
        case 15:
        {
            head = reverseRecursive(head);
            break;
        }
        case 16:
        {
            int mid = findMid(head);
            if(mid == -1)
            {
                cout<<"The linked list is empty"<<endl;
            }
            else
            {
                cout<<"The mid value is:"<<mid<<endl;
            }

            break;
        }
        case 17:
        {
            int pos;
            cout<<"Enter the desired position to create cycle:";
            cin>>pos;
            makeCycle(head,pos);
            break;
        }
        case 18:
        {
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if(cycleStatus == true)
            {
                cout<<"There is a cycle in the list"<<endl;

            }
            else
            {
                cout<<"There is no cycle in the list"<<endl;
            }
            break;
        }
        case 19:
        {
            bool cycleStatus;
            cycleStatus = detectCycle(head);
            if(cycleStatus == true)
            {
                removeCycle(head);
                cout<<"The cycle has been removed"<<endl;
            }
            else
            {
                cout<<"There is no cycle in the list"<<endl;
            }
            break;

        }

        case 100:
        {
            if(countLength(head)>0)
            {
                cout<<"Linked List:";
                display(head);
                cout<<endl;
            }
            else
            {
                cout<<"The linked list is empty"<<endl;
            }

            break;
        }
        case 101:
        {
            if(countLength(head)>0)
            {
                cout<<"Linked List(Reverse):";
                reverseDisplay(head);
                cout<<endl;
            }
            else
            {
                cout<<"The linked list is empty"<<endl;
            }
            break;
        }
        case 102:
        {
            cout<<"The length of linked List:"<<countLength(head)<<endl;
            break;
        }
        default:
            break;
        }
        cout<<"Next choice:";
        cin>>choice;
    }


    cout<<endl;
    display(head);
    cout<<"The length of linked List:"<<countLength(head)<<endl;
    return 0;
}


