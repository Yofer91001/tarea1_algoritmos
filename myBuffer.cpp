#include "myBuffer.hpp"



void EditorBuffer::moveCursorForward(){

    if(after.size() != 0){
        char temp = before.top();
        before.pop();
        after.push(temp);
    }

};
void EditorBuffer::moveCursorBackward(){

    if(before.size() != 0){
        char temp = after.top();
        after.pop();
        before.push(temp);
    }
};
std::string EditorBuffer::getText(){
    unsigned before_len = before.size(), 
            after_len = after.size();

    std::string text;
    for(int i = 0; i < before_len; i++){
        moveCursorBackward();
    }
    for(int i = 0; i < before_len; i++){
        text += after.top();
        moveCursorForward();
    }
    std::cout<<"^";
    for(int i = 0; i < after_len; i++){
        text += after.top();
        moveCursorForward();
    }
    for(int i = 0; i < after_len; i++){
        moveCursorBackward();
    }
    
    return text;
};
unsigned EditorBuffer::getCursor() const{
    return before.size();
};