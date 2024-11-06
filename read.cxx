#include <TFile.h>
#include <TTree.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <iostream>
#include <TRandom.h>
#include "MomentumData.h"
#include <typeinfo>
#include <TH1F.h>

void read() {

    auto file = TFile::Open("tree_file.root");

    TTree *tree = static_cast<TTree*>(file->Get("tree"));
    //file->GetObject("tree", tree);

    Float_t fPx, fPy;

    tree->SetBranchAddress("fPx", &fPx);
    tree->SetBranchAddress("fPy", &fPy);

    auto *c1 = new TCanvas("c1","Canvas",800,600);

    
    auto *hist = new TH2F("hist", "histogram", 1000, -5, 5, 100, -5, 5);

    Long64_t n_entries = (Long64_t)tree->GetEntries();
    for (Long64_t entry = 0; entry < n_entries; entry++) {
        tree->GetEntry(entry);
        std::cout << fPx << std::endl; //It prints correct values!
        hist->Fill(fPx, fPy);
        
    }

    hist->Draw(); 
    c1->Update();
    /*
    I do not understand why this is drawing a blank canvas...
    */

    auto *c2 = new TCanvas("c2", "Canvas2", 800, 600);
    tree->Draw("fPx*fPy:fPz", "fPmag > 1", "COLZ");
    c2->Update();

    auto *c3 = new TCanvas("c3", "Canvas3", 800, 600);
    tree->Draw("fPx:fPy", "", "COLZ");
    c3->Update();

    file->Close();
}
