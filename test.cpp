// Copyright 2022
// By Dr. Rykalova
// Edited by Dr. Daly
// test.cpp for PS1a
// updated 1/8/2024

#include <iostream>
#include <string>

#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

using PhotoMagic::FibLFSR;

BOOST_AUTO_TEST_CASE(testStepInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testGenerateInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(testPrintToScreen) {
  // Redirecting cout to a stringstream.
  std::ostringstream redirected_output;
  std::streambuf* original_cout = std::cout.rdbuf(redirected_output.rdbuf());

  // Performing the action that should print to the screen.
  FibLFSR l("1011011000110110");
  std::cout << l;  // Assuming you have overloaded the << operator.

  // Restoring the original cout.
  std::cout.rdbuf(original_cout);

  // Checking if the printed output matches the expected output.
  BOOST_CHECK_EQUAL(redirected_output.str(), "1011011000110110");
}

BOOST_AUTO_TEST_CASE(testInitialState) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.get_register(), "1011011000110110");
}

BOOST_AUTO_TEST_CASE(transform_test) {
    // Create a 2x2 image with all white pixels.
    sf::Image image;
    image.create(2, 2, sf::Color::White);

    // Create a FibLFSR with a seed of "1011".
    PhotoMagic::FibLFSR lfsr("1011");

    // Transforming the image.
    PhotoMagic::transform(image, &lfsr);

    // Checking that the image has been transformed correctly.
    for (unsigned y = 0; y < image.getSize().y; y++) {
        for (unsigned x = 0; x < image.getSize().x; x++) {
            sf::Color pixel = image.getPixel(x, y);
            BOOST_CHECK(pixel.r != 255);
            BOOST_CHECK(pixel.g != 255);
            BOOST_CHECK(pixel.b != 255);
        }
    }
}
