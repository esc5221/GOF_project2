/* Implement: Define each function of Square class */
#include "Square.h"
#include <GL/glut.h>

Square::Square(float x, float y, float r, float g, float b, float sl) : Quad(x,y) , Color(r,g,b){
	side_length = new float[1];
	side_length[0] = sl;
}
Square::~Square() {
	delete [] side_length;
}

void Square::draw() const {
	glBegin(GL_POLYGON);
	glColor3f(color[0], color[1], color[2]);

	float a = side_length[0];
	glVertex3f(center_pos[0] + a, center_pos[1] + a, 0);
	glVertex3f(center_pos[0] - a, center_pos[1] + a, 0);
	glVertex3f(center_pos[0] - a, center_pos[1] - a, 0);
	glVertex3f(center_pos[0] + a, center_pos[1] - a, 0);
	
	glColor3f(0, 1, 1);
	glEnd();
}

float Square::getSideLength() const {
	return side_length[0];
}


