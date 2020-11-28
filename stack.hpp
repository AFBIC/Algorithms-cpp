#include <stdexept>
#include <cstdlib>

namespace AFBIC{
    template<typename T>
    class Stack{
    private:
        T* inptr;
        int size,toploc;
    public:
        Stack();
        explicit Stack(const int size);
        explicit Stack(Stack s);
        
        ~Stack();
        
        push();
        pop();
        size();
        top();
        empty();
        expand(int new_size);
        shrink(int new_size);
        shrink_safe(int new_size);
        shrink_to_fit();
        }//Stack
    }//namespace AFBIC

