#include <stdexept>
#include <new>
#include <cstdlib>

namespace AFBIC{
    template<typename T>
    class Stack{
    private:
        T* inptr;
        int size,toploc;
        //toploc:highest empty location
    public:
        explicit Stack(const int s);
        explicit Stack(const Stack s);
        explicit Stack(const Stack&& s);
        
        ~Stack();
        
        void operator=(Stack s);
        
        void push(T data);
        void pop();
        int size();
        T top();
        bool empty();
        }//Stack
    }//namespace AFBIC

AFBIC::Stack::Stack(const int s){
    try{
        inptr=new T[s];
    }
    catch(std::bad_alloc& ba){
        size=0;
        toploc=0;
        inptr=nullptr;
        throw;
    }
    size=s;
    toploc=0;
}

AFBIC::Stack::Stack(const Stack s){
    try{
        inptr=new T[s.size];
    }
    catch(std::bad_alloc& ba){
        size=0;
        toploc=0;
        inptr=nullptr;
        throw;
    }
    size=s.size;
    toploc=s.toploc;
    for(int head=0;head!=toploc;head++){
        inptr[head]=s.inptr[head];
    }
}

AFBIC::Stack::Stack(const Stack&& s){
    inptr=s.inptr; //just moving
    size=s.size;
    toploc=s.toploc;
}

AFBIC::Stack::~Stack(){
    delete(inptr);
    size=0;
    toploc=0;
}

bool AFBIC::Stack::empty(){
    if(toploc==0) return true;
    return false;
}

int AFBIC::Stack::size(){
    return toploc;
}

template <typename T>
T AFBIC::Stack::top(){
    return inptr[toploc-1];
}

void AFBIC::Stack::pop(){
    if(empty()) throw std::runtime_error("Stack Underflow");
    else toploc=toploc-1;
}

template <typename T>
void AFBIC::Stack::push(T data){
    if(toploc>size) throw std::runtime_error("Stack Overflow");
    inptr[toploc]=data;
    toploc++;
}
