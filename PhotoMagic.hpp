// Copyright 2024 Daniel Dsouza
#ifndef PHOTOMAGIC_HPP
#define PHOTOMAGIC_HPP
#include <SFML/Graphics.hpp>

namespace PhotoMagic {
  // Transforming imagage using FibLFSR.
  void transform(sf::Image&, FibLFSR*);
  // Using the LFSR to do the encryption, we display an encrypted copy of the picture.
}
#endif
