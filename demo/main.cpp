//
// Created by Haoda Fu on 2019-04-27.
//

#include <iostream>
#include "StatsModel4Sim.h"

using namespace std;

int main(){
    std::cout << "hello" << std::endl;
    StatsModel4Sim Model1(100,4,1);

    Eigen::VectorXd par(4);
    par << 1,1,0,0;

    Model1.setBeta(par);

    for(int i=0; i<3; ++i){
        Model1.generateSimpleLinearModelSim();
        cout << "Simulation: " << i << endl;
        cout << "Design Matrix" << endl;
        cout << Model1.getDataM() << endl;
        cout << "Response Y" << endl;
        cout << Model1.getY() << endl;
    }

    Eigen::VectorXd estPar=Eigen::VectorXd::Zero(4);

    int nIter =10000;

    for(int i=0;i<nIter;++i)
    {
        Model1.generateSimpleLinearModelSim();
        auto & dataM = Model1.getDataM();
        estPar+=(dataM.transpose()*dataM).ldlt().solve(dataM.transpose()*Model1.getY());
    }

    cout << "estimated results" << endl;
    cout << estPar/nIter << endl;

    return 0;
}