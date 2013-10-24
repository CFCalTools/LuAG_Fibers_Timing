#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>

#include "TCint.h"
#include "TFile.h"
#include "TRandom3.h"

#include "Randomize.hh"

#include "G4ios.hh"
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"
#include "G4UIExecutive.hh"

#include "ConfigFile.hh"
#include "CreateTree.hh"
#include "DetectorConstruction.hh"
#include "EventAction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "StackingAction.hh"
#include "TrackingAction.hh"
#include "SteppingVerbose.hh"
#include "SteppingAction.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif



long int CreateSeed();



int main(int argc, char** argv)
{
  // -----------------------------------------
  // -----------------------------------------
  // PARSE CONFIGURATION FILE
  // -----------------------------------------
  // -----------------------------------------
  
  gInterpreter -> GenerateDictionary("vector<float>","vector");
  
  if( argc != 2 && argc != 3 )
    {
      G4cout << "Syntax for exec: crystal.cfg <configuration file> out <output file>" << G4endl; 
      G4cout << "Syntax for viz:  crystal.cfg <configuration file>"                   << G4endl; 
      return -1;
    }
  
  std::string filename;
  TFile* outfile = NULL;
  
  if (argc == 2)
    {
      G4cout << "Starting viz mode..." << G4endl; 
    }
  
  if( argc == 3 ) 
    {
      G4cout << "Starting exec mode..." << G4endl; 
      filename = argv[2];
      filename += ".root";
      G4cout << "Writing data to file '" << filename << "' ..." << G4endl;
      
      outfile = new TFile(filename.c_str(),"RECREATE");
    }
  
  
  
  G4cout<< "\n" << G4endl;
  G4cout << "###########################################################" << G4endl;
  G4cout << "#                                                         #" << G4endl;
  G4cout << "#  GEANT4 simulation of a scintillator read-out           #" << G4endl;  
  G4cout << "#  by a photo-detector (crystal fibers).                  #" << G4endl;  
  G4cout << "#                                                         #" << G4endl;  
  G4cout << "#  Author: Nicolas Di Vara & Marco Lucchini, CERN, 2013   #" << G4endl;
  G4cout << "#                                                         #" << G4endl;  
  G4cout << "###########################################################" << G4endl;
  G4cout << "\n\n" << G4endl;
  G4cout << "=====>   C O N F I G U R A T I O N   <====\n" << G4endl;
  
  G4cout << "Configuration file: '" << argv[1] << "'" << G4endl;
  ConfigFile config(argv[1]);
  
  
  //------------------
  // global parameters
  
  G4long myseed = config.read<long int>("seed");
  if( myseed == -1 ) 
    {
      G4cout << "Creating random seed..." << G4endl;   
      myseed = CreateSeed();
    }
  G4cout << "Random seed : " << myseed << G4endl;
  
  Bool_t HITS = (Bool_t) config.read<int>("hits");
  G4cout << "External detector : " << HITS << G4endl;
  
  Bool_t WINDOW = (Bool_t) config.read<int>("window");
  G4cout << "Window : " << WINDOW << G4endl;
  
  Bool_t FIBER = (Bool_t) config.read<int>("fiber");
  G4cout << "Fiber present : " << FIBER << G4endl;
  
  Bool_t CONTROL = (Bool_t) config.read<int>("control");
  G4cout << "Control volumes : " << CONTROL << G4endl;
  
  Bool_t DEPOSITION = (Bool_t) config.read<int>("deposition");
  G4cout << "Deposition data : " << DEPOSITION << G4endl;
  
  Bool_t PRODUCTION = (Bool_t) config.read<int>("production");
  G4cout << "Production data : " << PRODUCTION << G4endl;
  
  
  //-------------------
  // fiber parameters
  
  G4double FiberLength = config.read<double>("fiber_l");
  G4cout << "Fiber length [mm]: " << FiberLength << G4endl;
  G4double FiberRadius = config.read<double>("fiber_r");
  G4cout << "Fiber radius [mm]: " << FiberRadius << G4endl; 
  
  
  //  //-----------------------------
  //	// control volumes and detector
  //	
  //	G4double depth = config.read<double>("depth");
  //  G4cout << "Depth control volume [mm]: " << depth << G4endl;
  //  G4double det_mat = config.read<double>("det_mat");
  //  G4cout << "Detector material: " << det_mat << G4endl; 
  //  G4double det_d = config.read<double>("det_d");
  //  G4cout << "Detector thickness [mm]: " << det_d << G4endl;
  
  
  //-----------------------------
  // scintillator characteristics  
  
  G4cout << "\nScintillator properties: " << G4endl;
  G4long material = config.read<int>("material");
  if     ( material == 1 )  G4cout << "Scintillator material: LSO"     << G4endl;
  else if( material == 2 )  G4cout << "Scintillator material: LYSO"    << G4endl;
  else if( material == 3 )  G4cout << "Scintillator material: LuAG:Ce" << G4endl; 
  else if( material == 4 )  G4cout << "Scintillator material: LuAG:Pr" << G4endl;
  else if( material == 5 )  G4cout << "Scintillator material: PbWO"    << G4endl;
  else if( material == 6 )  G4cout << "Scintillator material: Air"     << G4endl;
  else if( material == 7 )  G4cout << "Scintillator material: Quartz"  << G4endl;
  else
    {
      G4cerr << "<main>: Invalid material specifier: " << material << G4endl;
      return -1;
    }
  
  G4double lightyield = config.read<double>("lightyield");
  if( lightyield >= 0 ) G4cout << "Light yield [photons/MeV]: " << lightyield << G4endl;
  else                  G4cout << "Light yield [photons/MeV]: material default" << G4endl;
  
  G4double risetime = config.read<double>("risetime");
  if( risetime >= 0 ) G4cout << "Scintillation rise time [ns]: " << risetime << G4endl;
  else                G4cout << "Scintillation rise time [ns]: material default" << G4endl;
  
  G4double abslength = config.read<double>("abslength");
  if( abslength >= 0 ) G4cout << "Abslength [m]: " << abslength << G4endl;
  else                 G4cout << "Abslength [m]: material default" << G4endl;
  
  G4double ind_abslength = config.read<double>("ind_abslength");
  if(ind_abslength >= 0) G4cout << "Induced Abslength [m]: " << ind_abslength << G4endl;
  else                	 G4cout << "Induced Abslength [m]: 0" << G4endl;
  
  G4double det_distance = config.read<double>("det_distance");
  G4cout << "Detector Distance [mm]: " << det_distance << G4endl;
  
  
  
  CreateTree* mytree = new CreateTree("FiberTiming",HITS,WINDOW,FIBER,CONTROL,DEPOSITION,PRODUCTION);
  CreateTree::Instance() -> LightYield = lightyield;
  CreateTree::Instance() -> RiseTime = risetime;
  CreateTree::Instance() -> AbsLength = abslength;
  CreateTree::Instance() -> InducedAbsLength = ind_abslength;
  CreateTree::Instance() -> FiberLength = FiberLength;
  CreateTree::Instance() -> FiberRadius = FiberRadius;
  CreateTree::Instance() -> ScMaterial = material;
  CreateTree::Instance() -> DetDistance = det_distance;
  
  
  
  // -----------------------------------------
  // -----------------------------------------
  // END CONFIGURATION ----> SIMULATION
  // -----------------------------------------
  // -----------------------------------------
  
  
  
  G4cout << "\n\n" << G4endl;
  G4cout << "=====>   S I M U L A T I O N   <====" << G4endl;
  
  CLHEP::HepRandom::setTheSeed(myseed);
  
  // User Verbose output class
  G4VSteppingVerbose* verbosity = new SteppingVerbose;
  G4VSteppingVerbose::SetInstance(verbosity);
  
  // Run manager
  G4RunManager* runManager = new G4RunManager;
  
  // UserInitialization classes - mandatory / Detector
  G4VUserDetectorConstruction* detector = new DetectorConstruction();
  runManager->SetUserInitialization(detector);
  
  // UserInitialization classes - mandatory / Physics list
  G4VUserPhysicsList* physics = new PhysicsList;
  runManager->SetUserInitialization(physics);
  
  // UserAction classes
  G4UserRunAction* run_action = new RunAction;
  runManager->SetUserAction(run_action);
  
  // Gen action
  G4VUserPrimaryGeneratorAction* gen_action = new PrimaryGeneratorAction("e-",G4ThreeVector(0.*mm,3.*mm,0.*mm),G4ThreeVector(0.,-1.,0.));
  runManager->SetUserAction(gen_action);
  
  // Event action
  G4UserEventAction* event_action = new EventAction;
  runManager->SetUserAction(event_action);
  
  // Stacking action
  G4UserStackingAction* stacking_action = new StackingAction;
  runManager->SetUserAction(stacking_action);
  
  // Tracking action
  G4UserTrackingAction* tracking_action = new TrackingAction;
  runManager->SetUserAction(tracking_action);
  
  // Stepping action
  SteppingAction* stepping_action = new SteppingAction;
  runManager->SetUserAction(stepping_action);
  
  
  
  if( argc == 2 )   // Define UI session for interactive mode
    {   
      // Initialize G4 kernel
      runManager -> Initialize();
      
#ifdef G4VIS_USE
      G4VisManager* visManager = new G4VisExecutive;
      visManager -> Initialize();
      
      G4UImanager* UImanager = G4UImanager::GetUIpointer(); 
      G4UIExecutive * ui = new G4UIExecutive(argc,argv);
      UImanager -> ApplyCommand("/control/execute vis.mac");
      ui -> SessionStart();
      delete ui;
      delete visManager;
#endif  
    }
  if( argc == 3 )   // Define session for executive mode
    {
      G4UImanager* UImanager = G4UImanager::GetUIpointer(); 
      UImanager -> ApplyCommand("/control/execute gps.mac");
    }
  
  
  
  // Job termination
  // Free the store: user actions, physics_list and detector_description are
  // owned and deleted by the run manager, so they should not
  // be deleted in the main() program !
  
  delete runManager;
  delete verbosity;
  
  if( argc == 3 ) 
    {
      G4cout << "Writing tree to file " << filename << " ..." << G4endl;
      
      outfile -> cd();
      mytree -> GetTree() -> Write();
      outfile -> Close();
    }
  
  return 0;
}



long int CreateSeed()
{
  TRandom3 rangen;
  long int s = time(0);
  G4cout<< "Time : " << s << G4endl;
  s += getpid();
  G4cout << "PID  : " << getpid() << G4endl;
  
  FILE* fp = fopen("/proc/uptime", "r");
  int uptime,upsecs = 0;
  if(fp != NULL)
    {
      char buf[BUFSIZ];
      int res;
      char* b = fgets(buf,BUFSIZ,fp);
      if( b == buf )
        {
          setlocale(LC_NUMERIC,"C");
          res = sscanf(buf,"%i",&upsecs);
          setlocale(LC_NUMERIC,"");
          if( res == 1 ) uptime = (time_t) upsecs;
        }
      fclose (fp);
    }
  
  G4cout << "Uptime: " << upsecs << G4endl;
  s+=upsecs;
  
  G4cout << "Seed for srand: " << s << G4endl;
  srand(s);
  rangen.SetSeed(rand());
  long int seed = round(1000000*rangen.Uniform());
  return seed;
}
