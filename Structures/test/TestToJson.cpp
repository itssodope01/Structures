
#include <Structures/Dictionary.h>
#include <gtest/gtest.h>

std::string demangle(char const *name);
std::string demangle(char const *name)
{
    int status = -4;
    std::unique_ptr<char, void (*)(void *)> res{abi::__cxa_demangle(name, NULL, NULL, &status), std::free};
    return (status == 0) ? res.get() : name;
}

TEST(TestDictionary, TestConcatenation)
{
    using namespace dictionary;
    const Dictionary d{{"stringKey", "stringValue"}, {"intKey", 1}, {"floatKey", 2.0F}};
    EXPECT_EQ(d.toJson(), "{\"floatKey\":2.000000,\"intKey\":1,\"stringKey\":\"stringValue\"}");
    Dictionary d2{{"stringKey", "stringValue"}, {"intKey", 1}, {"stringKey2", "stringValue1"}, {"floatKey", 2.0F}};
    EXPECT_EQ(d2.toJson(),
              "{\"floatKey\":2.000000,\"intKey\":1,\"stringKey\":\"stringValue\",\"stringKey2\":\"stringValue1\"}");
}
