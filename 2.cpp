#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Stack{
private:
    T* s;
    int p;
    int _space;
public:
    Stack(int n){
        s=new T[n];
        _space=n;
        p=-1;
    }
    ~Stack(){
        delete[] s;
    }
    bool empty(){
        return p==_space-1;
    }
    int size(){
        return p+1;
    }
    T top(){
        if(p==-1)
            return NULL;
        else
            return s[p];
    }
    bool push(T v){
        if(empty())
            return false;
        else{
            p++;
            s[p]=v;
            return true;
        }
    }
    bool pop(){
        if(p==-1)
            return false;
        else
            p--;
    }
    void clear(){
        p=-1;
    }
    void output(){
        for(int i=0;i<=p;i++)
            cout << s[i] << ' ';
        cout << '\b' << endl;
    }
};

template <class T>
struct Node{
    T data;
    Node<T>* next;
};


template <class T>
class Queue{
private:
    int _size;
    Node<T> *head,*tail,*pre;
public:
    Queue(){
        head=new Node<T>();
        head->next=NULL;
        pre=tail=head;
        _size=0;
    }
    ~Queue(){
        pre=head=tail=NULL;
    }
    bool empty(){
        if(head==tail)
            return true;
        else
            return false;
    }
    int size(){
        return _size;
    }
    void push(T v){
        tail=new Node<T>();
        tail->data=v;
        pre->next=tail;
        tail->next=NULL;
        pre=tail;
        _size++;
    }
    T front(){
        if(empty())
            return NULL;
        else{
            return head->next->data;
        }
    }
    bool pop(){
        if(empty())
            return false;
        else{
            head=head->next;
            _size--;
            return true;
        }
    }
};

int main(){
//    Stack<int> sta(3);
//    sta.push(1);
//    sta.push(2);
//    sta.push(3);
//    sta.output();
//    sta.clear();
//    sta.push(100);
//    sta.output();
    Queue<int> que;
    que.push(1);
    cout << que.front() << endl;
    que.push(2);
    que.push(3);
    que.pop();
    cout << que.front() << endl;
    que.pop();
    cout << que.front() << endl;
    return 0;
}
