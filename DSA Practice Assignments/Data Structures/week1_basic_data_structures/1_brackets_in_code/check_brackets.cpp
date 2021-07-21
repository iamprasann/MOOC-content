#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int flag=0;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket item;
            item.type=next;
            item.position=position;
            opening_brackets_stack.push(item);
        }

        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty()){
                cout<<position+1;
                flag=1;
                break;
            }
            else{
                Bracket top=opening_brackets_stack.top();
                if(top.Matchc(next)){
                    opening_brackets_stack.pop();
                    continue;
                }
                else{
                    cout<<position+1;
                    flag=1;
                    break;
                }
            }

        }
    }

    if(flag==1)
        return 0;
    else
        if(opening_brackets_stack.empty())
            cout<<"Success";
        else
            cout<<(opening_brackets_stack.top().position+1);

    return 0;
}
