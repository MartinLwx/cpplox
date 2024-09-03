#ifndef CPPLOX_DEBUG_H
#define CPPLOX_DEBUG_H

#include "instruction/chunk.h"

void disassembleChunk(const Chunk *chunk, std::string_view name);
int disassembleInstruction(const Chunk *chunk, int offset);

#endif
