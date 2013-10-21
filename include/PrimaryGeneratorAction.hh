#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

#include "G4String.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleGun.hh"
#include "Randomize.hh"



class G4VPrimaryGenerator;
 
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
   //! constructor
   PrimaryGeneratorAction(const G4String& particleName,
                          G4ThreeVector position, 
                          G4ThreeVector momentumDirection);
  
   //! destructor
   ~PrimaryGeneratorAction();
   
   //! defines primary particles (mandatory)
   void GeneratePrimaries(G4Event*);

 private:  
  G4ParticleGun* fParticleGun;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
