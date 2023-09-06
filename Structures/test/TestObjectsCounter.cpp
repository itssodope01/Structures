
#include <Structures/Dictionary.h>
#include <gtest/gtest.h>

std::string demangle(char const *name);
std::string demangle(char const *name)
{
    int status = -4;
    std::unique_ptr<char, void (*)(void *)> res{abi::__cxa_demangle(name, NULL, NULL, &status), std::free};
    return (status == 0) ? res.get() : name;
}

TEST(TestDictionary, TestObjectsCounter)
{
    using namespace dictionary;
    Dictionary d;
    EXPECT_EQ(Dictionary::getObjCounter(), 1);
    Dictionary d2{{"s", "s"}};
    EXPECT_EQ(Dictionary::getObjCounter(), 2);
    Dictionary d3 = d2;
    EXPECT_EQ(Dictionary::getObjCounter(), 3);
    {
        Dictionary d4;
        EXPECT_EQ(Dictionary::getObjCounter(), 4);
    }
    EXPECT_EQ(Dictionary::getObjCounter(), 3);
    Dictionary d5(std::move(d));
    EXPECT_EQ(Dictionary::getObjCounter(), 4);
}
