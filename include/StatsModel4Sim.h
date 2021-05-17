//
// Created by Haoda Fu on 2019-04-27.
//

#ifndef DEMO_STATSMODEL4SIM_H
#define DEMO_STATSMODEL4SIM_H

#include <Eigen/Dense>
#include <random>
class StatsModel4Sim{
public:
    //constructor
    StatsModel4Sim(size_t sampleSzie, size_t nPar, size_t seed);


    //Linear Models
    void generateSimpleLinearModelSim();

    //setter and getter function
    size_t getSampleSzie() const;
    void setSampleSzie(size_t sampleSzie);
    size_t getNPar() const;
    void setNPar(size_t nPar);

    const Eigen::VectorXd &getBeta() const;
    void setBeta(const Eigen::VectorXd &beta);

    const Eigen::MatrixXd &getDataM() const;
    const Eigen::VectorXd &getY() const;

private:

    void generateXUnif();
    void generateErrNorm01IID();

    size_t sampleSzie_{200};
    size_t nPar_{10};
    Eigen::VectorXd beta_;
    Eigen::MatrixXd dataM_;
    Eigen::VectorXd y_;
    Eigen::VectorXd err_;

    std::default_random_engine generator_;
    std::normal_distribution<> rnorm_{0,1};
    std::uniform_real_distribution<> runifDouble_{0,1};
    std::uniform_int_distribution<> runifInt_{0,1};
    std::binomial_distribution<int> rbinom_{1,0.5};


};
#endif //DEMO_STATSMODEL4SIM_H
