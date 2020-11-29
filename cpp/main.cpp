
#include <iostream>
#include "problem/backtrack/10.h"
#include <unordered_map>

using namespace std;

int main() {
    int a = 12;
    int *p = &a;
    return 0;
}

struct Scope {
    std::unordered_map<std::string, void *> variables;
    Scope *parent;
};

void *get_val(const Scope *scope, const std::string &name) {
    if (scope == nullptr) return nullptr;
    auto p = scope->variables.find(name);
    if (p != scope->variables.end()) {
        return p->second;
    }
    return get_val(scope->parent, name);
}