#include <bits/stdc++.h> 
class Queue {
public:
    int qfront;
    int qrear;
    int*arr;
    int size;
    Queue() {
        // Implement the Constructor
        size=10000;
        qfront=0;
        qrear=0;
        arr=new int[size];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront==qrear){
           return true;
        }
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(qrear==size){
            return;
        }
        else{
            arr[qrear++]=data;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront==qrear)
        { return -1;
        }
        else{
            int t=arr[qfront];
            qfront++;
            if(qfront==qrear){
               qfront=0;
               qrear=0; 
            }
            return t;  
        }
        
    }

    int front() {
        // Implement the front() function
        if(qfront==qrear){
            return -1;
        }
        return arr[qfront];
    }
};
