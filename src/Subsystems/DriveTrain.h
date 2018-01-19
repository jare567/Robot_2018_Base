#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <ctre/Phoenix.h>
#include "../RobotMap.h"
#include <OI.h>

/*
 *  xbox controller axes
 *  0 - Left stick X axis
 *  1 - Left stick Y axis
 *  2 - Right stick X axis
 */
#define DRIVE_X_AXIS 0
#define DRIVE_Y_AXIS 1
#define TURN_AXIS 2

#define DEADBAND .2 // Axis deadband

class DriveTrain : public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	WPI_TalonSRX *fl; // Front Left motor
	WPI_TalonSRX *fr; // Front Right motor
	WPI_TalonSRX *rl; // Rear left motor
	WPI_TalonSRX *rr; // Rear Right motor
//	ADIS16448_IMU *imu;
	double gyroAngle;
	char gyroString[128];
	bool reversed;

public:
	MecanumDrive *m_robotDrive;
	DriveTrain();
	void InitDefaultCommand();
	void SaucerDrive(double, double);
	void Go(double, double, double, double); // Left X, Left Y, Twist, Gyro
	double GetGyroAngle();
	double Db(double); // Deadband
};

#endif  // DriveTrain_H
