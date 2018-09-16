#include "MiniCooper.hpp"
#include "Shape.hpp"
#include "Vehicle.hpp"
#include "Cylinder.hpp"
#include "RectangularPrism.hpp"
#include "Messages.hpp"

MiniCooper::MiniCooper() {
	Shape *ShaPtr1 = new RectangularPrism(8, 1, 4);//Base
	ShaPtr1->setColor(1, 0, 1);
	ShaPtr1->setPosition(0, 1, 0);
	Shape *ShaPtr2 = new RectangularPrism(3, 0.5, 0.5);//Bar1
	ShaPtr2->setColor(0.5, 0.2, 0.4);
	ShaPtr2->setPosition(-2.5, 2, 1.75);
	Shape *ShaPtr3 = new RectangularPrism(3, 0.5, 0.5);//Bar2
	ShaPtr3->setColor(0.5, 0.2, 0.4);
	ShaPtr3->setPosition(-2.5, 2, -1.75);
	Shape *ShaPtr4 = new Cylinder(1, 1, 1, 6, 6, 6, 1, 1);//right front Wheel
	ShaPtr4->setColor(1, 1, 1);
	ShaPtr4->setPosition(2.5, 0, 2.5);
	Shape *ShaPtr5 = new Cylinder(1, 1, 1, 6, 6, 6, 0, 1);//right back Wheel
	ShaPtr5->setColor(1, 1, 1);
	ShaPtr5->setPosition(-2.5, 0, 2.5);
	Shape *ShaPtr6 = new Cylinder(1, 1, 1, 6, 6, 6, 1, 1);//Left front Wheel
	ShaPtr6->setColor(1, 1, 1);
	ShaPtr6->setPosition(2.5, 0, -2.5);
	Shape *ShaPtr7 = new Cylinder(1, 1, 1, 6, 6, 6, 0, 1);//left back Wheel
	ShaPtr7->setColor(1, 1, 1);
	ShaPtr7->setPosition(-2.5, 0, -2.5);
	Shape *ShaPtr8 = new TrapezoidalPrism(1, 3.5, 5, 4, 0);
	ShaPtr8->setPosition(1.5, 2, 0);
	ShaPtr8->setColor(0, 1, 0);//Top

	localshapes.push_back(ShaPtr1);//
	localshapes.push_back(ShaPtr2);//
	localshapes.push_back(ShaPtr3);//
	localshapes.push_back(ShaPtr4);//
	localshapes.push_back(ShaPtr5);//
	localshapes.push_back(ShaPtr6);//
	localshapes.push_back(ShaPtr7);//
	localshapes.push_back(ShaPtr8);//Push location model to local shape vector
}

MiniCooper::MiniCooper(VehicleModel vm) {
	std::vector<ShapeInit>::iterator loop;
	for (loop = vm.shapes.begin(); loop != vm.shapes.end(); ++loop) {
		if (loop->type == RECTANGULAR_PRISM) {
			Shape *ShaPtr1 = new RectangularPrism(loop->params.rect.xlen, loop->params.rect.ylen, loop->params.rect.zlen);
			ShaPtr1->setPosition(loop->xyz[0], loop->xyz[1], loop->xyz[2]);
			ShaPtr1->setColor(loop->rgb[0], loop->rgb[1], loop->rgb[2]);
			ShaPtr1->setRotation(loop->rotation);
			addShape(ShaPtr1);
		}
		else if (loop->type == TRIANGULAR_PRISM) {
			Shape *ShaPtr2 = new TriangularPrism(loop->params.tri.alen, loop->params.tri.blen, loop->params.tri.angle, loop->params.tri.depth);
			ShaPtr2->setPosition(loop->xyz[0], loop->xyz[1], loop->xyz[2]);
			ShaPtr2->setColor(loop->rgb[0], loop->rgb[1], loop->rgb[2]);
			ShaPtr2->setRotation(loop->rotation);
			addShape(ShaPtr2);
		}
		else if (loop->type == CYLINDER) {
			Shape *ShaPtr3 = new Cylinder(loop->params.cyl.radius, loop->params.cyl.radius, loop->params.cyl.radius, 10, 10, 10, loop->params.cyl.isSteering, loop->params.cyl.isRolling);
			ShaPtr3->setPosition(loop->xyz[0], loop->xyz[1], loop->xyz[2]);
			ShaPtr3->setColor(loop->rgb[0], loop->rgb[1], loop->rgb[2]);
			ShaPtr3->setRotation(loop->rotation);
			addShape(ShaPtr3);
		}
		else if (loop->type == TRAPEZOIDAL_PRISM) {
			Shape *ShaPtr4 = new TrapezoidalPrism(loop->params.trap.height, loop->params.trap.blen, loop->params.trap.alen, loop->params.trap.depth, loop->params.trap.aoff);
			ShaPtr4->setPosition(loop->xyz[0], loop->xyz[1], loop->xyz[2]);
			ShaPtr4->setColor(loop->rgb[0], loop->rgb[1], loop->rgb[2]);
			ShaPtr4->setRotation(loop->rotation);
			addShape(ShaPtr4);
		}
	}
}

VehicleModel MiniCooper::upload()
{
	VehicleModel vm;
	ShapeInit Rect;
	Rect.type = RECTANGULAR_PRISM;
	Rect.xyz[0] = 0;
	Rect.xyz[1] = 1;
	Rect.xyz[2] = 0;
	Rect.rgb[0] = 1;
	Rect.rgb[1] = 0;
	Rect.rgb[2] = 1;
	Rect.rotation = 0;
	Rect.params.rect.xlen = 8;
	Rect.params.rect.ylen = 1;
	Rect.params.rect.zlen = 4;
	local.shapes.push_back(Rect);

	//Right Back
	ShapeInit Wheel1;
	Wheel1.type = CYLINDER;
	Wheel1.xyz[0] = -2.5;
	Wheel1.xyz[1] = 0;
	Wheel1.xyz[2] = 2.5;
	Wheel1.rgb[0] = 1;
	Wheel1.rgb[1] = 1;
	Wheel1.rgb[2] = 1;
	Wheel1.rotation = 0;
	Wheel1.params.cyl.isSteering = 0;
	Wheel1.params.cyl.isRolling = 1;
	Wheel1.params.cyl.radius = 1;
	Wheel1.params.cyl.depth = 1;
	local.shapes.push_back(Wheel1);

	//Right Front
	ShapeInit Wheel2;
	Wheel2.type = CYLINDER;
	Wheel2.xyz[0] = 2.5;
	Wheel2.xyz[1] = 0;
	Wheel2.xyz[2] = 2.5;
	Wheel2.rgb[0] = 1;
	Wheel2.rgb[1] = 1;
	Wheel2.rgb[2] = 1;
	Wheel2.rotation = steering;
	Wheel2.params.cyl.isSteering = 1;
	Wheel2.params.cyl.isRolling = 1;
	Wheel2.params.cyl.radius = 1;
	Wheel2.params.cyl.depth = 1;
	local.shapes.push_back(Wheel2);

	//Left Back
	ShapeInit Wheel3;
	Wheel3.type = CYLINDER;
	Wheel3.xyz[0] = -2.5;
	Wheel3.xyz[1] = 0;
	Wheel3.xyz[2] = -2.5;
	Wheel3.rgb[0] = 1;
	Wheel3.rgb[1] = 1;
	Wheel3.rgb[2] = 1;
	Wheel3.rotation = 0;
	Wheel3.params.cyl.isSteering = 0;
	Wheel3.params.cyl.isRolling = 1;
	Wheel3.params.cyl.radius = 1;
	Wheel3.params.cyl.depth = 1;
	local.shapes.push_back(Wheel3);

	//Left Front
	ShapeInit Wheel4;
	Wheel4.type = CYLINDER;
	Wheel4.xyz[0] = 2.5;
	Wheel4.xyz[1] = 0;
	Wheel4.xyz[2] = -2.5;
	Wheel4.rgb[0] = 1;
	Wheel4.rgb[1] = 1;
	Wheel4.rgb[2] = 1;
	Wheel4.rotation = steering;
	Wheel4.params.cyl.isSteering = 1;
	Wheel4.params.cyl.isRolling = 1;
	Wheel4.params.cyl.radius = 1;
	Wheel4.params.cyl.depth = 1;
	local.shapes.push_back(Wheel4);

	//Left Bar
	ShapeInit Bar1;
	Bar1.type = RECTANGULAR_PRISM;
	Bar1.xyz[0] = -2.5;
	Bar1.xyz[1] = 2;
	Bar1.xyz[2] = -1.75;
	Bar1.rgb[0] = 0.5;
	Bar1.rgb[1] = 0.2;
	Bar1.rgb[2] = 0.4;
	Bar1.rotation = 0;
	Bar1.params.rect.xlen = 3;
	Bar1.params.rect.ylen = 0.5;
	Bar1.params.rect.zlen = 0.5;
	local.shapes.push_back(Bar1);

	//Right Bar
	ShapeInit Bar2;
	Bar2.type = RECTANGULAR_PRISM;
	Bar2.xyz[0] = -2.5;
	Bar2.xyz[1] = 2;
	Bar2.xyz[2] = 1.75;
	Bar2.rgb[0] = 0.5;
	Bar2.rgb[1] = 0.2;
	Bar2.rgb[2] = 0.4;
	Bar2.rotation = 0;
	Bar2.params.rect.xlen = 3;
	Bar2.params.rect.ylen = 0.5;
	Bar2.params.rect.zlen = 0.5;
	local.shapes.push_back(Bar2);

	//Top
	ShapeInit Trap;
	Trap.type = TRAPEZOIDAL_PRISM;
	Trap.xyz[0] = 1.5;
	Trap.xyz[1] = 2;
	Trap.xyz[2] = 0;
	Trap.rgb[0] = 0;
	Trap.rgb[1] = 1;
	Trap.rgb[2] = 0;
	Trap.rotation = 0;
	Trap.params.trap.alen = 5;
	Trap.params.trap.blen = 3.5;
	Trap.params.trap.height = 1;
	Trap.params.trap.depth = 4;
	Trap.params.trap.aoff = 0;
	local.shapes.push_back(Trap);

	return local;
}


void MiniCooper::draw() {
	std::vector<Shape *>::iterator iter2;
	for (iter2 = shapes.begin(); iter2 != shapes.end(); ++iter2) {
			RectangularPrism *rect = dynamic_cast<RectangularPrism*>(*iter2);
			if (rect != nullptr) {
				glPushMatrix();
				positionInGL();
				rect->draw();
				glPopMatrix();
			}
			TriangularPrism *Tri = dynamic_cast<TriangularPrism*>(*iter2);
			if (Tri != nullptr) {
				glPushMatrix();
				positionInGL();
				Tri->draw();
				glPopMatrix();
			}
			Cylinder *Cyl = dynamic_cast<Cylinder*>(*iter2);
			if (Cyl != nullptr) {
				if (Cyl->GetIsRolling() != 0 && Cyl->GetIsSteering() != 0) {
					glPushMatrix();
					positionInGL();	
					glTranslated(Cyl->getX(), 0, Cyl->getZ());
					glRotated(-steering, 0, 1, 0);
					glTranslated(-Cyl->getX(), 0, -Cyl->getZ());

					glTranslated(Cyl->getX(), Cyl->GetTop(), 0);
					time++;
					s = s + time * speed;
					glRotated((-s / 1) * (180 / M_PI), 0, 0, 1);
					s = 0;
					glTranslated(-Cyl->getX(), -Cyl->GetTop(), 0);
					Cyl->draw();
					glPopMatrix();
				}
				else if (Cyl->GetIsRolling() != 0 && Cyl->GetIsSteering() == 0) {
					glPushMatrix();
					positionInGL();
					glTranslated(Cyl->getX(), Cyl->GetTop(), 0);
					time++;
					s = s + time * speed;
					glRotated((-s / 1) * (180 / M_PI), 0, 0, 1);
					s = 0;
					glTranslated(-Cyl->getX(), -Cyl->GetTop(), 0);
					Cyl->draw();
					glPopMatrix();
				}
				else {
					glPushMatrix();
					positionInGL();
					Cyl->draw();
					glPopMatrix();
				}
			}
			TrapezoidalPrism *Tra = dynamic_cast<TrapezoidalPrism*>(*iter2);
			if (Tra != nullptr) {
				glPushMatrix();
				positionInGL();
				Tra->draw();
				glPopMatrix();
			}
		}



	std::vector<Shape *>::iterator iter;
	for (iter = localshapes.begin(); iter != localshapes.end(); ++iter) {
		RectangularPrism *rect = dynamic_cast<RectangularPrism*>(*iter);
		if (rect != nullptr) {
			glPushMatrix();
			positionInGL();
			rect->draw();
			glPopMatrix();
		}
		Cylinder *Cyl = dynamic_cast<Cylinder*>(*iter);
		if (Cyl != nullptr) {
			if (Cyl->GetIsRolling() != 0 && Cyl->GetIsSteering() != 0) {
				glPushMatrix();
				positionInGL();
				glTranslated(Cyl->getX(), 0, Cyl->getZ());
				glRotated(-steering, 0, 1, 0);
				glTranslated(-Cyl->getX(), 0, -Cyl->getZ());
				glTranslated(Cyl->getX(), 1, 0);
				time++;
				s = s + time * speed;
				glRotated((-s / 1) * (180 / M_PI), 0, 0, 1);
				s = 0;
				glTranslated(-Cyl->getX(), -1, 0);
				Cyl->draw();
				glPopMatrix();
			}
			else if (Cyl->GetIsRolling() != 0 && Cyl->GetIsSteering() == 0) {
				glPushMatrix();
				positionInGL();
				glTranslated(Cyl->getX(), 1, 0);
				time++;
				s = s + time * speed;
				glRotated((-s / 1) * (180 / M_PI), 0, 0, 1);
				s = 0;
				glTranslated(-Cyl->getX(), -1, 0);
				Cyl->draw();
				glPopMatrix();
			}
			else {
				glPushMatrix();
				positionInGL();
				Cyl->draw();
				glPopMatrix();
			}
		}
			/*Cyl->SetDepth(1);
			Cyl->SetTop(1);
			Cyl->SetBase(1);
			Cyl->SetSlices(6);
			Cyl->SetLoops(6);
			Cyl->SetStacks(6);
			glPushMatrix();
			positionInGL();
			Cyl->setColor(1, 1, 1);
			glTranslated(2.5, 0, -2.5);
			glRotated(-steering, 0, 1, 0);
			glTranslated(0, 1, 0);
			if (speed != 0) {
				time++;
				s = s + time * speed;
				glRotated((-s / 1) * (180 / M_PI), 0, 0, 1);
				s = 0;
			}
			glTranslated(0, -1, 0);
			Cyl->draw();
			glPopMatrix(); //left front

			glPushMatrix();
			positionInGL();
			Cyl->setColor(1, 1, 1);
			glTranslated(2.5, 0, 2.5);
			glRotated(-steering, 0, 1, 0);
			glTranslated(0, 1, 0);
			if (speed != 0) {
				time++;
				s = s + time * speed;
				glRotated((-s / 1) * (180 / M_PI), 0, 0, 1);
				s = 0;
			}
			glTranslated(0, -1, 0);
			Cyl->draw();
			glPopMatrix();//right front

			glPushMatrix();
			positionInGL();
			glTranslated(-2.5, 0, 2.5);
			Cyl->setColor(1, 1, 1);
			glTranslated(0, 1, 0);
			if (speed != 0) {
				time++;
				s = s + time * speed;
				glRotated((-s / 1) * (180 / M_PI), 0, 0, 1);
				s = 0;
			}
			glTranslated(0, -1, 0);
			Cyl->draw();
			glPopMatrix();//right back

			glPushMatrix();
			positionInGL();
			Cyl->setColor(1, 1, 1);
			glTranslated(-2.5, 0, -2.5);
			glTranslated(0, 1, 0);
			if (speed != 0) {
				time++;
				s = s + time * speed;
				glRotated((-s / 1) * (180 / M_PI), 0, 0, 1);
				s = 0;
			}
			glTranslated(0, -1, 0);
			Cyl->draw();
			glPopMatrix();//left back

			*/
		TrapezoidalPrism *Tra = dynamic_cast<TrapezoidalPrism*>(*iter);
		if (Tra != nullptr) {
			glPushMatrix();
			positionInGL();
			Tra->draw();
			glPopMatrix();//Front
		}
	}	
}