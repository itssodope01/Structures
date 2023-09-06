
#include <Structures/Dictionary.h>
#include <gtest/gtest.h>

std::string demangle(char const *name);
std::string demangle(char const *name)
{
    int status = -4;
    std::unique_ptr<char, void (*)(void *)> res{abi::__cxa_demangle(name, NULL, NULL, &status), std::free};
    return (status == 0) ? res.get() : name;
}

struct TestDerivDict : public dictionary::Dictionary
{
    using dictionary::Dictionary::Dictionary;
    auto &getItems() { return items_; };
    void addItems(const std::pair<std::string, dictionary::CustomVariant> &val) { items_.emplace(val); };
};

TEST(TestDictionary, TestInitializerList)
{
    TestDerivDict d{{"stringKey", "stringValue"}, {"intKey", 1}, {"floatKey", 2.0F}};

    EXPECT_EQ(d.getItems().size(), 3);
    EXPECT_EQ(std::get<std::string>(d.getItems()["stringKey"]), "stringValue");
    EXPECT_EQ(std::get<int>(d.getItems()["intKey"]), 1);
    EXPECT_EQ(std::get<float>(d.getItems()["floatKey"]), 2.0F);
}
