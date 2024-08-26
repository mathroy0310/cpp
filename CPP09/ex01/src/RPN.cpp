/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:48:21 by maroy             #+#    #+#             */
/*   Updated: 2024/08/20 23:08:29 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

namespace {
bool isOP(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
}  // namespace

RPN::RPN(const std::string &arg) {
    // std::cout << "RPN parametric constructor called" << std::endl;

    size_t i = 0;
    while (i < arg.length()) {
        // Skip whitespace
        while (i < arg.length() && isspace(arg[i])) {
            i++;
        }
        if (i == arg.length()) {
            break;
        }
        if (isdigit(arg[i])) {
            handleDigit(arg, i);
        } else if (::isOP(arg[i])) {
            handleOperator(arg[i]);
        } else {
            throw std::invalid_argument(std::string("Invalid expression: invalid character {") + arg[i] + "}");
        }
        i++;
    }

    if (!_stack.empty()) {
        std::cout << _stack.top() << std::endl;
    } else {
        throw std::invalid_argument("Invalid expression: empty stack");
    }
}

void RPN::handleDigit(const std::string &arg, size_t &i) {
    if (i + 1 < arg.length() && isdigit(arg[i + 1])) {
        throw std::invalid_argument("Invalid expression: only 0-9");
    }
    _stack.push(arg[i] - '0');
}

void RPN::handleOperator(char op) {
    if (_stack.size() < 2) {
        throw std::invalid_argument("Invalid expression: not enough operands");
    }
    if (_stack.top() == 0 && op == '/') {
        throw std::invalid_argument("Invalid expression: division by zero");
    }

    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();
    _stack.pop();

    switch (op) {
    case '+':
        _stack.push(b + a);
        break;
    case '-':
        _stack.push(b - a);
        break;
    case '*':
        _stack.push(b * a);
        break;
    case '/':
        _stack.push(b / a);
        break;
    default:
        throw std::invalid_argument("Invalid operator");
    }
}

RPN::RPN() {
    // std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const RPN &other) {
    // std::cout << "RPN copy constructor called" << std::endl;
    *this = other;
}

RPN &RPN::operator=(const RPN &rhs) {
    // std::cout << "RPN assignation operator called" << std::endl;
    if (this == &rhs)
        return *this;
    this->_stack = rhs._stack;
    return *this;
}

RPN::~RPN() {
    // std::cout << "RPN destructor called" << std::endl;
}