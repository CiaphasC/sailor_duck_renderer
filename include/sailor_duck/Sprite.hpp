#ifndef SAILOR_DUCK_SPRITE_HPP
#define SAILOR_DUCK_SPRITE_HPP

#include <memory>

namespace sailor_duck {

// Gestiona la memoria del plano de pixeles usando RAII para evitar fugas.
class Sprite {
public:
    Sprite(int width, int height, std::unique_ptr<char[]> pixels);

    Sprite(Sprite&&) noexcept = default;
    Sprite& operator=(Sprite&&) noexcept = default;

    Sprite(const Sprite&) = delete;
    Sprite& operator=(const Sprite&) = delete;

    const char* row_data(int row) const;
    const char* raw_data() const;

    int width() const;
    int height() const;

private:
    int width_;
    int height_;
    std::unique_ptr<char[]> pixels_;
};

} // namespace sailor_duck

#endif // SAILOR_DUCK_SPRITE_HPP
