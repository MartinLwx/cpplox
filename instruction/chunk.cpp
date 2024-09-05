#include "instruction/chunk.h"

void Chunk::write(std::uint8_t byte, int lineno) {
  code_.emplace_back(byte);
  lines_.emplace_back(lineno);
}
int Chunk::addConstant(Value value) {
  constants_.write(value);
  return constants_.size() - 1; // the index of value we just wrote
}
