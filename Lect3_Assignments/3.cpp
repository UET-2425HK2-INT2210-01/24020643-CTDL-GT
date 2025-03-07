#include <iostream>
using namespace std;

class Queue{
public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
        head = 0;
        tail = -1;
    }
    bool isEmpty(){ 
        return head > tail;
    }
    bool isFull(){
        return tail == size - 1;
    }
    void Enqueue(int x){
        if (isFull()){
            return;
        }
        arr[++tail] = x;
    }
    void Dequeue(){
        if (isEmpty()){
            return;
        }
        tail--;
        for (int i = head; i <= tail; i++){
            arr[i] = arr[i + 1];
        }
    }
    int getHead(){
        return arr[head];
    }
    void print(){
        for (int i = head; i <= tail; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
private:
    int* arr;
    int head;
    int tail;
    int size;
};

int main(){
    int n; cin >> n;
    Queue q(n);
 for (int i = 0; i < n; i++){
        int x; cin >> x;
        q.Enqueue(x);
    }
    q.Dequeue();
    q.print();

    return 0;
}


// class Queue
//     private:
//         var arr[]
//         var head
//         var tail
//         var size

//     public:
//         // time complexity O(1) || space complexity O(n)
//         constructor Queue(var size)
//             this.size = size
//             arr = NEW ARRAY OF INTEGER WITH SIZE size
//             head = 0
//             tail = -1

//         // time complexity O(1) || space complexity O(1)
//         function isEmpty() -> BOOLEAN
//             return head > tail
//         end funtion

//         // time complexity O(1) || space complexity O(1)
//         function isFull() -> BOOLEAN
//             return tail == size - 1
//         end function

//         // time complexity O(1) || space complexity O(1)
//         function Enqueue(var x)
//             if isFull() then
//                 return
//             end if
//             tail = tail + 1
//             arr[tail] = x
//         end function

//         // time complexity O(n) || space complexity O(1)
//         function Dequeue()
//             if isEmpty() then
//                 return
//             end if
//             tail = tail - 1
//             for i = head to tail
//                 arr[i] = arr[i + 1]
//             end for
//         end function

//         // time complexity O(1) || space complexity O(1)
//         function getHead()
//             return arr[head]
//         end function

//         // time complexity O(n) || space complexity O(1)
//         function print()
//             fpr i = head to tail
//                 print arr[i] + " "
//             end for
//             print newline
//         end function
// end class
