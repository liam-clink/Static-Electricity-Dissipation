//
// Created by Liam Clink on 2020-01-10.
//

// TODO: add droplet size variation if it matters. Dipole moment does scale with mass...
// TODO: 

#include <array>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include <armadillo>

const double pi = acos(-1);
const double epsilon_0 = 8.854e-12; // Farad per meter (C*m / (m^3 * V/m))
const double coulomb_const = 1./(4.*pi*epsilon_0);

struct Particle
{
    Particle() = default;

    Particle(double charge,
             double mass,
             arma::vec position,
             arma::vec velocity)
        : _charge(charge),
          _mass(mass),
          _position{position},
          _velocity{velocity}
    {}

    double _charge, _mass;
    arma::vec _position;
    arma::vec _velocity;
};

// We need the vapor particles to be polarizable, as well as having a charge
struct PolarParticle : public Particle
{
    PolarParticle(double charge,
                  double mass,
                  arma::vec position, 
                  arma::vec velocity,
                  arma::vec dipole)
        : Particle(charge, mass, position, velocity),
          dipole_moment{dipole}
    {}

    arma::vec dipole_moment;
    double polarization_coefficient = epsilon_0*79.;
};

bool in_circle(arma::vec point, arma::vec center, double radius)
{
    double distance = arma::norm(point-center, 2);
    return distance <= radius;
}

// Actually only need gradient of the field for calculation, this is for plotting
arma::vec monopole_field(arma::vec test_position, arma::vec charge_position, double charge)
{
    arma::vec separation = test_position-charge_position;
    return coulomb_const*charge*pow(arma::norm(separation,2),-3)*(separation);
}



class Simulation
{
public:
	Simulation(double x_length,
               double y_length,
			   double surface_charge_density,
               double vapor_density,
               double ball_radius)
        : _x_length(x_length),
          _y_length(y_length),
          _ball_radius(ball_radius)
    {
        charge_ball = Particle(1.,1.,{0.,0.},{0.,0.});

        std::random_device rd;
        rng = std::mt19937(rd());
        
        int vapor_number = std::round(x_length*y_length*vapor_density);
        vapor = std::vector<PolarParticle>(vapor_number);

        std::uniform_real_distribution<double> x_dist(-x_length/2., x_length/2.);
        std::uniform_real_distribution<double> y_dist(-y_length/2., y_length/2.);

        for (int i=0; i<vapor_number; i++)
        {
            arma::vec position = {x_dist(rng),y_dist(rng)};
            if (in_circle(position, {0.,0.}, _ball_radius)) continue;
            
            vapor.at(i) = PolarParticle(0.,1.,position,{0.,0.},{0.,0.});
        }

        electron_count = std::round(pi*_ball_radius*surface_charge_density);
    }

    int run()
    {
        std::cout << "test\n";
        return 0;
    }

private:
    std::mt19937 rng;

    double _x_length, _y_length;
    double _ball_radius;

    Particle charge_ball;
    int electron_count;
    std::vector<PolarParticle> vapor;
};

int main()
{
    Simulation sim(1.,1.,1.,1.,0.05);
    sim.run();
    
    return 0;
}
