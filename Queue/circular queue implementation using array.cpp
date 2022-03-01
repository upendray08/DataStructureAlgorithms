#include<bits/stdc++.h>
using namespace std;
class CircularArrayQueue{
    int* arr;
    int n;
    int rear =-1;
    int front =-1;
public:
    CircularArrayQueue(int size){
        n = size ;
        arr = new int[n];
    }
    void Enqueue(int x);
    void Dequeue();
    void printQueue();
};
void CircularArrayQueue::Enqueue(int x){
    if((rear+1)%n==front ||(rear == n-1&&front==0)){
        cout<<"Queue is Full"<<endl;
        return;
    }
    if(front==-1){
        front=0;
    }
    rear = (rear+1)%n;
    arr[rear]=x;
}
void CircularArrayQueue::printQueue(){
    if(front==-1){
        cout<<"Empty Queue"<<endl;
        return;
    }
    if(rear>=front){
        for(int i=front;i<=rear;++i){
            cout<<arr[i]<<" ";
        }
    }else{
        for(int i=front;i<n;++i){
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<=rear;++i){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}
void CircularArrayQueue::Dequeue(){
    if(front==-1){
        cout<<"Queue is Empty"<<endl;
        return;
    }
    int result = arr[front];
    arr[front]=-1;
    if(front==rear){
        front=-1;
        rear=-1;
    }else{
        front =(front+1)%n;
    }
    cout<<result<<endl;
    return;
}
int main() {
	CircularArrayQueue myqueue(3);
	myqueue.Enqueue(10);
	myqueue.Enqueue(20);
	myqueue.Enqueue(40);
	myqueue.Enqueue(50);
	myqueue.printQueue();
	myqueue.Dequeue();
	myqueue.Enqueue(60);
	myqueue.printQueue();
    myqueue.Dequeue();
    myqueue.printQueue();
    myqueue.Enqueue(12);
    myqueue.printQueue();
	return 0;
}