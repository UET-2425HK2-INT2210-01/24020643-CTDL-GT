#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Queue{
public:
    Queue(){
        size = 0;
        head = nullptr;
    }
    bool isEmpty(){
        return head == nullptr;
    }
    void Enqueue(int x){
        if (isEmpty()){
            head = new Node(x);
        }
        else{
            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = new Node(x);
        }
    }
    void Dequeue(){
        if (isEmpty()){
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    int getFront(){
        return head->data;
    }
    void Print(){
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
private:
    Node* head;
    int size;
};

int main(){
    Queue q;
    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Dequeue();
    q.Enqueue(7);
    q.Print();
}




// class Node 
// public:
//     var data
//     next: point to Node
//     constructor(var value)
//         data = value
//         next = null pointer
//     end constructor
// end 

// class Queue
// private:
//     head: point to Node
//     var size

// public:
//     // time complexity O(1) || space complexity O(1)
//     constructor Queue()
//         size = 0
//         head = null pointer
//     end constructor

//     // time complexity O(1) || space complexity O(1)
//     function isEmpty() -> BOOLEAN
//         return head == null pointer
//     end function

//     // time complexity O(n) || space complexity O(1)
//     function Enqueue(var x)
//         if isEmpty() then
//             head = new Node(x)
//         else    
//             temp: point to Node
//             while(temp.next != null pointer)
//                 temp = temp.next
//             end while
//             temp.next = new Node(x)
//         end if
//     end function

//     // time complexity O(1) || space complexity O(1)
//     function Dequeue()
//         if isEmpty() then
//             return
//         end if
//         temp: point to Node
//         temp = head
//         head = head.next
//         delete temp
//     end function

//     // time complexity O(1) || space complexity O(1)
//     function getFront()
//         return head.data
//     end function

//     // time complexity O(n) || space complexity O(1)
//     funtion Print()
//         temp: point to Node
//         temp = head
//         while (temp != nullptr)
//             print temp.data + " "
//             temp = temp.next
//         end while
//         print newline
//     end function

// end class

        