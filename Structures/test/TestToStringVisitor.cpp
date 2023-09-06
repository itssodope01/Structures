
#include <gtest/gtest.h>

#include <Structures/VariantVisitors.hpp>

std::string demangle(char const *name);
std::string demangle(char const *name)
{
    int status = -4;
    std::unique_ptr<char, void (*)(void *)> res{abi::__cxa_demangle(name, NULL, NULL, &status), std::free};
    return (status == 0) ? res.get() : name;
}

TEST(TestVariantVisitors, ToStringVisitor)
{
    using namespace variantVisitors;
    EXPECT_EQ(demangle(typeid(ToStringVariant).name()), "std::variant<bool, int, double, float>");
    {
        ToStringVariant v{true};
        EXPECT_EQ(std::visit(ToStringVisitor{}, v), "true");
    }
    {
        ToStringVariant v{255};
        EXPECT_EQ(std::visit(ToStringVisitor{}, v), "ff");
    }
    {
        ToStringVariant v{1.0F};
        EXPECT_EQ(std::visit(ToStringVisitor{}, v), "1");
    }
    {
        ToStringVariant v{1.0};
        EXPECT_EQ(std::visit(ToStringVisitor{}, v), "1");
    }

}
