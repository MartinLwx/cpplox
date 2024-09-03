#include "instruction/chunk.h"

void Chunk::write(std::uint8_t byte) { code_.emplace_back(byte); }
int Chunk::addConstant(Value value) {
  constants_.write(value);
  return constants_.size() - 1; // the index of value we just wrote
}
