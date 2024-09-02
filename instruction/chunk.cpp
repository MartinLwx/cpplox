#include "instruction/chunk.h"

void Chunk::write(OpCode byte) { code_.emplace_back(byte); }
