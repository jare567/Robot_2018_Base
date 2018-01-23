/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <Commands/GearLight.h>
#include <Commands/PistonExtend.h>
#include <Commands/PistonRetract.h>

/* ****
 *
 * 	xBox Controller button mapping:
 * 	Button 0 - A
 * 	Button 1 - B
 * 	Button 2 - X
 * 	Button 3 - Y
 * 	Button 4 - Left Bumper
 * 	Button 5 - Right Bumper
 */
OI::OI() {
	// Process operator interface input here.

	// Driver Station USB Port 4: Xbox controller
	xboxController = new Joystick(4);
	// Green light from SteamWorks "Gear Ready"
	gearLightBtn = new JoystickButton(xboxController, 1);
	gearLightBtn->WhileHeld(new GearLight);

	// Piston Extend & Retract buttons
	extendBtn = new JoystickButton(xboxController, 6);
	extendBtn->WhenPressed(new PistonExtend);
	retractBtn = new JoystickButton(xboxController, 7);
	retractBtn->WhenPressed(new PistonRetract);

	// PowerCube Grab
	lBumper = new JoystickButton(xboxController, 4);
	lBumper->WhenPressed(new GearLight); // FIXME: GrabLeft
	rBumper = new JoystickButton(xboxController, 5);
	rBumper->WhenPressed(new GearLight); // FIXME: GrabRight

	// PowerCube Eject
	xboxXBtn = new JoystickButton(xboxController, 1);
	xboxXBtn->WhenPressed(new GearLight); // FIXME: EjectCube

	// Forklift Raise & Lower
	xboxABtn = new JoystickButton(xboxController, 1);
	xboxABtn->WhenPressed(new GearLight); // FIXME: LowerFork
	xboxBBtn = new JoystickButton(xboxController, 0);
	xboxBBtn->WhenPressed(new GearLight); // FIXME: RaiseFork



}
