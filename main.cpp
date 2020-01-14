//
// Created by Liam Clink on 2020-01-10.
//

#include <vector>

struct Particle
{
    double charge, mass;
    std::vector<double, 2> position;
    std::vector<double, 2> velocity;

    Particle(double c, double m, std::vector<double, 2> pos, std::vector<double, 2> vel)
    {
        charge = c;
	mass = m;
        position = pos;
        velocity = vel;
    }
};

// We need the vapor particles to be polarizable, as well as having a charge
struct PolarParticle : public Particle
{
    std::vector<double, 2> dipole_moment;

    PolarParticle(std::vector<double, 2> dipole) : dipole_moment{dipole}
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
