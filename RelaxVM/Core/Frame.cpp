#include "Frame.h"
#include "../GlobalVariables.h"

Frame::Frame(Method* method, const VariableList& variableList) : method(method), variables(variableList)
{
}

Variable* Frame::GetVariable(int id)
{
    return &variables[id];
}

Method* Frame::GetMethod() const
{
    return method;
}

VariableList Frame::GetVariableList() const
{
    return variables;
}

void Frame::SetMethod(Method* method)
{
    this->method = method;
}

void Frame::SetVariableList(const VariableList& variables)
{
    this->variables = variables;
}

void Frame::CreateVariable(int id, const QString& dataType)
{
    variables[id] = Variable(GlobalVariables::heap.push_back(new RelaxNull), dataType);
}

Stack& Frame::GetStack()
{
    return stack;
}

OpBase* Frame::Next()
{
    return method->GetCode()[index++];
}

bool Frame::IsEnd()
{
    return index >= method->GetCode().size();
}

void Frame::SetIndex(int index)
{
    this->index = index;
}
