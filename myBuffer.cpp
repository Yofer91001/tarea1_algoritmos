#include "myBuffer.hpp"
//Lo hicimos con el hpp adjunto


void EditorBuffer::insertCharacter(char ch){
    before.push(ch);
}
void EditorBuffer::deleteCharacter(){
    if(before.size() >0 ){
        before.pop();
    }else{
        throw std::runtime_error("NOTHING TO DELETE");
    }

}
void EditorBuffer::moveCursorForward(){

    if(after.size() != 0){
        char temp = after.top();
        after.pop();
        before.push(temp);
    }

};
void EditorBuffer::moveCursorBackward(){

    if(before.size() != 0){
        char temp = before.top();
        before.pop();
        after.push(temp);
    }
};
void EditorBuffer::moveCursorToStart(){
    while(!before.empty()){
        char temp = before.top();
        before.pop();
        after.push(temp);
    }
};
void EditorBuffer::moveCursorToEnd(){
    while(!after.empty()){
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
