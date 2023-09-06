
#include <Structures/Dictionary.h>
#include <gtest/gtest.h>

std::string demangle(char const *name);
std::string demangle(char const *name)
{
    int status = -4;
    std::unique_ptr<char, void (*)(void *)> res{abi::__cxa_demangle(name, NULL, NULL, &status), std::free};
    return (status == 0) ? res.get() : name;
}

TEST(TestDictionary, TestConst)
{
    using namespace dictionary;
    const Dictionary d{{"s", "s"}};
    auto ret = d["s"];
    d.keys();
    d.values();
    EXPECT_EQ(std::get<std::string>(d["s"]), "s");
}
