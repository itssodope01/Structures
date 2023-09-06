
#include <Structures/Dictionary.h>
#include <gtest/gtest.h>

std::string demangle(char const *name);
std::string demangle(char const *name)
{
    int status = -4;
    std::unique_ptr<char, void (*)(void *)> res{abi::__cxa_demangle(name, NULL, NULL, &status), std::free};
    return (status == 0) ? res.get() : name;
}

TEST(TestDictionary, TestKeys)
{
    dictionary::Dictionary d{{"stringKey", "stringValue"}, {"intKey", 1}, {"floatKey", 2.0F}};

    auto v = d.keys();

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], "floatKey");
    EXPECT_EQ(v[1], "intKey");
    EXPECT_EQ(v[2], "stringKey");
}
