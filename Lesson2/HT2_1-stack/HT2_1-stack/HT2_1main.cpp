#include <iostream>
#include <string>
#include <stack>

#include "HT2_1head.hpp"

void EnterString (std::string &MyString){
    getline(std::cin, MyString);
};

bool CheckValidString (std::string const & MyString, std::stack<char> & MyStack){
    for (auto element : MyString){
        if (element == '\0'){
            break;
        }
        MyStack.push(element);
    }

    size_t BracketsOpened = 0, BracketsClosed = 0,
          CurlyBracketsOpened = 0, CurlyBracketsClosed = 0,
          SquareBracketsOpened = 0, SquareBracketsClosed = 0;
    size_t sizeOfStack = MyStack.size();

    if ((MyStack.top() == ')') || (MyStack.top() == '}') || (MyStack.top() == ']')){
        char previousElement;
        for (size_t i = 0; i < sizeOfStack; ++i){

            int closeCheck = 0;
            if((MyStack.top() != '[') && (MyStack.top() != ']') && (MyStack.top() != '(')
                && (MyStack.top() != ')') && (MyStack.top() != '{') && (MyStack.top() != '}')){
                return false;
                break;
            }

            else if(((MyStack.top() == '(') && (BracketsOpened == 0) && (BracketsClosed == 0))
            || ((MyStack.top() == '{') && (CurlyBracketsOpened == 0) && (CurlyBracketsClosed == 0))
            || ((MyStack.top() == '[') && (SquareBracketsOpened == 0) && (SquareBracketsClosed == 0))){
                return false;
                break;
            }

            else if ((MyStack.top() == '(') && (previousElement != ')')){
                return false;
                break;
            }
            else if ((MyStack.top() == '[') && (previousElement != ']')){
                return false;
                break;
            }
            else if ((MyStack.top() == '{') && (previousElement != '}')){
                return false;
                break;
            }

            else if (MyStack.top() == ')'){
                BracketsClosed++;
            }
            else if (MyStack.top() == '('){
                BracketsOpened++;
            }
            else if (MyStack.top() == '}'){
                CurlyBracketsClosed++;
            }
            else if (MyStack.top() == '{'){
                CurlyBracketsOpened++;
            }
            else if (MyStack.top() == ']'){
                SquareBracketsClosed++;
            }
            else if (MyStack.top() == '['){
                SquareBracketsOpened++;
            }
            previousElement = MyStack.top();

            MyStack.pop();
        }
        if ((BracketsOpened == BracketsClosed) &&
            (CurlyBracketsOpened == CurlyBracketsClosed) &&
            (SquareBracketsOpened == SquareBracketsClosed)){
            return true;
        }
        else {
            return false;
        }
    }
    return 0;
};

int main()
{
    std::cout << "In(enter only brackets):";
    std::string MyString;
    EnterString(MyString);

    std::stack<char> MyStack;

    std::cout << CheckValidString(MyString, MyStack) << std::endl;

    return 0;
}