#ifndef ASTNODETYPECHECKER_H
#define ASTNODETYPECHECKER_H

#include "astnodevisitor.hpp"

class AstNodeTypeChecker : public AstNodeVisitor
{
private:
    SymbolTable<Symbol, Symbol> env;  
    std::map<ClassPtr, ClassPtr> inherit_graph;

    bool is_subtype(const Symbol& child, const Symbol& parent);

public:
    AstNodeTypeChecker(const std::map<ClassPtr, ClassPtr>&);
    void visit(Program&);
    void visit(Class&);
    void visit(Feature&);
    void visit(Attribute&);
    void visit(Method&);
    void visit(Formal&);
    void visit(StringConst&);
    void visit(IntConst&);
    void visit(BoolConst&);
    void visit(New&);
    void visit(IsVoid&);
    void visit(CaseBranch&);
    void visit(Assign&);
    void visit(Block&);
    void visit(If&);
    void visit(While&);
    void visit(Complement&);
    void visit(LessThan&);
    void visit(EqualTo&);
    void visit(LessThanEqualTo&);
    void visit(Plus&);
    void visit(Sub&);
    void visit(Mul&);
    void visit(Div&);
    void visit(Not&);
    void visit(StaticDispatch&);
    void visit(DynamicDispatch&);
    void visit(Let&);
    void visit(Case&);
    void visit(Object&);
    void visit(NoExpr&);
};

#endif