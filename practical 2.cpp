#include<bits/stdc++.h>
using namespace std;

// 1) Stack
class Stack{
    int arr[10];
    int n;
    int top;
public:
    Stack(int size){
        n = size;
        top=-1;
    }
    void push(int data){
        if(top==n-1){
            cout<<"Stack OverFlow...\n";
            return;
        }
        top++;
        arr[top] = data;
        return;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack UnderFlow...\n";
            return;
        }
        top--;
        return;
    }
    void print(){
        if(top==-1){
            cout<<"Stack UnderFlow...\n";
            return;
        }
        for(int i=top;i>=0;i--)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
};

// 2) Queue
class Queue{
    int arr[10];
    int front,rear,n;
public:
    Queue(int n){
        this->n = n;
        this->front = -1;
        this->rear = -1;
    }
    void enqueue(int data){
        if(front==-1){
            front++;
        }
        if(rear==n-1){
            cout<<"Queue OverFlow...\n";
            return;
        }
        rear++;
        arr[rear] = data;
        return;
    }
    void dequeue(){
        if(front==-1){
            cout<<"Queue UnderFlow...\n";
            return;
        }
        front++;
        if(front==rear){
            front=rear=-1;
        }
        return;
    }
    void print(){
        if(front==-1){
            cout<<"Queue UnderFlow...\n";
            return;
        }
        for(int i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
};

// 3) Stack Using Two Queues
class StackUsingQueue{
    queue<int> q1;
    queue<int> q2;
    int n;
public:

    StackUsingQueue(int n){
        this->n = n;
    }
    void pushS(int data){
        if(q1.size()==n){
            cout<<"Stack OverFlow...\n";
            return;
        }
        if(q1.size()==0){
            q1.push(data);
            return;
        }
        while(q1.size()!=0){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(q2.size()!=0){
            q1.push(q2.front());
;           q2.pop();
        }
        return;
    }
    void popS(){
        if(q1.size()==0){
            cout<<"Stack UnderFlow...\n";
            return;
        }
        q1.pop();
        return;
    }
    void print(){
        if(q1.size()==0){
            cout<<"Stack UnderFlow...\n";
            return;
        }
        q2 = q1;
        while(!q2.empty()){
            cout<<q2.front()<<" ";
            q2.pop();
        }
        cout<<"\n";
    }
};

// 4) Queue Using Stack
class QueueUsingStack{
    stack<int> s1;
    stack<int> s2;
    int n;
public:
    QueueUsingStack(int n){
        this->n = n;
    }
    void enqueueQ(int data){
        if(s1.size()==n){
            cout<<"Queue OverFlow...\n";
            return;
        }
        s1.push(data);
        return;
    }
    void dequeueQ(){
        if(s1.size()==0){
            cout<<"Queue UnderFlow...\n";
            return;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return;
    }
    void printQueue(stack<int>&s2){
        if(s2.size()==0){
            return;
        }
        int temp = s2.top();
        s2.pop();
        printQueue(s2);
        cout<<temp<<" ";
        return;
    }
    void print(){
        if(s1.size()==0){
            cout<<"Queue UnderFlow...\n";
            return;
        }
        s2=s1;
        printQueue(s2);
        cout<<"\n";
        return;
    }

};

int main(){

    // Stack Creation
    Stack *o1 = new Stack(6);
    o1->pop();
    o1->push(10);
    o1->push(20);
    o1->pop();
    o1->push(30);
    o1->push(40);
    o1->print();

    // Queue Creation
    Queue *o2 = new Queue(5);
    o2->dequeue();
    o2->enqueue(10);
    o2->enqueue(20);
    o2->enqueue(30);
    o2->enqueue(0);
    o2->print();
    o2->dequeue();
    o2->enqueue(40);
    o2->enqueue(50);
    o2->print();

    // Stack Using Queue Creation
    StackUsingQueue *o3 = new StackUsingQueue(7);
    o3->popS();
    o3->pushS(10);
    o3->pushS(20);
    o3->pushS(30);
    o3->print();
    o3->popS();
    o3->print();

    // Queue Using Stack Creation
    QueueUsingStack *o4 = new QueueUsingStack(4);
    o4->dequeueQ();
    o4->enqueueQ(10);
    o4->enqueueQ(20);
    o4->enqueueQ(30);
    o4->enqueueQ(40);
    o4->enqueueQ(50);
    o4->print();
    o4->dequeueQ();
    o4->print();
}
