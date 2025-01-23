// Copyright 2024 Daniel Dsouza
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " input-file.png output-file.png 1011011000110110\n";
        return 1;
    }

    sf::Image image, encryptedImage;
    if (!image.loadFromFile(argv[1])) {
        std::cerr << "Failed to load image file " << argv[1] << "\n";
        return 1;
    }

    if (!encryptedImage.loadFromFile(argv[1])) {
        std::cerr << "Failed to load image file " << argv[1] << "\n";
        return 1;
    }

    PhotoMagic::FibLFSR lfsr(argv[3]);

    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::RenderWindow window1(sf::VideoMode(image.getSize().x, image.getSize().y), "Original Image");

    PhotoMagic::transform(encryptedImage, &lfsr);

    if (!encryptedImage.saveToFile(argv[2])) {
        std::cerr << "Failed to save image file " << argv[2] << "\n";
        return 1;
    }

    sf::Texture eTexture;
    eTexture.loadFromImage(encryptedImage);
    sf::Sprite eSprite;
    eSprite.setTexture(eTexture);

    sf::RenderWindow window2(sf::VideoMode(encryptedImage.getSize().x, encryptedImage.getSize().y)
    , "Encrypted Image");

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }

        window1.clear();
        window1.draw(sprite);
        window1.display();

        window2.clear();
        window2.draw(eSprite);
        window2.display();
    }

    return 0;
}
