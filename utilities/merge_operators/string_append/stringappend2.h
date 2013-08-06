/**
 * A TEST MergeOperator for rocksdb/leveldb that implements string append.
 * It is built using the MergeOperator interface rather than the simpler
 * AssociativeMergeOperator interface. This is useful for testing/benchmarking.
 * While the two operators are semantically the same, all production code
 * should use the StringAppendOperator defined in stringappend.{h,cc}. The
 * operator defined in the present file is primarily for testing.
 *
 * @author Deon Nicholas (dnicholas@fb.com)
 * Copyright 2013 Facebook
 */

#include "leveldb/merge_operator.h"
#include "leveldb/slice.h"

namespace leveldb {

class StringAppendTESTOperator : public MergeOperator {
 public:

  StringAppendTESTOperator(char delim_char);    /// Constructor with delimiter

  virtual bool Merge(const Slice& key,
                     const Slice* existing_value,
                     const std::deque<std::string>& operand_sequence,
                     std::string* new_value,
                     Logger* logger) const override;

  virtual bool PartialMerge(const Slice& key,
                            const Slice& left_operand,
                            const Slice& right_operand,
                            std::string* new_value,
                            Logger* logger) const override;

  virtual const char* Name() const override;

 private:
  char delim_;         // The delimiter is inserted between elements

};

} // namespace leveldb