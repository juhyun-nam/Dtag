
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "dtag/env/enviroment.h"
#include "dtag/operations/add.h"
#include "dtag/operations/clear.h"
#include "dtag/operations/help.h"
#include "dtag/operations/recent.h"
#include "dtag/operations/remove.h"
#include "dtag/operations/search.h"
#include "dtag/operations/show.h"

namespace dtag {
namespace {
class FakeEnviroment : public env::Enviroment {
 public:
  FakeEnviroment() = default;
  virtual ~FakeEnviroment() = default;
  const std::string& TagReadFile() const override { return read_; }
  const std::string& TagWriteFile() const override { return write_; }
  const std::string& RecentFile() const override { return recent_; }
  const std::string& CurrentDirectory() const override { return cur_dir_; }
  void OverwriteTagFile() const override {
    if (std::rename(TagWriteFile().data(), TagReadFile().data())) {
      throw std::runtime_error("CAN NOT RENAME TAG FILE");
    }
  }

 private:
  static const std::string read_;
  static const std::string write_;
  static const std::string recent_;
  static const std::string cur_dir_;
};
const std::string FakeEnviroment::read_ = "dtag_read.test";
const std::string FakeEnviroment::write_ = "dtag_write.test";
const std::string FakeEnviroment::recent_ = "dtag_recent.test";
const std::string FakeEnviroment::cur_dir_ = get_current_dir_name();

FakeEnviroment fake_env;
}  // namespace

TEST_CASE("add operation test") {
  op::Add op(fake_env);
  op.Process("tag");
  CHECK_NOTHROW();
}
TEST_CASE("clear operation test") {
  op::Clear op(fake_env);
  op.Process("tag");
  CHECK_NOTHROW();
}
TEST_CASE("help operation test") {
  op::Help op;
  op.Process("tag");
  CHECK_NOTHROW();
}
TEST_CASE("recent operation test") {
  op::Recent op(fake_env);
  op.Process("tag");
  CHECK_NOTHROW();
}
TEST_CASE("remove operation test") {
  op::Remove op(fake_env);
  op.Process("tag");
  CHECK_NOTHROW();
}
TEST_CASE("search operation test") {
  op::Search op(fake_env);
  op.Process("tag");
  CHECK_NOTHROW();
}
TEST_CASE("show operation test") {
  op::Show op(fake_env);
  op.Process("tag");
  CHECK_NOTHROW();
}

}  // namespace dtag
