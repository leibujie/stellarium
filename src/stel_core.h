/*
 * Copyright (C) 2003 Fabien Ch�reau
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

// Main class for stellarium
// Manage all the objects to be used in the program

#ifndef _STEL_CORE_H_
#define _STEL_CORE_H_

using namespace std;

#include "navigator.h"
#include "stel_object.h"
#include "hip_star_mgr.h"
#include "constellation_mgr.h"
#include "nebula_mgr.h"
#include "stel_atmosphere.h"
#include "tone_reproductor.h"
#include "stel_ui.h"
#include "solarsystem.h"
#include "stel_utility.h"


class stel_core
{
friend class stel_ui;
friend class stel_sdl;
public:
    stel_core();
    virtual ~stel_core();
	void init(void);
	void load_config(void);

	// Set the main data, textures and configuration directories
	void set_directories(char * DDIR, char * TDIR, char * CDIR);

	// Set the 2 config files names.
	void set_config_files(char * config_file, char * location_file);

	void update(int delta_time);		// Update all the objects in function of the time
	void draw(int delta_time);			// Execute all the drawing functions

	// find and select the "nearest" object and retrieve his informations
	stel_object * find_stel_object(int x, int y);
	stel_object * find_stel_object(Vec3d);

	//double get_fov() {return navigation->get_fov();}
private:
	// Read the configuration file
	void loadConfig(char * configFile, char * locationFile);
	// Dump the configuration file
	void dumpConfig(void);
	// Dump the location file
	void dumpLocation(void);

	// Big options
	int screen_W;
	int screen_H;
	int bppMode;
	int Fullscreen;

    //Files location
    char TextureDir[255];
    char ConfigDir[255];
    char DataDir[255];

	int initialized;					// If the core has been initialized or not

	// Main elements of the program
	navigator * navigation;				// Manage all navigation parameters, coordinate transformations etc..
	stel_object * selected_object;		// The selected object in stellarium
	Hip_Star_mgr * hip_stars;			// Manage the hipparcos stars
	Constellation_mgr * asterisms;		// Manage constellations (boundaries, names etc..)
	Nebula_mgr * nebulas;				// Manage the nebulas
	stel_atmosphere * atmosphere;		// Atmosphere
	tone_reproductor * tone_converter;	// Tones conversion between stellarium world and display device
	stel_ui * ui;						// The main User Interface
	draw_utility * du;					// A usefull small class used to pass parameters and handy functions
										// to various drawing functions

    int LandscapeNumber;				// landscape "skin" number

	float fps;
    float sky_brightness;

	// GUI
	vec3_t GuiBaseColor;
	vec3_t GuiTextColor;

	int MaxMagStarName;
	float StarScale;
	float StarTwinkleAmount;

    // Flags
    int FlagUTC_Time;
    int FlagFps;
    int FlagStars;
	int FlagStarName;
    int FlagPlanets;
    int FlagPlanetsHintDrawing;
    int FlagNebula;
    int FlagNebulaName;
    int FlagNebulaCircle; // TODO is this useless?
    int FlagGround;
    int FlagHorizon;
    int FlagFog;
    int FlagAtmosphere;
    int FlagConstellationDrawing;
    int FlagConstellationName;
    int FlagAzimutalGrid;
    int FlagEquatorialGrid;
    int FlagEquator;
    int FlagEcliptic;
    int FlagCardinalPoints;
    int FlagRealMode;
    int FlagRealTime;
    int FlagAcceleredTime;
    int FlagVeryFastTime;
    int FlagMenu;
    int FlagHelp;
    int FlagInfos;
    int FlagMilkyWay;
    int FlagConfig;

	// Load the textures "for non object oriented stuff" TODO : remove that
	void load_base_textures(void);
	s_texture * texIds[200];			// Common Textures TODO : remove that!

};

#endif // _STEL_CORE_H_
