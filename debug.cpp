#include "debug.h"
#include "instruction/chunk.h"
#include <iomanip>
#include <iostream>
#include <string_view>

static int simpleInstruction(std::string_view name, int offset) {
  std::cout << name << "\n";
  return offset + 1;
}

static int constantInstruction(std::string_view name, const Chunk *chunk,
                               int offset) {
  auto constant_idx{chunk->getCode()[offset + 1]};
  std::cout << std::left << std::setw(16) << name;
  std::cout << std::right << std::setw(4) << constant_idx << " '";
  std::cout << chunk->getValueArray()[constant_idx];
  std::cout << "'\n";
  return offset + 2;
}

void disassembleChunk(const Chunk *chunk, std::string_view name) {
  std::cout << "== " << name << " ==\n";
  for (int offset = 0; offset < chunk->getCode().size();) {
    offset = disassembleInstruction(chunk, offset);
  }
}

int disassembleInstruction(const Chunk *chunk, int offset) {
  std::cout << std::setw(4) << std::setfill('0') << offset << " "
            << std::setfill(' ');

  auto instruction{chunk->getCode()[offset]};

  switch (instruction) {
  case OpCode::OP_CONSTANT:
    return constantInstruction("OP_CONSTANT", chunk, offset);
  case OpCode::OP_RETURN:
    return simpleInstruction("OP_RETURN", offset);
  default:
    std::cout << "Unknown opcode, Skip" << "\n";
    return offset + 1;
  }
}
