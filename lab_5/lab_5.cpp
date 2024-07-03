#include <iostream>
#include <stack>
#include <string>

bool areBracketsBalanced(const std::string& expr) {
    std::stack<char> s;
    char x;
    bool hasBrackets = false;

    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
            hasBrackets = true;
            continue;
        }

        if (ch == ')' || ch == ']' || ch == '}') {
            hasBrackets = true;
            if (s.empty())
                return false;

            switch (ch) {
            case ')':
                x = s.top();
                s.pop();
                if (x != '(')
                    return false;
                break;

            case ']':
                x = s.top();
                s.pop();
                if (x != '[')
                    return false;
                break;

            case '}':
                x = s.top();
                s.pop();
                if (x != '{')
                    return false;
                break;
            }
        }
    }

    if (!hasBrackets) {
        throw std::invalid_argument("В строке нет скобок");
    }

    return s.empty();
}

int main() {
    setlocale(LC_ALL, "rus");
    std::string expr;

    std::cout << "Введите строку: ";
    std::getline(std::cin, expr);

    try {
        if (areBracketsBalanced(expr))
            std::cout << "Скобки расставлены верно" << std::endl;
        else
            std::cout << "Скобки расставлены не верно" << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}