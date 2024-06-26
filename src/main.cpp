#include <SFML/Graphics.hpp>
#include <unistd.h>
 
using namespace sf;
 
int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(960, 540), "Speedometer");
    ContextSettings settings;
	settings.antialiasingLevel = 8;
    int coord_x = 0;
	int coord_prev = 0;
	int coord_prev2 = 0;
	int coord_prev3 = 0;

	int coord_prev4 = 0;
	int coord_prev5 = 0;
	int coord_prev6 = 0;

    int dx = 1;
	// ������� ���� ����������: �����������, ���� ������� ����
	while (window.isOpen())
	{
	    // ������������ ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		
		coord_prev6 = coord_prev5;		
		coord_prev5 = coord_prev4;
		coord_prev4 = coord_prev3;		
		coord_prev3 = coord_prev2;
		coord_prev2 = coord_prev;
		coord_prev = coord_x;
		coord_x +=dx;  

        if(((coord_x) > 120) or (coord_x < -120)){
        dx *= -1;
		
        //coord_x = 0;
    }
		// ��������� ����� ���� - �����
		window.clear(Color::Black);
 
		// ������� ���������� ��������
		Texture scale;
 
	    // ���������� ���� �������� �� ����� texture.png
	    scale.loadFromFile("oldcar.jpg");
        scale.setSmooth(true);
		// ������� ������ � ������������� ��� ���� ��������
        //texture.setRepeated(true);
		Sprite sprite(scale, IntRect(0,0,796,768));
        sprite.setOrigin(398,384);

		//sprite.setColor(Color(255,0,0,180));

        sprite.move(450,250);
        //sprite.rotate(45);
        sprite.setScale(0.5f,0.5f);
		// ��������� �������	 
		window.draw(sprite);


		// ������� ���������� ��������
		Texture arrow;
 
	    // ���������� ���� �������� �� ����� texture.png
	    arrow.loadFromFile("/home/alexey/Git/Comp/SFML/cmake-sfml-project/arrow.png");
        arrow.setSmooth(true);
		// ������� ������ � ������������� ��� ���� ��������
        //texture.setRepeated(true);
/*
		Sprite sprite7(arrow, IntRect(0,0,376,79));
        sprite7.setOrigin(70,40);

		sprite7.setColor(Color(250,50,50,50));

        sprite7.move(450,250);
        sprite7.rotate(coord_prev6 - 100);
        sprite7.setScale(0.5f,0.5f);
		// ��������� �������	 
		window.draw(sprite7);


		Sprite sprite6(arrow, IntRect(0,0,376,79));
        sprite6.setOrigin(70,40);

		sprite6.setColor(Color(250,50,50,50));

        sprite6.move(450,250);
        sprite6.rotate(coord_prev5 - 100);
        sprite6.setScale(0.5f,0.5f);
		// ��������� �������	 
		window.draw(sprite6);

		Sprite sprite5(arrow, IntRect(0,0,376,79));
        sprite5.setOrigin(70,40);

		sprite5.setColor(Color(250,50,50,50));

        sprite5.move(450,250);
        sprite5.rotate(coord_prev4 - 100);
        sprite5.setScale(0.5f,0.5f);
		// ��������� �������	 
		window.draw(sprite5);

		Sprite sprite4(arrow, IntRect(0,0,376,79));
        sprite4.setOrigin(70,40);

		sprite4.setColor(Color(250,50,50,50));

        sprite4.move(450,250);
        sprite4.rotate(coord_prev3 - 100);
        sprite4.setScale(0.5f,0.5f);
		// ��������� �������	 
		window.draw(sprite4);



		Sprite sprite3(arrow, IntRect(0,0,376,79));
        sprite3.setOrigin(70,40);

		sprite3.setColor(Color(250,50,50,100));

        sprite3.move(450,250);
        sprite3.rotate(coord_prev2 - 100);
        sprite3.setScale(0.5f,0.5f);
		// ��������� �������	 
		window.draw(sprite3);



		Sprite sprite2(arrow, IntRect(0,0,376,79));
        sprite2.setOrigin(70,40);

		sprite2.setColor(Color(250,50,50,150));

        sprite2.move(450,250);
        sprite2.rotate(coord_prev - 100);
        sprite2.setScale(0.5f,0.5f);
		// ��������� �������	 
		window.draw(sprite2);

*/

		Sprite sprite1(arrow, IntRect(0,0,376,79));
        sprite1.setOrigin(70,40);

		sprite1.setColor(Color(250,50,50,250));

        sprite1.move(450,250);
        sprite1.rotate(coord_x - 100);
        sprite1.setScale(0.5f,0.5f);
		// ��������� �������	 
		window.draw(sprite1);


        // ��������� ������ �������������� 
	//ConvexShape convex;
 
	// ������������� ��� 5 ������
	//convex.setPointCount(4);
 
	// ������������� ���������� ������
    //convex.setPoint(0, Vector2f(7.f, 0.f));
	//convex.setPoint(0, Vector2f(3.f, 0.f));
	//convex.setPoint(1, Vector2f(0.f, 120.f));
	//convex.setPoint(2, Vector2f(12.f, 120.f));

    //convex.setOrigin(6,120);
	
 
	// ������������� ���� �������������� - ������
	//convex.setFillColor(Color(0,169,200,255));
    //convex.setOutlineThickness(4.f);
    //convex.setOutlineColor(Color(10,180,230,155));
	// ������ ������� ��� ���� � ����-���� ������
	//convex.move(450, 250);
    //convex.rotate(coord_x);
	// ��������� ��������������
	//window.draw(convex);
    
   
 
		// ��������� ����
		window.display();
        //usleep(20000);
	}
 
	return 0;
}