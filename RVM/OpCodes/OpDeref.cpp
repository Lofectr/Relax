#include "OpDeref.h"
#include "../Core/FieldObject.h"
#include "../Std/Classes/RelaxPointer.h"

void OpDeref::Run()
{
	Value* value = frame->GetStack().pop();
	RelaxPointer* pointer = dynamic_cast<RelaxPointer*>(value->value.object);
	if (pointer->GetData().isAddress)
		frame->GetStack().push(frame->AddValue(new Value(ValueType::OBJECT, UValue{ .object = GlobalVariables::heap[pointer->GetData().data.address] })));
	else
	{
		frame->GetStack().push(pointer->GetData().data.value);
	}
}

void OpDeref::Parse(ifstream& device)
{
}
