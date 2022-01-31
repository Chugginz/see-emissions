// @ IntStack.cpp

#include "IntStack.h"

bool IntStack::is_empty() const{
    return list.is_empty();
}

void IntStack::push(int operand){
    list.add_front(operand);
}

int IntStack::pop(){
    return list.remove_front();
}

void IntStack::debug_write(ostream& outfile) const{
    list.write(outfile);
}

ostream& operator<<(ostream& outfile, const IntStack& stack){
    stack.debug_write(outfile);
    
    return outfile;
}