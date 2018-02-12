#include <iostream>
#include <stack>
using namespace std;

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        bool test = true;
        bool test_p = true;
        bool test_b = true;
        bool test_a = true;

        stack<char> op_left_p;
        stack<char> op_right_p;
        stack<char> op_left_b;
        stack<char> op_right_b;
        stack<char> op_left_a;
        stack<char> op_right_a;

        string ch;
        cin >> ch;
        char temp_;
        for (int i = 0; i < ch.length(); i++) {
            if ((temp_ =='(' && ch.at(i) ==']') || (temp_ =='(' && ch.at(i) =='}') || (temp_ =='[' && ch.at(i) == ')') || (temp_ == '[' && ch.at(i) == '}') || (temp_ == '{' && ch.at(i) ==')') || (temp_ == '{' && ch.at(i) ==']')) {
                test = false;
                break;
            }
            if (ch.at(i) == ')' && op_left_p.empty() && op_right_p.empty()) {
                test_p = false;
                break;
            }
            if (ch.at(i) == ']' && op_left_b.empty() && op_right_b.empty()) {
                test_b = false;
                break;
            }
            if (ch.at(i) == '}' && op_left_a.empty() && op_right_a.empty()) {
                test_a = false;
                break;
            }

            if (ch.at(i) == '(' or ch.at(i) == ')') {
                if (ch.at(i) == '(') {
                    if (op_right_p.empty())
                        op_left_p.push(ch.at(i));
                    else
                        op_right_p.pop();
                } else {
                    if (op_left_p.empty())
                        op_right_p.push(ch.at(i));
                    else
                        op_left_p.pop();
                }
            }

            if (ch.at(i) == '[' or ch.at(i) == ']') {

                if (ch.at(i) == '[') {
                    if (op_right_b.empty())
                        op_left_b.push(ch.at(i));
                    else
                        op_right_b.pop();
                } else {
                    if (op_left_b.empty())
                        op_right_b.push(ch.at(i));
                    else
                        op_left_b.pop();
                }
            }

            if (ch.at(i) == '{' or ch.at(i) == '}') {
                if (ch.at(i) == '{') {
                    if (op_right_a.empty())
                        op_left_a.push(ch.at(i));
                    else
                        op_right_a.pop();
                } else {
                    if (op_left_a.empty())
                        op_right_a.push(ch.at(i));
                    else
                        op_left_a.pop();
                }
            }
            temp_ = ch.at(i);
        }

        if (test == false) {
            cout << "NO" << endl;
            continue;
        }
        if (test_p == false || test_b == false || test_a == false) {
            cout << "NO" << endl;
            continue;
        }

        if (op_right_p.empty() && op_left_p.empty() && op_right_b.empty() && op_left_b.empty() && op_right_a.empty() && op_left_a.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


    return 0;
}
