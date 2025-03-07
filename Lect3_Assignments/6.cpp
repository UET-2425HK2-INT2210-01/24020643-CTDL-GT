#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Stack{
private:
    Node* top;
    int size;
public:
    Stack(){
        size = 0;
        top = nullptr;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    bool isFull(){
        return size == 0;
    }
    void Push(int x){
        if (isEmpty()){
            top = new Node(x);
        } 
        else{
            Node* temp = new Node(x);
            temp->next = top;
            top = temp;
            size++;
        }
    }
    void Pop(){
        if (isEmpty()){
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int getTop(){
        return top->data;
    }
    void print(){
        Node* temp = top;
        // top to bottom
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Stack s;
    s.Push(1);
    s.Push(5);
    s.Push(6);
    s.Pop();
    s.Pop();
    cout<<s.getTop()<<endl;
    s.print();
    return 0;
}




// class Node
//     data: integer (or any data type)
//     next: point to Node

//     constructor(int x)
//         data = x
//         next = null pointer
//     end constructor

// end class

// class Stack
//     top: point to Node
//     var size
    
//     // time complexity O(1) || space complexity O(1)
//     constructor Stack()
//         size = 0
//         top = null pointer
//     end constructor

//     // time complexity O(1) || space complexity O(1)
//     function isEmpty() -> BOOLEAN
//         return top == null pointer
//     end function
    
//     // time complexity O(1) || space complexity O(1)
//     function Push(int x)
//         if (isEmpty()) then
//             top = new Node(x)
//         else
//             temp: point to Node
//             temp = new Node(x)
//             temp.next = top
//             top = temp
//         end if
//     end function

//     // time complexity O(1) || space complexity O(1)
//     function Pop()
//         if (isFull) then
//             return
//         end if

//         temp: point to Node
//         temp = top
//         top = top.next
//         free temp
//         size = size - 1
//     end function

//     // time complexity O(1) || space complexity O(1)
//     function getTop()
//         return top.data
//     end function

//     // time complexity O(n) || space complexity O(1)
//     function print()
//         temp: point to Node
//         temp = top

//         while (temp != null pointer)
//             print(temp.data)
//             print(" ")
//             temp = temp.next
//         end while
//     end function
    
// end class