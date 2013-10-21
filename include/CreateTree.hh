#include <iostream>
#include <vector>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"



class CreateTree
{
 public:
  
  //! ctor
  CreateTree(TString name, bool hits, bool window, bool fiber, bool control, bool deposition, bool production);
  
  //! dtor
  ~CreateTree();
  
  //! methods
  TTree*  GetTree() const { return ftree; };
  TString GetName() const { return fname; };
  
  int Fill() { return this->GetTree()->Fill(); };
  bool Write();
  void Clear();
  
  static CreateTree* Instance() { return fInstance; };
  static CreateTree* fInstance;
  
  bool Hits()       const { return this->HITS; };
  bool Window()     const { return this->WINDOW; };
  bool Fiber()      const { return this->FIBER; };
  bool Control()    const { return this->CONTROL; };
  bool Deposition() const { return this->DEPOSITION; };
  
  int Run;
  int Event;
  
  float source_vertexX;
  float source_vertexY;
  float source_vertexZ;
  float source_vertexTheta;
  float source_vertexPhi;
  float source_energy;
  
  float totalEnergyDeposit;
  
  int opPhoton_n;
  std::vector<float> opPhoton_energy;
  std::vector<int>   opPhoton_process; // production process (1 for Cerenkov, 2 for Scintillation, -1 for unknown)
  std::vector<float> opPhoton_waveLength;
  std::vector<float> opPhoton_time;
  std::vector<float> opPhoton_vertexX;
  std::vector<float> opPhoton_vertexY;
  std::vector<float> opPhoton_vertexZ;
    
  int opAbsPhoton_n;
  std::vector<float> opAbsPhoton_energy;
  std::vector<int>   opAbsPhoton_process; // production process (1 for Cerenkov, 2 for Scintillation, -1 for unknown)
  std::vector<float> opAbsPhoton_waveLength;
  std::vector<float> opAbsPhoton_time;
  std::vector<float> opAbsPhoton_trackLength;
  
  int opPhoton_n_gap;
  std::vector<int> opPhoton_side_gap;    // +1 if front detector, -1 if rear detector
  std::vector<int> opPhoton_process_gap; // production process (1 for Cerenkov, 2 for Scintillation, -1 for unknown)
  std::vector<float> opPhoton_energy_gap;
  std::vector<float> opPhoton_waveLength_gap;
  std::vector<float> opPhoton_time_gap;
  std::vector<float> opPhoton_trackLength_gap;
      
  int opPhoton_n_win;
  std::vector<int> opPhoton_side_win;    // +1 if front detector, -1 if rear detector
  std::vector<int> opPhoton_process_win; // production process (1 for Cerenkov, 2 for Scintillation, -1 for unknown)
  std::vector<float> opPhoton_energy_win;
  std::vector<float> opPhoton_waveLength_win;
  std::vector<float> opPhoton_time_win;
  std::vector<float> opPhoton_trackLength_win;
  
  int opPhoton_n_det;
  std::vector<int> opPhoton_side_det;    // +1 if front detector, -1 if rear detector
  std::vector<int> opPhoton_process_det; // production process (1 for Cerenkov, 2 for Scintillation, -1 for unknown)
  std::vector<float> opPhoton_energy_det;
  std::vector<float> opPhoton_waveLength_det;
  std::vector<float> opPhoton_time_det;
  std::vector<float> opPhoton_trackLength_det;
    
  float LightYield;
  float RiseTime;
  float AbsLength;
  float InducedAbsLength;
  float FiberRadius;
  float FiberLength;
  float DetDistance;  
  float ScMaterial; 
  
  std::vector<int> Volume;		
  std::vector<int> opticProcess;
  std::vector<float>	energyDeposited;
  std::vector<float>	firstPosX;
  std::vector<float>	firstPosY;
  std::vector<float>	firstPosZ;
  
  std::vector<std::string> depositionProcess;
  
  
 private:
  
  TTree* ftree;
  TString fname;
  bool HITS;
  bool WINDOW;
  bool FIBER;
  bool CONTROL;
  bool DEPOSITION;
  bool PRODUCTION;
  
  static const int MaxNum = 2000000;
  static const int MaxNumPro = 1000;
};
