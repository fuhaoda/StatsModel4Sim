//
// Created by Haoda Fu on 2019-04-27.
//
#include <iostream>
#include "StatsModel4Sim.h"

using namespace std;
using namespace Eigen;


size_t StatsModel4Sim::getSampleSzie() const {
    return sampleSzie_;
}

void StatsModel4Sim::setSampleSzie(size_t sampleSzie) {
    sampleSzie_ = sampleSzie;
}

size_t StatsModel4Sim::getNPar() const {
    return nPar_;
}

void StatsModel4Sim::setNPar(size_t nPar) {
    nPar_ = nPar;
}

const Eigen::VectorXd &StatsModel4Sim::getBeta() const {
    return beta_;
}

void StatsModel4Sim::setBeta(const Eigen::VectorXd &beta) {
    if(nPar_!= beta.size()){
        cout << "The input parameter size is incorrect" << endl;
        exit(-1);
    }
    beta_ = beta;
}

const Eigen::MatrixXd & StatsModel4Sim::getDataM() const {
    return dataM_;
}

const Eigen::VectorXd &StatsModel4Sim::getY() const {
    return y_;
}

StatsModel4Sim::StatsModel4Sim(size_t sampleSzie, size_t nPar, size_t seed) : sampleSzie_(sampleSzie), nPar_(nPar) {
    generator_.seed(seed);
    beta_.resize(nPar);
    y_.resize(sampleSzie);
    err_.resize(sampleSzie);
    dataM_.resize(sampleSzie,nPar);
}

void StatsModel4Sim::generateXUnif() {
    dataM_ = MatrixXd::NullaryExpr(sampleSzie_,nPar_,[&](){return runifDouble_(generator_);});
    return;
}

void StatsModel4Sim::generateErrNorm01IID() {
    err_ = VectorXd::NullaryExpr(sampleSzie_, [&](){return rnorm_(generator_);});
    return;
}

void StatsModel4Sim::generateSimpleLinearModelSim() {
    generateXUnif();
    generateErrNorm01IID();
    y_=dataM_*beta_+err_;
    return;
}
