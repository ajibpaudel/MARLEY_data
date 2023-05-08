//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Feb 26 21:59:03 2023 by ROOT version 6.26/06
// from TTree mst/MARLEY summary tree
// found on file: MARLEY_rootfile.root
//////////////////////////////////////////////////////////

#ifndef MARLEY_events_h
#define MARLEY_events_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class MARLEY_events {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           pdgv;
   Double_t        Ev;
   Double_t        KEv;
   Double_t        pxv;
   Double_t        pyv;
   Double_t        pzv;
   Int_t           pdgt;
   Double_t        Mt;
   Int_t           pdgl;
   Double_t        El;
   Double_t        KEl;
   Double_t        pxl;
   Double_t        pyl;
   Double_t        pzl;
   Int_t           pdgr;
   Double_t        Er;
   Double_t        KEr;
   Double_t        pxr;
   Double_t        pyr;
   Double_t        pzr;
   Double_t        Ex;
   Int_t           twoJ;
   Int_t           parity;
   Int_t           np;
   Int_t           pdgp[20];   //[np]
   Double_t        Ep[20];   //[np]
   Double_t        KEp[20];   //[np]
   Double_t        pxp[20];   //[np]
   Double_t        pyp[20];   //[np]
   Double_t        pzp[20];   //[np]
   Double_t        xsec;

   // List of branches
   TBranch        *b_pdgv;   //!
   TBranch        *b_Ev;   //!
   TBranch        *b_KEv;   //!
   TBranch        *b_pxv;   //!
   TBranch        *b_pyv;   //!
   TBranch        *b_pzv;   //!
   TBranch        *b_pdgt;   //!
   TBranch        *b_Mt;   //!
   TBranch        *b_pdgl;   //!
   TBranch        *b_El;   //!
   TBranch        *b_KEl;   //!
   TBranch        *b_pxl;   //!
   TBranch        *b_pyl;   //!
   TBranch        *b_pzl;   //!
   TBranch        *b_pdgr;   //!
   TBranch        *b_Er;   //!
   TBranch        *b_KEr;   //!
   TBranch        *b_pxr;   //!
   TBranch        *b_pyr;   //!
   TBranch        *b_pzr;   //!
   TBranch        *b_Ex;   //!
   TBranch        *b_twoJ;   //!
   TBranch        *b_parity;   //!
   TBranch        *b_np;   //!
   TBranch        *b_pdgp;   //!
   TBranch        *b_Ep;   //!
   TBranch        *b_KEp;   //!
   TBranch        *b_pxp;   //!
   TBranch        *b_pyp;   //!
   TBranch        *b_pzp;   //!
   TBranch        *b_xsec;   //!

   MARLEY_events(TTree *tree=0);
   virtual ~MARLEY_events();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MARLEY_events_cxx
MARLEY_events::MARLEY_events(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("MARLEY_rootfile.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("MARLEY_rootfile.root");
      }
      f->GetObject("mst",tree);

   }
   Init(tree);
}

MARLEY_events::~MARLEY_events()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MARLEY_events::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MARLEY_events::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MARLEY_events::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pdgv", &pdgv, &b_pdgv);
   fChain->SetBranchAddress("Ev", &Ev, &b_Ev);
   fChain->SetBranchAddress("KEv", &KEv, &b_KEv);
   fChain->SetBranchAddress("pxv", &pxv, &b_pxv);
   fChain->SetBranchAddress("pyv", &pyv, &b_pyv);
   fChain->SetBranchAddress("pzv", &pzv, &b_pzv);
   fChain->SetBranchAddress("pdgt", &pdgt, &b_pdgt);
   fChain->SetBranchAddress("Mt", &Mt, &b_Mt);
   fChain->SetBranchAddress("pdgl", &pdgl, &b_pdgl);
   fChain->SetBranchAddress("El", &El, &b_El);
   fChain->SetBranchAddress("KEl", &KEl, &b_KEl);
   fChain->SetBranchAddress("pxl", &pxl, &b_pxl);
   fChain->SetBranchAddress("pyl", &pyl, &b_pyl);
   fChain->SetBranchAddress("pzl", &pzl, &b_pzl);
   fChain->SetBranchAddress("pdgr", &pdgr, &b_pdgr);
   fChain->SetBranchAddress("Er", &Er, &b_Er);
   fChain->SetBranchAddress("KEr", &KEr, &b_KEr);
   fChain->SetBranchAddress("pxr", &pxr, &b_pxr);
   fChain->SetBranchAddress("pyr", &pyr, &b_pyr);
   fChain->SetBranchAddress("pzr", &pzr, &b_pzr);
   fChain->SetBranchAddress("Ex", &Ex, &b_Ex);
   fChain->SetBranchAddress("twoJ", &twoJ, &b_twoJ);
   fChain->SetBranchAddress("parity", &parity, &b_parity);
   fChain->SetBranchAddress("np", &np, &b_np);
   fChain->SetBranchAddress("pdgp", pdgp, &b_pdgp);
   fChain->SetBranchAddress("Ep", Ep, &b_Ep);
   fChain->SetBranchAddress("KEp", KEp, &b_KEp);
   fChain->SetBranchAddress("pxp", pxp, &b_pxp);
   fChain->SetBranchAddress("pyp", pyp, &b_pyp);
   fChain->SetBranchAddress("pzp", pzp, &b_pzp);
   fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
   Notify();
}

Bool_t MARLEY_events::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MARLEY_events::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MARLEY_events::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MARLEY_events_cxx
