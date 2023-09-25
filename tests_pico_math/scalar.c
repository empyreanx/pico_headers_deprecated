#include "../pico_math.h"
#include "../pico_unit.h"

TEST_CASE(test_min)
{
    REQUIRE(2 == pm_min(2, 4));
    return true;
}

TEST_CASE(test_max)
{
    REQUIRE(4 == pm_max(2, 4));
    return true;
}

TEST_CASE(test_clamp)
{
    REQUIRE(-5 == pm_clamp(-10, -5, 5));
    REQUIRE( 5 == pm_clamp(10, -5, 5));
    REQUIRE( 0 == pm_clamp(0, -5, 5));

    return true;
}

TEST_CASE(test_next_pow2)
{
    REQUIRE(16 == pm_next_pow2(9));
    REQUIRE(16 == pm_next_pow2(8));
    REQUIRE(16 == pm_next_pow2(15));

    return true;
}

TEST_CASE(test_lerp_angle)
{
    pm_float angle = pm_lerp_angle(0.0f, PM_PI / 4.0, 0.5f);
    REQUIRE(pm_equal(angle, PM_PI / 8.0f));

    angle = pm_lerp_angle(PM_PI / 4.0, PM_PI * 3.0 / 4.0, 0.5f);
    REQUIRE(pm_equal(angle, PM_PI / 2.0f));

    angle = pm_lerp_angle(PM_PI / 4.0, PM_PI * 3.0 / 4.0, 0.0f);
    REQUIRE(pm_equal(angle, PM_PI / 4.0f));

    angle = pm_lerp_angle(PM_PI / 4.0, PM_PI * 3.0 / 4.0, 1.0f);
    REQUIRE(pm_equal(angle, PM_PI * 3.0 / 4.0));

    //NOTE: This pathological
    //angle = pm_lerp_angle(PM_PI / 4.0f, PM_PI * 7.0f / 4.0f, 0.5);
    //REQUIRE(pm_equal(angle, 0.0f));

    //angle = pm_lerp_angle(PM_PI / 4.0f, PM_PI * 7.0f / 4.0f, 0.5);
    //REQUIRE(pm_equal(angle, PM_PI));

    angle = pm_lerp_angle(PM_PI * 7.0f / 4.0f, PM_PI / 4.0f, 0.75);
    REQUIRE(pm_equal(angle, PM_PI / 8.0f));

    return true;
}

TEST_SUITE(suite_scalar)
{
    RUN_TEST_CASE(test_min);
    RUN_TEST_CASE(test_max);
    RUN_TEST_CASE(test_clamp);
    RUN_TEST_CASE(test_next_pow2);
    RUN_TEST_CASE(test_lerp_angle);
}
