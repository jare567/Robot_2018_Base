#include "DriveTrain.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	fl = new WPI_TalonSRX(FRONT_LEFT_MOTOR_ID); // Front Left
	rl = new WPI_TalonSRX(REAR_LEFT_MOTOR_ID); // Rear Left
	fr = new WPI_TalonSRX(FRONT_RIGHT_MOTOR_ID); // Front Right
	rr = new WPI_TalonSRX(REAR_RIGHT_MOTOR_ID); // Rear Right

	/*
	 * MecanumDrive library automatically inverts the right drive motors
	 */
	// Invert the two motors which need to spin backwards to move 'bot fwd
	// fl->SetInverted(true);
	// rl->SetInverted(true);
	// fr->SetInverted(false);
	// rr->SetInverted(false);

	m_robotDrive = new MecanumDrive(*fl, *rl, *fr, *rr);

	// FIXME: Need to import the IMU module for Gyro feedback
//	imu = new ADIS16448_IMU();
//	imu->Reset();
	gyroAngle = 0.0;
	reversed = false;

	/* Set every Talon to reset the motor safety timeout. */
	fl->Set(ControlMode::PercentOutput, 0);
	fr->Set(ControlMode::PercentOutput, 0);
	rl->Set(ControlMode::PercentOutput, 0);
	rr->Set(ControlMode::PercentOutput, 0);

	// CRE: 2017-02-17 Initialize the encoder position so we can (hopefully) tell how far we've moved
	// fl->SetPosition(0);
	// fr->SetPosition(0);
	// rl->SetPosition(0);
	// rr->SetPosition(0);

	// Create a RobotDrive object using PWMS 1, 2, 3, and 4
	m_robotDrive->SetExpiration(0.5);
	m_robotDrive->SetSafetyEnabled(false);

}

void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// FIXME: The following line throws an "expected type-specifier before 'MecanumSaucerDrive'" error
	// SetDefaultCommand(new MecanumSaucerDrive());
}

void DriveTrain::SaucerDrive(double angle, double magnitude)
{

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::Go(double x, double y, double twist, double gyroAngle)
{

	double angle = 0.0; // this->GetGyroAngle();
	//std::cout << "Angle : " << angle << std::endl;
	m_robotDrive->DriveCartesian(Db(x), Db(y), Db(twist), angle);

	/* on button 5, reset gyro angle to zero */
//	if(m_driveStick->GetRawButton(5))
//		gyro.Reset();
}

double DriveTrain::GetGyroAngle()
{
	// gyroAngle = imu->GetAngleZ()/4.0;
	//	printf("XBoxDrive::Execute() gyroAngle = %5.2f\n", gyroAngle);
	sprintf(gyroString, "%5.2f degrees", gyroAngle);
	// SmartDashboard::PutString("Gyro Angle: ", gyroString);
	return (gyroAngle);
}

/** @return deadband */
double DriveTrain::Db(double axisVal)
{
	if(axisVal < -DEADBAND)
		return axisVal;
	if(axisVal > +DEADBAND)
		return axisVal;
	return 0;
}
