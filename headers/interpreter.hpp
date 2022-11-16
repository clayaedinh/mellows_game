#ifndef MELLOWS_INTERPRET_HPP
#define MELLOWS_INTERPRET_HPP

enum InterpretResult{
    INTERPRET_NULL,
    INTERPRET_QUIT,
    INTERPRET_AGAIN,
    INTERPRET_DONE
};

InterpretResult interpretNextCommand();

#endif