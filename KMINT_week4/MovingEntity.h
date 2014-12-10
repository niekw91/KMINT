#ifndef MOVING_ENTITY
#define MOVING_ENTITY

#include <cassert>

#include "Vector2D.h"
#include "BaseGameEntity.h"

class MovingEntity : public BaseGameEntity
{
protected:

	Vector2D vVelocity;

	// A normalized vector pointing in the direction the entity is heading. 
	Vector2D vHeading;

	// A vector perpendicular to the heading vector
	Vector2D vSide;

	double mass;
	double maxSpeed;
	double maxForce;       
	double maxTurnRate;

public:

	MovingEntity(Vector2D position,
		double    radius,
		Vector2D velocity,
		double    max_speed,
		Vector2D heading,
		double    mass,
		Vector2D scale,
		double    turn_rate,
		double    max_force) :BaseGameEntity(0, position, radius),
		vHeading(heading),
		vVelocity(velocity),
		mass(mass),
		vSide(vHeading.Perp()),
		maxSpeed(max_speed),
		maxTurnRate(turn_rate),
		maxForce(max_force)
	{
		vScale = scale;
	}

	virtual ~MovingEntity(){}

	Vector2D Velocity()const{ return vVelocity; }
	void SetVelocity(const Vector2D& NewVel){ vVelocity = NewVel; }

	double Mass()const{ return mass; }

	Vector2D Side()const{ return vSide; }

	double MaxSpeed()const{ return maxSpeed; }
	void SetMaxSpeed(double new_speed){ maxSpeed = new_speed; }

	double MaxForce()const{ return maxForce; }
	void SetMaxForce(double mf){ maxForce = mf; }

	bool IsSpeedMaxedOut()const{ return maxSpeed*maxSpeed >= vVelocity.LengthSq(); }
	double Speed()const{ return vVelocity.Length(); }
	double SpeedSq()const{ return vVelocity.LengthSq(); }

	Vector2D Heading()const{ return vHeading; }
	void SetHeading(Vector2D new_heading);
	bool RotateHeadingToFacePosition(Vector2D target);

	double MaxTurnRate()const{ return maxTurnRate; }
	void SetMaxTurnRate(double val){ maxTurnRate = val; }

};


////--------------------------- RotateHeadingToFacePosition ---------------------
////
////  given a target position, this method rotates the entity's heading and
////  side vectors by an amount not greater than m_dMaxTurnRate until it
////  directly faces the target.
////
////  returns true when the heading is facing in the desired direction
////-----------------------------------------------------------------------------
//inline bool MovingEntity::RotateHeadingToFacePosition(Vector2D target)
//{
//	Vector2D toTarget = Vec2DNormalize(target - m_vPos);
//
//	//first determine the angle between the heading vector and the target
//	double angle = acos(m_vHeading.Dot(toTarget));
//
//	//return true if the player is facing the target
//	if (angle < 0.00001) return true;
//
//	//clamp the amount to turn to the max turn rate
//	if (angle > m_dMaxTurnRate) angle = m_dMaxTurnRate;
//
//	//The next few lines use a rotation matrix to rotate the player's heading
//	//vector accordingly
//	C2DMatrix RotationMatrix;
//
//	//notice how the direction of rotation has to be determined when creating
//	//the rotation matrix
//	RotationMatrix.Rotate(angle * m_vHeading.Sign(toTarget));
//	RotationMatrix.TransformVector2Ds(m_vHeading);
//	RotationMatrix.TransformVector2Ds(m_vVelocity);
//
//	//finally recreate m_vSide
//	m_vSide = m_vHeading.Perp();
//
//	return false;
//}
//
//
////------------------------- SetHeading ----------------------------------------
////
////  first checks that the given heading is not a vector of zero length. If the
////  new heading is valid this fumction sets the entity's heading and side 
////  vectors accordingly
////-----------------------------------------------------------------------------
//inline void MovingEntity::SetHeading(Vector2D new_heading)
//{
//	assert((new_heading.LengthSq() - 1.0) < 0.00001);
//
//	m_vHeading = new_heading;
//
//	//the side vector must always be perpendicular to the heading
//	m_vSide = m_vHeading.Perp();
//}



#endif