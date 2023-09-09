#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
    int qfront;
    int qrear;
    int *arr;
    int size;
    CircularQueue(int n){
        // Write your code here.
        arr=new int[n];
        size=n;
        qfront=-1;
        qrear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if(qfront==(qrear+1)%size){
            return false;
        }
        else{
            if(qfront==-1 && qrear==-1){
                qfront=qrear=0;
                arr[qrear]=value;
            }
            else{
                qrear=(qrear+1)%size;
                arr[qrear]=value;
            }
        }
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(qfront==-1||qrear==-1){
            return -1;
        }
        else{
            int item;
            if(qfront==qrear){
                item=arr[qfront];
                qfront=qrear=-1;
            }
            else{
                item=arr[qfront];
                qfront=(qfront+1)%size;
            }
            return item;
        }
    }
};
