#include <bits/stdc++.h> 
class Deque
{
public:
    // Initialize your data structure.
    int qfront;
    int qrear;
    int*arr;
    int size;
    Deque(int n)
    {
        // Write your code here.
        size=n;
        arr=new int[size];
        qfront=-1;
        qrear=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(qfront==(qrear+1)%size){
            return false;
        }
       
        else if(qfront==-1){
                qfront=qrear=0;
                arr[qfront]=x;
        }
        else if(qfront==0)
        {
                qfront=size-1;
                arr[qfront]=x;
        }
        else{
                qfront--;
                arr[qfront]=x;
        }
        return true;
    }
    

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(qfront==(qrear+1)%size){
            return false;
        }
        else{
            if(qfront==-1 && qrear==-1){
                qfront=qrear=0;
                arr[qrear]=x;
            }
            else{
                qrear=(qrear+1)%size;
                arr[qrear]=x;
            }
        }
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
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

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {   int item;
        // Write your code here.
        if(qfront==-1||qrear==-1){
            return -1;
        }
        
        else if(qfront==qrear){
            item=arr[qrear];
            qfront=qrear=-1;
        }
        else if(qrear==0){
            item=arr[qrear];
            qrear=size-1;
        }
        else{
            item=arr[qrear];

            qrear--;
        }
        return item;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(qfront==-1){
            return -1;
        }
        return arr[qfront];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(qrear==-1){
            return -1;
        }
        return arr[qrear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(qfront==-1){
            return true;
        }
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if(qfront==(qrear+1)%size){
            return true;
        }
        return false;
    }
};
