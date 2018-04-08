#include "move_detector.h"
#include "catch.hpp"

TEST_CASE("move detector") {
    SECTION("Construction") {
        move_detector m(1);
        REQUIRE(m.value == 1);
        REQUIRE(m.method == construction_method::constructed);
    }

    SECTION("Copy construction") {
        move_detector tmp(1);
        move_detector m(tmp);
        REQUIRE(m.value == 1);
        REQUIRE(m.method == construction_method::copy_contstucted);
        REQUIRE(tmp.was_moved == false);
    }

    SECTION("Move construction") {
        move_detector tmp(1);
        move_detector m(std::move(tmp));
        REQUIRE(m.value == 1);
        REQUIRE(m.method == construction_method::move_constructed);
        REQUIRE(tmp.was_moved == true);
    }

    SECTION("Move assignment") {
        move_detector tmp(1);
        move_detector m(0);
        m = std::move(tmp);
        REQUIRE(m.value == 1);
        REQUIRE(m.method == construction_method::move_assigned);
        REQUIRE(tmp.was_moved == true);
    }

    SECTION("copy assignment") {
        move_detector tmp(1);
        move_detector m(0);
        m = tmp;
        REQUIRE(m.value == 1);
        REQUIRE(m.method == construction_method::copy_assigned);
        REQUIRE(tmp.was_moved == false);
    }
}
