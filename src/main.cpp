#include <SFML/Graphics.hpp>
#include <unistd.h>
 
using namespace sf;
 
int main()
{
    // Устанавливаем 8-й уровень сглаживания
	ContextSettings settings;
	settings.antialiasingLevel = 80;
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(600, 600), "SFML Works!");
	int coord_x = 0;
    int dx = 1;
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
    window.clear(Color(25,25,25,0));

    CircleShape circle(350.f,120);
    circle.setOrigin(350,350);

    circle.setFillColor(Color(70,70,70,30));

    circle.setOutlineThickness(15.f);
    circle.setOutlineColor(Color(123,104,238,100));
    circle.move(350,450);
    //circle.rotate(coord_x);

    if(((coord_x += dx) > 30) or (coord_x < -90)){
        dx *= -1;
        //coord_x = 0;
    }
    window.draw(circle);
    
 
	// Заготовка фигуры многоугольника 
	ConvexShape convex;
 
	// Устанавливаем ему 5 вершин
	convex.setPointCount(3);
 
	// Устанавливаем координаты вершин
	convex.setPoint(0, Vector2f(5.f, 0.f));
	convex.setPoint(1, Vector2f(0.f, 200.f));
	convex.setPoint(2, Vector2f(10.f, 200.f));
    convex.setOrigin(5,200);
	
 
	// Устанавливаем цвет многоугольника - черный
	convex.setFillColor(Color(255,69,0,70));
    convex.setOutlineThickness(2.f);
    convex.setOutlineColor(Color(230,80,10,50));
	// Теперь сдвинем его вниз и чуть-чуть вправо
	convex.move(350, 450);
    convex.rotate(coord_x);
	// Отрисовка многоугольника
	window.draw(convex);
    
   

    // Линия с нулевой толщиной. Создаём её в качестве массива вершин типа Vertex
	Vertex line_without_thickness[] =
		{
			// Координата первой вершины
			Vertex(Vector2f(500.f, 200.f)),
			// Координата второй вершины
			Vertex(Vector2f(530.f, 153.8f))
		};
		
	// Устанавливаем цвет линии - черный
	line_without_thickness->color = Color::Black;
 
    
	// Отрисовка линии
	window.draw(line_without_thickness, 2, Lines);
 
	        
    // Отрисовка окна	
	window.display();
    //for(volatile int i = 0; i < 100000000; i++);
    usleep(10000);
	}
    
	return 0;
}