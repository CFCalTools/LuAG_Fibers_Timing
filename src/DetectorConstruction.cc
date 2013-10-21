#include "DetectorConstruction.hh"

#include "CreateTree.hh"
#include "MyMaterials.hh"

#include "TGraph.h"

#include "G4RunManager.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4PVPlacement.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4SDManager.hh"
#include "G4Color.hh"
#include "G4VisAttributes.hh"
#include "G4GeometryManager.hh"
#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4SubtractionSolid.hh"



DetectorConstruction::DetectorConstruction()
{
	// set defaults for geometry and material properties
	//detectorMessenger = new DetectorMessenger(this);
  
	expHall_x = expHall_y = expHall_z = 100*cm;
	
	updated = true;
}



DetectorConstruction::~DetectorConstruction()
{}



G4VPhysicalVolume* DetectorConstruction::Construct()
{
	readConfigFile("crystal.cfg");
	initializeMaterials();
  
	//
	// C O M M O N   V O L U M E S 
	//
	
	/*-------EXPERIMENTAL HALL-------*/
  
  G4Box* expHall_box = new G4Box("World_box",expHall_x,expHall_y,expHall_z);
  G4LogicalVolume* expHall_log = new G4LogicalVolume(expHall_box,MyMaterials::Air(),"World_log",0,0,0);
  G4VPhysicalVolume* expHall_phys = new G4PVPlacement(0,G4ThreeVector(0,0,0),expHall_log,"World",0,false,0);
  
	G4LogicalVolume* fiber_log = NULL;
  G4LogicalVolume* gap_log = NULL;
  G4LogicalVolume* gap_layer_log = NULL;
  G4LogicalVolume* side_log = NULL;
  G4LogicalVolume* win_log = NULL;
  G4LogicalVolume* win_layer_log = NULL;
  G4LogicalVolume* det_log = NULL;
  G4LogicalVolume* det_layer_log = NULL;
  
  G4VPhysicalVolume* fiber_phys = NULL;
  G4VPhysicalVolume* gap_front_phys = NULL;
  G4VPhysicalVolume* gap_rear_phys = NULL;
  G4VPhysicalVolume* gap_layer_front_phys = NULL;
  G4VPhysicalVolume* gap_layer_rear_phys = NULL;
  G4VPhysicalVolume* side_phys = NULL;
	G4VPhysicalVolume* win_front_phys = NULL;
	G4VPhysicalVolume* win_rear_phys = NULL;	
	G4VPhysicalVolume* win_layer_front_phys = NULL;
	G4VPhysicalVolume* win_layer_rear_phys = NULL;
	G4VPhysicalVolume* det_front_phys = NULL;
	G4VPhysicalVolume* det_rear_phys = NULL;
	G4VPhysicalVolume* det_layer_front_phys = NULL;
	G4VPhysicalVolume* det_layer_rear_phys = NULL;
  		  

  //******************************* VISUALIZATION ATTRIBUTES ******************************* //
  
  G4Colour  white  (1.0, 1.0, 1.0);
  G4Colour  gray   (0.5, 0.5, 0.5);
  G4Colour  black  (0.0, 0.0, 0.0);
  G4Colour  red    (1.0, 0.0, 0.0);
  G4Colour  green  (0.0, 1.0, 0.0);
  G4Colour  blue   (0.0, 0.0, 1.0);
  G4Colour  cyan   (0.0, 1.0, 1.0);
  G4Colour  magenta(1.0, 0.0, 1.0);
  G4Colour  yellow (1.0, 1.0, 0.0);
  G4Colour  mine   (0.212, 1.0, 0.0);
    
  //*********************************************************************************************//  
  
  
	/*-------FIBER-------*/
	if( CreateTree::Instance()->Fiber() )
	{   	
    G4Tubs* fiber_box = new G4Tubs("fiber_box",0,fiber_r,0.5*fiber_l,0,360);
    fiber_log = new G4LogicalVolume(fiber_box,ScMaterial,"fiber_log",0,0,0);
    fiber_phys = new G4PVPlacement(0,G4ThreeVector(0,0,0),fiber_log,"fiber",expHall_log,false,0);
    
    G4VisAttributes* VisAttFiber = new G4VisAttributes(mine);
	  VisAttFiber->SetVisibility(true);
    //VisAttFiber->SetForceWireframe(true);
 	  fiber_log->SetVisAttributes(VisAttFiber);	 	  
    
    
    G4Tubs* side_box = new G4Tubs("side_box",fiber_r,fiber_r+depth,0.5*fiber_l,0,360);
	  side_log = new G4LogicalVolume(side_box,MyMaterials::Air(),"side_log",0,0,0);
		side_phys = new G4PVPlacement(0,G4ThreeVector(0,0,0),side_log,"side",expHall_log,false,0);
		
		G4VisAttributes* VisAttSide = new G4VisAttributes(blue);
		VisAttSide->SetVisibility(false);
    //VisAttSide->SetForceWireframe(true);
		side_log->SetVisAttributes(VisAttSide);

	}
	
	
	/*-------GAP-------*/
	if( CreateTree::Instance()->Control() && gap_l > 0. )
  {
    G4Tubs* gap_layer_box = new G4Tubs("gap_layer_box",0,fiber_r+depth,0.5*depth,0,360);
    gap_layer_log = new G4LogicalVolume(gap_layer_box,GaMaterial,"gap_layer_log",0,0,0);
	  gap_layer_front_phys = new G4PVPlacement(0,G4ThreeVector(0.,0.,-0.5*fiber_l-0.5*depth),
	                                           gap_layer_log,"gap_layer_front",expHall_log,false,0);
   	gap_layer_rear_phys  = new G4PVPlacement(0,G4ThreeVector(0.,0.,+0.5*fiber_l+0.5*depth),
   	                                         gap_layer_log,"gap_layer_rear", expHall_log,false,0);
	  
		G4VisAttributes* VisAttGapLayer = new G4VisAttributes(blue);  
		VisAttGapLayer->SetVisibility(false);
    //VisAttGapLayer->SetForceWireframe(true);
		gap_layer_log->SetVisAttributes(VisAttGapLayer);
		
		
    G4Tubs* gap_box = new G4Tubs("gap_box",0,fiber_r+depth,0.5*(gap_l-depth),0,360);
    gap_log = new G4LogicalVolume(gap_box,GaMaterial,"gap_log",0,0,0);
	  gap_front_phys = new G4PVPlacement(0,G4ThreeVector(0.,0.,-0.5*fiber_l-depth-0.5*(gap_l-depth)),gap_log,"gap_front",expHall_log,false,0);
   	gap_rear_phys  = new G4PVPlacement(0,G4ThreeVector(0.,0.,+0.5*fiber_l+depth+0.5*(gap_l-depth)),gap_log,"gap_rear", expHall_log,false,0);
	  
		G4VisAttributes* VisAttGap = new G4VisAttributes(blue);  
		VisAttGap->SetVisibility(false);
    //VisAttGap->SetForceWireframe(true);
		gap_log->SetVisAttributes(VisAttGap);
	}
  
  
  /*-------DETECTOR-------*/
	if( CreateTree::Instance()->Hits() )
	{
   	G4Tubs* win_layer_box = new G4Tubs("win_layer_box",0.0,win_r,0.5*depth,0,360);
	  win_layer_log = new G4LogicalVolume(win_layer_box,WiMaterial,"win_layer_log",0,0,0);
	  win_layer_front_phys = new G4PVPlacement(0,G4ThreeVector(0,0,-0.5*fiber_l-gap_l-det_distance-0.5*depth),
	                                           win_layer_log,"win_layer_front",expHall_log,false,0);
	  win_layer_rear_phys  = new G4PVPlacement(0,G4ThreeVector(0,0,+0.5*fiber_l+gap_l+det_distance+0.5*depth),
	                                           win_layer_log,"win_layer_rear", expHall_log,false,0);
    
		G4VisAttributes* VisAttWinLayer = new G4VisAttributes(gray);
		VisAttWinLayer->SetVisibility(true);
    //VisAttWinLayer->SetForceWireframe(true);
		win_layer_log->SetVisAttributes(VisAttWinLayer);
		
		
   	G4Tubs* win_box = new G4Tubs("win_box",0.0,win_r,0.5*(win_l-depth),0,360);
	  win_log = new G4LogicalVolume(win_box,WiMaterial,"win_log",0,0,0);
	  win_front_phys = new G4PVPlacement(0,G4ThreeVector(0,0,-0.5*fiber_l-gap_l-det_distance-depth-0.5*(win_l-depth)),
	                                     win_log,"win_front",expHall_log,false,0);
	  win_rear_phys  = new G4PVPlacement(0,G4ThreeVector(0,0,+0.5*fiber_l+gap_l+det_distance+depth+0.5*(win_l-depth)),
	                                     win_log,"win_rear", expHall_log,false,0);
    
		G4VisAttributes* VisAttWin = new G4VisAttributes(gray);
		VisAttWin->SetVisibility(true);
    //VisAttWin->SetForceWireframe(true);
		win_log->SetVisAttributes(VisAttWin);
		
		
	  G4Box* det_layer_box = new G4Box("det_layer_box",0.5*det_d,0.5*det_d,0.5*depth);
	  det_layer_log = new G4LogicalVolume(det_layer_box,DeMaterial,"det_layer_log",0,0,0);
	  det_layer_front_phys = new G4PVPlacement(0,G4ThreeVector(0,0,-0.5*fiber_l-gap_l-det_distance-win_l-0.5*depth),
	                                           det_layer_log,"det_layer_front",expHall_log,false,0);
	  det_layer_rear_phys  = new G4PVPlacement(0,G4ThreeVector(0,0,+0.5*fiber_l+gap_l+det_distance+win_l+0.5*depth),
	                                           det_layer_log,"det_layer_rear", expHall_log,false,0);
		
		G4VisAttributes* VisAttDetLayer = new G4VisAttributes(gray);
		VisAttDetLayer->SetVisibility(true);
    VisAttDetLayer->SetForceWireframe(true);
		det_layer_log->SetVisAttributes(VisAttDetLayer);    
		
		
	  G4Box* det_box = new G4Box("det_box",0.5*det_d,0.5*det_d,0.5*(det_d-depth));
	  det_log = new G4LogicalVolume(det_box,DeMaterial,"det_log",0,0,0);
	  det_front_phys = new G4PVPlacement(0,G4ThreeVector(0,0,-0.5*fiber_l-gap_l-det_distance-win_l-depth-0.5*(det_d-depth)),
	                                     det_log,"det_front",expHall_log,false,0);
	  det_rear_phys  = new G4PVPlacement(0,G4ThreeVector(0,0,+0.5*fiber_l+gap_l+det_distance+win_l+depth+0.5*(det_d-depth)),
	                                     det_log,"det_rear", expHall_log,false,0);
		
		G4VisAttributes* VisAttDet = new G4VisAttributes(gray);
		VisAttDet->SetVisibility(true);
    VisAttDet->SetForceWireframe(true);
		det_log->SetVisAttributes(VisAttDet);
	}
  
 	expHall_log->SetVisAttributes(G4VisAttributes::Invisible);
  
	//always return the physical World
 	return expHall_phys;
}



//
// Update geometry
// 
void DetectorConstruction::UpdateGeometry()
{
  	G4cout<<"Updating detector ..."<<G4endl;
  	// clean-up previous geometry
  	G4GeometryManager::GetInstance()->OpenGeometry();
  	G4PhysicalVolumeStore::GetInstance()->Clean();
  	G4LogicalVolumeStore::GetInstance()->Clean();
  	G4SolidStore::GetInstance()->Clean();
  	G4LogicalSkinSurface::CleanSurfaceTable();
  	G4LogicalBorderSurface::CleanSurfaceTable();

  	//define new one
  	G4RunManager::GetRunManager()->DefineWorldVolume(this->Construct());
  	G4RunManager::GetRunManager()->GeometryHasBeenModified();

  	updated=false;
}



G4bool DetectorConstruction::GetUpdated() const { return updated; }


void DetectorConstruction::initializeMaterials()
{
 	// define materials
 	ScMaterial = NULL;
  if     ( crystal_material == 1 ) ScMaterial = MyMaterials::LSO();
  else if( crystal_material == 2 ) ScMaterial = MyMaterials::LYSO();
  else if( crystal_material == 3 ) ScMaterial = MyMaterials::LUAGCE();  
  else if( crystal_material == 4 ) ScMaterial = MyMaterials::LUAGPR();
  else if( crystal_material == 5 ) ScMaterial = MyMaterials::PbWO();
	else if( crystal_material == 6 ) ScMaterial = MyMaterials::Air();
	else if( crystal_material == 7 ) ScMaterial = MyMaterials::Quartz();
  else
	{
    G4cerr << "<DetectorConstruction::Construct>: Invalid material specifier " << crystal_material << G4endl;
   	exit(-1);
  }
  G4cout << "Sc. material: "<< ScMaterial << G4endl;
	
	
	GaMaterial = NULL;
	if     ( gap_material == 1 ) GaMaterial = MyMaterials::Air();
	else if( gap_material == 2 ) GaMaterial = MyMaterials::Water();
	else if( gap_material == 3 ) GaMaterial = MyMaterials::OpticalGrease();
  else
	{
    G4cerr << "<DetectorConstruction::Construct>: Invalid material specifier " << gap_material << G4endl;
   	exit(-1);
  }
  G4cout << "Gap material: " << gap_material << G4endl;
  
  
	WiMaterial = NULL;
	if( win_material == 1 ) WiMaterial = MyMaterials::Quartz();
  else
	{
    G4cerr << "<DetectorConstruction::Construct>: Invalid material specifier " << win_material << G4endl;
   	exit(-1);
  }
  G4cout << "Window material: " << win_material << G4endl;
  
  
	DeMaterial = NULL;
	if( det_material == 1 ) DeMaterial = MyMaterials::Silicon();
  else
	{
    G4cerr << "<DetectorConstruction::Construct>: Invalid material specifier " << det_material << G4endl;
   	exit(-1);
  }
  G4cout << "Detector material: " << det_material << G4endl;	
	
	
	
 	// modify default properties of the scintillator
 	if( crystal_lightyield >= 0 )
	{
    ScMaterial->GetMaterialPropertiesTable()->RemoveConstProperty("SCINTILLATIONYIELD");
    ScMaterial->GetMaterialPropertiesTable()->AddConstProperty("SCINTILLATIONYIELD",crystal_lightyield/MeV);  
    CreateTree::Instance()->LightYield = ScMaterial->GetMaterialPropertiesTable()->GetConstProperty("SCINTILLATIONYIELD");
  } 
	else 
	{
    CreateTree::Instance()->LightYield = ScMaterial->GetMaterialPropertiesTable()->GetConstProperty("SCINTILLATIONYIELD");
  }
  
  
  if( crystal_risetime >= 0 )
	{
    ScMaterial->GetMaterialPropertiesTable()->RemoveConstProperty("FASTSCINTILLATIONRISETIME");
    ScMaterial->GetMaterialPropertiesTable()->AddConstProperty("FASTSCINTILLATIONRISETIME",crystal_risetime/ns);  
    CreateTree::Instance()->RiseTime = ScMaterial->GetMaterialPropertiesTable()->GetConstProperty("FASTSCINTILLATIONRISETIME");
  } 
	else 
	{
    CreateTree::Instance()->RiseTime = ScMaterial->GetMaterialPropertiesTable()->GetConstProperty("FASTSCINTILLATIONRISETIME");
  }
  
  
  if( crystal_abslength >= 0 ) 
	{
    ScMaterial->GetMaterialPropertiesTable()->RemoveProperty("ABSLENGTH");
    ScMaterial->GetMaterialPropertiesTable()->AddConstProperty("ABSLENGTH",crystal_abslength);  
   	CreateTree::Instance()->AbsLength = ScMaterial->GetMaterialPropertiesTable()->GetConstProperty("ABSLENGTH");    
 	} 
	else 
	{
    gAbsorption = new TGraph();
    gAbsorption->SetTitle("gAbsorption");
    gAbsorption->SetName("gAbsorption");
		for(unsigned int j = 0; j < ScMaterial->GetMaterialPropertiesTable()->GetProperty("ABSLENGTH")->GetVectorLength();++j)
		{
		  double energy = ScMaterial->GetMaterialPropertiesTable()->GetProperty("ABSLENGTH")->Energy(j);
      gAbsorption ->SetPoint (j, energy, ScMaterial->GetMaterialPropertiesTable()->GetProperty("ABSLENGTH")->Value(energy)  );
    }
    gAbsorption->Write();
 	}
}



void DetectorConstruction::readConfigFile(string configFileName)
{	
	ConfigFile config(configFileName);
	
  config.readInto(fiber_l,"fiber_l");
  config.readInto(fiber_r,"fiber_r");
  
  config.readInto(depth,"depth");
  
  config.readInto(gap_l,"gap_l");
  config.readInto(gap_material,"gap_material");
  
  config.readInto(win_r,"win_r");
  config.readInto(win_l,"win_l");
  config.readInto(win_material,"win_material");
    
  config.readInto(det_d,"det_d");
  config.readInto(det_distance,"det_distance");
  config.readInto(det_material,"det_material");
    
  config.readInto(crystal_material,"material");
	config.readInto(crystal_risetime,"risetime");
	config.readInto(crystal_abslength,"abslength");
	config.readInto(crystal_lightyield,"lightyield");
}
