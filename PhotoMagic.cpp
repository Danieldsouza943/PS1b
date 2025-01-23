// Copyright 2024 Daniel Dsouza
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"
#include <SFML/Graphics.hpp>

namespace PhotoMagic {
  void transform(sf::Image& image, FibLFSR* lfsr) {
    sf::Vector2u size = image.getSize();

    for (unsigned y = 0; y < size.y; y++) {
      for (unsigned x = 0; x < size.x; x++) {
        sf::Color pixel = image.getPixel(x, y);

        // Generating a new 8-bit integer for each color component.
        int redRand = lfsr->generate(8);
        int greenRand = lfsr->generate(8);
        int blueRand = lfsr->generate(8);

        // XOR each color component with the newly-generated 8-bit integer.
        pixel.r ^= redRand;
        pixel.g ^= greenRand;
        pixel.b ^= blueRand;

        // Setting the pixel in the image to the new color.
        image.setPixel(x, y, pixel);
      }
    }
  }
}  // namespace PhotoMagic
