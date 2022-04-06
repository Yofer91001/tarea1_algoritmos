#ifndef _MYBUFFER_HPP
#define _MYBUFFER_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <stack>

class EditorBuffer{
    private:
        std::stack<char> before;
        std::stack<char> after;
    public:
        EditorBuffer(){}
        ~EditorBuffer(){}
        void moveCursorForward();
        void moveCursorBackward();
        void moveCursorToStart();
        void moveCursorToEnd();
        void insertCharacter(char ch);
        void deleteCharacter();
        std::string getText();
        unsigned getCursor() const;
        void display() const;
};
#endif
