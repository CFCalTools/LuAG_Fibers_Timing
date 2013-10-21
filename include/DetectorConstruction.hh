// Martin Goettlich @ DESY
//

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "ConfigFile.hh"
#include "TString.h"

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4OpBoundaryProcess.hh"
#include "TGraph.h" 


class DetectorConstruction : public G4VUserDetectorConstruction
{
	public:
		DetectorConstruction();
   	~DetectorConstruction();
    
    // World dimensions
    G4double expHall_x;
    G4double expHall_y;
    G4double expHall_z;
    
    // Crystal parameters
    G4double fiber_l;
    G4double fiber_r;    
    
    G4double depth;
    
    G4double gap_l;
		G4int    gap_material;
		
		G4double win_r;
		G4double win_l;
		G4int    win_material;
		
		G4double det_d;
 		G4double det_distance;
		G4int    det_material;
    
		G4int    crystal_material;
 		G4int    crystal_lightyield;
 		G4double crystal_risetime;
 		G4double crystal_abslength;
 		G4double crystal_induced_abslength;

		//Materials
		G4Material* ScMaterial;
		G4Material* GaMaterial;
		G4Material* WiMaterial;
		G4Material* DeMaterial;
		    
    G4VPhysicalVolume* Construct();
    		
		TGraph* gAbsorption;
     
    //
		// Update geometry
		// 
    void     UpdateGeometry();
    G4bool   GetUpdated() const;
    G4bool 	 updated;
    
    //DetectorMessenger* detectorMessenger;
		void readConfigFile(string configFileName);
		void initializeMaterials();
};

#endif /*DetectorConstruction_h*/
