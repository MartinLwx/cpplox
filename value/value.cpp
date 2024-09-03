#include "value/value.h"

void ValueArray::write(Value value) { values_.emplace_back(value); }
Value ValueArray::operator[](int i) const { return values_[i]; }
