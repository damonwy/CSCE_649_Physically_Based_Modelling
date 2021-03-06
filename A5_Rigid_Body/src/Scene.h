#pragma once
#ifndef __Scene__
#define __Scene__

#include <vector>
#include <memory>
#include <string>

#define EIGEN_DONT_ALIGN_STATICALLY
#include <Eigen/Dense>
class RigidBody;
class Tetrahedron;
class Cloth;
//class Bar;
class Particle;
class MatrixStack;
class Program;
class Shape;
class FemTet;
class FemNesme;
class FemSimit;

class Scene
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	
	Scene();
	virtual ~Scene();
	
	void load(const std::string &RESOURCE_DIR);
	void init();
	void tare();
	void reset();
	void step();
	void draw(std::shared_ptr<MatrixStack> MV, const std::shared_ptr<Program> prog) const;
	double randDouble(double l, double h);
	double getTime() const { return t; }
	
private:
	double t;
	double h;
	int numrbs;
	Eigen::Vector3d grav;
	
	std::shared_ptr<RigidBody> rigidbody;
	std::shared_ptr<Shape> sphereShape;
	std::shared_ptr<Cloth> cloth;
	std::shared_ptr<Tetrahedron> tet;
	//std::shared_ptr<Bar> bar;
	std::shared_ptr<FemTet> femtet;
	std::shared_ptr<FemNesme> femNesme;
	std::shared_ptr<FemSimit> femSimit;
	
	std::vector< std::shared_ptr<Particle> > spheres;
	std::vector< std::shared_ptr<RigidBody> >rigidbodies;
};

#endif
