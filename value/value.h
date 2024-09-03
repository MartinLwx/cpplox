#include <vector>
using Value = double;

class ValueArray {
public:
  void write(Value value);
  int size() const { return values_.size(); }
  Value operator[](int i) const;

private:
  std::vector<Value> values_;
};
