#include "monte_carlo_pi.h"

double simulate_pi(int n)
{
    // A standard interface to a platform−specific non−deterministic random number generator
    std::random_device rd; // Create Random Device as seed
    std::mt19937 mt(rd()); // Init Mersenne Twister Engine with that seed
    // A continuous random distribution on the range [min, max] with equal probability .
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    // make a count within circle
    int cnt = 0;
    // Generate x,y values
    for (int i=0; i<n; ++i)
    {
        double x = dist(mt);
        double y = dist(mt);
        if ((x*x + y*y) <= 1) cnt += 1;
    }
    return (4.0 * cnt / n);
}
