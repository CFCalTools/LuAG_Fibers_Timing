#include "SteppingAction.hh"

#include "MyMaterials.hh"
#include "CreateTree.hh"

#include <iostream>
#include <fstream>

#include "G4SteppingManager.hh"
#include "G4SDManager.hh"
#include "G4EventManager.hh"
#include "G4ProcessManager.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4StepPoint.hh"
#include "G4TrackStatus.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4UnitsTable.hh"



SteppingAction::SteppingAction()
{}



SteppingAction::~SteppingAction()
{}



void SteppingAction::UserSteppingAction(const G4Step* theStep)
{
  G4StepPoint* thePrePoint  = theStep->GetPreStepPoint();
  G4StepPoint* thePostPoint = theStep->GetPostStepPoint();
  G4VPhysicalVolume* thePrePV  = thePrePoint ->GetPhysicalVolume();
  G4VPhysicalVolume* thePostPV = thePostPoint->GetPhysicalVolume();
  G4TouchableHandle thePreTouch  = thePrePoint ->GetTouchableHandle();
  G4TouchableHandle thePostTouch = thePostPoint->GetTouchableHandle();
  
  
  ////-------------------------------------------------------
  ////find the boundary process for optical photons only once
  //G4OpBoundaryProcessStatus boundaryStatus = Undefined;
  //static G4OpBoundaryProcess* boundary = NULL;
  //if( !boundary )
  //{
  //  G4ProcessManager* pm = theStep->GetTrack()->GetDefinition()->GetProcessManager();
  //  G4int nprocesses = pm -> GetProcessListLength();
  //  G4ProcessVector* pv = pm->GetProcessList();
  //  for(int i = 0; i < nprocesses; ++i)
  //  {
  //    if( (*pv)[i]->GetProcessName() == "OpBoundary" )
  //    {
  //      boundary = (G4OpBoundaryProcess*)(*pv)[i];
  //      break;
  //    }
  //  }
  //}
  
  
  if( thePostPV != NULL ) // check post step volume is always in the mother volume to avoid crashing
  {
    G4Track* theTrack = theStep->GetTrack();
    G4ParticleDefinition* particleType = theTrack->GetDefinition();
    
    
    // ------------------------------------------------------------------------- //
    // ------------------------ Energy deposition info ------------------------- //
    // ------------------------------------------------------------------------- //
    
    if( theTrack->GetTrackID() == 1 )
    {
      CreateTree::Instance()->totalEnergyDeposit += theStep->GetTotalEnergyDeposit()/GeV;
    }
    
    
    
    // ------------------------------------------------------------------ //
    // ------------------------ Optical photons ------------------------- //
    // ------------------------------------------------------------------ //
        
    if( particleType == G4OpticalPhoton::OpticalPhotonDefinition() )
    {
      //---------------------------------------------------------
      // storing time, energy and position of all optical photons
        
      G4int nStep = theTrack -> GetCurrentStepNumber();
      
      if( (theTrack->GetLogicalVolumeAtVertex()->GetName() == "fiber_log") && (nStep == 1) )
      {
        G4String processName = theTrack->GetCreatorProcess()->GetProcessName();
        if     ( processName == "Cerenkov" )      CreateTree::Instance()->opPhoton_process.push_back( +1 );
        else if( processName == "Scintillation" ) CreateTree::Instance()->opPhoton_process.push_back( +2 );
        else                                      CreateTree::Instance()->opPhoton_process.push_back( -1 );
        
        CreateTree::Instance()->opPhoton_n++;
        CreateTree::Instance()->opPhoton_energy.push_back( theTrack->GetTotalEnergy()/eV );
        CreateTree::Instance()->opPhoton_waveLength.push_back( MyMaterials::fromEvToNm(theTrack->GetTotalEnergy()/eV) );
        CreateTree::Instance()->opPhoton_time.push_back( thePrePoint->GetGlobalTime()/picosecond );
        CreateTree::Instance()->opPhoton_vertexX.push_back( thePrePoint->GetPosition().x()/cm );
        CreateTree::Instance()->opPhoton_vertexY.push_back( thePrePoint->GetPosition().y()/cm );
        CreateTree::Instance()->opPhoton_vertexZ.push_back( thePrePoint->GetPosition().z()/cm );          
      }
      
      
      
      //--------------------------------------------------------------
      // storing time, energy and position of optical photons absorbed
      
      if( thePostPoint->GetProcessDefinedStep()->GetProcessName() == "OpAbsorption" )
      {
        if( thePrePV->GetName() == "fiber" )
        {
          CreateTree::Instance()->opAbsPhoton_n++;
          
          if( theTrack->GetCreatorProcess() )
          {
            G4String processName = theTrack->GetCreatorProcess()->GetProcessName();
            if     ( processName == "Cerenkov" )      CreateTree::Instance()->opAbsPhoton_process.push_back( +1 );
            else if( processName == "Scintillation" ) CreateTree::Instance()->opAbsPhoton_process.push_back( +2 );
            else                                      CreateTree::Instance()->opAbsPhoton_process.push_back( -1 );
          }
          
          CreateTree::Instance()->opAbsPhoton_energy.push_back( theTrack->GetTotalEnergy()/eV );
          CreateTree::Instance()->opAbsPhoton_waveLength.push_back( MyMaterials::fromEvToNm(theTrack->GetTotalEnergy()/eV) );
          CreateTree::Instance()->opAbsPhoton_time.push_back( theTrack->GetGlobalTime()/picosecond );
          CreateTree::Instance()->opAbsPhoton_trackLength.push_back( theTrack->GetTrackLength()/cm );
        }
      }
      
      
      
      //----------------------------------------------
      // storing time, energy and position at detector
            
      if( CreateTree::Instance()->Hits() )
      {
        if( ( (thePrePV->GetName() == "gap_layer_front") && (thePostPV->GetName() == "gap_front") ) ||
            ( (thePrePV->GetName() == "gap_layer_rear")  && (thePostPV->GetName() == "gap_rear" ) ) )
        {
          if     ( thePostPV->GetName() == "gap_front" ) CreateTree::Instance()->opPhoton_side_gap.push_back( +1 );
  		    else if( thePostPV->GetName() == "gap_rear"  ) CreateTree::Instance()->opPhoton_side_gap.push_back( -1 );
                    
          if( theTrack->GetCreatorProcess() )
          {
            G4String processName = theTrack->GetCreatorProcess()->GetProcessName();
            if     ( processName == "Cerenkov" )      CreateTree::Instance()->opPhoton_process_gap.push_back( +1 );
            else if( processName == "Scintillation" ) CreateTree::Instance()->opPhoton_process_gap.push_back( +2 );
            else                                      CreateTree::Instance()->opPhoton_process_gap.push_back( -1 );
          }
          
          CreateTree::Instance()->opPhoton_n_gap++;
          CreateTree::Instance()->opPhoton_energy_gap.push_back( theTrack->GetTotalEnergy()/eV );
          CreateTree::Instance()->opPhoton_waveLength_gap.push_back( MyMaterials::fromEvToNm(theTrack->GetTotalEnergy()/eV) );
          CreateTree::Instance()->opPhoton_time_gap.push_back( theTrack->GetGlobalTime()/picosecond );
          CreateTree::Instance()->opPhoton_trackLength_gap.push_back( theTrack->GetTrackLength()/cm );
        }
        
        if( ( (thePrePV->GetName() == "win_layer_front") && (thePostPV->GetName() == "win_front") ) ||
            ( (thePrePV->GetName() == "win_layer_rear")  && (thePostPV->GetName() == "win_rear" ) ) )
        {
          if     ( thePostPV->GetName() == "win_front" ) CreateTree::Instance()->opPhoton_side_win.push_back( +1 );
  		    else if( thePostPV->GetName() == "win_rear"  ) CreateTree::Instance()->opPhoton_side_win.push_back( -1 );
                    
          if( theTrack->GetCreatorProcess() )
          {
            G4String processName = theTrack->GetCreatorProcess()->GetProcessName();
            if     ( processName == "Cerenkov" )      CreateTree::Instance()->opPhoton_process_win.push_back( +1 );
            else if( processName == "Scintillation" ) CreateTree::Instance()->opPhoton_process_win.push_back( +2 );
            else                                      CreateTree::Instance()->opPhoton_process_win.push_back( -1 );
          }
          
          CreateTree::Instance()->opPhoton_n_win++;
          CreateTree::Instance()->opPhoton_energy_win.push_back( theTrack->GetTotalEnergy()/eV );
          CreateTree::Instance()->opPhoton_waveLength_win.push_back( MyMaterials::fromEvToNm(theTrack->GetTotalEnergy()/eV) );
          CreateTree::Instance()->opPhoton_time_win.push_back( theTrack->GetGlobalTime()/picosecond );
          CreateTree::Instance()->opPhoton_trackLength_win.push_back( theTrack->GetTrackLength()/cm );
        }
        
        if( ( (thePrePV->GetName() == "det_layer_front") && (thePostPV->GetName() == "det_front") ) ||
            ( (thePrePV->GetName() == "det_layer_rear")  && (thePostPV->GetName() == "det_rear" ) ) )
        {
          if     ( thePostPV->GetName() == "det_front" ) CreateTree::Instance()->opPhoton_side_det.push_back( +1 );
  		    else if( thePostPV->GetName() == "det_rear"  ) CreateTree::Instance()->opPhoton_side_det.push_back( -1 );
                    
          if( theTrack->GetCreatorProcess() )
          {
            G4String processName = theTrack->GetCreatorProcess()->GetProcessName();
            if     ( processName == "Cerenkov" )      CreateTree::Instance()->opPhoton_process_det.push_back( +1 );
            else if( processName == "Scintillation" ) CreateTree::Instance()->opPhoton_process_det.push_back( +2 );
            else                                      CreateTree::Instance()->opPhoton_process_det.push_back( -1 );
          }
          
          CreateTree::Instance()->opPhoton_n_det++;
          CreateTree::Instance()->opPhoton_energy_det.push_back( theTrack->GetTotalEnergy()/eV );
          CreateTree::Instance()->opPhoton_waveLength_det.push_back( MyMaterials::fromEvToNm(theTrack->GetTotalEnergy()/eV) );
          CreateTree::Instance()->opPhoton_time_det.push_back( theTrack->GetGlobalTime()/picosecond );
          CreateTree::Instance()->opPhoton_trackLength_det.push_back( theTrack->GetTrackLength()/cm );
        }
      }
    } // optical photons
  } // loop for physical volume inside world volume
}
