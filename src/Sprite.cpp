#include "sailor_duck/Sprite.hpp"

#include <cassert>

namespace sailor_duck {

Sprite::Sprite(int width, int height, std::unique_ptr<char[]> pixels)
    : width_{width}, height_{height}, pixels_{std::move(pixels)} {
    assert(width_ > 0 && height_ > 0 && "El sprite necesita dimensiones validas");
}

const char* Sprite::row_data(int row) const {
    assert(row >= 0 && row < height_ && "Fila fuera de rango en el sprite");
    return pixels_.get() + static_cast<std::size_t>(row) * width_;
}

const char* Sprite::raw_data() const {
    return pixels_.get();
}

int Sprite::width() const {
    return width_;
}

int Sprite::height() const {
    return height_;
}

} // namespace sailor_duck
