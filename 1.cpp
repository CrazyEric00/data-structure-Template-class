#include <iostream>
#include <cstring>
using namespace std;


template <class T>
class Vec{
private:
    T* s;
    int _space;
    int _size;
public:
    Vec(int n){
        s=new T[n];
        _space=n;
        _size=0;
    }
    ~Vec(){
        delete[] s;
    }
    bool empty(){
        return _size==0;
    }
    int size(){
        return _size;
    }
    T get(int i){
        return s[i];
    }
    void modify(int i,T v){
        s[i]=v;
    }
    bool insert(int i,T v){
        if(i<0){
            if(_size>=_space)
                return false;
            s[_size++]=v;
            return true;
        }
        else{
            if(_size>=_space||i>=_space)
                return false;
            for(int j=_size;j>i;j--)
                s[j]=s[j-1];
            s[i]=v;
            _size++;
            return true;
        }
    }
    bool del(int i){
        if(i>=_size)
            return false;
        for(int j=i;j<_size-1;j++)
            s[j]=s[j+1];
        _size--;
        return true;
    }
    void output(){
        for(int i=0;i<_size;i++){
            if(i)
                cout << ' ';
            cout << s[i];
        }
        cout << endl;
    }
};


template <class T>
struct Node{
    T data;
    Node<T>* next;
};

template <class T>
class Link{
private:
    Node<T> *head,*tail,*p;
public:
    Link():head(NULL),tail(NULL){}
    ~Link(){
        p = head;
        while (p) {
            Node<T> *_next = p->next;
            delete p;
            p = _next;
        }
        head = tail = p = NULL;
    }
    bool insert(T x)
    {
        if (head == NULL) {
            p=(Node<T>*)malloc(sizeof(T));
            p->data=x;
            p->next=NULL;
            head=tail=p;
        }
        else
        {
            p =(Node<T>*)malloc(sizeof(T));
            p->data=x;
            p->next=NULL;
            tail->next = p;
            tail=p;
        }
        return true;
    }
    //重载插入方法
    bool insert(int num,T x){
        if(num<0) {
            return insert(x);
        }
        else if(num==0){
            p=(Node<T>*)malloc(sizeof(T));
            p->data=x;
            p->next=head;
            head=p;
            return true;
        }
        else{
            p=head;
            num--;
            while(num) {
                p = p->next;
                num--;
                if(p==tail&&num>0)
                    return false;
            }
            Node<T>* t=(Node<T>*)malloc(sizeof(T));
            t->data=x;
            if(p->next==NULL) {
                p->next = t;
                tail=t;
                t=NULL;
            }
            else{
                t->next=p->next;
                p->next=t;
                t=NULL;
            }
            return true;
        }
    }
    T get(int num){
        p=head;
        for(int i=0;i<num;i++) {
            p = p->next;
            if(p==NULL)
                return NULL;
        }
        return p->data;
    }
    void output(){
        p=head;
        while(p!=tail->next){
            cout << p->data << ' ';
            p=p->next;
        }
        cout << '\b' << endl;
    }
    bool del(int num){
        p=head;
        if(num==0) {
            head = head->next;
            delete p;
        }
        else{
            num--;
            while(num){
                p=p->next;
                num--;
                if(p==tail)
                    return false;
            }
            if(p->next==tail)
                tail=p;
            else
                p->next=p->next->next;
        }
        return true;
    }
};

int main(){
    //首先是顺序表
    int n=5;
    Vec<int> v(n);
    v.insert(0,1);
    v.insert(1,2);
    v.insert(2,3);
    v.insert(3,4);
    v.insert(4,5);
    v.del(0);
    v.modify(0,100);
    cout << v.size() << endl;
    v.output();
    //然后是单链表
    Link<int> link;
    link.insert(1);
    link.insert(2);
    link.insert(3);
    link.insert(4);
    link.insert(5);
    link.del(4);
    link.insert(3,100);
    link.output();
    return 0;
}

