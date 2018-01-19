#include "Piston.h"

Piston::Piston() : Subsystem("Piston")
{
	s = new DoubleSolenoid(CYLINDER_PORT0, CYLINDER_PORT1);
	isOpen = true;
}

void Piston::Extend()
{
	s->Set(DoubleSolenoid::Value::kForward);
	isOpen = true;
}

void Piston::Retract()
{
	isOpen = false;
	s->Set(DoubleSolenoid::Value::kReverse);
}
