
#include <Structures/Dictionary.h>
#include <gtest/gtest.h>

TEST(TestConstructors, DefaultConstructor)
{
    using namespace dictionary;
    testing::internal::CaptureStdout();
    Dictionary dict{};
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "default constructor\n");
}

TEST(TestConstructors, CopyConstructor)
{
    using namespace dictionary;
    Dictionary dict{};
    testing::internal::CaptureStdout();
    Dictionary dict2{dict};
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "copy constructor\n");
}

TEST(TestConstructors, MoveConstructor)
{
    using namespace dictionary;
    Dictionary dict{};
    testing::internal::CaptureStdout();
    Dictionary dict2{std::move(dict)};
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "move constructor\n");
}

TEST(TestConstructors, Destructor)
{
    using namespace dictionary;
    testing::internal::CaptureStdout();
    {
        Dictionary dict{};
    }
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "default constructor\ndestructor\n");
}

TEST(TestConstructors, CopyAssignment)
{
    using namespace dictionary;
    Dictionary dict{};
    Dictionary dict2{};
    {
        testing::internal::CaptureStdout();
        dict2 = dict;
        EXPECT_EQ(testing::internal::GetCapturedStdout(), "copy assignment\n");
    }
}

TEST(TestConstructors, MoveAssignment)
{
    using namespace dictionary;
    Dictionary dict{};
    Dictionary dict2{};
    {
        testing::internal::CaptureStdout();
        dict2 = std::move(dict);
        EXPECT_EQ(testing::internal::GetCapturedStdout(), "move assignment\n");
    }
}
