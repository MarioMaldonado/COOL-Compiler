#ifndef SEMANTICANALYZER_H
#define SEMANTICANALYZER_H

#include "ast.hpp"
#include <map>
#include <set>
#include <vector>
#include <memory>

class Program;
class Class;
typedef std::vector<std::shared_ptr<Class>> Classes;

struct Environment
{
    Symbol curr_class;
};

class SemanticAnalyzer
{
private:
    std::set<std::string> visited;
    std::set<std::string> processed;

    bool invalid_parent(const std::string&); 
    bool cyclic_check(std::map<std::string, std::string>&, const std::string&);

public:
    bool validate_inheritance(const Classes&); 
    bool type_check(const std::shared_ptr<Program>&);
};


#endif
