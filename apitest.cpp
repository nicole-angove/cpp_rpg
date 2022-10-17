#include <gtest/gtest.h>
#include "api.h"

TEST(API, useAbilitySuccess) {

    bool expectedResult = true;

    bool result = useAbility(0);

    EXPECT_EQ(expectedResult, result);
}

TEST(API, useAbilityFailure) {
    bool expectedResult = false;

    bool result = useAbility(1);

    EXPECT_EQ(expectedResult, result);
}
