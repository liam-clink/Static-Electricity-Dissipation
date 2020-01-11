//
// Created by Liam Clink on 2020-01-10.
//

#include <vector>

struct Particle
{
    double charge_mass_ratio;
    std::vector<double, 2> position;
    std::vector<double, 2> velocity;

    Particle(double cm_ratio, std::vector<double, 2> pos, std::vector<double, 2> vel)
    {
        charge_mass_ratio = cm_ratio;
        position = pos;
        velocity = vel;
    }
};

struct PolarParticle : public Particle
{
    std::vector<double, 2> dipole_moment;

    PolarParticle(std::vector<double, 2> dipole) : dipole_moment{dipole}
};

int main()
{

    return 0;
}