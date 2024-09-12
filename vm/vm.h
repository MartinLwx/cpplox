#ifndef CPPLOX_VM_H
#define CPPLOX_VM_H

#include <vector>
#define DEBUG_TRACE_EXECUTION
#include "debug/debug.h"
#include "instruction/chunk.h"
#include <iostream>

enum class InterpretResult {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR,
};

class VM {
public:
  InterpretResult interpret(Chunk *chunk);

private:
  Chunk *chunk_;
  std::uint8_t ip_;
  std::vector<Value> stack_;

  InterpretResult run() {
    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
      std::cout << "          ";
      for (const auto &slot : stack_) {
        std::cout << "[ " << slot << " ]";
      }
      std::cout << "\n";
      disassembleInstruction(chunk_, ip_);
#endif
      auto instruction{chunk_->getCode()[ip_++]};
      switch (instruction) {
      case OP_RETURN: {
        auto last{stack_[stack_.size() - 1]};
        std::cout << last << "\n";
        return InterpretResult::INTERPRET_OK;
      }
      case OP_CONSTANT: {
        auto constant{chunk_->getValueArray()[chunk_->getCode()[ip_++]]};
        stack_.emplace_back(constant);
        break;
      }
      }
    }
  };
};

#endif
