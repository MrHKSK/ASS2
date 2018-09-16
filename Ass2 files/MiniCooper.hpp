#include "Shape.hpp"
#include "Vehicle.hpp"
#include "TrapezoidalPrism.hpp"
#include "Triangular.hpp"
#include "RectangularPrism.hpp"
#include "Messages.hpp"
#include <Windows.h>
#include <GL/glut.h>

class MiniCooper : public Vehicle
{
public:
	MiniCooper();//defult constructor that recive data from server
	MiniCooper(VehicleModel vm);//constructor that recive data from server
	VehicleModel upload();//upload local model to server
	void draw();//draw model
private:
	VehicleModel local;//store local shape vector
	double time;
	double s;
};