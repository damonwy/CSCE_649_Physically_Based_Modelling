#pragma once
#ifndef __Particle__
#define __Particle__

#include <vector>
#include <memory>

#define EIGEN_DONT_ALIGN_STATICALLY
#include <Eigen/Dense>

class Shape;
class Program;
class MatrixStack;

class Particle
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	
	Particle();
	Particle(const std::shared_ptr<Shape> shape);
	virtual ~Particle();
	void tare();
	void reset();
	void draw(std::shared_ptr<MatrixStack> MV, const std::shared_ptr<Program> p) const;
	
	double r; // radius
	double m; // mass
	int i;  // starting index
	Eigen::Vector3d x0; // initial position
	Eigen::Vector3d v0; // initial velocity
	Eigen::Vector3d x_old;
	Eigen::Vector3d x;  // position
	Eigen::Vector3d v;  // velocity
	Eigen::Vector3d normal; 

	double lifespan;
	double tEnd;
	double alpha;
	double scale;
	Eigen::Vector3d color;

	bool fixed;
	
private:
	const std::shared_ptr<Shape> sphere;
};

#endif
