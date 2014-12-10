#ifndef BASE_GAME_ENTITY_H
#define BASE_GAME_ENTITY_H

#include <vector>
#include <string>
#include "Vector2D.h"
#include "2D/Geometry.h"
#include "misc/Utils.h"

struct Telegram;


class BaseGameEntity
{
public:

	enum { default_entity_type = -1 };

private:

	int         id;
	int         entityType; 
	bool        bTag;

	//used by the constructor to give each entity a unique ID
	int NextValidID(){ static int NextID = 0; return NextID++; }


protected:

	// Location in the environment
	Vector2D vPos;

	Vector2D vScale;

	// Length of this object's bounding radius
	double boundingRadius;


	BaseGameEntity() :id(NextValidID()),
		boundingRadius(0.0),
		vPos(Vector2D()),
		vScale(Vector2D(1.0, 1.0)),
		entityType(default_entity_type),
		bTag(false)
	{}

	BaseGameEntity(int entity_type) :id(NextValidID()),
		boundingRadius(0.0),
		vPos(Vector2D()),
		vScale(Vector2D(1.0, 1.0)),
		entityType(entity_type),
		bTag(false)
	{}

	BaseGameEntity(int entity_type, Vector2D pos, double r) :vPos(pos),
		boundingRadius(r),
		id(NextValidID()),
		vScale(Vector2D(1.0, 1.0)),
		entityType(entity_type),
		bTag(false)

	{}

public:

	virtual ~BaseGameEntity(){}

	virtual void Update(double time_elapsed){};
	virtual void Render(){};
	virtual bool HandleMessage(const Telegram& msg){ return false; }

	// Entities should be able to read/write their data to a stream
	virtual void Write(std::ostream&  os)const{}
	virtual void Read(std::ifstream& is){}



	Vector2D Pos()const{ return vPos; }
	void SetPos(Vector2D new_pos){ vPos = new_pos; }

	double BRadius()const{ return boundingRadius; }
	void SetBRadius(double r){ boundingRadius = r; }
	int ID()const{ return id; }

	bool IsTagged()const{ return bTag; }
	void Tag(){ bTag = true; }
	void UnTag(){ bTag = false; }

	Vector2D Scale()const{ return vScale; }
	void SetScale(Vector2D val){ boundingRadius *= MaxOf(val.x, val.y) / MaxOf(vScale.x, vScale.y); vScale = val; }
	void SetScale(double val){ boundingRadius *= (val / MaxOf(vScale.x, vScale.y)); vScale = Vector2D(val, val); }

	int EntityType()const{ return entityType; }
	void SetEntityType(int new_type){ entityType = new_type; }

};




#endif




