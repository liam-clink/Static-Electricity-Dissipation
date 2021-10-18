//
// Created by Liam Clink on 2020-01-10.
//

#include <array>
#include <vector>
#include <iostream>

struct Particle
{
    double charge, mass;
    std::array<double, 2> position;
    std::array<double, 2> velocity;

    Particle(double c, double m, std::array<double, 2> pos, std::array<double, 2> vel)
    {
	// The reason that the pos and vel parameters are arrays instead of multiple
	// args each is that changing the dimension of the simulation is possible
	// without complicated overloading
        charge = c;
	    mass = m;
        position = pos;
        velocity = vel;
    }
};

// We need the vapor particles to be polarizable, as well as having a charge
struct PolarParticle : public Particle
{
    std::array<double, 2> dipole_moment;

    PolarParticle(double c,
                  double m,
                  std::array<double, 2> pos, 
                  std::array<double, 2> vel,
                  std::array<double, 2> dipole)
        : Particle(c, m, pos, vel),
          dipole_moment{dipole}
    {}
};

class Simulation
{
public:
	Simulation(double _x_length,
               double _y_length, 
               double _dx,
               double _dy,
			   double _charge_density,
               double _vapor_density)
        : x_length(_x_length),
          y_length(_y_length),
          dx(_dx),
          dy(_dy),
          charge_density(_charge_density),
          vapor_density(_vapor_density)
    {}

    int run()
    {
        std::cout << "test\n";
        return 0;
    }

private:
	double x_length, y_length;
	double dx, dy;
	double charge_density, vapor_density;

	std::vector<Particle> ions;
	std::vector<Particle> electrons;
	std::vector<PolarParticle> vapor;
};

int main()
{
    Simulation sim(1.,1.,.1,.1,1.,1.);
    return 0;
}
