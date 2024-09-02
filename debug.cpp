#include "debug.h"
#include "instruction/chunk.h"
#include <cstdio>
#include <iostream>
#include <string_view>

int simpleInstruction(std::string_view name, int offset) {
  std::cout << name;
  return offset + 1;
}

void disassembleChunk(const Chunk *chunk, std::string_view name) {
  std::cout << "== " << name << " ==\n";
  for (int offset = 0; offset < chunk->getCode().size();) {
    offset = disassembleInstruction(chunk->getCode()[offset], offset);
  }
}

int disassembleInstruction(OpCode instruction, int offset) {
  printf("%04d ", offset);

  switch (instruction) {
  case OpCode::OP_RETURN:
    return simpleInstruction("OP_RETURN", offset);
  default:
    printf("Unknown opcode, Skip");
    return offset + 1;
  }
}
