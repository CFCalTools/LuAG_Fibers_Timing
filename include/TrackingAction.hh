#ifndef TrackingAction_H
#define TrackingAction_H 1

#include "globals.hh"
#include "G4UserTrackingAction.hh"



class TrackingAction : public G4UserTrackingAction
{
  public:
    TrackingAction();
   ~TrackingAction();

  public:
    void PostUserTrackingAction(const G4Track* aTrack);
};


#endif

