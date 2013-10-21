#include "TrackingAction.hh"

#include "CreateTree.hh"
#include "MyMaterials.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4Track.hh"
#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "G4VProcess.hh"



TrackingAction::TrackingAction()
{}

TrackingAction::~TrackingAction()
{}

void TrackingAction::PostUserTrackingAction(const G4Track* aTrack)
{}
