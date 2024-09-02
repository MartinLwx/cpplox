#include "debug.h"
#include "instruction/chunk.h"

int main() {
  Chunk chunk{}; // value initialization
  chunk.write(OpCode::OP_RETURN);
  disassembleChunk(&chunk, "test chunk");
}
