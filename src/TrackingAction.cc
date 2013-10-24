#include "TrackingAction.hh"

#include "CreateTree.hh"
#include "MyMaterials.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4Track.hh"
#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "G4VProcess.hh"
#include "G4TrackingManager.hh"



TrackingAction::TrackingAction()
{}

TrackingAction::~TrackingAction()
{}

void TrackingAction::PreUserTrackingAction(const G4Track* aTrack)
{
  if( (aTrack->GetParentID() == 0) && (aTrack->GetUserInformation() == 0) )
  {
    TrackInformation* anInfo = new TrackInformation(aTrack);
    G4Track* theTrack = (G4Track*)aTrack;
    theTrack->SetUserInformation(anInfo);
  }
}

void TrackingAction::PostUserTrackingAction(const G4Track* aTrack)
{
  G4TrackVector* secondaries = fpTrackingManager->GimmeSecondaries();
  if( secondaries )
  {
    TrackInformation* info = (TrackInformation*)(aTrack->GetUserInformation());
    for(unsigned int i = 0; i < secondaries->size(); ++i)
    { 
      TrackInformation* infoNew = new TrackInformation(info);
      (*secondaries)[i]->SetUserInformation(infoNew);
    }
  }
}
