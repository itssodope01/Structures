
#include <gtest/gtest.h>

#include <Structures/VariantVisitors.hpp>

std::string demangle(char const *name);
std::string demangle(char const *name)
{
    int status = -4;
    std::unique_ptr<char, void (*)(void *)> res{abi::__cxa_demangle(name, NULL, NULL, &status), std::free};
    return (status == 0) ? res.get() : name;
}

TEST(TestVariantVisitors, PrintVisitor)
{
    using namespace variantVisitors;
    EXPECT_EQ(demangle(typeid(PrintVariant).name()), "std::variant<bool, int, float>");
    {
        testing::internal::CaptureStdout();
        PrintVariant v{true};
        std::visit(PrintVisitor{}, v);
        EXPECT_EQ(testing::internal::GetCapturedStdout(), "bool");
    }
    {
        testing::internal::CaptureStdout();
        PrintVariant v{1};
        std::visit(PrintVisitor{}, v);
        EXPECT_EQ(testing::internal::GetCapturedStdout(), "int");
    }
    {
        testing::internal::CaptureStdout();
        PrintVariant v{1.0F};
        std::visit(PrintVisitor{}, v);
        EXPECT_EQ(testing::internal::GetCapturedStdout(), "float");
    }
}
