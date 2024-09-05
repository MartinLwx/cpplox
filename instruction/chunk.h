#ifndef CPPLOX_CHUNK_H
#define CPPLOX_CHUNK_H

#include "value/value.h"
#include <cstdint>
#include <vector>

enum OpCode : std::uint8_t {
  OP_CONSTANT,
  OP_RETURN, // returns from the current function
};

class Chunk {
public:
  void write(std::uint8_t byte, int lineno);
  int addConstant(Value value);
  const std::vector<std::uint8_t> &getCode() const { return code_; }
  const std::vector<int> &getLines() const { return lines_; }
  const ValueArray &getValueArray() const { return constants_; }

private:
  std::vector<std::uint8_t> code_;
  std::vector<int> lines_;
  ValueArray constants_;
};

#endif
