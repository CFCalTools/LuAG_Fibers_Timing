#include "MyMaterials.hh"

#include "ConfigFile.hh"
#include "CreateTree.hh"

#include "TF1.h"
#include "TGraph.h"



MyMaterials::MyMaterials()
{}



MyMaterials::~MyMaterials()
{}



G4Material *MyMaterials::Air()
{
  G4double a, z, density;
  G4int nelements;

  G4Element *N = new G4Element ("Nitrogen", "N", z = 7 , a = 14.01 * g / mole);
  G4Element *O = new G4Element ("Oxygen"  , "O", z = 8 , a = 16.00 * g / mole);
  
  G4Material *Air = new G4Material ("Air", density = 1.29 * mg / cm3, nelements = 2);
  Air->AddElement (N, 70.*perCent);
  Air->AddElement (O, 30.*perCent);

  const G4int nEntries = 34;
  
  G4double PhotonEnergy[nEntries] = {
      0.0001 * eV, 1.00 * eV,  2.034 * eV, 2.068 * eV, 2.103 * eV, 2.139 * eV,
      2.177 * eV, 2.216 * eV, 2.256 * eV, 2.298 * eV,
      2.341 * eV, 2.386 * eV, 2.433 * eV, 2.481 * eV,
      2.532 * eV, 2.585 * eV, 2.640 * eV, 2.697 * eV,
      2.757 * eV, 2.820 * eV, 2.885 * eV, 2.954 * eV,
      3.026 * eV, 3.102 * eV, 3.181 * eV, 3.265 * eV,
      3.353 * eV, 3.446 * eV, 3.545 * eV, 3.649 * eV,
      3.760 * eV, 3.877 * eV, 4.002 * eV, 4.136 * eV
  };
  
  G4double RefractiveIndex[nEntries] = {
      1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
      1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
      1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
      1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
      1.0003, 1.0003, 1.0003, 1.0003, 1.0003
  };
  
  G4MaterialPropertiesTable *myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty ("RINDEX", PhotonEnergy, RefractiveIndex, nEntries);
  
  Air->SetMaterialPropertiesTable (myMPT);
  
  return Air;
}



G4Material *MyMaterials::SensorAir()
{
  G4double a, z, density;
  G4int nelements;
  
  G4Element *N = new G4Element ("Nitrogen", "N", z = 7 , a = 14.01 * g / mole);
  G4Element *O = new G4Element ("Oxygen"  , "O", z = 8 , a = 16.00 * g / mole);
  
  G4Material *SensorAir = new G4Material ("SensorAir", density = 1.29 * mg / cm3, nelements = 2);
  SensorAir->AddElement (N, 70.*perCent);
  SensorAir->AddElement (O, 30.*perCent);
  
  const G4int nEntries = 34;
  
  G4double PhotonEnergy[nEntries] = {
      0.0001 * eV, 1.00 * eV, 2.034 * eV, 2.068 * eV, 2.103 * eV, 2.139 * eV,
      2.177 * eV, 2.216 * eV, 2.256 * eV, 2.298 * eV,
      2.341 * eV, 2.386 * eV, 2.433 * eV, 2.481 * eV,
      2.532 * eV, 2.585 * eV, 2.640 * eV, 2.697 * eV,
      2.757 * eV, 2.820 * eV, 2.885 * eV, 2.954 * eV,
      3.026 * eV, 3.102 * eV, 3.181 * eV, 3.265 * eV,
      3.353 * eV, 3.446 * eV, 3.545 * eV, 3.649 * eV,
      3.760 * eV, 3.877 * eV, 4.002 * eV, 4.136 * eV
  };
  
  G4double RefractiveIndex[nEntries] = {
      1.48, 1.48, 1.48, 1.48, 1.48, 1.48, 1.48, 1.48,
      1.48, 1.48, 1.48, 1.48, 1.48, 1.48, 1.48,
      1.48, 1.48, 1.48, 1.48, 1.48, 1.48, 1.48,
      1.48, 1.48, 1.48, 1.48, 1.48, 1.48, 1.48,
      1.48, 1.48, 1.48, 1.48, 1.48
  };
  
  G4MaterialPropertiesTable *myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty ("RINDEX", PhotonEnergy, RefractiveIndex, nEntries);
  
  SensorAir->SetMaterialPropertiesTable (myMPT);
  
  return SensorAir;
}



G4Material *MyMaterials::Water()
{
  G4double a, z, density;
  G4int nelements;
  
  G4Element *H = new G4Element ("Hydrogen", "H", z = 1 , a = 1.01 * g / mole);
  G4Element *O = new G4Element ("Oxygen"  , "O", z = 8 , a = 16.00 * g / mole);
  G4Material *Water = new G4Material ("Water", density = 1.0 * g / cm3, nelements = 2);
  Water->AddElement (H, 2);
  Water->AddElement (O, 1);
  
  const G4int nEntries = 33;
  
  G4double PhotonEnergy[nEntries] = {
      0.1 * eV, 2.034 * eV, 2.068 * eV, 2.103 * eV, 2.139 * eV,
      2.177 * eV, 2.216 * eV, 2.256 * eV, 2.298 * eV,
      2.341 * eV, 2.386 * eV, 2.433 * eV, 2.481 * eV,
      2.532 * eV, 2.585 * eV, 2.640 * eV, 2.697 * eV,
      2.757 * eV, 2.820 * eV, 2.885 * eV, 2.954 * eV,
      3.026 * eV, 3.102 * eV, 3.181 * eV, 3.265 * eV,
      3.353 * eV, 3.446 * eV, 3.545 * eV, 3.649 * eV,
      3.760 * eV, 3.877 * eV, 4.002 * eV, 4.136 * eV
  };
  
  G4double RefractiveIndex[nEntries] = {
      1.3435, 1.3435, 1.344,  1.3445, 1.345,  1.3455,
      1.346,  1.3465, 1.347,  1.3475, 1.348,
      1.3485, 1.3492, 1.35,   1.3505, 1.351,
      1.3518, 1.3522, 1.3530, 1.3535, 1.354,
      1.3545, 1.355,  1.3555, 1.356,  1.3568,
      1.3572, 1.358,  1.3585, 1.359,  1.3595,
      1.36,   1.3608
  };
  
  G4double Absorption[nEntries] = {
      3.448, 3.448 * m,  4.082 * m,  6.329 * m,  9.174 * m, 12.346 * m, 13.889 * m,
      15.152 * m, 17.241 * m, 18.868 * m, 20.000 * m, 26.316 * m, 35.714 * m,
      45.455 * m, 47.619 * m, 52.632 * m, 52.632 * m, 55.556 * m, 52.632 * m,
      52.632 * m, 47.619 * m, 45.455 * m, 41.667 * m, 37.037 * m, 33.333 * m,
      30.000 * m, 28.500 * m, 27.000 * m, 24.500 * m, 22.000 * m, 19.500 * m,
      17.500 * m, 14.500 * m
  };
  
  G4double ScintilFast[nEntries] = {
      1.00,   1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00, 1.00, 1.00, 1.00,
      1.00, 1.00, 1.00, 1.00
  };
  
  G4double ScintilSlow[nEntries] = {
      0.01,   0.01, 1.00, 2.00, 3.00, 4.00, 5.00, 6.00,
      7.00, 8.00, 9.00, 8.00, 7.00, 6.00, 4.00,
      3.00, 2.00, 1.00, 0.01, 1.00, 2.00, 3.00,
      4.00, 5.00, 6.00, 7.00, 8.00, 9.00, 8.00,
      7.00, 6.00, 5.00, 4.00
  };
  
  G4MaterialPropertiesTable *myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty ("RINDEX",        PhotonEnergy, RefractiveIndex, nEntries);
  myMPT->AddProperty ("ABSLENGTH",     PhotonEnergy, Absorption,      nEntries);
  myMPT->AddProperty ("FASTCOMPONENT", PhotonEnergy, ScintilFast,     nEntries);
  myMPT->AddProperty ("SLOWCOMPONENT", PhotonEnergy, ScintilSlow,     nEntries);

  myMPT->AddConstProperty ("SCINTILLATIONYIELD", 50. / MeV);
  myMPT->AddConstProperty ("RESOLUTIONSCALE", 1.0);
  myMPT->AddConstProperty ("FASTTIMECONSTANT", 1.*ns);
  myMPT->AddConstProperty ("SLOWTIMECONSTANT", 10.*ns);
  myMPT->AddConstProperty ("YIELDRATIO", 0.8);
  
  Water->SetMaterialPropertiesTable (myMPT);
  
  return Water;
}



G4Material *MyMaterials::Vacuum()
{
  G4double a, z, density;
  G4int nelements;
  
  G4Element *N = new G4Element ("Nitrogen", "N", z = 7 , a = 14.01 * g / mole);
  G4Element *O = new G4Element ("Oxygen"  , "O", z = 8 , a = 16.00 * g / mole);
  
  G4Material *Air = new G4Material ("Air", density =  1e-25 * g / cm3, nelements = 2);
  Air->AddElement (N, 70.*perCent);
  Air->AddElement (O, 30.*perCent);
  
  const G4int nEntries = 34;
  
  G4double PhotonEnergy[nEntries] = {
      0.0001 * eV, 1.00 * eV,  2.034 * eV, 2.068 * eV, 2.103 * eV, 2.139 * eV,
      2.177 * eV, 2.216 * eV, 2.256 * eV, 2.298 * eV,
      2.341 * eV, 2.386 * eV, 2.433 * eV, 2.481 * eV,
      2.532 * eV, 2.585 * eV, 2.640 * eV, 2.697 * eV,
      2.757 * eV, 2.820 * eV, 2.885 * eV, 2.954 * eV,
      3.026 * eV, 3.102 * eV, 3.181 * eV, 3.265 * eV,
      3.353 * eV, 3.446 * eV, 3.545 * eV, 3.649 * eV,
      3.760 * eV, 3.877 * eV, 4.002 * eV, 4.136 * eV
  };
  
  G4double RefractiveIndex[nEntries] = {
      1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
      1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
      1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
      1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003, 1.0003,
      1.0003, 1.0003, 1.0003, 1.0003, 1.0003
  };
  
  G4MaterialPropertiesTable *myMPT = new G4MaterialPropertiesTable();
  myMPT->AddProperty ("RINDEX", PhotonEnergy, RefractiveIndex, nEntries);
  
  Air->SetMaterialPropertiesTable (myMPT);
  
  return Air;
}



G4Material *MyMaterials::Silicon()
{
  G4double a, z, density;
  
  G4Element *Si = new G4Element ("Si", "Si", z = 14., a = 28.09 * g / mole);
  G4Material *Silicon = new G4Material ("Silicon", density = 2.33 * g / cm3, 1);
  Silicon->AddElement (Si, 1);
  
  const G4int NUM = 5;
  
  G4double Energy[NUM]         = { 0.0001 * eV, 1.0 * eV, 1.84 * eV, 4.08 * eV,  6.26 * eV};
  G4double RIND_INDEX[NUM]     = { 4.0, 4.0, 4.0, 4.0, 4.0 };
  G4double ABS_LENGTH[NUM]     = { 0.1 * mm, 0.1 * mm, 0.1 * mm, 0.1 * mm, 0.1 * mm};
  
  G4MaterialPropertiesTable *Si_mt = new G4MaterialPropertiesTable();
  Si_mt->AddProperty ("RINDEX",        Energy,  RIND_INDEX,     NUM);
  Si_mt->AddProperty ("ABSLENGTH",     Energy,  ABS_LENGTH,     NUM);
  
  Silicon->SetMaterialPropertiesTable (Si_mt);
  
  return Silicon;
}



G4Material *MyMaterials::Quartz()
{
  G4double a, z, density;
  G4Element *Si = new G4Element ("Silicon",    "Si", z = 14., a = 28.09 * g / mole);
  G4Element *O = new G4Element ("Oxygen"  , "O", z = 8 , a = 16.00 * g / mole);
  
  G4Material *Quartz = new G4Material ("Quartz", density = 2.65 * g / cm3, 2);
  Quartz->AddElement (Si, 1);
  Quartz->AddElement (O, 2);
  
  const G4int nEntries_RI = 11;
  
  G4double PhotonEnergy[nEntries_RI] = {
      1.0 * eV, 2.0 * eV, 2.5 * eV, 3.0 * eV, 3.5 * eV,
      4.0 * eV, 4.5 * eV, 5.0 * eV, 5.5 * eV, 6.0 * eV, 6.26 * eV       
  };
  
  G4double RefractiveIndex[nEntries_RI] = {
      1.53, 1.54, 1.55, 1.56, 1.56, 1.57, 1.59, 1.60, 1.62,
      1.64, 1.65
  };
  
  const G4int nEntries_ABS = 4;
  
  G4double ABS_Energy[nEntries_ABS] = { 1.0 * eV, 1.84 * eV, 4.08 * eV, 6.26 * eV };
  G4double ABS_LENGTH[nEntries_ABS] = { 138.*mm, 138.*mm, 138.*mm, 138. *mm };
  
  G4MaterialPropertiesTable *myMPT = new G4MaterialPropertiesTable();
  
  myMPT->AddProperty ("RINDEX", PhotonEnergy, RefractiveIndex, nEntries_RI);
  myMPT->AddProperty ("ABSLENGTH", ABS_Energy, ABS_LENGTH, nEntries_ABS);
  
  Quartz->SetMaterialPropertiesTable (myMPT);
  
  return Quartz;
}



G4Material *MyMaterials::OpticalGrease()
{
  G4double a, z, density;
  G4Element *H = new G4Element ("Hydrogen", "H", z = 1 , a = 1.01 * g / mole);
  G4Element *O = new G4Element ("Oxygen"  , "O", z = 8 , a = 16.00 * g / mole);
  G4Element *C = new G4Element ("Carbon"  , "C", z = 6 , a = 12.01 * g / mole);

  G4Material *Grease = new G4Material ("Grease", density = 1.0 * g / cm3, 3);
  Grease->AddElement (C, 1);
  Grease->AddElement (H, 1);
  Grease->AddElement (O, 1);

  const G4int nEntries = 34;

  G4double PhotonEnergy[nEntries] = {
      0.0001 * eV, 1.0 * eV, 2.034 * eV, 2.068 * eV, 2.103 * eV, 2.139 * eV,
      2.177 * eV, 2.216 * eV, 2.256 * eV, 2.298 * eV,
      2.341 * eV, 2.386 * eV, 2.433 * eV, 2.481 * eV,
      2.532 * eV, 2.585 * eV, 2.640 * eV, 2.697 * eV,
      2.757 * eV, 2.820 * eV, 2.885 * eV, 2.954 * eV,
      3.026 * eV, 3.102 * eV, 3.181 * eV, 3.265 * eV,
      3.353 * eV, 3.446 * eV, 3.545 * eV, 3.649 * eV,
      3.760 * eV, 3.877 * eV, 4.002 * eV, 4.136 * eV
  };

  G4double RefractiveIndex[nEntries] = {
      1.41, 1.41, 1.41, 1.41, 1.41, 1.41, 1.41, 1.41, 1.41,
      1.41, 1.41, 1.41, 1.41, 1.41, 1.41, 1.41,
      1.41, 1.41, 1.41, 1.41, 1.41, 1.41, 1.41,
      1.41, 1.41, 1.41, 1.41, 1.41, 1.41, 1.41,
      1.41, 1.41, 1.41, 1.41
  };
  
  //   G4double Absorption[nEntries] =
  //    { 3.448*m, 3.448*m,  4.082*m,  6.329*m,  9.174*m, 12.346*m, 13.889*m,
  //            15.152*m, 17.241*m, 18.868*m, 20.000*m, 26.316*m, 35.714*m,
  //            45.455*m, 47.619*m, 52.632*m, 52.632*m, 55.556*m, 52.632*m,
  //            52.632*m, 47.619*m, 45.455*m, 41.667*m, 37.037*m, 33.333*m,
  //            30.000*m, 28.500*m, 27.000*m, 24.500*m, 22.000*m, 19.500*m,
  //            17.500*m, 14.500*m };
  
  G4MaterialPropertiesTable *myMPT = new G4MaterialPropertiesTable();
  
  myMPT->AddProperty ("RINDEX",       PhotonEnergy, RefractiveIndex, nEntries);
  //myMPT->AddProperty("ABSLENGTH",    PhotonEnergy, Absorption,      nEntries);
  
  Grease->SetMaterialPropertiesTable (myMPT);
  
  return Grease;
}


G4Material *MyMaterials::LUAGCE()  // Lutetium Aluminum Garnet
{
    G4double a, z, density;
    G4Element  *O = new G4Element ("Oxygen",    "O",   z = 8,  a = 16.00 * g / mole);
    G4Element *Lu = new G4Element ("Lutetium",  "Lu",  z = 71, a = 174.97 * g / mole);
    G4Element *Al = new G4Element ("Aluminum",  "Al",  z = 27, a = 28.09 * g / mole);

    G4Material *mat = new G4Material ("LUAG", density = 6.73 * g / cm3, 3);
    mat->AddElement (Lu, 3);
    mat->AddElement (Al, 12);
    mat->AddElement (O, 5);

    // large band between 470 (2.64 eV) and 630 nm (1.97 eV) (mean 535 nm, 2.32)
    const G4int NUMENTRIES_1 = 460;
    G4double FAST_Energy[NUMENTRIES_1]    = {
    1.82487*eV, 1.82622*eV, 1.82756*eV, 1.82891*eV, 1.83026*eV, 1.83161*eV, 1.83296*eV, 1.83432*eV, 1.83568*eV, 1.83704*eV, 1.8384*eV, 1.83976*eV, 1.84113*eV, 1.8425*eV, 1.84387*eV, 1.84524*eV, 1.84661*eV, 1.84799*eV, 1.84937*eV, 1.85075*eV, 1.85213*eV, 1.85351*eV, 1.8549*eV, 1.85629*eV, 1.85768*eV, 1.85907*eV, 1.86047*eV, 1.86186*eV, 1.86326*eV, 1.86466*eV, 1.86606*eV, 1.86747*eV, 1.86888*eV, 1.87029*eV, 1.8717*eV, 1.87311*eV, 1.87453*eV, 1.87595*eV, 1.87737*eV, 1.87879*eV, 1.88021*eV, 1.88164*eV, 1.88307*eV, 1.8845*eV, 1.88593*eV, 1.88737*eV, 1.8888*eV, 1.89024*eV, 1.89169*eV, 1.89313*eV, 1.89458*eV, 1.89602*eV, 1.89748*eV, 1.89893*eV, 1.90038*eV, 1.90184*eV, 1.9033*eV, 1.90476*eV, 1.90623*eV, 1.90769*eV, 1.90916*eV, 1.91063*eV, 1.9121*eV, 1.91358*eV, 1.91506*eV, 1.91654*eV, 1.91802*eV, 1.9195*eV, 1.92099*eV, 1.92248*eV, 1.92397*eV, 1.92547*eV, 1.92696*eV, 1.92846*eV, 1.92996*eV, 1.93146*eV, 1.93297*eV, 1.93448*eV, 1.93599*eV, 1.9375*eV, 1.93901*eV, 1.94053*eV, 1.94205*eV, 1.94357*eV, 1.9451*eV, 1.94662*eV, 1.94815*eV, 1.94969*eV, 1.95122*eV, 1.95276*eV, 1.95429*eV, 1.95584*eV, 1.95738*eV, 1.95893*eV, 1.96047*eV, 1.96203*eV, 1.96358*eV, 1.96513*eV, 1.96669*eV, 1.96825*eV, 1.96982*eV, 1.97138*eV, 1.97295*eV, 1.97452*eV, 1.9761*eV, 1.97767*eV, 1.97925*eV, 1.98083*eV, 1.98241*eV, 1.984*eV, 1.98559*eV, 1.98718*eV, 1.98877*eV, 1.99037*eV, 1.99197*eV, 1.99357*eV, 1.99517*eV, 1.99678*eV, 1.99839*eV, 2*eV, 2.00161*eV, 2.00323*eV, 2.00485*eV, 2.00647*eV, 2.0081*eV, 2.00972*eV, 2.01135*eV, 2.01299*eV, 2.01462*eV, 2.01626*eV, 2.0179*eV, 2.01954*eV, 2.02119*eV, 2.02284*eV, 2.02449*eV, 2.02614*eV, 2.0278*eV, 2.02946*eV, 2.03112*eV, 2.03279*eV, 2.03445*eV, 2.03612*eV, 2.0378*eV, 2.03947*eV, 2.04115*eV, 2.04283*eV, 2.04452*eV, 2.0462*eV, 2.04789*eV, 2.04959*eV, 2.05128*eV, 2.05298*eV, 2.05468*eV, 2.05638*eV, 2.05809*eV, 2.0598*eV, 2.06151*eV, 2.06323*eV, 2.06495*eV, 2.06667*eV, 2.06839*eV, 2.07012*eV, 2.07185*eV, 2.07358*eV, 2.07531*eV, 2.07705*eV, 2.07879*eV, 2.08054*eV, 2.08228*eV, 2.08403*eV, 2.08579*eV, 2.08754*eV, 2.0893*eV, 2.09106*eV, 2.09283*eV, 2.09459*eV, 2.09637*eV, 2.09814*eV, 2.09992*eV, 2.10169*eV, 2.10348*eV, 2.10526*eV, 2.10705*eV, 2.10884*eV, 2.11064*eV, 2.11244*eV, 2.11424*eV, 2.11604*eV, 2.11785*eV, 2.11966*eV, 2.12147*eV, 2.12329*eV, 2.12511*eV, 2.12693*eV, 2.12876*eV, 2.13058*eV, 2.13242*eV, 2.13425*eV, 2.13609*eV, 2.13793*eV, 2.13978*eV, 2.14162*eV, 2.14347*eV, 2.14533*eV, 2.14719*eV, 2.14905*eV, 2.15091*eV, 2.15278*eV, 2.15465*eV, 2.15652*eV, 2.1584*eV, 2.16028*eV, 2.16216*eV, 2.16405*eV, 2.16594*eV, 2.16783*eV, 2.16973*eV, 2.17163*eV, 2.17353*eV, 2.17544*eV, 2.17735*eV, 2.17926*eV, 2.18118*eV, 2.1831*eV, 2.18502*eV, 2.18695*eV, 2.18888*eV, 2.19081*eV, 2.19275*eV, 2.19469*eV, 2.19663*eV, 2.19858*eV, 2.20053*eV, 2.20249*eV, 2.20444*eV, 2.20641*eV, 2.20837*eV, 2.21034*eV, 2.21231*eV, 2.21429*eV, 2.21626*eV, 2.21825*eV, 2.22023*eV, 2.22222*eV, 2.22422*eV, 2.22621*eV, 2.22821*eV, 2.23022*eV, 2.23222*eV, 2.23423*eV, 2.23625*eV, 2.23827*eV, 2.24029*eV, 2.24231*eV, 2.24434*eV, 2.24638*eV, 2.24841*eV, 2.25045*eV, 2.2525*eV, 2.25455*eV, 2.2566*eV, 2.25865*eV, 2.26071*eV, 2.26277*eV, 2.26484*eV, 2.26691*eV, 2.26898*eV, 2.27106*eV, 2.27314*eV, 2.27523*eV, 2.27732*eV, 2.27941*eV, 2.28151*eV, 2.28361*eV, 2.28571*eV, 2.28782*eV, 2.28994*eV, 2.29205*eV, 2.29417*eV, 2.2963*eV, 2.29842*eV, 2.30056*eV, 2.30269*eV, 2.30483*eV, 2.30698*eV, 2.30912*eV, 2.31128*eV, 2.31343*eV, 2.31559*eV, 2.31776*eV, 2.31993*eV, 2.3221*eV, 2.32427*eV, 2.32645*eV, 2.32864*eV, 2.33083*eV, 2.33302*eV, 2.33522*eV, 2.33742*eV, 2.33962*eV, 2.34183*eV, 2.34405*eV, 2.34626*eV, 2.34848*eV, 2.35071*eV, 2.35294*eV, 2.35518*eV, 2.35741*eV, 2.35966*eV, 2.3619*eV, 2.36416*eV, 2.36641*eV, 2.36867*eV, 2.37094*eV, 2.37321*eV, 2.37548*eV, 2.37776*eV, 2.38004*eV, 2.38232*eV, 2.38462*eV, 2.38691*eV, 2.38921*eV, 2.39151*eV, 2.39382*eV, 2.39614*eV, 2.39845*eV, 2.40077*eV, 2.4031*eV, 2.40543*eV, 2.40777*eV, 2.41011*eV, 2.41245*eV, 2.4148*eV, 2.41715*eV, 2.41951*eV, 2.42188*eV, 2.42424*eV, 2.42661*eV, 2.42899*eV, 2.43137*eV, 2.43376*eV, 2.43615*eV, 2.43854*eV, 2.44094*eV, 2.44335*eV, 2.44576*eV, 2.44817*eV, 2.45059*eV, 2.45302*eV, 2.45545*eV, 2.45788*eV, 2.46032*eV, 2.46276*eV, 2.46521*eV, 2.46766*eV, 2.47012*eV, 2.47258*eV, 2.47505*eV, 2.47752*eV, 2.48*eV, 2.48248*eV, 2.48497*eV, 2.48746*eV, 2.48996*eV, 2.49246*eV, 2.49497*eV, 2.49748*eV, 2.5*eV, 2.50252*eV, 2.50505*eV, 2.50758*eV, 2.51012*eV, 2.51266*eV, 2.51521*eV, 2.51777*eV, 2.52033*eV, 2.52289*eV, 2.52546*eV, 2.52803*eV, 2.53061*eV, 2.5332*eV, 2.53579*eV, 2.53838*eV, 2.54098*eV, 2.54359*eV, 2.5462*eV, 2.54882*eV, 2.55144*eV, 2.55407*eV, 2.5567*eV, 2.55934*eV, 2.56198*eV, 2.56463*eV, 2.56729*eV, 2.56995*eV, 2.57261*eV, 2.57529*eV, 2.57796*eV, 2.58065*eV, 2.58333*eV, 2.58603*eV, 2.58873*eV, 2.59143*eV, 2.59414*eV, 2.59686*eV, 2.59958*eV, 2.60231*eV, 2.60504*eV, 2.60778*eV, 2.61053*eV, 2.61328*eV, 2.61603*eV, 2.6188*eV, 2.62156*eV, 2.62434*eV, 2.62712*eV, 2.6299*eV, 2.6327*eV, 2.63549*eV, 2.6383*eV, 2.64111*eV, 2.64392*eV, 2.64674*eV, 2.64957*eV, 2.65241*eV, 2.65525*eV, 2.65809*eV, 2.66094*eV, 2.6638*eV, 2.66667*eV, 2.66954*eV, 2.67241*eV, 2.6753*eV, 2.67819*eV, 2.68108*eV, 2.68398*eV, 2.68689*eV, 2.6898*eV, 2.69273*eV, 2.69565*eV, 2.69859*eV, 2.70153*eV, 2.70447*eV, 2.70742*eV, 2.71038*eV, 2.71335*eV, 2.71632*eV, 2.7193*eV, 2.72228*eV, 2.72527*eV, 2.72827*eV, 2.73128*eV, 2.73429*eV, 2.73731*eV, 2.74033*eV, 2.74336*eV, 2.7464*eV, 2.74945*eV};
    
    G4double FAST_COMPONENT[NUMENTRIES_1] = {
    5.81332e-05, 6.44431e-05, 5.14981e-05, 5.53578e-05, 7.63256e-05, 7.53282e-05, 7.58269e-05, 8.97693e-05, 7.76917e-05, 7.38103e-05, 7.78435e-05, 7.09481e-05, 7.49162e-05, 8.77528e-05, 8.86852e-05, 9.01596e-05, 7.3355e-05, 8.61916e-05, 8.31125e-05, 9.63177e-05, 9.64045e-05, 8.96609e-05, 0.000118934, 0.000122446, 0.000112017, 8.10092e-05, 9.10487e-05, 9.54287e-05, 0.000102975, 0.000102996, 0.00010833, 9.44529e-05, 9.82259e-05, 0.000117372, 0.000121601, 0.00011206, 0.000123183, 0.000126371, 0.000114987, 0.000121687, 0.00011065, 0.000131879, 0.000124766, 0.000119606, 0.000146146, 0.000145279, 0.000141441, 0.000148553, 0.000156012, 0.000149746, 0.000163168, 0.000161043, 0.000174898, 0.000182661, 0.000175918, 0.000175939, 0.000171169, 0.000159807, 0.0001726, 0.000178866, 0.000175028, 0.000190836, 0.000208768, 0.000179539, 0.000198165, 0.000197644, 0.000199509, 0.000202545, 0.000218005, 0.000208031, 0.000212584, 0.000219848, 0.000234961, 0.000249945, 0.000232078, 0.000224814, 0.000229476, 0.000248232, 0.000290948, 0.000269568, 0.000289062, 0.000288346, 0.000276572, 0.000287999, 0.000306235, 0.000306452, 0.000293724, 0.000325186, 0.000335356, 0.000332277, 0.000323885, 0.000335464, 0.000335724, 0.000372413, 0.000366406, 0.000352919, 0.000341297, 0.000400384, 0.00038796, 0.000373518, 0.000396785, 0.000419986, 0.00042712, 0.000413654, 0.000429158, 0.000443621, 0.000482629, 0.000489546, 0.00047736, 0.000457151, 0.000534973, 0.000505028, 0.000518277, 0.000507934, 0.000520879, 0.000552884, 0.00054859, 0.00057396, 0.000561015, 0.000557329, 0.000603645, 0.000608111, 0.000628646, 0.000624894, 0.000634196, 0.000647055, 0.000670148, 0.000680122, 0.000679211, 0.000696731, 0.000703887, 0.000728888, 0.000708722, 0.000749509, 0.000780863, 0.000772819, 0.000771908, 0.000782294, 0.000797256, 0.000792767, 0.000837197, 0.00086081, 0.000856668, 0.000894267, 0.000905629, 0.000906323, 0.00097068, 0.00095175, 0.000955696, 0.000969986, 0.000980069, 0.00103508, 0.00108445, 0.00109566, 0.00108985, 0.00108554, 0.00116115, 0.00116232, 0.00123272, 0.00118337, 0.0012059, 0.00121104, 0.00122034, 0.00134806, 0.00132759, 0.00131655, 0.00134255, 0.0014004, 0.00139422, 0.00140613, 0.00148002, 0.00146782, 0.00151511, 0.00152601, 0.00156979, 0.00156765, 0.00161945, 0.00161797, 0.00164276, 0.00167585, 0.00163298, 0.00169692, 0.00173064, 0.00185434, 0.0018602, 0.00183116, 0.00184591, 0.00187262, 0.00185005, 0.00187863, 0.00193908, 0.00196593, 0.00204381, 0.00207335, 0.00214098, 0.00216439, 0.00214946, 0.00215717, 0.00218378, 0.00220102, 0.00226733, 0.00225952, 0.00232741, 0.0023407, 0.00237913, 0.0023986, 0.00246035, 0.00246658, 0.00256504, 0.00255051, 0.00260585, 0.00261381, 0.00263094, 0.00263575, 0.00272168, 0.00272411, 0.00270891, 0.00276706, 0.00281004, 0.00290874, 0.00298958, 0.00287925, 0.00292917, 0.00294574, 0.00308388, 0.00300632, 0.00300664, 0.00304351, 0.00310511, 0.00314704, 0.00307382, 0.0031967, 0.00324223, 0.0032804, 0.00328582, 0.00328493, 0.00322873, 0.00335108, 0.00344131, 0.00348589, 0.00347806, 0.00350257, 0.00354257, 0.00361777, 0.00364609, 0.00357236, 0.00361374, 0.0036504, 0.00367545, 0.00370214, 0.00372157, 0.00380769, 0.00386073, 0.00378243, 0.0038225, 0.00388172, 0.00388896, 0.0039206, 0.00382433, 0.0039355, 0.00394595, 0.00403936, 0.00412466, 0.00398097, 0.00412995, 0.00410556, 0.00412607, 0.00409762, 0.00417612, 0.00419223, 0.00418902, 0.00420858, 0.00418737, 0.00438864, 0.00428859, 0.00424058, 0.00428341, 0.00434349, 0.00426255, 0.00425739, 0.00426099, 0.00435654, 0.00430615, 0.0043434, 0.00436442, 0.00443317, 0.00453702, 0.00458465, 0.00451718, 0.00454829, 0.004526, 0.00444941, 0.00459784, 0.00461657, 0.00464116, 0.00463936, 0.00462128, 0.00464869, 0.00472074, 0.00464255, 0.00463531, 0.00464357, 0.00472312, 0.00471226, 0.00472876, 0.00475929, 0.00477558, 0.00477493, 0.00476745, 0.00480513, 0.00488634, 0.00489984, 0.00491695, 0.0049675, 0.00488809, 0.00492643, 0.0048836, 0.00497446, 0.00506449, 0.00503294, 0.00507216, 0.00511015, 0.00528854, 0.00508509, 0.00508214, 0.00515293, 0.00521213, 0.00535207, 0.00521807, 0.00530294, 0.00523004, 0.00531701, 0.00543113, 0.00540544, 0.00534221, 0.00529414, 0.00536786, 0.00530663, 0.00540221, 0.0054366, 0.00546841, 0.00534307, 0.0053802, 0.00543647, 0.00542493, 0.00540019, 0.0054354, 0.00542636, 0.00540218, 0.00539761, 0.00546834, 0.00538748, 0.0054119, 0.00524333, 0.0052661, 0.00528475, 0.00527178, 0.00527688, 0.00527451, 0.0051803, 0.00532525, 0.00516377, 0.00502179, 0.00498588, 0.00493792, 0.00504124, 0.00497812, 0.00480997, 0.00484698, 0.00475996, 0.00467631, 0.0046375, 0.00452982, 0.00445893, 0.00443842, 0.00431203, 0.004365, 0.00422527, 0.00416564, 0.00407752, 0.00394289, 0.00401572, 0.00385061, 0.00368295, 0.00359867, 0.00356532, 0.00350603, 0.00343337, 0.00328738, 0.00314308, 0.00308744, 0.00307742, 0.00298919, 0.00291293, 0.00276594, 0.00274861, 0.00263172, 0.00244029, 0.00243841, 0.0023837, 0.00222602, 0.00220015, 0.00206933, 0.0019725, 0.00198421, 0.00188412, 0.00176243, 0.00169384, 0.00163604, 0.00154739, 0.00148061, 0.00135909, 0.00128767, 0.00121056, 0.00116466, 0.00113142, 0.00102363, 0.000933341, 0.000903136, 0.00086764, 0.000834096, 0.000722275, 0.000704733, 0.000665919, 0.000615007, 0.00057151, 0.000541261, 0.000484668, 0.000465868, 0.000435923, 0.000406347, 0.000362091, 0.000334272, 0.000302766, 0.000280562, 0.000268874, 0.000248102, 0.000231557, 0.0002133, 0.0001981, 0.000193611, 0.000166442, 0.000154017, 0.000139056, 0.0001301, 0.00011928, 0.000122511, 0.000106704, 8.5411e-05, 8.49339e-05, 8.20717e-05, 6.96905e-05, 6.09304e-05, 5.20402e-05, 5.76345e-05, 5.77646e-05, 4.39089e-05, 6.16243e-05
    };
      
    //const G4int NUMENTRIES_1 = 2;
    //G4double FAST_Energy[NUMENTRIES_1]    = {1.8*eV, 2.7*eV};
    //G4double FAST_COMPONENT[NUMENTRIES_1] = {0.5, 0.5};
    
    const G4int NUMENTRIES_2 = 3;
    G4double RIND_Energy[NUMENTRIES_2]    = { 1.0 * eV, 1.84 * eV, 4.08 * eV };
    G4double RIND_INDEX[NUMENTRIES_2]     = { 1.82, 1.82, 1.82 };
    
    
    ///number obtained from ...
    const G4int NUMENTRIES_3 = 89;
    G4double ABS_Energy[NUMENTRIES_3]     = {     1.78417*eV , 1.7971*eV , 1.81022*eV , 1.82353*eV , 1.83704*eV , 1.85075*eV , 1.86466*eV , 1.87879*eV , 1.89313*eV , 1.90769*eV , 1.92248*eV , 1.9375*eV , 1.95276*eV , 1.96825*eV , 1.984*eV , 2*eV , 2.01626*eV , 2.03279*eV , 2.04959*eV , 2.06667*eV , 2.08403*eV , 2.10169*eV , 2.11966*eV , 2.13793*eV , 2.15652*eV , 2.17544*eV , 2.19469*eV , 2.21429*eV , 2.23423*eV , 2.25455*eV , 2.27523*eV , 2.2963*eV , 2.31776*eV , 2.33962*eV , 2.3619*eV , 2.38462*eV , 2.40777*eV , 2.43137*eV , 2.45545*eV , 2.48*eV , 2.50505*eV , 2.53061*eV , 2.5567*eV , 2.58333*eV , 2.61053*eV , 2.6383*eV , 2.66667*eV , 2.69565*eV , 2.72527*eV , 2.75556*eV , 2.78652*eV , 2.81818*eV , 2.85057*eV , 2.88372*eV , 2.91765*eV , 2.95238*eV , 2.98795*eV , 3.02439*eV , 3.06173*eV , 3.1*eV , 3.13924*eV , 3.17949*eV , 3.22078*eV , 3.26316*eV , 3.30667*eV , 3.35135*eV , 3.39726*eV , 3.44444*eV , 3.49296*eV , 3.54286*eV , 3.5942*eV , 3.64706*eV , 3.70149*eV , 3.75758*eV , 3.81538*eV , 3.875*eV , 3.93651*eV , 4*eV , 4.06557*eV , 4.13333*eV , 4.20339*eV , 4.27586*eV , 4.35088*eV , 4.42857*eV , 4.50909*eV , 4.59259*eV , 4.67925*eV , 4.76923*eV , 4.86275*eV
    };
    
    ///****  LuAG fiber LAG C8      ***
    /*
    G4double ABS_LENGTH[NUMENTRIES_3]       = { 
    0.0189179*m , 0.0146392*m , 0.0127109*m , 0.011902*m , 0.0127634*m , 0.0139595*m , 0.0152425*m , 0.0159177*m , 0.0167732*m , 0.0163943*m , 0.0161551*m , 0.0171217*m , 0.0177309*m , 0.0193562*m , 0.0205334*m , 0.0221373*m , 0.0219748*m , 0.0196871*m , 0.016983*m , 0.0151677*m , 0.0164068*m , 0.0226319*m , 0.0380565*m , 0.0590681*m , 0.0762137*m , 0.0804394*m , 0.0936013*m , 0.0952692*m , 0.101572*m , 0.0991345*m , 0.0959568*m , 0.0863835*m , 0.0669488*m , 0.0483707*m , 0.0325662*m , 0.0214491*m , 0.0157045*m , 0.0118905*m , 0.0100267*m , 0.00917782*m , 0.00930942*m , 0.0105797*m , 0.0133354*m , 0.0186495*m , 0.0266801*m , 0.0443704*m , 0.07227*m , 0.108585*m , 0.147005*m , 0.170305*m , 0.18461*m , 0.207082*m , 0.20653*m , 0.256516*m , 0.234353*m , 0.214725*m , 0.192919*m , 0.255283*m , 0.229393*m , 0.226853*m , 0.241211*m , 0.285162*m , 0.271303*m , 0.294866*m , 0.289152*m , 0.254488*m , 0.320426*m , 0.229631*m , 0.258444*m , 0.263453*m , 0.271229*m , 0.2632*m , 0.297389*m , 0.319752*m , 0.272595*m , 0.278699*m , 0.313377*m , 0.373724*m , 0.226539*m , 0.254233*m , 0.387362*m , 0.321563*m , 0.320576*m , 0.300958*m , 0.305814*m , 0.363562*m , 0.320771*m , 0.29869*m , 0.323131*m , 0.361457*m 
    };
    */
    
    
    ///*** LuAG bulk Ashot 2734 
    G4double ABS_LENGTH[NUMENTRIES_3]       = {     1.66482*m , 1.0584*m , 1.90233*m , 0.958758*m , 1.16913*m , 1.05368*m , 0.881739*m , 2.74593*m , 0.969113*m , 1.30342*m , 1.11065*m , 1.14053*m , 0.926481*m , 0.835474*m , 0.814388*m , 0.702776*m , 1.01264*m , 0.749002*m , 0.691299*m , 0.791851*m , 0.708582*m , 0.609636*m , 0.625308*m , 0.59058*m , 0.522642*m , 0.599727*m , 0.595345*m , 0.594927*m , 0.574464*m , 0.541271*m , 0.531547*m , 0.581632*m , 0.57251*m , 0.560577*m , 0.493902*m , 0.422165*m , 0.354962*m , 0.255139*m , 0.151762*m , 0.0827965*m , 0.0409174*m , 0.02007*m , 0.0100463*m , 0.00588694*m , 0.00636339*m , 0.0084497*m , 0.0224574*m , 0.0509883*m , 0.262914*m , 0.0571499*m , 0.0830375*m , 0.378696*m , 0.0528428*m , 0.0661874*m , 0.0930821*m , 0.0672707*m , 0.0152385*m , 0.00676752*m , 0.00538106*m , 0.00799596*m , 0.0177025*m , 0.0411282*m , 0.0919861*m , 0.149875*m , 0.132761*m , 0.068419*m , 0.0246548*m , 0.00922619*m , 0.00902168*m , 0.0264256*m , 0.0839517*m , 0.0796384*m , 0.0552649*m , 0.0197203*m , 0.00872616*m , 0.00764327*m , 0.0153009*m , 0.0299903*m , 0.0403526*m , 0.0377371*m , 0.0322887*m , 0.0251734*m , 0.0194992*m , 0.0145645*m , 0.0112908*m , 0.0100775*m , 0.0112081*m , 0.0158907*m , 0.019793*m
    };
        
    
    ///introducing the induced absorption as a function of wavelength: modify the array according to a function
    /*
    for (int i = 0; i < NUMENTRIES_3; i++){
   	  	cout << " old abs length = " << ABS_LENGTH[i] << endl;
   	}
   	*/
   	  	
	  ConfigFile config("crystal.cfg");
    G4double ind_abslength = config.read<double>("ind_abslength");	//induced absorption length at 535 nm
    for (int i = 0; i < NUMENTRIES_3; i++){
      //ABS_LENGTH[i] = (ABS_LENGTH[i]*ind_abslength*fInduced_vs535->Eval(ABS_Energy[i])) / (ABS_LENGTH[i] + ind_abslength*fInduced_vs535->Eval(ABS_Energy[i]));
      //ABS_LENGTH[i] = (ABS_LENGTH[i]*ind_abslength) / (ABS_LENGTH[i] + ind_abslength);
   	  ABS_LENGTH[i] = ABS_LENGTH[i]*ind_abslength;
 	  	//cout << " new abs length = " << ABS_LENGTH[i] << endl;
    }
    
    //G4double Rayleigh[NUMENTRIES_2]       = { 138.*mm, 138.*mm, 138.*mm};
    
    
    
    G4MaterialPropertiesTable *mt = new G4MaterialPropertiesTable();
    
    mt->AddProperty ("FASTCOMPONENT", FAST_Energy, FAST_COMPONENT, NUMENTRIES_1);
    //cout << "fast component emission: [" << endl;
    //for (int i = 0; i < NUMENTRIES_1; i++) cout << FAST_COMPONENT[i] << ", ";
    //cout << "]. " << endl;
    
    mt->AddProperty ("RINDEX",        RIND_Energy, RIND_INDEX,     NUMENTRIES_2);
    //cout << "rindex: [" << endl;
    //for (int i = 0; i < NUMENTRIES_2; i++) cout << RIND_INDEX[i] << ", ";
    //cout << "]. " << endl;
        
    mt->AddProperty ("ABSLENGTH",     ABS_Energy,  ABS_LENGTH,     NUMENTRIES_3);
    //cout << "abslength: [" << endl;
    //for (int i = 0; i < NUMENTRIES_3; i++) cout << ABS_LENGTH[i] << ", ";
    //cout << "]. " << endl;
    
    mt->AddConstProperty ("SCINTILLATIONYIELD", 15000 / MeV );
    mt->AddConstProperty ("RESOLUTIONSCALE", 8.5);
    mt->AddConstProperty ("FASTTIMECONSTANT", 60.*ns);
    mt->AddConstProperty ("YIELDRATIO", 1.0);
    mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.5 * ns);
    //mt->AddProperty("RAYLEIGH",ABS_Energy,Rayleigh,NUMENTRIES_2);
    
    mat->SetMaterialPropertiesTable (mt);

    return mat;
}




G4Material *MyMaterials::LUAGPR()
{
  G4double a, z, density;
  G4Element  *O = new G4Element ("Oxygen",    "O",   z = 8,  a = 16.00 * g / mole);
  G4Element *Lu = new G4Element ("Lutetium",  "Lu",  z = 71, a = 174.97 * g / mole);
  G4Element *Al = new G4Element ("Aluminum",  "Al",  z = 27, a = 28.09 * g / mole);
  
  G4Material *mat = new G4Material ("LUAG", density = 6.7 * g / cm3, 3);
  mat->AddElement (Lu, 3);
  mat->AddElement (Al, 12);
  mat->AddElement (O, 5);
  
  //  2 bands at 290nm (4.28eV) and 350nm (3.54eV) about 50% of the light in each.
  const G4int NUMENTRIES_1 = 8;
  G4double FAST_Energy[NUMENTRIES_1]    = {1.0 * eV, 3.4 * eV, 3.5 * eV, 3.60 * eV, 3.90 * eV, 3.91 * eV, 4.07 * eV, 4.08 * eV};
  G4double FAST_COMPONENT[NUMENTRIES_1] = {0.00  , 0.00,  1.00,  0.0,    0.0,    1.0,    0.0,    0.0    };

  const G4int NUMENTRIES_2 = 3;
  G4double RIND_Energy[NUMENTRIES_2]    = { 1.0 * eV, 1.84 * eV, 4.08 * eV };
  G4double RIND_INDEX[NUMENTRIES_2]     = { 1.82, 1.82, 1.82 };
  G4double ABS_Energy[NUMENTRIES_2]     = { 1.0 * eV, 1.84 * eV, 4.08 * eV };
  G4double ABS_LENGTH[NUMENTRIES_2]       = { 138.*mm, 138.*mm, 138.*mm };
  //G4double Rayleigh[NUMENTRIES_2]       = { 138.*mm, 138.*mm, 138.*mm};

  G4MaterialPropertiesTable *mt = new G4MaterialPropertiesTable();
  
  mt->AddProperty ("FASTCOMPONENT", FAST_Energy, FAST_COMPONENT, NUMENTRIES_1);
  mt->AddProperty ("RINDEX",        RIND_Energy, RIND_INDEX,     NUMENTRIES_2);
  mt->AddProperty ("ABSLENGTH",     ABS_Energy,  ABS_LENGTH,     NUMENTRIES_2);
  //mt->AddProperty("RAYLEIGH",      ABS_Energy,  Rayleigh,     NUMENTRIES_2);
  
  mt->AddConstProperty ("SCINTILLATIONYIELD", 7000 / MeV);
  mt->AddConstProperty ("RESOLUTIONSCALE", 6.4);
  mt->AddConstProperty ("FASTTIMECONSTANT", 20.*ns);
  mt->AddConstProperty ("YIELDRATIO", 1.0);
  mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.5 * ns);
  mat->SetMaterialPropertiesTable (mt);
  
  return mat;
}



G4Material *MyMaterials::LYSO()
{
    G4double a, z, density;
    G4Element  *O = new G4Element ("Oxygen",    "O",   z = 8.,  a = 16.00 * g / mole);
    G4Element *Lu = new G4Element ("Lutetium",  "Lu",  z = 71., a = 174.97 * g / mole);
    G4Element *Si = new G4Element ("Silicon",   "Si",  z = 14., a = 28.09 * g / mole);

    G4Material *mat = new G4Material ("LYSO", density = 7.1 * g / cm3, 3, kStateSolid);
    mat->AddElement (Lu, 2);
    mat->AddElement (Si, 1);
    mat->AddElement (O, 5);

    const G4int NUMENTRIES_1 = 261;
    G4double FAST_Energy[NUMENTRIES_1] = {
        1.77169 * eV,
        1.77266 * eV,
        1.77558 * eV,
        1.77851 * eV,
        1.78145 * eV,
        1.78539 * eV,
        1.79033 * eV,
        1.7963 * eV,
        1.80231 * eV,
        1.80836 * eV,
        1.81445 * eV,
        1.82058 * eV,
        1.82882 * eV,
        1.83401 * eV,
        1.84553 * eV,
        1.85293 * eV,
        1.86147 * eV,
        1.869 * eV,
        1.87769 * eV,
        1.89308 * eV,
        1.90536 * eV,
        1.92007 * eV,
        1.93039 * eV,
        1.94901 * eV,
        1.95846 * eV,
        1.9668 * eV,
        1.97884 * eV,
        1.99102 * eV,
        2.00088 * eV,
        2.01209 * eV,
        2.02596 * eV,
        2.03617 * eV,
        2.04519 * eV,
        2.0569 * eV,
        2.06611 * eV,
        2.0794 * eV,
        2.09151 * eV,
        2.10239 * eV,
        2.112 * eV,
        2.1231 * eV,
        2.13431 * eV,
        2.14565 * eV,
        2.15566 * eV,
        2.16868 * eV,
        2.18038 * eV,
        2.19519 * eV,
        2.21171 * eV,
        2.2193 * eV,
        2.23619 * eV,
        2.23464 * eV,
        2.24395 * eV,
        2.25806 * eV,
        2.27234 * eV,
        2.28358 * eV,
        2.29493 * eV,
        2.30475 * eV,
        2.31631 * eV,
        2.32463 * eV,
        2.33134 * eV,
        2.33809 * eV,
        2.34487 * eV,
        2.35856 * eV,
        2.36719 * eV,
        2.37939 * eV,
        2.38642 * eV,
        2.40238 * eV,
        2.41134 * eV,
        2.424 * eV,
        2.43312 * eV,
        2.44047 * eV,
        2.44786 * eV,
        2.46278 * eV,
        2.47788 * eV,
        2.48741 * eV,
        2.49317 * eV,
        2.49702 * eV,
        2.50282 * eV,
        2.50865 * eV,
        2.5145 * eV,
        2.52038 * eV,
        2.52432 * eV,
        2.53223 * eV,
        2.5362 * eV,
        2.54619 * eV,
        2.55424 * eV,
        2.56031 * eV,
        2.56437 * eV,
        2.57049 * eV,
        2.57663 * eV,
        2.58487 * eV,
        2.59317 * eV,
        2.59734 * eV,
        2.60571 * eV,
        2.61414 * eV,
        2.61414 * eV,
        2.61837 * eV,
        2.62262 * eV,
        2.62475 * eV,
        2.62902 * eV,
        2.63331 * eV,
        2.63545 * eV,
        2.63976 * eV,
        2.64191 * eV,
        2.64841 * eV,
        2.65493 * eV,
        2.6593 * eV,
        2.66149 * eV,
        2.66588 * eV,
        2.67914 * eV,
        2.67914 * eV,
        2.68136 * eV,
        2.68136 * eV,
        2.68359 * eV,
        2.68805 * eV,
        2.68805 * eV,
        2.68805 * eV,
        2.69477 * eV,
        2.69477 * eV,
        2.69702 * eV,
        2.70153 * eV,
        2.70605 * eV,
        2.71286 * eV,
        2.71742 * eV,
        2.71971 * eV,
        2.722 * eV,
        2.722 * eV,
        2.72429 * eV,
        2.72889 * eV,
        2.72889 * eV,
        2.73351 * eV,
        2.73814 * eV,
        2.74279 * eV,
        2.74512 * eV,
        2.74979 * eV,
        2.75213 * eV,
        2.75447 * eV,
        2.75917 * eV,
        2.75682 * eV,
        2.76389 * eV,
        2.76626 * eV,
        2.76389 * eV,
        2.76626 * eV,
        2.77338 * eV,
        2.77576 * eV,
        2.78533 * eV,
        2.79255 * eV,
        2.79738 * eV,
        2.80223 * eV,
        2.80466 * eV,
        2.80709 * eV,
        2.80953 * eV,
        2.80953 * eV,
        2.81934 * eV,
        2.8218 * eV,
        2.82673 * eV,
        2.83168 * eV,
        2.84164 * eV,
        2.84916 * eV,
        2.85419 * eV,
        2.8643 * eV,
        2.86684 * eV,
        2.87449 * eV,
        2.87705 * eV,
        2.87961 * eV,
        2.88475 * eV,
        2.88733 * eV,
        2.8925 * eV,
        2.89509 * eV,
        2.90028 * eV,
        2.90549 * eV,
        2.90811 * eV,
        2.91073 * eV,
        2.91335 * eV,
        2.91335 * eV,
        2.91335 * eV,
        2.91861 * eV,
        2.92125 * eV,
        2.92125 * eV,
        2.92389 * eV,
        2.92654 * eV,
        2.92654 * eV,
        2.92919 * eV,
        2.92919 * eV,
        2.93185 * eV,
        2.93451 * eV,
        2.93717 * eV,
        2.93985 * eV,
        2.94252 * eV,
        2.9452 * eV,
        2.94789 * eV,
        2.94789 * eV,
        2.94789 * eV,
        2.95058 * eV,
        2.95868 * eV,
        2.96411 * eV,
        2.96955 * eV,
        2.97228 * eV,
        2.97228 * eV,
        2.96955 * eV,
        2.97228 * eV,
        2.97502 * eV,
        2.97776 * eV,
        2.97502 * eV,
        2.9805 * eV,
        2.9805 * eV,
        2.9805 * eV,
        2.98601 * eV,
        2.99154 * eV,
        2.99431 * eV,
        2.99431 * eV,
        2.99708 * eV,
        2.99431 * eV,
        2.99708 * eV,
        3.00544 * eV,
        3.00824 * eV,
        3.00824 * eV,
        3.00824 * eV,
        3.00824 * eV,
        3.01385 * eV,
        3.0223 * eV,
        3.02797 * eV,
        3.03081 * eV,
        3.02797 * eV,
        3.03365 * eV,
        3.03081 * eV,
        3.03081 * eV,
        3.0365 * eV,
        3.03935 * eV,
        3.04221 * eV,
        3.04795 * eV,
        3.04795 * eV,
        3.05083 * eV,
        3.05371 * eV,
        3.05949 * eV,
        3.06239 * eV,
        3.06529 * eV,
        3.0682 * eV,
        3.06529 * eV,
        3.07112 * eV,
        3.0682 * eV,
        3.07696 * eV,
        3.08283 * eV,
        3.0976 * eV,
        3.09464 * eV,
        3.09464 * eV,
        3.10653 * eV,
        3.11252 * eV,
        3.11852 * eV,
        3.12757 * eV,
        3.13668 * eV,
        3.14583 * eV,
        3.15813 * eV,
        3.16741 * eV,
        3.17675 * eV,
        3.20828 * eV,
        3.23719 * eV,
        3.26664 * eV,
        3.28656 * eV,
        3.31351 * eV,
        3.34783 * eV,
        3.38287 * eV,
    };
    G4double FAST_COMPONENT[NUMENTRIES_1] = {
        0.011691,
        0.011691,
        0.011691,
        0.0146138,
        0.0146138,
        0.0146138,
        0.011691,
        0.011691,
        0.00876827,
        0.00876827,
        0.00584551,
        0.00584551,
        0.00584551,
        0.00292276,
        0.00876827,
        0.0146138,
        0.0146138,
        0.0146138,
        0.0204593,
        0.023382,
        0.0263048,
        0.0204593,
        0.0204593,
        0.023382,
        0.0292276,
        0.0321503,
        0.0350731,
        0.0379958,
        0.0379958,
        0.0379958,
        0.0350731,
        0.0379958,
        0.0409186,
        0.0438413,
        0.0526096,
        0.0584551,
        0.0643006,
        0.0730689,
        0.0730689,
        0.0818372,
        0.0906054,
        0.0964509,
        0.0993737,
        0.105219,
        0.111065,
        0.122756,
        0.125678,
        0.146138,
        0.146138,
        0.160752,
        0.157829,
        0.163674,
        0.184134,
        0.192902,
        0.20167,
        0.219207,
        0.230898,
        0.242589,
        0.25428,
        0.265971,
        0.274739,
        0.292276,
        0.306889,
        0.315658,
        0.321503,
        0.350731,
        0.368267,
        0.385804,
        0.397495,
        0.415031,
        0.432568,
        0.458873,
        0.482255,
        0.496868,
        0.514405,
        0.529019,
        0.549478,
        0.564092,
        0.581628,
        0.593319,
        0.602088,
        0.616701,
        0.637161,
        0.660543,
        0.681002,
        0.71023,
        0.736534,
        0.756994,
        0.777453,
        0.806681,
        0.844676,
        0.868058,
        0.891441,
        0.9119,
        0.938205,
        0.955741,
        0.984969,
        1.0142,
        1.03173,
        1.05511,
        1.07557,
        1.11649,
        1.13695,
        1.15741,
        1.17495,
        1.19248,
        1.21002,
        1.22756,
        1.27432,
        1.2977,
        1.31524,
        1.32985,
        1.36785,
        1.40292,
        1.39415,
        1.4,
        1.41754,
        1.44092,
        1.47015,
        1.48476,
        1.50814,
        1.5286,
        1.54906,
        1.56952,
        1.58998,
        1.61921,
        1.63967,
        1.66597,
        1.68935,
        1.71566,
        1.73904,
        1.76242,
        1.77996,
        1.80042,
        1.8238,
        1.83549,
        1.85303,
        1.8618,
        1.87933,
        1.89979,
        1.91733,
        1.92902,
        1.95825,
        1.98163,
        2.01378,
        2.03424,
        2.0547,
        2.07808,
        2.09562,
        2.11023,
        2.12484,
        2.13361,
        2.15407,
        2.15699,
        2.15992,
        2.16576,
        2.16868,
        2.16868,
        2.16284,
        2.15699,
        2.14823,
        2.13946,
        2.12484,
        2.11023,
        2.08977,
        2.06639,
        2.04593,
        2.02839,
        2.01086,
        1.98455,
        1.96409,
        1.94948,
        1.93194,
        1.91733,
        1.90271,
        1.87641,
        1.86472,
        1.8501,
        1.83841,
        1.82088,
        1.79749,
        1.77119,
        1.75073,
        1.73027,
        1.70689,
        1.68058,
        1.65428,
        1.6309,
        1.60167,
        1.57244,
        1.55491,
        1.53152,
        1.50522,
        1.47891,
        1.45261,
        1.43215,
        1.40877,
        1.38831,
        1.362,
        1.33862,
        1.31232,
        1.28601,
        1.27432,
        1.25678,
        1.21587,
        1.19541,
        1.17203,
        1.14864,
        1.12234,
        1.10772,
        1.08434,
        1.06096,
        1.0142,
        0.987891,
        0.967432,
        0.938205,
        0.9119,
        0.879749,
        0.853445,
        0.82714,
        0.786221,
        0.765762,
        0.739457,
        0.716075,
        0.681002,
        0.660543,
        0.637161,
        0.60501,
        0.581628,
        0.552401,
        0.531942,
        0.505637,
        0.485177,
        0.458873,
        0.435491,
        0.412109,
        0.379958,
        0.356576,
        0.336117,
        0.309812,
        0.280585,
        0.25428,
        0.207516,
        0.175365,
        0.157829,
        0.13737,
        0.119833,
        0.0993737,
        0.0759916,
        0.0613779,
        0.0526096,
        0.0350731,
        0.0263048,
        0.011691,
        0.00876827,
        0.00876827,
        0.011691,
        0.011691,
        0.011691,
        0.00876827,
        0.011691,
    };

	const G4int NUMENTRIES_2 = 5;
    G4double RIND_Energy[NUMENTRIES_2]      = { 1.91 * eV, 2.06 * eV, 2.27 * eV, 3.06 * eV, 3.54 * eV };
    G4double RIND_INDEX[NUMENTRIES_2]       = { 1.8, 1.8, 1.81, 1.83, 1.85 };
    G4double ABS_Energy[NUMENTRIES_2]       = { 1.91 * eV, 2.06 * eV, 2.27 * eV, 3.06 * eV, 3.54 * eV };
    G4double ABS_LENGTH[NUMENTRIES_2]       = { 138.*mm, 138.*mm, 138.*mm, 138.*mm, 138.*mm };
    
//const G4int NUMENTRIES_3 = 3;
//G4double ABS_Energy[NUMENTRIES_3]     = { 1.0*eV, 1.84*eV, 4.08*eV };
//G4double ABS_LENGTH[NUMENTRIES_3]       = { 138000.*mm, 138000.*mm, 138000.*mm };
//G4double ABS_LENGTH[NUMENTRIES_3]       = { 500.*mm, 500.*mm, 500.*mm };


    //G4double Rayleigh[NUMENTRIES_2]       = { 138.*mm, 138.*mm, 138.*mm};


    G4MaterialPropertiesTable *mt = new G4MaterialPropertiesTable();
    mt->AddProperty ("FASTCOMPONENT", FAST_Energy, FAST_COMPONENT, NUMENTRIES_1);
    mt->AddProperty ("RINDEX",        RIND_Energy, RIND_INDEX,     NUMENTRIES_2);
    mt->AddProperty ("ABSLENGTH",     ABS_Energy,  ABS_LENGTH,     NUMENTRIES_2);
    //mt->AddProperty("RAYLEIGH",      ABS_Energy,  Rayleigh,     NUMENTRIES_2);
    mt->AddConstProperty ("SCINTILLATIONYIELD", 40000. / MeV);
    mt->AddConstProperty ("RESOLUTIONSCALE", 3.4);
    mt->AddConstProperty ("FASTTIMECONSTANT", 40.*ns);
    mt->AddConstProperty ("YIELDRATIO", 1.0);
    mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.1 * ns);
    mat->SetMaterialPropertiesTable (mt);


    return mat;
}
G4Material *MyMaterials::LSO()
{
    G4double a, z, density;
    G4Element  *O = new G4Element ("Oxygen",    "O",   z = 8.,  a = 16.00 * g / mole);
    G4Element *Lu = new G4Element ("Lutetium",  "Lu",  z = 71., a = 174.97 * g / mole);
    G4Element *Si = new G4Element ("Silicon",   "Si",  z = 14., a = 28.09 * g / mole);

    G4Material *LSO = new G4Material ("LSO", density = 7.4 * g / cm3, 3);
    LSO->AddElement (Lu, 2);
    LSO->AddElement (Si, 1);
    LSO->AddElement (O, 5);

    const G4int LSO_NUMENTRIES_1 = 501;
    G4double LSO_FAST_Energy[LSO_NUMENTRIES_1] = {
        1.7712026714 * eV,
1.7737365808 * eV,
1.7762777507 * eV,
1.7788262123 * eV,
1.7813819971 * eV,
1.7839451367 * eV,
1.7865156628 * eV,
1.7890936075 * eV,
1.7916790029 * eV,
1.7942718813 * eV,
1.7968722754 * eV,
1.7994802177 * eV,
1.8020957413 * eV,
1.8047188792 * eV,
1.8073496647 * eV,
1.8099881314 * eV,
1.8126343129 * eV,
1.815288243 * eV,
1.817949956 * eV,
1.820619486 * eV,
1.8232968676 * eV,
1.8259821355 * eV,
1.8286753245 * eV,
1.8313764697 * eV,
1.8340856065 * eV,
1.8368027704 * eV,
1.839527997 * eV,
1.8422613224 * eV,
1.8450027827 * eV,
1.8477524143 * eV,
1.8505102537 * eV,
1.8532763378 * eV,
1.8560507036 * eV,
1.8588333883 * eV,
1.8616244294 * eV,
1.8644238647 * eV,
1.8672317319 * eV,
1.8700480694 * eV,
1.8728729154 * eV,
1.8757063086 * eV,
1.8785482879 * eV,
1.8813988923 * eV,
1.8842581611 * eV,
1.8871261339 * eV,
1.8900028506 * eV,
1.8928883511 * eV,
1.8957826758 * eV,
1.8986858652 * eV,
1.9015979601 * eV,
1.9045190015 * eV,
1.9074490308 * eV,
1.9103880894 * eV,
1.9133362191 * eV,
1.9162934621 * eV,
1.9192598607 * eV,
1.9222354574 * eV,
1.925220295 * eV,
1.9282144168 * eV,
1.931217866 * eV,
1.9342306864 * eV,
1.9372529219 * eV,
1.9402846166 * eV,
1.943325815 * eV,
1.946376562 * eV,
1.9494369025 * eV,
1.9525068819 * eV,
1.9555865457 * eV,
1.95867594 * eV,
1.9617751108 * eV,
1.9648841046 * eV,
1.9680029683 * eV,
1.9711317488 * eV,
1.9742704936 * eV,
1.9774192504 * eV,
1.9805780671 * eV,
1.983746992 * eV,
1.9869260737 * eV,
1.9901153612 * eV,
1.9933149035 * eV,
1.9965247504 * eV,
1.9997449516 * eV,
2.0029755574 * eV,
2.0062166181 * eV,
2.0094681848 * eV,
2.0127303084 * eV,
2.0160030407 * eV,
2.0192864332 * eV,
2.0225805383 * eV,
2.0258854085 * eV,
2.0292010966 * eV,
2.0325276557 * eV,
2.0358651396 * eV,
2.039213602 * eV,
2.0425730972 * eV,
2.0459436799 * eV,
2.049325405 * eV,
2.0527183278 * eV,
2.0561225041 * eV,
2.05953799 * eV,
2.0629648419 * eV,
2.0664031167 * eV,
2.0698528715 * eV,
2.0733141639 * eV,
2.0767870519 * eV,
2.080271594 * eV,
2.0837678487 * eV,
2.0872758754 * eV,
2.0907957336 * eV,
2.0943274831 * eV,
2.0978711844 * eV,
2.1014268983 * eV,
2.1049946859 * eV,
2.1085746088 * eV,
2.1121667291 * eV,
2.1157711092 * eV,
2.119387812 * eV,
2.1230169007 * eV,
2.1266584391 * eV,
2.1303124914 * eV,
2.1339791222 * eV,
2.1376583966 * eV,
2.14135038 * eV,
2.1450551384 * eV,
2.1487727383 * eV,
2.1525032465 * eV,
2.1562467304 * eV,
2.1600032578 * eV,
2.163772897 * eV,
2.1675557168 * eV,
2.1713517863 * eV,
2.1751611754 * eV,
2.1789839543 * eV,
2.1828201937 * eV,
2.1866699647 * eV,
2.1905333392 * eV,
2.1944103894 * eV,
2.1983011879 * eV,
2.2022058082 * eV,
2.2061243238 * eV,
2.2100568093 * eV,
2.2140033393 * eV,
2.2179639893 * eV,
2.2219388351 * eV,
2.2259279533 * eV,
2.2299314209 * eV,
2.2339493153 * eV,
2.2379817148 * eV,
2.242028698 * eV,
2.2460903442 * eV,
2.2501667332 * eV,
2.2542579455 * eV,
2.2583640619 * eV,
2.2624851642 * eV,
2.2666213346 * eV,
2.2707726557 * eV,
2.274939211 * eV,
2.2791210846 * eV,
2.283318361 * eV,
2.2875311255 * eV,
2.291759464 * eV,
2.296003463 * eV,
2.3002632096 * eV,
2.3045387918 * eV,
2.308830298 * eV,
2.3131378172 * eV,
2.3174614393 * eV,
2.3218012547 * eV,
2.3261573546 * eV,
2.3305298308 * eV,
2.3349187759 * eV,
2.339324283 * eV,
2.3437464461 * eV,
2.3481853598 * eV,
2.3526411195 * eV,
2.3571138213 * eV,
2.3616035619 * eV,
2.3661104389 * eV,
2.3706345507 * eV,
2.3751759962 * eV,
2.3797348752 * eV,
2.3843112885 * eV,
2.3889053372 * eV,
2.3935171236 * eV,
2.3981467505 * eV,
2.4027943217 * eV,
2.4074599417 * eV,
2.412143716 * eV,
2.4168457505 * eV,
2.4215661523 * eV,
2.4263050294 * eV,
2.4310624902 * eV,
2.4358386444 * eV,
2.4406336024 * eV,
2.4454474753 * eV,
2.4502803755 * eV,
2.4551324158 * eV,
2.4600037103 * eV,
2.4648943738 * eV,
2.4698045219 * eV,
2.4747342715 * eV,
2.47968374 * eV,
2.4846530461 * eV,
2.4896423092 * eV,
2.4946516499 * eV,
2.4996811895 * eV,
2.5047310505 * eV,
2.5098013563 * eV,
2.5148922312 * eV,
2.5200038008 * eV,
2.5251361914 * eV,
2.5302895306 * eV,
2.5354639468 * eV,
2.5406595697 * eV,
2.5458765298 * eV,
2.5511149588 * eV,
2.5563749897 * eV,
2.5616567562 * eV,
2.5669603934 * eV,
2.5722860373 * eV,
2.5776338254 * eV,
2.5830038958 * eV,
2.5883963883 * eV,
2.5938114435 * eV,
2.5992492034 * eV,
2.6047098109 * eV,
2.6101934105 * eV,
2.6157001477 * eV,
2.6212301691 * eV,
2.6267836229 * eV,
2.6323606582 * eV,
2.6379614255 * eV,
2.6435860768 * eV,
2.649234765 * eV,
2.6549076445 * eV,
2.6606048712 * eV,
2.6663266022 * eV,
2.6720729957 * eV,
2.6778442117 * eV,
2.6836404113 * eV,
2.689461757 * eV,
2.695308413 * eV,
2.7011805447 * eV,
2.7070783188 * eV,
2.7130019037 * eV,
2.7189514693 * eV,
2.7249271868 * eV,
2.7309292291 * eV,
2.7369577704 * eV,
2.7430129867 * eV,
2.7490950554 * eV,
2.7552041556 * eV,
2.7613404677 * eV,
2.7675041741 * eV,
2.7736954586 * eV,
2.7799145067 * eV,
2.7861615056 * eV,
2.7924366441 * eV,
2.7987401129 * eV,
2.8050721041 * eV,
2.8114328118 * eV,
2.8178224318 * eV,
2.8242411617 * eV,
2.8306892009 * eV,
2.8371667506 * eV,
2.8436740138 * eV,
2.8502111954 * eV,
2.8567785023 * eV,
2.8633761432 * eV,
2.8700043287 * eV,
2.8766632715 * eV,
2.883353186 * eV,
2.890074289 * eV,
2.8968267991 * eV,
2.9036109368 * eV,
2.9104269249 * eV,
2.9172749882 * eV,
2.9241553538 * eV,
2.9310682506 * eV,
2.93801391 * eV,
2.9449925653 * eV,
2.9520044524 * eV,
2.9590498091 * eV,
2.9661288756 * eV,
2.9732418945 * eV,
2.9803891106 * eV,
2.9875707711 * eV,
2.9947871256 * eV,
3.0020384262 * eV,
3.0093249272 * eV,
3.0166468856 * eV,
3.024004561 * eV,
3.0313982152 * eV,
3.0388281127 * eV,
3.0462945209 * eV,
3.0537977094 * eV,
3.0613379506 * eV,
3.0689155198 * eV,
3.0765306948 * eV,
3.0841837562 * eV,
3.0918749875 * eV,
3.099604675 * eV,
3.1073731078 * eV,
3.1151805779 * eV,
3.1230273804 * eV,
3.1309138131 * eV,
3.1388401772 * eV,
3.1468067766 * eV,
3.1548139186 * eV,
3.1628619133 * eV,
3.1709510742 * eV,
3.1790817179 * eV,
3.1872541645 * eV,
3.1954687371 * eV,
3.2037257623 * eV,
3.2120255699 * eV,
3.2203684935 * eV,
3.2287548698 * eV,
3.2371850392 * eV,
3.2456593455 * eV,
3.2541781365 * eV,
3.2627417632 * eV,
3.2713505805 * eV,
3.2800049471 * eV,
3.2887052255 * eV,
3.2974517819 * eV,
3.3062449867 * eV,
3.3150852139 * eV,
3.3239728418 * eV,
3.3329082527 * eV,
3.3418918329 * eV,
3.350923973 * eV,
3.3600050678 * eV,
3.3691355163 * eV,
3.3783157221 * eV,
3.3875460929 * eV,
3.3968270411 * eV,
3.4061589835 * eV,
3.4155423416 * eV,
3.4249775414 * eV,
3.4344650139 * eV,
3.4440051944 * eV,
3.4535985237 * eV,
3.4632454469 * eV,
3.4729464146 * eV,
3.482701882 * eV,
3.4925123099 * eV,
3.5023781638 * eV,
3.512299915 * eV,
3.5222780398 * eV,
3.5323130199 * eV,
3.5424053429 * eV,
3.5525555014 * eV,
3.5627639943 * eV,
3.5730313256 * eV,
3.5833580058 * eV,
3.5937445507 * eV,
3.6041914826 * eV,
3.6146993294 * eV,
3.6252686257 * eV,
3.635899912 * eV,
3.6465937353 * eV,
3.657350649 * eV,
3.668171213 * eV,
3.6790559941 * eV,
3.6900055655 * eV,
3.7010205075 * eV,
3.7121014072 * eV,
3.7232488589 * eV,
3.7344634639 * eV,
3.7457458308 * eV,
3.7570965758 * eV,
3.7685163222 * eV,
3.7800057012 * eV,
3.7915653517 * eV,
3.8031959202 * eV,
3.8148980615 * eV,
3.8266724383 * eV,
3.8385197214 * eV,
3.8504405901 * eV,
3.8624357321 * eV,
3.8745058438 * eV,
3.8866516301 * eV,
3.898873805 * eV,
3.9111730915 * eV,
3.9235502215 * eV,
3.9360059365 * eV,
3.9485409873 * eV,
3.9611561342 * eV,
3.9738521474 * eV,
3.9866298071 * eV,
3.9994899032 * eV,
4.0124332362 * eV,
4.0254606169 * eV,
4.0385728664 * eV,
4.051770817 * eV,
4.0650553115 * eV,
4.0784272039 * eV,
4.0918873597 * eV,
4.1054366556 * eV,
4.1190759801 * eV,
4.1328062333 * eV,
4.1466283278 * eV,
4.1605431879 * eV,
4.1745517508 * eV,
4.1886549662 * eV,
4.2028537966 * eV,
4.2171492177 * eV,
4.2315422184 * eV,
4.2460338014 * eV,
4.2606249828 * eV,
4.2753167931 * eV,
4.2901102768 * eV,
4.3050064931 * eV,
4.3200065157 * eV,
4.3351114336 * eV,
4.3503223509 * eV,
4.3656403873 * eV,
4.3810666784 * eV,
4.3966023759 * eV,
4.4122486477 * eV,
4.4280066786 * eV,
4.4438776703 * eV,
4.4598628417 * eV,
4.4759634296 * eV,
4.4921806884 * eV,
4.5085158909 * eV,
4.5249703285 * eV,
4.5415453114 * eV,
4.5582421691 * eV,
4.5750622509 * eV,
4.5920069259 * eV,
4.6090775836 * eV,
4.6262756343 * eV,
4.6436025094 * eV,
4.6610596617 * eV,
4.678648566 * eV,
4.6963707197 * eV,
4.7142276426 * eV,
4.7322208779 * eV,
4.7503519923 * eV,
4.7686225769 * eV,
4.7870342471 * eV,
4.8055886434 * eV,
4.8242874319 * eV,
4.8431323047 * eV,
4.8621249804 * eV,
4.8812672047 * eV,
4.900560751 * eV,
4.9200074206 * eV,
4.9396090438 * eV,
4.95936748 * eV,
4.9792846185 * eV,
4.999362379 * eV,
5.0196027126 * eV,
5.0400076016 * eV,
5.0605790612 * eV,
5.0813191393 * eV,
5.1022299177 * eV,
5.1233135124 * eV,
5.1445720747 * eV,
5.1660077917 * eV,
5.187622887 * eV,
5.2094196218 * eV,
5.2314002954 * eV,
5.2535672458 * eV,
5.2759228511 * eV,
5.2984695299 * eV,
5.3212097425 * eV,
5.3441459914 * eV,
5.3672808225 * eV,
5.3906168261 * eV,
5.4141566376 * eV,
5.4379029386 * eV,
5.4618584581 * eV,
5.4860259735 * eV,
5.5104083111 * eV,
5.5350083482 * eV,
5.5598290135 * eV,
5.5848732883 * eV,
5.6101442081 * eV,
5.6356448636 * eV,
5.6613784018 * eV,
5.6873480275 * eV,
5.7135570046 * eV,
5.7400086574 * eV,
5.7667063721 * eV,
5.7936535981 * eV,
5.8208538498 * eV,
5.8483107075 * eV,
5.8760278199 * eV,
5.9040089048 * eV,
5.9322577512 * eV,
5.9607782212 * eV,
5.9895742512 * eV,
6.0186498544 * eV,
6.048009122 * eV,
6.0776562255 * eV,
6.1075954187 * eV,
6.1378310396 * eV,
6.1683675124 * eV,
6.19920935 * eV

    };
    

G4double LSO_FAST_COMPONENT[LSO_NUMENTRIES_1] = {
        5.483032797e-45	,
1.102767892e-44	,
2.212389792e-44	,
4.427447731e-44	,
8.838112051e-44	,
1.759866919e-43	,
3.495541125e-43	,
6.925693504e-43	,
1.368757096e-42	,
2.698384064e-42	,
5.30634407e-42	,
1.040881558e-41	,
2.036673839e-41	,
3.975171954e-41	,
7.739352331e-41	,
1.503029763e-40	,
2.9116878e-40	,
5.626473746e-40	,
1.0845312e-39	,
2.085268909e-39	,
3.999413879e-39	,
7.651470258e-39	,
1.460184397e-38	,
2.779615829e-38	,
5.278081751e-38	,
9.997276711e-38	,
1.888867861e-37	,
3.559882839e-37	,
6.692433996e-37	,
1.255008745e-36	,
2.347597679e-36	,
4.380410936e-36	,
8.153053674e-36	,
1.513700701e-35	,
2.803328463e-35	,
5.178717548e-35	,
9.542995673e-35	,
1.754128855e-34	,
3.216270167e-34	,
5.882444195e-34	,
1.073191868e-33	,
1.953040252e-33	,
3.545351334e-33	,
6.41980191e-33	,
1.159573389e-32	,
2.089243772e-32	,
3.754864386e-32	,
6.731528054e-32	,
1.203780566e-31	,
2.147312534e-31	,
3.820827706e-31	,
6.78162722e-31	,
1.2006727e-30	,
2.120457745e-30	,
3.735501138e-30	,
6.564208803e-30	,
1.150615354e-29	,
2.011834294e-29	,
3.508879971e-29	,
6.104626279e-29	,
1.059409627e-28	,
1.833931086e-28	,
3.166768911e-28	,
5.454613679e-28	,
9.371862012e-28	,
1.606208936e-27	,
2.745948916e-27	,
4.682708604e-27	,
7.965555664e-27	,
1.351603427e-26	,
2.287687795e-26	,
3.862411043e-26	,
6.5048081e-26	,
1.092759904e-25	,
1.831172584e-25	,
3.060892433e-25	,
5.103652797e-25	,
8.488450867e-25	,
1.408283272e-24	,
2.330589932e-24	,
3.847299313e-24	,
6.335200261e-24	,
1.04058841e-23	,
1.704950933e-23	,
2.786500011e-23	,
4.542767156e-23	,
7.387477464e-23	,
1.198356745e-22	,
1.939055966e-22	,
3.129744085e-22	,
5.038967697e-22	,
8.092609511e-22	,
1.296432351e-21	,
2.071692997e-21	,
3.30228993e-21	,
5.250724915e-21	,
8.327940162e-21	,
1.317559357e-20	,
2.07929949e-20	,
3.2732424e-20	,
5.139886786e-20	,
8.050877189e-20	,
1.257902888e-19	,
1.960492976e-19	,
3.047879065e-19	,
4.726551941e-19	,
7.311481788e-19	,
1.128185813e-18	,
1.736481374e-18	,
2.666084368e-18	,
4.083117816e-18	,
6.237695898e-18	,
9.50540769e-18	,
1.444879279e-17	,
2.190819718e-17	,
3.313568728e-17	,
4.999189374e-17	,
7.523457259e-17	,
1.129404702e-16	,
1.691203966e-16	,
2.526135542e-16	,
3.763843645e-16	,
5.593978107e-16	,
8.293239635e-16	,
1.226427643e-15	,
1.809147226e-15	,
2.662074186e-15	,
3.907335126e-15	,
5.720782451e-15	,
8.354961785e-15	,
1.217160267e-14	,
1.768745424e-14	,
2.563876818e-14	,
3.70717635e-14	,
5.346918936e-14	,
7.692689753e-14	,
1.103994982e-13	,
1.580411731e-13	,
2.256771839e-13	,
3.214543645e-13	,
4.567360204e-13	,
6.473295969e-13	,
9.151661085e-13	,
1.290591072e-12	,
1.815480751e-12	,
2.547468979e-12	,
3.565664062e-12	,
4.978358953e-12	,
6.933399971e-12	,
9.63209074e-12	,
1.334778307e-11	,
1.845066308e-11	,
2.544070141e-11	,
3.499132974e-11	,
4.800716685e-11	,
6.570009091e-11	,
8.96891954e-11	,
1.221317413e-10	,
1.658942122e-10	,
2.247750916e-10	,
3.037941425e-10	,
4.095669202e-10	,
5.507881812e-10	,
7.388539793e-10	,
9.886598203e-10	,
1.319621602e-09	,
1.756977547e-09	,
2.333443399e-09	,
3.09131025e-09	,
4.085095189e-09	,
5.384880021e-09	,
7.080503565e-09	,
9.286809223e-09	,
1.215019271e-08	,
1.585674608e-08	,
2.064235494e-08	,
2.680517672e-08	,
3.472101177e-08	,
4.486217581e-08	,
5.782059518e-08	,
7.433597574e-08	,
9.533004516e-08	,
1.219480373e-07	,
1.55608779e-07	,
1.980649546e-07	,
2.514753644e-07	,
3.184912589e-07	,
4.023591228e-07	,
5.070426033e-07	,
6.373666191e-07	,
7.991870553e-07	,
9.995898353e-07	,
1.247123565e-06	,
1.552070353e-06	,
1.926759837e-06	,
2.385931827e-06	,
2.947153388e-06	,
3.631296515e-06	,
4.463082859e-06	,
5.471702172e-06	,
6.691511288e-06	,
8.162820438e-06	,
9.93277357e-06	,
1.205632901e-05	,
1.459734629e-05	,
1.762978412e-05	,
2.123901353e-05	,
2.552324872e-05	,
3.059509651e-05	,
3.658322314e-05	,
4.363413475e-05	,
5.191406478e-05	,
6.161095842e-05	,
7.293654023e-05	,
8.612844695e-05	,
0.0001015	,
0.0001192	,
0.0001397	,
0.0001633	,
0.0001905	,
0.0002216	,
0.0002571	,
0.0002976	,
0.0003436	,
0.0003958	,
0.0004547	,
0.0005210	,
0.0005956	,
0.0006791	,
0.0007725	,
0.0008764	,
0.0009919	,
0.0011197	,
0.0012609	,
0.0014164	,
0.0015870	,
0.0017737	,
0.0019775	,
0.0021992	,
0.0024396	,
0.0026995	,
0.0029797	,
0.0032808	,
0.0036032	,
0.0039475	,
0.0043139	,
0.0047025	,
0.0051132	,
0.0055460	,
0.0060005	,
0.0064759	,
0.0069715	,
0.0074864	,
0.0080192	,
0.0085684	,
0.0091325	,
0.0097093	,
0.0102968	,
0.0108926	,
0.0114941	,
0.0120985	,
0.0127030	,
0.0133043	,
0.0138992	,
0.0144846	,
0.0150569	,
0.0156127	,
0.0161486	,
0.0166612	,
0.0171472	,
0.0176033	,
0.0180263	,
0.0184135	,
0.0187620	,
0.0190694	,
0.0193334	,
0.0195521	,
0.0197240	,
0.0198476	,
0.0199222	,
0.0199471	,
0.0199222	,
0.0198476	,
0.0197240	,
0.0195521	,
0.0193334	,
0.0190694	,
0.0187620	,
0.0184135	,
0.0180263	,
0.0176033	,
0.0171472	,
0.0166612	,
0.0161486	,
0.0156127	,
0.0150569	,
0.0144846	,
0.0138992	,
0.0133043	,
0.0127030	,
0.0120985	,
0.0114941	,
0.0108926	,
0.0102968	,
0.0097093	,
0.0091325	,
0.0085684	,
0.0080192	,
0.0074864	,
0.0069715	,
0.0064759	,
0.0060005	,
0.0055460	,
0.0051132	,
0.0047025	,
0.0043139	,
0.0039475	,
0.0036032	,
0.0032808	,
0.0029797	,
0.0026995	,
0.0024396	,
0.0021992	,
0.0019775	,
0.0017737	,
0.0015870	,
0.0014164	,
0.0012609	,
0.0011197	,
0.0009919	,
0.0008764	,
0.0007725	,
0.0006791	,
0.0005956	,
0.0005210	,
0.0004547	,
0.0003958	,
0.0003436	,
0.0002976	,
0.0002571	,
0.0002216	,
0.0001905	,
0.0001633	,
0.0001397	,
0.0001192	,
0.0001015	,
8.612844695e-05	,
7.293654023e-05	,
6.161095842e-05	,
5.191406478e-05	,
4.363413475e-05	,
3.658322314e-05	,
3.059509651e-05	,
2.552324872e-05	,
2.123901353e-05	,
1.762978412e-05	,
1.459734629e-05	,
1.205632901e-05	,
9.93277357e-06	,
8.162820438e-06	,
6.691511288e-06	,
5.471702172e-06	,
4.463082859e-06	,
3.631296515e-06	,
2.947153388e-06	,
2.385931827e-06	,
1.926759837e-06	,
1.552070353e-06	,
1.247123565e-06	,
9.995898353e-07	,
7.991870553e-07	,
6.373666191e-07	,
5.070426033e-07	,
4.023591228e-07	,
3.184912589e-07	,
2.514753644e-07	,
1.980649546e-07	,
1.55608779e-07	,
1.219480373e-07	,
9.533004516e-08	,
7.433597574e-08	,
5.782059518e-08	,
4.486217581e-08	,
3.472101177e-08	,
2.680517672e-08	,
2.064235494e-08	,
1.585674608e-08	,
1.215019271e-08	,
9.286809223e-09	,
7.080503565e-09	,
5.384880021e-09	,
4.085095189e-09	,
3.09131025e-09	,
2.333443399e-09	,
1.756977547e-09	,
1.319621602e-09	,
9.886598203e-10	,
7.388539793e-10	,
5.507881812e-10	,
4.095669202e-10	,
3.037941425e-10	,
2.247750916e-10	,
1.658942122e-10	,
1.221317413e-10	,
8.96891954e-11	,
6.570009091e-11	,
4.800716685e-11	,
3.499132974e-11	,
2.544070141e-11	,
1.845066308e-11	,
1.334778307e-11	,
9.63209074e-12	,
6.933399971e-12	,
4.978358953e-12	,
3.565664062e-12	,
2.547468979e-12	,
1.815480751e-12	,
1.290591072e-12	,
9.151661085e-13	,
6.473295969e-13	,
4.567360204e-13	,
3.214543645e-13	,
2.256771839e-13	,
1.580411731e-13	,
1.103994982e-13	,
7.692689753e-14	,
5.346918936e-14	,
3.70717635e-14	,
2.563876818e-14	,
1.768745424e-14	,
1.217160267e-14	,
8.354961785e-15	,
5.720782451e-15	,
3.907335126e-15	,
2.662074186e-15	,
1.809147226e-15	,
1.226427643e-15	,
8.293239635e-16	,
5.593978107e-16	,
3.763843645e-16	,
2.526135542e-16	,
1.691203966e-16	,
1.129404702e-16	,
7.523457259e-17	,
4.999189374e-17	,
3.313568728e-17	,
2.190819718e-17	,
1.444879279e-17	,
9.50540769e-18	,
6.237695898e-18	,
4.083117816e-18	,
2.666084368e-18	,
1.736481374e-18	,
1.128185813e-18	,
7.311481788e-19	,
4.726551941e-19	,
3.047879065e-19	,
1.960492976e-19	,
1.257902888e-19	,
8.050877189e-20	,
5.139886786e-20	,
3.2732424e-20	,
2.07929949e-20	,
1.317559357e-20	,
8.327940162e-21	,
5.250724915e-21	,
3.30228993e-21	,
2.071692997e-21	,
1.296432351e-21	,
8.092609511e-22	,
5.038967697e-22	,
3.129744085e-22	,
1.939055966e-22	,
1.198356745e-22	,
7.387477464e-23	,
4.542767156e-23	,
2.786500011e-23	,
1.704950933e-23	,
1.04058841e-23	,
6.335200261e-24	,
3.847299313e-24	,
2.330589932e-24	,
1.408283272e-24	,
8.488450867e-25	,
5.103652797e-25	,
3.060892433e-25	,
1.831172584e-25	,
1.092759904e-25	,
6.5048081e-26	,
3.862411043e-26	,
2.287687795e-26	,
1.351603427e-26	,
7.965555664e-27	,
4.682708604e-27	,
2.745948916e-27	,
1.606208936e-27	,
9.371862012e-28	,
5.454613679e-28	,
3.166768911e-28	,
1.833931086e-28	,
1.059409627e-28	
    };

    
    const G4int LSO_NUMENTRIES_2 = 7;
    G4double LSO_RIND_Energy[LSO_NUMENTRIES_2]      = { 1.5 * eV, 1.91 * eV, 2.06 * eV, 2.27 * eV, 3.06 * eV, 3.54 * eV , 4.13 * eV};
    G4double LSO_RIND_INDEX[LSO_NUMENTRIES_2]       = { 1.8, 1.8,  1.8, 1.81, 1.83, 1.85, 1.85 };
    G4double LSO_ABS_Energy[LSO_NUMENTRIES_2]       = {  1.5 * eV,1.91 * eV, 2.06 * eV, 2.27 * eV, 3.06 * eV, 3.54 * eV , 4.13 * eV};
    G4double LSO_ABS_LENGTH[LSO_NUMENTRIES_2]       = { 138.*mm, 138.*mm, 138.*mm, 138.*mm, 138.*mm , 138.*mm , 138.*mm };
    
    /*
    const G4int LSO_NUMENTRIES_2 = 7;
    G4double LSO_RIND_Energy[LSO_NUMENTRIES_2]      = { 0.1 * eV, 1.91 * eV, 2.06 * eV, 2.27 * eV, 3.06 * eV, 3.54 * eV, 10 * eV };
    G4double LSO_RIND_INDEX[LSO_NUMENTRIES_2]       = { 1.82, 1.82, 1.82, 1.82, 1.82, 1.82, 1.82 };
    G4double LSO_ABS_Energy[LSO_NUMENTRIES_2]       = { 0.1 * eV, 1.91 * eV, 2.06 * eV, 2.27 * eV, 3.06 * eV, 3.54 * eV, 10 * eV };
    G4double LSO_ABS_LENGTH[LSO_NUMENTRIES_2]       = { 138.*mm, 138.*mm, 138.*mm, 138.*mm, 138.*mm, 138.*mm, 138.*mm };
	*/

    G4MaterialPropertiesTable *LSO_mt = new G4MaterialPropertiesTable();
    LSO_mt->AddProperty ("FASTCOMPONENT", LSO_FAST_Energy, LSO_FAST_COMPONENT, LSO_NUMENTRIES_1);
    LSO_mt->AddProperty ("RINDEX",        LSO_RIND_Energy, LSO_RIND_INDEX,     LSO_NUMENTRIES_2);
    LSO_mt->AddProperty ("ABSLENGTH",     LSO_ABS_Energy,  LSO_ABS_LENGTH,     LSO_NUMENTRIES_2);

    LSO_mt->AddConstProperty ("SCINTILLATIONYIELD", 60000. / MeV);
    LSO_mt->AddConstProperty ("RESOLUTIONSCALE", 3.2);
    LSO_mt->AddConstProperty ("FASTTIMECONSTANT", 42.*ns);
    LSO_mt->AddConstProperty ("YIELDRATIO", 1.0);
    LSO_mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.1 * ns);

    const G4int LSO_SCY_NUMENTRIES = 12;
    G4double LSO_SCY_Energy[LSO_SCY_NUMENTRIES] = { 0.000 * MeV, 0.015 * MeV, 0.020 * MeV, 0.030 * MeV, 0.040 * MeV, 0.060 * MeV,
            0.080 * MeV, 0.090 * MeV, 0.105 * MeV, 0.300 * MeV, 0.500 * MeV, 1.000 * MeV
                                                  };
    G4double LSO_SCY[LSO_SCY_NUMENTRIES]        = { 0.10, 0.46, 0.60, 0.68, 0.74, 0.80, 0.82,
            0.84, 0.87,  0.96,  0.98,  1.00
                                                  };
    for (int i = 0; i < LSO_SCY_NUMENTRIES; i++) {
        LSO_SCY[i] = 60000.0 * MeV * LSO_SCY[i] * LSO_SCY_Energy[i];
    }
    //LSO_mt->AddProperty ("ELECTRONSCINTILLATIONYIELD", LSO_SCY_Energy, LSO_SCY, LSO_SCY_NUMENTRIES);




    LSO->SetMaterialPropertiesTable (LSO_mt);


    return LSO;
}



G4Material *MyMaterials::PbWO()
{
    G4double a, z, density;
    G4Element *O = new G4Element ("Oxygen",    "O",   z = 8.,  a = 16.00 * g / mole);
    G4Element *Pb = new G4Element ("Lead",     "Pb",  z = 82., a = 207.21 * g / mole);
    G4Element *W = new G4Element ("Tungsten",  "W",   z = 74., a = 183.85 * g / mole);

    G4Material *PbWO = new G4Material ("PbWO", density = 8.28 * g / cm3, 3);
    PbWO->AddElement (Pb, 1);
    PbWO->AddElement (W, 1);
    PbWO->AddElement (O, 4);

    const G4int PbWO_NUMENTRIES_1 = 501;
    G4double PbWO_FAST_Energy[PbWO_NUMENTRIES_1] = {
        1.7712026714 * eV,
1.7737365808 * eV,
1.7762777507 * eV,
1.7788262123 * eV,
1.7813819971 * eV,
1.7839451367 * eV,
1.7865156628 * eV,
1.7890936075 * eV,
1.7916790029 * eV,
1.7942718813 * eV,
1.7968722754 * eV,
1.7994802177 * eV,
1.8020957413 * eV,
1.8047188792 * eV,
1.8073496647 * eV,
1.8099881314 * eV,
1.8126343129 * eV,
1.815288243 * eV,
1.817949956 * eV,
1.820619486 * eV,
1.8232968676 * eV,
1.8259821355 * eV,
1.8286753245 * eV,
1.8313764697 * eV,
1.8340856065 * eV,
1.8368027704 * eV,
1.839527997 * eV,
1.8422613224 * eV,
1.8450027827 * eV,
1.8477524143 * eV,
1.8505102537 * eV,
1.8532763378 * eV,
1.8560507036 * eV,
1.8588333883 * eV,
1.8616244294 * eV,
1.8644238647 * eV,
1.8672317319 * eV,
1.8700480694 * eV,
1.8728729154 * eV,
1.8757063086 * eV,
1.8785482879 * eV,
1.8813988923 * eV,
1.8842581611 * eV,
1.8871261339 * eV,
1.8900028506 * eV,
1.8928883511 * eV,
1.8957826758 * eV,
1.8986858652 * eV,
1.9015979601 * eV,
1.9045190015 * eV,
1.9074490308 * eV,
1.9103880894 * eV,
1.9133362191 * eV,
1.9162934621 * eV,
1.9192598607 * eV,
1.9222354574 * eV,
1.925220295 * eV,
1.9282144168 * eV,
1.931217866 * eV,
1.9342306864 * eV,
1.9372529219 * eV,
1.9402846166 * eV,
1.943325815 * eV,
1.946376562 * eV,
1.9494369025 * eV,
1.9525068819 * eV,
1.9555865457 * eV,
1.95867594 * eV,
1.9617751108 * eV,
1.9648841046 * eV,
1.9680029683 * eV,
1.9711317488 * eV,
1.9742704936 * eV,
1.9774192504 * eV,
1.9805780671 * eV,
1.983746992 * eV,
1.9869260737 * eV,
1.9901153612 * eV,
1.9933149035 * eV,
1.9965247504 * eV,
1.9997449516 * eV,
2.0029755574 * eV,
2.0062166181 * eV,
2.0094681848 * eV,
2.0127303084 * eV,
2.0160030407 * eV,
2.0192864332 * eV,
2.0225805383 * eV,
2.0258854085 * eV,
2.0292010966 * eV,
2.0325276557 * eV,
2.0358651396 * eV,
2.039213602 * eV,
2.0425730972 * eV,
2.0459436799 * eV,
2.049325405 * eV,
2.0527183278 * eV,
2.0561225041 * eV,
2.05953799 * eV,
2.0629648419 * eV,
2.0664031167 * eV,
2.0698528715 * eV,
2.0733141639 * eV,
2.0767870519 * eV,
2.080271594 * eV,
2.0837678487 * eV,
2.0872758754 * eV,
2.0907957336 * eV,
2.0943274831 * eV,
2.0978711844 * eV,
2.1014268983 * eV,
2.1049946859 * eV,
2.1085746088 * eV,
2.1121667291 * eV,
2.1157711092 * eV,
2.119387812 * eV,
2.1230169007 * eV,
2.1266584391 * eV,
2.1303124914 * eV,
2.1339791222 * eV,
2.1376583966 * eV,
2.14135038 * eV,
2.1450551384 * eV,
2.1487727383 * eV,
2.1525032465 * eV,
2.1562467304 * eV,
2.1600032578 * eV,
2.163772897 * eV,
2.1675557168 * eV,
2.1713517863 * eV,
2.1751611754 * eV,
2.1789839543 * eV,
2.1828201937 * eV,
2.1866699647 * eV,
2.1905333392 * eV,
2.1944103894 * eV,
2.1983011879 * eV,
2.2022058082 * eV,
2.2061243238 * eV,
2.2100568093 * eV,
2.2140033393 * eV,
2.2179639893 * eV,
2.2219388351 * eV,
2.2259279533 * eV,
2.2299314209 * eV,
2.2339493153 * eV,
2.2379817148 * eV,
2.242028698 * eV,
2.2460903442 * eV,
2.2501667332 * eV,
2.2542579455 * eV,
2.2583640619 * eV,
2.2624851642 * eV,
2.2666213346 * eV,
2.2707726557 * eV,
2.274939211 * eV,
2.2791210846 * eV,
2.283318361 * eV,
2.2875311255 * eV,
2.291759464 * eV,
2.296003463 * eV,
2.3002632096 * eV,
2.3045387918 * eV,
2.308830298 * eV,
2.3131378172 * eV,
2.3174614393 * eV,
2.3218012547 * eV,
2.3261573546 * eV,
2.3305298308 * eV,
2.3349187759 * eV,
2.339324283 * eV,
2.3437464461 * eV,
2.3481853598 * eV,
2.3526411195 * eV,
2.3571138213 * eV,
2.3616035619 * eV,
2.3661104389 * eV,
2.3706345507 * eV,
2.3751759962 * eV,
2.3797348752 * eV,
2.3843112885 * eV,
2.3889053372 * eV,
2.3935171236 * eV,
2.3981467505 * eV,
2.4027943217 * eV,
2.4074599417 * eV,
2.412143716 * eV,
2.4168457505 * eV,
2.4215661523 * eV,
2.4263050294 * eV,
2.4310624902 * eV,
2.4358386444 * eV,
2.4406336024 * eV,
2.4454474753 * eV,
2.4502803755 * eV,
2.4551324158 * eV,
2.4600037103 * eV,
2.4648943738 * eV,
2.4698045219 * eV,
2.4747342715 * eV,
2.47968374 * eV,
2.4846530461 * eV,
2.4896423092 * eV,
2.4946516499 * eV,
2.4996811895 * eV,
2.5047310505 * eV,
2.5098013563 * eV,
2.5148922312 * eV,
2.5200038008 * eV,
2.5251361914 * eV,
2.5302895306 * eV,
2.5354639468 * eV,
2.5406595697 * eV,
2.5458765298 * eV,
2.5511149588 * eV,
2.5563749897 * eV,
2.5616567562 * eV,
2.5669603934 * eV,
2.5722860373 * eV,
2.5776338254 * eV,
2.5830038958 * eV,
2.5883963883 * eV,
2.5938114435 * eV,
2.5992492034 * eV,
2.6047098109 * eV,
2.6101934105 * eV,
2.6157001477 * eV,
2.6212301691 * eV,
2.6267836229 * eV,
2.6323606582 * eV,
2.6379614255 * eV,
2.6435860768 * eV,
2.649234765 * eV,
2.6549076445 * eV,
2.6606048712 * eV,
2.6663266022 * eV,
2.6720729957 * eV,
2.6778442117 * eV,
2.6836404113 * eV,
2.689461757 * eV,
2.695308413 * eV,
2.7011805447 * eV,
2.7070783188 * eV,
2.7130019037 * eV,
2.7189514693 * eV,
2.7249271868 * eV,
2.7309292291 * eV,
2.7369577704 * eV,
2.7430129867 * eV,
2.7490950554 * eV,
2.7552041556 * eV,
2.7613404677 * eV,
2.7675041741 * eV,
2.7736954586 * eV,
2.7799145067 * eV,
2.7861615056 * eV,
2.7924366441 * eV,
2.7987401129 * eV,
2.8050721041 * eV,
2.8114328118 * eV,
2.8178224318 * eV,
2.8242411617 * eV,
2.8306892009 * eV,
2.8371667506 * eV,
2.8436740138 * eV,
2.8502111954 * eV,
2.8567785023 * eV,
2.8633761432 * eV,
2.8700043287 * eV,
2.8766632715 * eV,
2.883353186 * eV,
2.890074289 * eV,
2.8968267991 * eV,
2.9036109368 * eV,
2.9104269249 * eV,
2.9172749882 * eV,
2.9241553538 * eV,
2.9310682506 * eV,
2.93801391 * eV,
2.9449925653 * eV,
2.9520044524 * eV,
2.9590498091 * eV,
2.9661288756 * eV,
2.9732418945 * eV,
2.9803891106 * eV,
2.9875707711 * eV,
2.9947871256 * eV,
3.0020384262 * eV,
3.0093249272 * eV,
3.0166468856 * eV,
3.024004561 * eV,
3.0313982152 * eV,
3.0388281127 * eV,
3.0462945209 * eV,
3.0537977094 * eV,
3.0613379506 * eV,
3.0689155198 * eV,
3.0765306948 * eV,
3.0841837562 * eV,
3.0918749875 * eV,
3.099604675 * eV,
3.1073731078 * eV,
3.1151805779 * eV,
3.1230273804 * eV,
3.1309138131 * eV,
3.1388401772 * eV,
3.1468067766 * eV,
3.1548139186 * eV,
3.1628619133 * eV,
3.1709510742 * eV,
3.1790817179 * eV,
3.1872541645 * eV,
3.1954687371 * eV,
3.2037257623 * eV,
3.2120255699 * eV,
3.2203684935 * eV,
3.2287548698 * eV,
3.2371850392 * eV,
3.2456593455 * eV,
3.2541781365 * eV,
3.2627417632 * eV,
3.2713505805 * eV,
3.2800049471 * eV,
3.2887052255 * eV,
3.2974517819 * eV,
3.3062449867 * eV,
3.3150852139 * eV,
3.3239728418 * eV,
3.3329082527 * eV,
3.3418918329 * eV,
3.350923973 * eV,
3.3600050678 * eV,
3.3691355163 * eV,
3.3783157221 * eV,
3.3875460929 * eV,
3.3968270411 * eV,
3.4061589835 * eV,
3.4155423416 * eV,
3.4249775414 * eV,
3.4344650139 * eV,
3.4440051944 * eV,
3.4535985237 * eV,
3.4632454469 * eV,
3.4729464146 * eV,
3.482701882 * eV,
3.4925123099 * eV,
3.5023781638 * eV,
3.512299915 * eV,
3.5222780398 * eV,
3.5323130199 * eV,
3.5424053429 * eV,
3.5525555014 * eV,
3.5627639943 * eV,
3.5730313256 * eV,
3.5833580058 * eV,
3.5937445507 * eV,
3.6041914826 * eV,
3.6146993294 * eV,
3.6252686257 * eV,
3.635899912 * eV,
3.6465937353 * eV,
3.657350649 * eV,
3.668171213 * eV,
3.6790559941 * eV,
3.6900055655 * eV,
3.7010205075 * eV,
3.7121014072 * eV,
3.7232488589 * eV,
3.7344634639 * eV,
3.7457458308 * eV,
3.7570965758 * eV,
3.7685163222 * eV,
3.7800057012 * eV,
3.7915653517 * eV,
3.8031959202 * eV,
3.8148980615 * eV,
3.8266724383 * eV,
3.8385197214 * eV,
3.8504405901 * eV,
3.8624357321 * eV,
3.8745058438 * eV,
3.8866516301 * eV,
3.898873805 * eV,
3.9111730915 * eV,
3.9235502215 * eV,
3.9360059365 * eV,
3.9485409873 * eV,
3.9611561342 * eV,
3.9738521474 * eV,
3.9866298071 * eV,
3.9994899032 * eV,
4.0124332362 * eV,
4.0254606169 * eV,
4.0385728664 * eV,
4.051770817 * eV,
4.0650553115 * eV,
4.0784272039 * eV,
4.0918873597 * eV,
4.1054366556 * eV,
4.1190759801 * eV,
4.1328062333 * eV,
4.1466283278 * eV,
4.1605431879 * eV,
4.1745517508 * eV,
4.1886549662 * eV,
4.2028537966 * eV,
4.2171492177 * eV,
4.2315422184 * eV,
4.2460338014 * eV,
4.2606249828 * eV,
4.2753167931 * eV,
4.2901102768 * eV,
4.3050064931 * eV,
4.3200065157 * eV,
4.3351114336 * eV,
4.3503223509 * eV,
4.3656403873 * eV,
4.3810666784 * eV,
4.3966023759 * eV,
4.4122486477 * eV,
4.4280066786 * eV,
4.4438776703 * eV,
4.4598628417 * eV,
4.4759634296 * eV,
4.4921806884 * eV,
4.5085158909 * eV,
4.5249703285 * eV,
4.5415453114 * eV,
4.5582421691 * eV,
4.5750622509 * eV,
4.5920069259 * eV,
4.6090775836 * eV,
4.6262756343 * eV,
4.6436025094 * eV,
4.6610596617 * eV,
4.678648566 * eV,
4.6963707197 * eV,
4.7142276426 * eV,
4.7322208779 * eV,
4.7503519923 * eV,
4.7686225769 * eV,
4.7870342471 * eV,
4.8055886434 * eV,
4.8242874319 * eV,
4.8431323047 * eV,
4.8621249804 * eV,
4.8812672047 * eV,
4.900560751 * eV,
4.9200074206 * eV,
4.9396090438 * eV,
4.95936748 * eV,
4.9792846185 * eV,
4.999362379 * eV,
5.0196027126 * eV,
5.0400076016 * eV,
5.0605790612 * eV,
5.0813191393 * eV,
5.1022299177 * eV,
5.1233135124 * eV,
5.1445720747 * eV,
5.1660077917 * eV,
5.187622887 * eV,
5.2094196218 * eV,
5.2314002954 * eV,
5.2535672458 * eV,
5.2759228511 * eV,
5.2984695299 * eV,
5.3212097425 * eV,
5.3441459914 * eV,
5.3672808225 * eV,
5.3906168261 * eV,
5.4141566376 * eV,
5.4379029386 * eV,
5.4618584581 * eV,
5.4860259735 * eV,
5.5104083111 * eV,
5.5350083482 * eV,
5.5598290135 * eV,
5.5848732883 * eV,
5.6101442081 * eV,
5.6356448636 * eV,
5.6613784018 * eV,
5.6873480275 * eV,
5.7135570046 * eV,
5.7400086574 * eV,
5.7667063721 * eV,
5.7936535981 * eV,
5.8208538498 * eV,
5.8483107075 * eV,
5.8760278199 * eV,
5.9040089048 * eV,
5.9322577512 * eV,
5.9607782212 * eV,
5.9895742512 * eV,
6.0186498544 * eV,
6.048009122 * eV,
6.0776562255 * eV,
6.1075954187 * eV,
6.1378310396 * eV,
6.1683675124 * eV,
6.19920935 * eV

    };
    G4double PbWO_FAST_COMPONENT[PbWO_NUMENTRIES_1] = {
        5.483032797e-45	, 1.102767892e-44	, 2.212389792e-44	, 4.427447731e-44	, 8.838112051e-44	, 1.759866919e-43	, 3.495541125e-43	, 6.925693504e-43	,
        1.368757096e-42	, 2.698384064e-42	, 5.30634407e-42	, 1.040881558e-41	, 2.036673839e-41	, 3.975171954e-41	, 7.739352331e-41	, 1.503029763e-40	,
        2.9116878e-40	, 5.626473746e-40	, 1.0845312e-39	, 2.085268909e-39	, 3.999413879e-39	, 7.651470258e-39	, 1.460184397e-38	, 2.779615829e-38	,
        5.278081751e-38	, 9.997276711e-38	, 1.888867861e-37	, 3.559882839e-37	, 6.692433996e-37	, 1.255008745e-36	, 2.347597679e-36	, 4.380410936e-36	,
        8.153053674e-36	, 1.513700701e-35	, 2.803328463e-35	, 5.178717548e-35	, 9.542995673e-35	, 1.754128855e-34	, 3.216270167e-34	, 5.882444195e-34	,
        1.073191868e-33	, 1.953040252e-33	, 3.545351334e-33	, 6.41980191e-33	, 1.159573389e-32	, 2.089243772e-32	, 3.754864386e-32	, 6.731528054e-32	,
        1.203780566e-31	, 2.147312534e-31	, 3.820827706e-31	, 6.78162722e-31	, 1.2006727e-30	, 2.120457745e-30	, 3.735501138e-30	, 6.564208803e-30	,
        1.150615354e-29	, 2.011834294e-29	, 3.508879971e-29	, 6.104626279e-29	, 1.059409627e-28	, 1.833931086e-28	, 3.166768911e-28	, 5.454613679e-28	,
        9.371862012e-28	, 1.606208936e-27	, 2.745948916e-27	, 4.682708604e-27	, 7.965555664e-27	, 1.351603427e-26	, 2.287687795e-26	, 3.862411043e-26	,
        6.5048081e-26	, 1.092759904e-25	, 1.831172584e-25	, 3.060892433e-25	, 5.103652797e-25	, 8.488450867e-25	, 1.408283272e-24	, 2.330589932e-24	,
        3.847299313e-24	, 6.335200261e-24	, 1.04058841e-23 ,  1.704950933e-23	, 2.786500011e-23	, 4.542767156e-23	, 7.387477464e-23	, 1.198356745e-22	,
        1.939055966e-22	, 3.129744085e-22	, 5.038967697e-22	, 8.092609511e-22	, 1.296432351e-21	, 2.071692997e-21	, 3.30228993e-21	, 5.250724915e-21	,
8.327940162e-21	,
1.317559357e-20	,
2.07929949e-20	,
3.2732424e-20	,
5.139886786e-20	,
8.050877189e-20	,
1.257902888e-19	,
1.960492976e-19	,
3.047879065e-19	,
4.726551941e-19	,
7.311481788e-19	,
1.128185813e-18	,
1.736481374e-18	,
2.666084368e-18	,
4.083117816e-18	,
6.237695898e-18	,
9.50540769e-18	,
1.444879279e-17	,
2.190819718e-17	,
3.313568728e-17	,
4.999189374e-17	,
7.523457259e-17	,
1.129404702e-16	,
1.691203966e-16	,
2.526135542e-16	,
3.763843645e-16	,
5.593978107e-16	,
8.293239635e-16	,
1.226427643e-15	,
1.809147226e-15	,
2.662074186e-15	,
3.907335126e-15	,
5.720782451e-15	,
8.354961785e-15	,
1.217160267e-14	,
1.768745424e-14	,
2.563876818e-14	,
3.70717635e-14	,
5.346918936e-14	,
7.692689753e-14	,
1.103994982e-13	,
1.580411731e-13	,
2.256771839e-13	,
3.214543645e-13	,
4.567360204e-13	,
6.473295969e-13	,
9.151661085e-13	,
1.290591072e-12	,
1.815480751e-12	,
2.547468979e-12	,
3.565664062e-12	,
4.978358953e-12	,
6.933399971e-12	,
9.63209074e-12	,
1.334778307e-11	,
1.845066308e-11	,
2.544070141e-11	,
3.499132974e-11	,
4.800716685e-11	,
6.570009091e-11	,
8.96891954e-11	,
1.221317413e-10	,
1.658942122e-10	,
2.247750916e-10	,
3.037941425e-10	,
4.095669202e-10	,
5.507881812e-10	,
7.388539793e-10	,
9.886598203e-10	,
1.319621602e-09	,
1.756977547e-09	,
2.333443399e-09	,
3.09131025e-09	,
4.085095189e-09	,
5.384880021e-09	,
7.080503565e-09	,
9.286809223e-09	,
1.215019271e-08	,
1.585674608e-08	,
2.064235494e-08	,
2.680517672e-08	,
3.472101177e-08	,
4.486217581e-08	,
5.782059518e-08	,
7.433597574e-08	,
9.533004516e-08	,
1.219480373e-07	,
1.55608779e-07	,
1.980649546e-07	,
2.514753644e-07	,
3.184912589e-07	,
4.023591228e-07	,
5.070426033e-07	,
6.373666191e-07	,
7.991870553e-07	,
9.995898353e-07	,
1.247123565e-06	,
1.552070353e-06	,
1.926759837e-06	,
2.385931827e-06	,
2.947153388e-06	,
3.631296515e-06	,
4.463082859e-06	,
5.471702172e-06	,
6.691511288e-06	,
8.162820438e-06	,
9.93277357e-06	,
1.205632901e-05	,
1.459734629e-05	,
1.762978412e-05	,
2.123901353e-05	,
2.552324872e-05	,
3.059509651e-05	,
3.658322314e-05	,
4.363413475e-05	,
5.191406478e-05	,
6.161095842e-05	,
7.293654023e-05	,
8.612844695e-05	,
0.0001015	,
0.0001192	,
0.0001397	,
0.0001633	,
0.0001905	,
0.0002216	,
0.0002571	,
0.0002976	,
0.0003436	,
0.0003958	,
0.0004547	,
0.0005210	,
0.0005956	,
0.0006791	,
0.0007725	,
0.0008764	,
0.0009919	,
0.0011197	,
0.0012609	,
0.0014164	,
0.0015870	,
0.0017737	,
0.0019775	,
0.0021992	,
0.0024396	,
0.0026995	,
0.0029797	,
0.0032808	,
0.0036032	,
0.0039475	,
0.0043139	,
0.0047025	,
0.0051132	,
0.0055460	,
0.0060005	,
0.0064759	,
0.0069715	,
0.0074864	,
0.0080192	,
0.0085684	,
0.0091325	,
0.0097093	,
0.0102968	,
0.0108926	,
0.0114941	,
0.0120985	,
0.0127030	,
0.0133043	,
0.0138992	,
0.0144846	,
0.0150569	,
0.0156127	,
0.0161486	,
0.0166612	,
0.0171472	,
0.0176033	,
0.0180263	,
0.0184135	,
0.0187620	,
0.0190694	,
0.0193334	,
0.0195521	,
0.0197240	,
0.0198476	,
0.0199222	,
0.0199471	,
0.0199222	,
0.0198476	,
0.0197240	,
0.0195521	,
0.0193334	,
0.0190694	,
0.0187620	,
0.0184135	,
0.0180263	,
0.0176033	,
0.0171472	,
0.0166612	,
0.0161486	,
0.0156127	,
0.0150569	,
0.0144846	,
0.0138992	,
0.0133043	,
0.0127030	,
0.0120985	,
0.0114941	,
0.0108926	,
0.0102968	,
0.0097093	,
0.0091325	,
0.0085684	,
0.0080192	,
0.0074864	,
0.0069715	,
0.0064759	,
0.0060005	,
0.0055460	,
0.0051132	,
0.0047025	,
0.0043139	,
0.0039475	,
0.0036032	,
0.0032808	,
0.0029797	,
0.0026995	,
0.0024396	,
0.0021992	,
0.0019775	,
0.0017737	,
0.0015870	,
0.0014164	,
0.0012609	,
0.0011197	,
0.0009919	,
0.0008764	,
0.0007725	,
0.0006791	,
0.0005956	,
0.0005210	,
0.0004547	,
0.0003958	,
0.0003436	,
0.0002976	,
0.0002571	,
0.0002216	,
0.0001905	,
0.0001633	,
0.0001397	,
0.0001192	,
0.0001015	,
8.612844695e-05	,
7.293654023e-05	,
6.161095842e-05	,
5.191406478e-05	,
4.363413475e-05	,
3.658322314e-05	,
3.059509651e-05	,
2.552324872e-05	,
2.123901353e-05	,
1.762978412e-05	,
1.459734629e-05	,
1.205632901e-05	,
9.93277357e-06	,
8.162820438e-06	,
6.691511288e-06	,
5.471702172e-06	,
4.463082859e-06	,
3.631296515e-06	,
2.947153388e-06	,
2.385931827e-06	,
1.926759837e-06	,
1.552070353e-06	,
1.247123565e-06	,
9.995898353e-07	,
7.991870553e-07	,
6.373666191e-07	,
5.070426033e-07	,
4.023591228e-07	,
3.184912589e-07	,
2.514753644e-07	,
1.980649546e-07	,
1.55608779e-07	,
1.219480373e-07	,
9.533004516e-08	,
7.433597574e-08	,
5.782059518e-08	,
4.486217581e-08	,
3.472101177e-08	,
2.680517672e-08	,
2.064235494e-08	,
1.585674608e-08	,
1.215019271e-08	,
9.286809223e-09	,
7.080503565e-09	,
5.384880021e-09	,
4.085095189e-09	,
3.09131025e-09	,
2.333443399e-09	,
1.756977547e-09	,
1.319621602e-09	,
9.886598203e-10	,
7.388539793e-10	,
5.507881812e-10	,
4.095669202e-10	,
3.037941425e-10	,
2.247750916e-10	,
1.658942122e-10	,
1.221317413e-10	,
8.96891954e-11	,
6.570009091e-11	,
4.800716685e-11	,
3.499132974e-11	,
2.544070141e-11	,
1.845066308e-11	,
1.334778307e-11	,
9.63209074e-12	,
6.933399971e-12	,
4.978358953e-12	,
3.565664062e-12	,
2.547468979e-12	,
1.815480751e-12	,
1.290591072e-12	,
9.151661085e-13	,
6.473295969e-13	,
4.567360204e-13	,
3.214543645e-13	,
2.256771839e-13	,
1.580411731e-13	,
1.103994982e-13	,
7.692689753e-14	,
5.346918936e-14	,
3.70717635e-14	,
2.563876818e-14	,
1.768745424e-14	,
1.217160267e-14	,
8.354961785e-15	,
5.720782451e-15	,
3.907335126e-15	,
2.662074186e-15	,
1.809147226e-15	,
1.226427643e-15	,
8.293239635e-16	,
5.593978107e-16	,
3.763843645e-16	,
2.526135542e-16	,
1.691203966e-16	,
1.129404702e-16	,
7.523457259e-17	,
4.999189374e-17	,
3.313568728e-17	,
2.190819718e-17	,
1.444879279e-17	,
9.50540769e-18	,
6.237695898e-18	,
4.083117816e-18	,
2.666084368e-18	,
1.736481374e-18	,
1.128185813e-18	,
7.311481788e-19	,
4.726551941e-19	,
3.047879065e-19	,
1.960492976e-19	,
1.257902888e-19	,
8.050877189e-20	,
5.139886786e-20	,
3.2732424e-20	,
2.07929949e-20	,
1.317559357e-20	,
8.327940162e-21	,
5.250724915e-21	,
3.30228993e-21	,
2.071692997e-21	,
1.296432351e-21	,
8.092609511e-22	,
5.038967697e-22	,
3.129744085e-22	,
1.939055966e-22	,
1.198356745e-22	,
7.387477464e-23	,
4.542767156e-23	,
2.786500011e-23	,
1.704950933e-23	,
1.04058841e-23	,
6.335200261e-24	,
3.847299313e-24	,
2.330589932e-24	,
1.408283272e-24	,
8.488450867e-25	,
5.103652797e-25	,
3.060892433e-25	,
1.831172584e-25	,
1.092759904e-25	,
6.5048081e-26	,
3.862411043e-26	,
2.287687795e-26	,
1.351603427e-26	,
7.965555664e-27	,
4.682708604e-27	,
2.745948916e-27	,
1.606208936e-27	,
9.371862012e-28	,
5.454613679e-28	,
3.166768911e-28	,
1.833931086e-28	,
1.059409627e-28	
    };

    G4double PbWO_indexZero     = 1.5861;
    G4double PbWO_nVec[1]       = { 1.1062 };
    G4double PbWO_lVec[1]       = { 270.63 };

    const G4int PbWO_NUMENTRIES_2 = 5;
    G4double PbWO_RIND_Energy[PbWO_NUMENTRIES_2]      = { 0.0001 * eV, 1.0 * eV, 1.84 * eV, 2.952 * eV, 4.08 * eV };
    //G4double PbWO_RIND_INDEX[PbWO_NUMENTRIES_2]       = { 2.325, 2.325, 2.325, 2.325, 2.325};
    //G4double PbWO_RIND_INDEX[PbWO_NUMENTRIES_2]       = { 2.368, 2.368, 2.368, 2.368, 2.368};

    int sizeVect = sizeof(PbWO_nVec)/sizeof(*PbWO_nVec);
    G4double PbWO_RIND_INDEX[PbWO_NUMENTRIES_2]       = {
    CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(0.0001)),
    CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(1.0)),
    CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(1.84)),
    CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(2.952)),
    CalculateSellmeier(sizeVect,PbWO_indexZero,PbWO_nVec,PbWO_lVec,fromEvToNm(4.08)),
    };

    const G4int PbWO_ABS_entries = 70;
    G4double PbWO_ABS_Energy[PbWO_ABS_entries]       = {
        1.25237 * eV, 1.26514 * eV, 1.27819 * eV, 1.2915 * eV, 1.3051 * eV, 1.31898 * eV, 1.33316 * eV, 1.34765 * eV, 1.36246 * eV, 1.3776 * eV,
        1.39308 * eV, 1.40891 * eV, 1.42511 * eV, 1.44168 * eV, 1.45864 * eV, 1.476 * eV, 1.49379 * eV, 1.512 * eV, 1.53067 * eV, 1.5498 * eV,
        1.56942 * eV, 1.58954 * eV, 1.61018 * eV, 1.63137 * eV, 1.65312 * eV, 1.67546 * eV, 1.69841 * eV, 1.722 * eV, 1.74626 * eV, 1.7712 * eV,
        1.79687 * eV, 1.8233 * eV, 1.85051 * eV, 1.87855 * eV, 1.90745 * eV, 1.93725 * eV, 1.968 * eV, 1.99974 * eV, 2.03253 * eV, 2.0664 * eV,
        2.10143 * eV, 2.13766 * eV, 2.17516 * eV, 2.214 * eV, 2.25426 * eV, 2.296 * eV, 2.33932 * eV, 2.38431 * eV, 2.43106 * eV, 2.47968 * eV,
        2.53029 * eV, 2.583 * eV, 2.63796 * eV, 2.69531 * eV, 2.7552 * eV, 2.81782 * eV, 2.88335 * eV, 2.952 * eV, 3.024 * eV, 3.0996 * eV,
        3.17908 * eV, 3.26274 * eV, 3.35092 * eV, 3.44401 * eV, 3.54241 * eV, 3.64659 * eV, 3.7571 * eV, 3.87451 * eV, 3.99949 * eV, 4.13281 * eV
    };

    G4double PbWO_ABS_LENGTH[PbWO_ABS_entries] = {
        3110 * mm, 3110 * mm, 3110 * mm, 3110 * mm, 3110 * mm, 3105 * mm, 3105 * mm, 3105 * mm, 3105 * mm, 3105 * mm,
        3105 * mm, 2745 * mm, 2460 * mm, 2230 * mm, 2039 * mm, 1877 * mm, 1859 * mm, 1826 * mm, 1764 * mm, 1760 * mm,
        1664 * mm, 1585 * mm, 1471 * mm, 1376 * mm, 1272 * mm, 1187 * mm, 1114 * mm, 1046 * mm, 993.2 * mm, 942.9 * mm,
        898.8 * mm, 856.9 * mm, 821.7 * mm, 794.2 * mm, 767.7 * mm, 746.5 * mm, 725.6 * mm, 710.7 * mm, 695.3 * mm, 686.2 * mm,
        674.8 * mm, 663.5 * mm, 648.3 * mm, 633.4 * mm, 622.3 * mm, 607.8 * mm, 590.9 * mm, 568.9 * mm, 541.4 * mm, 502.9 * mm,
        467 * mm, 430.2 * mm, 390.1 * mm, 345.3 * mm, 298.9 * mm, 256.7 * mm, 219.8 * mm, 185.4 * mm, 150.9 * mm, 116.4 * mm,
        84.8 * mm, 59.4 * mm, 41.1 * mm, 27.5 * mm, 24.2 * mm, 24.2 * mm, 24.3 * mm, 24.3 * mm, 24.4 * mm, 24.6 * mm
    };
    
    const G4int PbWO_SCY_NUMENTRIES = 12;
    G4double PbWO_SCY_Energy[PbWO_SCY_NUMENTRIES] = { 0.000 * MeV, 0.015 * MeV, 0.020 * MeV, 0.030 * MeV, 0.040 * MeV, 0.060 * MeV,
            0.080 * MeV, 0.090 * MeV, 0.105 * MeV, 0.300 * MeV, 0.500 * MeV, 1.000 * MeV};
    G4double PbWO_SCY[PbWO_SCY_NUMENTRIES] = { 0.10, 0.46, 0.60, 0.68, 0.74, 0.80, 0.82,
            0.84, 0.87,  0.96,  0.98,  1.00};
    for (int i = 0; i < PbWO_SCY_NUMENTRIES; i++) {
        PbWO_SCY[i] = 60000.0 * MeV * PbWO_SCY[i] * PbWO_SCY_Energy[i];
    }
    
    /*
    const G4int PbWO_ABS_entries = 4;
    G4double PbWO_ABS_Energy[PbWO_ABS_entries]       = { 0.0001 * eV, 1.0 * eV, 1.84 * eV, 4.08 * eV };
    G4double PbWO_ABS_LENGTH[PbWO_ABS_entries] 	= { 185.4 * mm, 185.4 * mm, 185.4 * mm, 185.4 * mm};
    //G4double PbWO_ABS_LENGTH[PbWO_ABS_entries] 	= { 5 * mm, 5 * mm, 5 * mm, 5 * mm};
    */
    
    G4MaterialPropertiesTable *PbWO_mt = new G4MaterialPropertiesTable();
    
    PbWO_mt->AddProperty ("FASTCOMPONENT", PbWO_FAST_Energy, PbWO_FAST_COMPONENT, PbWO_NUMENTRIES_1);
    PbWO_mt->AddProperty ("RINDEX",        PbWO_RIND_Energy, PbWO_RIND_INDEX,     PbWO_NUMENTRIES_2);
    PbWO_mt->AddProperty ("ABSLENGTH",      PbWO_ABS_Energy,  PbWO_ABS_LENGTH,  PbWO_ABS_entries);
    PbWO_mt->AddProperty ("ELECTRONSCINTILLATIONYIELD", PbWO_SCY_Energy, PbWO_SCY, PbWO_SCY_NUMENTRIES);
    
    PbWO_mt->AddConstProperty ("SCINTILLATIONYIELD", 60000. / MeV);
    PbWO_mt->AddConstProperty ("RESOLUTIONSCALE", 3.2);
    PbWO_mt->AddConstProperty ("FASTTIMECONSTANT", 40.*ns);
    PbWO_mt->AddConstProperty ("YIELDRATIO", 1.0);
    PbWO_mt->AddConstProperty ("FASTSCINTILLATIONRISETIME", 0.1 * ns);

    PbWO->SetMaterialPropertiesTable (PbWO_mt);

    return PbWO;
}



G4double MyMaterials::CalculateSellmeier (int size, G4double indexZero, G4double *nVec, G4double *lVec, G4double wavelength)
{
  /*------http://gentitfx.fr/SLitrani/code/SLitraniCode/TLitSellmeier.html----*/
  
  float partial = indexZero * indexZero;
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += nVec[i] * nVec[i] / (1 - lVec[i] * lVec[i] / (wavelength*wavelength));
  }
  
  partial += sum;
  partial += 1;
  
  G4cout << "Wavelength: " << wavelength << " -> rifr. index: " << sqrt (partial) << G4endl;
  
  return sqrt (partial);
}



G4double MyMaterials::fromEvToNm (G4double energy)
{
  return 1239.84187 / energy;
}

G4double MyMaterials::fromNmToEv (G4double wavelength)
{
  return 1239.84187 / wavelength;
}
