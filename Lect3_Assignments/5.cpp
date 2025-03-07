#include <iostream>
using namespace std;

class Stack{
private:
    int* arr;
    int top;
    int size;
public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    bool isEmpty(){ 
        return top == -1; 
    }
    bool isFull(){
        return top == size - 1;
    }
    void Push(int x){
        if (isFull()){
            return;
        }
        arr[++top] = x;
    }
    void Pop(){
        if (isEmpty()){
            return;
        }
        top--;
    }
    int getTop(){
        return arr[top];
    }
    void print(){
        for (int i = top; i >= 0; i--){
            cout << arr[i] << " ";
        }
        cout << '\n';
    }

};
int main(){
    Stack s(25);
    s.Push(15);
    s.Push(25);
    s.Pop();
    s.Pop();
    s.Push(100);
    s.Push(250);
    s.print();
    return 0;
}





// class Stack
//     var arr[]
//     var top
//     var size
//     // time complexity O(1) || space complexity O(n)
//     function initializeStack(Size)
//         stack = array of size Size
//         top = -1
//     end function

//     // time complexity O(1) || space complexity O(1)
//     function isEmpty(stack) -> BOOLEAN
//         return top == -1
//     end function

//     // time complexity O(1) || space complexity O(1)
//     function isFull(stack) -> BOOLEAN
//         return top == Size - 1
//     end function

//     // time complexity O(1) || space complexity O(1)
//     function Push(x)
//         if isFull(stack) == true
//             return
//         end if

//         top = top + 1
//         stack[top] = x
//     end function

//     // time complexity O(1) || space complexity O(1)
//     function Pop()
//         if isEmpty(stack) == true
//             return 
//         end if

//         top = top - 1
//     end function

//     // time complexity O(1) || space complexity O(1)
//     function getTop()
//         return stack[top]
//     end function

//     // time complexity O(n) || space complexity O(1)
//     function print()
//         for i = top to 0
//             print(stack[i])
//             print('\n')
//         end for
//     end function

// end class