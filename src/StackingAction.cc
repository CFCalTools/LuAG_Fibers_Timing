#include "StackingAction.hh"

#include "CreateTree.hh"
#include "MyMaterials.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4Track.hh"
#include "G4ios.hh"
#include "G4UnitsTable.hh"
#include "G4VProcess.hh"



StackingAction::StackingAction()
{}

StackingAction::~StackingAction()
{}

G4ClassificationOfNewTrack StackingAction::ClassifyNewTrack(const G4Track * aTrack)
{
  return fUrgent;
}
