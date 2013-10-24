#include "CreateTree.hh"



CreateTree* CreateTree::fInstance = NULL;

CreateTree::CreateTree(TString name, Bool_t hits, Bool_t window, Bool_t fiber, Bool_t control, Bool_t deposition, Bool_t production)
{
  if( fInstance ) return; 
  
  this->fInstance = this;
  
  this->fname = name;
  this->ftree = new TTree("ntu","ntu");
  
  this->HITS = hits;
  this->WINDOW = window;
  this->FIBER = fiber;
  this->CONTROL = control;
  this->DEPOSITION = deposition;
  this->PRODUCTION = production;
  
  this->GetTree()->Branch("Run",&this->Run,"Run/I");
  this->GetTree()->Branch("Event",&this->Event,"Event/I");
  
  this->GetTree()->Branch("LightYield",&this->LightYield,"LightYield/F");
  this->GetTree()->Branch("RiseTime",&this->RiseTime,"RiseTime/F");
  this->GetTree()->Branch("AbsLength",&this->AbsLength,"AbsLength/F");
  this->GetTree()->Branch("InducedAbsLength",&this->InducedAbsLength,"InducedAbsLength/F");
  this->GetTree()->Branch("FiberLength",&this->FiberLength,"FiberLength/F");
  this->GetTree()->Branch("FiberRadius",&this->FiberRadius,"FiberRadius/F");   
  this->GetTree()->Branch("DetDistance",&this->DetDistance,"DetDistance/F");  	
  this->GetTree()->Branch("ScMaterial",&this->ScMaterial,"ScMaterial/F");
  
  this->GetTree()->Branch("source_vertexX",&this->source_vertexX,"source_vertexX/F");
  this->GetTree()->Branch("source_vertexY",&this->source_vertexY,"source_vertexY/F");
  this->GetTree()->Branch("source_vertexZ",&this->source_vertexZ,"source_vertexZ/F");
  this->GetTree()->Branch("source_vertexTheta",&this->source_vertexTheta,"source_vertexTheta/F");
  this->GetTree()->Branch("source_vertexPhi",&this->source_vertexPhi,"source_vertexPhi/F");
  this->GetTree()->Branch("source_energy",&this->source_energy,"source_energy/F");
  
  this->GetTree()->Branch("totalEnergyDeposit",&this->totalEnergyDeposit,"totalEnergyDeposit/F");
  
  if(this->DEPOSITION)
  {
    this->GetTree()->Branch("opPhoton_vertexX",&opPhoton_vertexX);
    this->GetTree()->Branch("opPhoton_vertexY",&opPhoton_vertexY);
    this->GetTree()->Branch("opPhoton_vertexZ",&opPhoton_vertexZ);
    //this->GetTree()->Branch("depositionProcess",&depositionProcess);
    //this->GetTree()->Branch("energyDeposited",&energyDeposited);
    //this->GetTree()->Branch("firstPosX",&firstPosX);
    //this->GetTree()->Branch("firstPosY",&firstPosY);
    //this->GetTree()->Branch("firstPosZ",&firstPosZ);
  }
  
  if(this->PRODUCTION)
  {
    //this->GetTree()->Branch("opticProcess",&opticProcess);
    //this->GetTree()->Branch("Prod_Time",&Prod_Time);
    //this->GetTree()->Branch("OptPhotonEnergy",&OptPhotonEnergy);
  }
  
  if(this->CONTROL)
  {
    //this->GetTree()->Branch("Extraction",&Extraction);		
    ////this->GetTree()->Branch("Time",&Time);	
    //this->GetTree()->Branch("Parent",&Parent);
    ////this->GetTree()->Branch("Wglth_ex", &Wglth_ex);
  }
  
  if(this->HITS)
  {	
    this->GetTree()->Branch("opPhoton_n",&this->opPhoton_n,"opPhoton_n/I");
    this->GetTree()->Branch("opPhoton_process",&opPhoton_process);
    this->GetTree()->Branch("opPhoton_parentTrackID",&opPhoton_parentTrackID);
    this->GetTree()->Branch("opPhoton_energy",&opPhoton_energy);
    this->GetTree()->Branch("opPhoton_waveLength",&opPhoton_waveLength);
    this->GetTree()->Branch("opPhoton_time",&opPhoton_time);
    
    this->GetTree()->Branch("opAbsPhoton_n",&this->opAbsPhoton_n,"opAbsPhoton_n/I");
    this->GetTree()->Branch("opAbsPhoton_process",&opAbsPhoton_process);
    this->GetTree()->Branch("opAbsPhoton_parentTrackID",&opAbsPhoton_parentTrackID);
    this->GetTree()->Branch("opAbsPhoton_energy",&opAbsPhoton_energy);
    this->GetTree()->Branch("opAbsPhoton_waveLength",&opAbsPhoton_waveLength);
    this->GetTree()->Branch("opAbsPhoton_time",&opAbsPhoton_time);
    this->GetTree()->Branch("opAbsPhoton_trackLength",&opAbsPhoton_trackLength);
    
    this->GetTree()->Branch("opPhoton_n_gap",&this->opPhoton_n_gap,"opPhoton_n_gap/I");
    this->GetTree()->Branch("opPhoton_side_gap",&opPhoton_side_gap);
    this->GetTree()->Branch("opPhoton_process_gap",&opPhoton_process_gap);
    this->GetTree()->Branch("opPhoton_parentTrackID_gap",&opPhoton_parentTrackID_gap);
    this->GetTree()->Branch("opPhoton_energy_gap",&opPhoton_energy_gap);
    this->GetTree()->Branch("opPhoton_waveLength_gap",&opPhoton_waveLength_gap);
    this->GetTree()->Branch("opPhoton_time_gap",&opPhoton_time_gap);
    this->GetTree()->Branch("opPhoton_trackLength_gap",&opPhoton_trackLength_gap);
    
    this->GetTree()->Branch("opPhoton_n_win",&this->opPhoton_n_win,"opPhoton_n_win/I");
    this->GetTree()->Branch("opPhoton_side_win",&opPhoton_side_win);
    this->GetTree()->Branch("opPhoton_process_win",&opPhoton_process_win);
    this->GetTree()->Branch("opPhoton_parentTrackID_win",&opPhoton_parentTrackID_win);
    this->GetTree()->Branch("opPhoton_energy_win",&opPhoton_energy_win);
    this->GetTree()->Branch("opPhoton_waveLength_win",&opPhoton_waveLength_win);
    this->GetTree()->Branch("opPhoton_time_win",&opPhoton_time_win);
    this->GetTree()->Branch("opPhoton_trackLength_win",&opPhoton_trackLength_win);
    
    this->GetTree()->Branch("opPhoton_n_det",&this->opPhoton_n_det,"opPhoton_n_det/I");
    this->GetTree()->Branch("opPhoton_side_det",&opPhoton_side_det);
    this->GetTree()->Branch("opPhoton_process_det",&opPhoton_process_det);
    this->GetTree()->Branch("opPhoton_parentTrackID_det",&opPhoton_parentTrackID_det);
    this->GetTree()->Branch("opPhoton_energy_det",&opPhoton_energy_det);
    this->GetTree()->Branch("opPhoton_waveLength_det",&opPhoton_waveLength_det);
    this->GetTree()->Branch("opPhoton_time_det",&opPhoton_time_det);
    this->GetTree()->Branch("opPhoton_trackLength_det",&opPhoton_trackLength_det);
    
    if(this->WINDOW)
    {
      this->GetTree()->Branch("Volume",&Volume);		
    }
  }
  
  this->Clear();
}



CreateTree::~CreateTree()
{}



Bool_t CreateTree::Write()
{
  return true;
}



void CreateTree::Clear()
{
  Run = -1;
  Event = -1;
  
  totalEnergyDeposit = 0.;
  
  if(this->DEPOSITION)
  {
    ////firstPosX.clear();
    ////firstPosY.clear();
    ////firstPosZ.clear();
    ////depositionProcess.clear();
    //// energyDeposited.clear();
    opPhoton_vertexX.clear();
    opPhoton_vertexY.clear();
    opPhoton_vertexZ.clear();
  }
  
  if(this->PRODUCTION)
  {
    //opticProcess.clear();
    //OptPhotonEnergy.clear();
    //Prod_Time.clear();
  }
  
  if(this->CONTROL)
  {
  }
  
  if(this->HITS)
  {
    opPhoton_n = 0;
    opPhoton_process.clear();
    opPhoton_parentTrackID.clear();
    opPhoton_energy.clear();
    opPhoton_waveLength.clear();
    opPhoton_time.clear();
    
    opAbsPhoton_n = 0;
    opAbsPhoton_process.clear();
    opAbsPhoton_parentTrackID.clear();
    opAbsPhoton_energy.clear();
    opAbsPhoton_waveLength.clear();
    opAbsPhoton_time.clear();
    opAbsPhoton_trackLength.clear();
    
    opPhoton_n_gap = 0;
    opPhoton_side_gap.clear();
    opPhoton_process_gap.clear();
    opPhoton_parentTrackID_gap.clear();
    opPhoton_energy_gap.clear();
    opPhoton_waveLength_gap.clear();
    opPhoton_time_gap.clear();
    opPhoton_trackLength_gap.clear();
    
    opPhoton_n_win = 0;
    opPhoton_side_win.clear();
    opPhoton_process_win.clear();
    opPhoton_parentTrackID_win.clear();
    opPhoton_energy_win.clear();
    opPhoton_waveLength_win.clear();
    opPhoton_time_win.clear();
    opPhoton_trackLength_win.clear();
    
    opPhoton_n_det = 0;
    opPhoton_side_det.clear();
    opPhoton_process_det.clear();
    opPhoton_parentTrackID_det.clear();
    opPhoton_energy_det.clear();
    opPhoton_waveLength_det.clear();
    opPhoton_time_det.clear();
    opPhoton_trackLength_det.clear();
    
    //if(this->WINDOW)
    //{
    //  Volume.clear();
    //}
  }
}
