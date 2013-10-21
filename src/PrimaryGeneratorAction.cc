// Martin Goettlich @ DESY
//

#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "CreateTree.hh"
#include "G4GeneralParticleSource.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::PrimaryGeneratorAction(const G4String& particleName, 
                                               G4ThreeVector position, 
                                               G4ThreeVector momentumDirection)
{
  G4int nofParticles = 1;
  fParticleGun  = new G4ParticleGun(nofParticles);

  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle(particleName);
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleEnergy(5*GeV);
  fParticleGun->SetParticlePosition(position);
  fParticleGun->SetParticleMomentumDirection(momentumDirection);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{ 
  G4double rand = 5.*CLHEP::RandFlat::shoot();
  if( rand >= 0. && rand < 1. )
    fParticleGun->SetParticleEnergy(1*GeV);
  if( rand >= 1. && rand < 2. )
    fParticleGun->SetParticleEnergy(5*GeV);
  if( rand >= 2. && rand < 3. )
    fParticleGun->SetParticleEnergy(10*GeV);
  if( rand >= 3. && rand < 4. )
    fParticleGun->SetParticleEnergy(50*GeV);
  if( rand >= 4. && rand < 5. )
    fParticleGun->SetParticleEnergy(100*GeV);
  
  fParticleGun -> GeneratePrimaryVertex(anEvent);
  
  CreateTree::Instance()->source_vertexX = fParticleGun->GetParticlePosition().x();
  CreateTree::Instance()->source_vertexY = fParticleGun->GetParticlePosition().y();
  CreateTree::Instance()->source_vertexZ = fParticleGun->GetParticlePosition().z();
  CreateTree::Instance()->source_vertexTheta = fParticleGun->GetParticleMomentumDirection().theta();
  CreateTree::Instance()->source_vertexPhi = fParticleGun->GetParticleMomentumDirection().phi();
  CreateTree::Instance()->source_energy = fParticleGun->GetParticleEnergy()/GeV;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
