#define DEBUG_TRACE_EXECUTION
#include "instruction/chunk.h"
#include "vm/vm.h"

int main() {
  Chunk chunk{}; // value initialization
  int index{chunk.addConstant(1.2)};
  chunk.write(OpCode::OP_CONSTANT, 123);
  chunk.write(index, 123);
  chunk.write(OpCode::OP_RETURN, 123);

  VM vm;
  vm.interpret(&chunk);
}
