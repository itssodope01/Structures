
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
    Dictionary d1{{"s", "s"}};
    const Dictionary d2{{"a", "a"}};
    Dictionary d3 = d1 + d2;
    EXPECT_EQ(std::get<std::string>(d1["s"]), "s");
    EXPECT_EQ(std::get<std::string>(d2["a"]), "a");
    EXPECT_EQ(std::get<std::string>(d3["s"]), "s");
    EXPECT_EQ(std::get<std::string>(d3["a"]), "a");
    d1 += d2;
    EXPECT_EQ(std::get<std::string>(d1["s"]), "s");
    EXPECT_EQ(std::get<std::string>(d1["a"]), "a");
}
