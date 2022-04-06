#include <cctype>
#include <iostream>
#include <string>
#include "myBuffer.hpp"

void executeCommand(EditorBuffer &buffer, std::string);
void displayBuffer(EditorBuffer &buffer);
void printHelpText();

int main() {
  EditorBuffer buffer;
  while(true){
    std::string cmd;
    std::cout << "*";
    std::getline(std::cin, cmd);
    if(cmd != "") executeCommand(buffer, cmd);
  }
  return 0;
}

void executeCommand(EditorBuffer &buffer, std::string line) {
  switch(toupper(line[0])) {
  case 'I':
    for(int i = 1; i < line.length(); i++){
      buffer.insertCharacter(line[i]);
    }
    displayBuffer(buffer);
    break;
  case 'D':
    buffer.deleteCharacter(); displayBuffer(buffer); break;
  case 'F':
    buffer.moveCursorForward(); displayBuffer(buffer); break;
  case 'B':
    buffer.moveCursorBackward(); displayBuffer(buffer); break;
  case 'J':
    buffer.moveCursorToStart(); displayBuffer(buffer); break;
  case 'E':
    buffer.moveCursorToEnd(); displayBuffer(buffer); break;
  case 'H':
    printHelpText(); break;
  case 'Q':
    exit(0);
  dafault:
    std::cout << "Illegal command\n"; break;
  }
}

void displayBuffer(EditorBuffer &buffer) {
  std::string str = buffer.getText();
  for(int i = 0; i < str.length(); i++)
    std::cout << " " << str[i];
  std::cout << "\n";
  std::cout << std::string(2*buffer.getCursor(), ' ') << "^\n";
}

void printHelpText() {
  std::cout << "Editor commands:\n";
  std::cout << " Iabc\tInserts the characters abc at the cursor position.\n";
  std::cout << " F\tMoves the cursor forward one character.\n";
  std::cout << " B\tMoves the cursor backward one character.\n";
  std::cout << " D\tDeletes the character after the cursor.\n";
  std::cout << " J\tJumps to the beginning of the buffer.\n";
  std::cout << " J\tJumps to the end of the buffer.\n";
  std::cout << " H\tPrints this message.\n";
  std::cout << " Q\tExits from the editor program.\n";
}
