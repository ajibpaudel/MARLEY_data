#define MARLEY_events_cxx
#include "MARLEY_events.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

void MARLEY_events::Loop()
{
  //define histograms
  TH1D *E_nu=new TH1D("E_nu","Incident neutrino energy [MeV];incident neutrino energy [MeV];entries",70,0,70); 
  TH1D *E_final=new TH1D("E_final","Total final energy;total final energy [MeV];entries",70,0,70);
  TH2D *Enu_vs_Efinal=new TH2D("Enu_vs_Efinal","Neutrino energy vs total final energy; Neutrino energy [MeV];Final product energy [MeV]",70,0,70,70,0,70);
  TH2D *Enu_vs_Efinalcharged=new TH2D("Enu_vs_Efinalcharged","Neutrino energy vs total final energy; Neutrino energy [MeV];Final product energy [MeV]",70,0,70,70,0,70);
  TH1D *Einc_min_Final=new TH1D("Einc_min_Final","Energy difference;Enu-Etotal [MeV];entries",200,-50,50);
   TH1D *Einc_min_Finalresidual=new TH1D("Einc_min_Finalresidual","Energy difference including residual energy;Enu-Etotal [MeV];entries",200,-50,50);
   TH2D *Enu_vs_Efinalres=new TH2D("Enu_vs_Efinalres","Neutrino energy vs total final energy (considering residual energy); Neutrino energy [MeV];Final product energy [MeV]",70,0,70,70,0,70);


   TH2D *Enu_vs_El=new TH2D("Enu_vs_El","Neutrino energy vs ejectile electron energy for inelastic scattering; Neutrino energy [MeV];Final product energy [MeV]",70,0,70,70,0,70);
  
  TFile *f=new TFile("MARLEY_energies.root","RECREATE");

  double Enu=0.0;
  double Etot=0.0;
  bool onlyphotons=true;
  int neutroncount=0;
  int protoncount=0;
  int countpdgothers=0;
  double Eej=0.0;//Ejectile total energy
  double Etotcharged=0.0;//considering energy from charged final states only
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //if(pdgt!=11) continue;

      ////Checking final stage
      onlyphotons=true;
      countpdgothers=0;
      neutroncount=0;
      protoncount=0;
      for(int i=0; i<np;i++){
	if(pdgp[i]==22) continue;
	onlyphotons=false;
	//	if(pdgp[i]==2212) onlyphotons=false;//protons
	//	if(pdgp[i]==2112) onlyphotons=false;//protons
	if(pdgp[i]==2212) protoncount++;//protons
	if(pdgp[i]==2112) neutroncount++;//protons
	if(pdgp[i]>2500) countpdgothers++;
      }
      std::cout<<"neutron count , proton count "<<neutroncount<<"  "<<protoncount<<std::endl;
      /* if(neutroncount>0) continue;
      if(protoncount!=1) continue;
      if(countpdgothers>0) continue;*/
      if(!onlyphotons) continue;
      std::cout<<"Onlyphotons "<<onlyphotons<<std::endl;

      //////////////////////////
      Etot=0.0;

      Enu=Ev;//neutrino energy
      Eej=KEl;
      //if(pdgt==11) Enu_vs_El->Fill(Ev, Eej);
      if(pdgt==11) continue;
      Enu_vs_El->Fill(Ev, KEl);
      Etot=0.0+Eej;
      Etotcharged=0.0+Eej;
      for(int i=0;i<np;i++){//np is the number of excitation products
	Etot=Etot+KEp[i];
      }
      for(int i=0;i<np;i++){//np is the number of excitation products
	Etotcharged=Etotcharged+Ep[i];
      }


      //std::cout<<"Etotal vs Enu "<<Etot<<"  "<<Enu<<std::endl;

       std::cout<<"Etotal - Enu "<<Etot-Enu<<"  "<<std::endl;
      
      
      E_nu->Fill(Enu);
      E_final->Fill(Etot);
      Enu_vs_Efinal->Fill(Enu, Etot);
      Einc_min_Final->Fill(Enu-Etot);
      Einc_min_Finalresidual->Fill(Enu-Etot+Mt-Er);
      Enu_vs_Efinalres->Fill(Enu, Etot+Er-Mt);

   }
   E_nu->Write();
   E_final->Write();
   Enu_vs_Efinal->Write();
   Einc_min_Final->Write();
   Einc_min_Finalresidual->Write();
   Enu_vs_El->Write();
   Enu_vs_Efinalres->Write();
   f->Close();
}
