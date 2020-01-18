//
// Created by Liam Clink on 2020-01-10.
//

#include <vector>

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

    PolarParticle(std::array<double, 2> dipole) : dipole_moment{dipole}
};

class Simulation
{
	Simulation(double x_length, double y_length, double dx, double dy,
			double charge_density, double vapor_density);
	double x_length, y_length;
	double dx, dy;
	double charge_density, vapor_density;

	std::vector<Particle> ions;
	std::vector<Particle> electrons;
	std::vector<PolarParticle> vapor;
}

int main()
{

    return 0;
}
