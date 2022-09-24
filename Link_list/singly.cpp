#include<iostream>
#include<climits>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *head;
int count = 0;

void initial()
{
    head = 0;
}

int lengthOfList(){
    return count;
}

void insertLast(int val){
    node *newNode;
    newNode = new node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    count ++;
}
void insertFirst(int val){
    if(head == 0){
        insertLast(val);
    }else{
        node *newNode,*temp;
        newNode = new node;
        newNode->data = val;
        newNode->next = 0;
        temp = head;
        while(temp->next !=0){
            temp = temp->next;
        }
        temp->next = newNode;
        count++;
    }
}
void insertAfterPosition(int pos,int val){
    int index =1;
    if(pos == 0){
        cout<<"Position Can't be Zero!!\n";
        return;
    }
    if(pos == 1){
        insertFirst(val);
        return;
    }
    if(lengthOfList() < pos){
        cout<<"Invalid Position!"<<endl;
    }else{
        node *temp,*newNode;
        temp = head;
        while(index<pos-1){
            temp = temp->next;
            index++;
        }
        newNode = new node;
        newNode->data = val;
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
    }
}
void display()
{
    if(head == 0)
    {
        cout<<"\nEmpty List!";
    }else{
        cout<<endl;
        node *temp;
        temp = head;
        while(temp != 0)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
void deleteFirstNode(){
    if(head == 0){
        cout<<"Empty List"<<endl;
    }
    node *temp;
    temp = head;
    head = head->next;
    free(temp);
}
void deleteLastNode(){
     if(head == 0){
        cout<<"Empty List"<<endl;
    }
    node *temp,*prev;
    temp = head;
    while(temp->next != 0){
            prev = temp;
        temp = temp->next;
    }
    if(head == temp){
        head = 0;
    }else{
        prev->next = 0;
    }
    free(temp);
}

void deleteNodeByPosition(int pos){
    if(head == 0){
        cout<<"Empty List"<<endl;
        return;
    }
    if(pos> lengthOfList()){
        cout<<"\nInvalid Position\n";
        return;
    }
    if(pos == 1){
        deleteFirstNode();
        return;
    }
    int index = 1;
    node *temp,*prevNode,*nextNode;
    temp = head;
    while(index < pos-1){
        temp = temp->next;
          //cout<<"t "<<temp->data;
        index++;
    }
    prevNode = temp;
    nextNode = prevNode->next;
    temp->next = nextNode->next;
    free(nextNode);
}
void reverse(){
    node *prev = NULL;
    node *current = head;
    node *next = NULL;

    while(current != NULL){
        next = current->next;

        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int searchNodePositionByValue(int val){
    if(head == 0){
        return -1;
    }
    node *temp;
    int index = 1;
    temp = head;
    while(temp != 0){
        if(temp->data == val){
            return index;
        }
        else if(temp->next == 0){
            return -2;//-2 for invalid input
        }
        index ++;
        temp = temp->next;
    }
}
int getMaximumValue(){
    int max = INT_MIN;
    node *temp;
    temp = head;
    while(temp != 0){
        if(max < temp->data){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}
node *getNodeByValue(int val){
    node *temp;
    int index = 1;
    temp = head;
    while(temp != 0){
        if(temp->data == val){
            return temp;
        }
        else if(temp->next == 0){
            return NULL;//-2 for invalid input
        }
        index ++;
        temp = temp->next;
    }
}
void changeNodeValue(int oldVal, int newVal){
   getNodeByValue(oldVal)->data = newVal;
}
int main(){
    initial();
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    insertFirst(40);

   display();
 cout<<getMaximumValue();
    return 0;
}
