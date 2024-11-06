#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>
#include <iostream>
#include "MomentumData.h" 

void write(){
    const Int_t nEvents = 1000;

    TFile *file = new TFile("tree_file.root", "RECREATE");

    TTree *tree = new TTree("tree", "A tree storing the data");

    MomentumData *eventdata = new MomentumData();

    tree->Branch("eventdata", &eventdata);

    for (Int_t i{0}; i<nEvents; i++){
        Float_t px = gRandom->Gaus();
        Float_t py = gRandom->Gaus();
        Float_t pz = gRandom->Gaus();

        std::cout << "px: " << px << ", py: " << py << ", pz: " << pz << std::endl;

        *eventdata = MomentumData(px, py, pz);

        tree->Fill();
    };

    tree->Write();

    delete eventdata;
    file->Close();
    delete file;

}
