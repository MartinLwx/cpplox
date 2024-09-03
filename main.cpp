#include "debug.h"
#include "instruction/chunk.h"

int main() {
  Chunk chunk{}; // value initialization
  int index{chunk.addConstant(1.2)};
  chunk.write(OpCode::OP_CONSTANT);
  chunk.write(index);
  chunk.write(OpCode::OP_RETURN);
  disassembleChunk(&chunk, "test chunk");
}
