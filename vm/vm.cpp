#include "vm.h"

InterpretResult VM::interpret(Chunk *chunk) {
  chunk_ = chunk;
  ip_ = 0;
  return run();
}
