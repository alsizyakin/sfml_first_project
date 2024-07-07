#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <vector>

// using namespace sf;

int main() {

    float arrow_angle = 0;
    float cursor_angle = 0;
    float d_angle = 0.5f;
    float max_angle = 120;
    float min_angle = -120;
    int d_cursor = 1;
    int tail_length = 25;
    std::vector<float> tail;
    int tail_pointer = 0;
    int stop_ind = 4;
    // SFML vars
    //  Объект, который, собственно, является главным окном
    //  приложения
    sf::RenderWindow window(sf::VideoMode(960, 540), "Speedometer");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::Texture scale;
    // Подгружаем текстуру шкалы из файла
    scale.loadFromFile("oldcar.jpg");
    scale.setSmooth(true);
    sf::Texture arrow;
    // Подгружаем нашу текстуру стрелки из файла
    arrow.loadFromFile("arrow.png");
    arrow.setSmooth(true);
    // Главный цикл приложения: выполняется, пока открыто окно

    tail.resize(tail_length);
    while (window.isOpen()) {
        // Обрабатываем события в цикле
        sf::Event event;
        while (window.pollEvent(event)) {
            // Пользователь нажал на «крестик» и хочет закрыть окно
            if (event.type == sf::Event::Closed) {
                // тогда закрываем его
                window.close();
            }
        }

        //  Создаем спрайт фона и устанавливаем ему текстуру шкалы
        sf::Sprite sprite_scale(scale, sf::IntRect(0, 0, 754, 753));
        sprite_scale.setOrigin(377, 377);

        // sprite.setColor(Color(255,0,0,180));
        //sprite_scale.move(377, 377);
        // sprite.rotate(45);
        sprite_scale.setScale(0.5f, 0.5f);
        // Отрисовка спрайта
        window.draw(sprite_scale);

        // Заготовка фигуры многоугольника стрелки круиза
        sf::ConvexShape convex;
        // Устанавливаем ему 5 вершин
        convex.setPointCount(4);
        // Устанавливаем координаты вершин
        convex.setPoint(0, sf::Vector2f(7.f, 0.f));
        convex.setPoint(1, sf::Vector2f(3.f, 0.f));
        convex.setPoint(2, sf::Vector2f(0.f, 60.f));
        convex.setPoint(3, sf::Vector2f(12.f, 60.f));
        convex.setOrigin(6, 120);
        // Устанавливаем цвет многоугольника
        convex.setFillColor(sf::Color(0, 169, 200, 255));
        convex.setOutlineThickness(4.f);
        convex.setOutlineColor(sf::Color(10, 180, 230, 155));
        // Теперь сдвинем его вниз и чуть-чуть вправо
        convex.move(377, 377);
        convex.rotate(cursor_angle);
        // Отрисовка многоугольника
        window.draw(convex);


        if (tail_pointer++ == tail.size()) {
            tail_pointer = 0;
            tail[tail_pointer] = tail[tail_length - 1];
        } else {
            tail[tail_pointer] = tail[tail_pointer - 1];
        }
        tail[tail_pointer] += d_angle;
        if (tail[tail_pointer] > max_angle or tail[tail_pointer] < min_angle) {
            d_angle *= -1.f;
            if (--stop_ind == 0) {
                d_angle = 0.f;
            }
        }

        // Создаем спрайт и устанавливаем ему нашу
        // текстуру texture.setRepeated(true);
        int i = tail_pointer + 1;
        int j = 0;
        while (j < tail.size()) {
            if (i > tail.size() - 1) {
                i = 0;
            }

            sf::Sprite sprite_arrow(arrow, sf::IntRect(0, 0, 376, 79));
            sprite_arrow.setOrigin(70, 40);

            sprite_arrow.setColor(
                sf::Color(250, 50 * !static_cast<bool>(j == tail_length - 1),
                          100 * !static_cast<bool>(j == tail_length - 1),
                          250 / tail_length * j));

            sprite_arrow.move(377, 377);
            sprite_arrow.rotate(tail[i] - 100);
            sprite_arrow.setScale(0.5f, 0.5f);
            // Отрисовка спрайта
            window.draw(sprite_arrow);
            j++;
            i++;
        }
        // Отрисовка окна
        window.display();
        usleep(16667);
    }

    return 0;
}