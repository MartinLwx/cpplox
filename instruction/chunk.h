#ifndef CPPLOX_CHUNK_H
#define CPPLOX_CHUNK_H

#include <vector>

enum class OpCode {
  OP_RETURN, // returns from the current function
};

class Chunk {
public:
  void write(OpCode byte);
  const std::vector<OpCode> &getCode() const { return code_; }

private:
  std::vector<OpCode> code_;
};

#endif
