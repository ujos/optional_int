#include "opt_value.h"
#include <gtest/gtest.h>

TEST( OptValue, testSmoke )
{
    using OptInt = std::optional_int<int, -1>;

    auto v = std::optional_int<int, -1>{};
    ASSERT_FALSE(v);
    ASSERT_FALSE(v.has_value());
    ASSERT_EQ(2, v.value_or(2));

    v = 1;
    ASSERT_TRUE(v);
    ASSERT_TRUE(v.has_value());
    ASSERT_EQ(1, v.value());
    ASSERT_EQ(1, v.value_or(2));

    v.reset();
    ASSERT_FALSE(v);
    ASSERT_FALSE(v.has_value());
    ASSERT_EQ(2, v.value_or(2));
}

TEST( OptValue, testInterface )
{
    std::optional_int<int, -1> v1;
    v1 = 1;
    v1.reset();

    std::optional_int<int, -1> v2 = std::move(v1);
    std::swap(v1, v2);

    if(v1) {
        v1.reset();
    }
}
