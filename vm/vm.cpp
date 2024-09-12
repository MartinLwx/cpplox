#include "vm.h"

// TODO: Is Pointer Copy a good thing or not?
//       What's the better way?
InterpretResult VM::interpret(Chunk *chunk) {
  chunk_ = chunk;
  ip_ = 0;
  return run();
}
