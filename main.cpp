#include <iostream>

/* Uygulay�c�(implementer)
* Uygulama s�n�flar� i�in arabirimi tan�mlar. 
* Bu arabirimin do�rudan soyutlama arabirimine kar��l�k gelmesi gerekmez ve �ok farkl� olabilir. 
* Soyutlama imp, Implementer arabirimi taraf�ndan sa�lanan i�lemler a��s�ndan bir uygulama sa�lar.
*/
class DrawingAPI {
public:
    virtual void drawCircle(double x, double y, double radius) = 0;
    virtual ~DrawingAPI() {}
};

/*Somut uygulay�c� (Concrete Implementer)*/
class DrawingAPI1 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) {
        std::cout << "API1.circle at " << x << ':' << y << ' ' << radius << std::endl;
    }
};

/* Somut uygulay�c�*/
class DrawingAPI2 : public DrawingAPI {
public:
    void drawCircle(double x, double y, double radius) {
        std::cout << "API2.circle at " << x << ':' << y << ' ' << radius << std::endl;
    }
};

/** Soyutlama(Abstraction)
* K�pr� tasar�m deseninin �ekirde�ini olu�turur ve p�f noktas�n� tan�mlar. 
* Uygulay�c� i�in bir referans i�erir.
*/
class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() = 0;
    virtual void resizeByPercentage(double pct) = 0;
};

/** Rafine soyutlama(Refined Abstraction)
* Soyutlamay� geni�letir, daha ince ayr�nt�y� bir seviye a�a��ya al�r. 
* Daha ince ��eleri uygulamalardan gizler.
*/
class CircleShape : public Shape {
public:
    CircleShape(double x, double y, double radius, DrawingAPI* drawingAPI) :
        m_x(x), m_y(y), m_radius(radius), m_drawingAPI(drawingAPI)
    {}
    void draw() {
        m_drawingAPI->drawCircle(m_x, m_y, m_radius);
    }
    void resizeByPercentage(double pct) {
        m_radius *= pct;
    }
private:
    double m_x, m_y, m_radius;
    DrawingAPI* m_drawingAPI;
};

int main(void) {
    CircleShape circle1(1, 2, 3, new DrawingAPI1());
    CircleShape circle2(5, 7, 11, new DrawingAPI2());
    circle1.resizeByPercentage(2.5);
    circle2.resizeByPercentage(2.5);
    circle1.draw();
    circle2.draw();
    return 0;
}