#include <SFML/Graphics.hpp>
#include <unistd.h>
 
using namespace sf;
 
int main()
{
    // ������������� 8-� ������� �����������
	ContextSettings settings;
	settings.antialiasingLevel = 80;
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(600, 600), "SFML Works!");
	int coord_x = 0;
    int dx = 1;
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
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
    
 
	// ��������� ������ �������������� 
	ConvexShape convex;
 
	// ������������� ��� 5 ������
	convex.setPointCount(3);
 
	// ������������� ���������� ������
	convex.setPoint(0, Vector2f(5.f, 0.f));
	convex.setPoint(1, Vector2f(0.f, 200.f));
	convex.setPoint(2, Vector2f(10.f, 200.f));
    convex.setOrigin(5,200);
	
 
	// ������������� ���� �������������� - ������
	convex.setFillColor(Color(255,69,0,70));
    convex.setOutlineThickness(2.f);
    convex.setOutlineColor(Color(230,80,10,50));
	// ������ ������� ��� ���� � ����-���� ������
	convex.move(350, 450);
    convex.rotate(coord_x);
	// ��������� ��������������
	window.draw(convex);
    
   

    // ����� � ������� ��������. ������ � � �������� ������� ������ ���� Vertex
	Vertex line_without_thickness[] =
		{
			// ���������� ������ �������
			Vertex(Vector2f(500.f, 200.f)),
			// ���������� ������ �������
			Vertex(Vector2f(530.f, 153.8f))
		};
		
	// ������������� ���� ����� - ������
	line_without_thickness->color = Color::Black;
 
    
	// ��������� �����
	window.draw(line_without_thickness, 2, Lines);
 
	        
    // ��������� ����	
	window.display();
    //for(volatile int i = 0; i < 100000000; i++);
    usleep(10000);
	}
    
	return 0;
}