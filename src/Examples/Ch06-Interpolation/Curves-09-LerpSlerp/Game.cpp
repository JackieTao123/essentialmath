//===============================================================================
// @ Game.cpp
// ------------------------------------------------------------------------------
// Game core routines
//
// Copyright (C) 2008-2015 by James M. Van Verth and Lars M. Bishop.
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
//===============================================================================

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include <IvClock.h>
#include <IvRenderer.h>
#include <IvRendererHelp.h>
#include <IvVector4.h>

#include "Game.h"
#include "Player.h"

//-------------------------------------------------------------------------------
//-- Static Members -------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Methods --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ IvGame::Create()
//-------------------------------------------------------------------------------
// Static constructor
//-------------------------------------------------------------------------------
bool
IvGame::Create()
{
    IvGame::mGame = new Game();
    return ( IvGame::mGame != 0 );

}   // End of IvGame::Create()


//-------------------------------------------------------------------------------
// @ Game::Game()
//-------------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------------
Game::Game() : IvGame()
{
    // init variables
    mPlayer = 0;            // main player object

}   // End of Game::Game()


//-------------------------------------------------------------------------------
// @ Game::~Game()
//-------------------------------------------------------------------------------
// Destructor
//-------------------------------------------------------------------------------
Game::~Game()
{
    delete mPlayer;
    mPlayer = 0;

}   // End of Game::~Game()


//-------------------------------------------------------------------------------
// @ Game::PostRendererInitialize()
//-------------------------------------------------------------------------------
// Set up internal subsystems
//-------------------------------------------------------------------------------
bool 
Game::PostRendererInitialize()
{
    // Set up base class 
    if ( !IvGame::PostRendererInitialize() )
        return false;
    
    mPlayer = new Player();
    if (!mPlayer)
        return false;

    IvSetDefaultLighting();

    return true;
}   // End of Game::PostRendererInitialize()


//-------------------------------------------------------------------------------
// @ Game::Update()
//-------------------------------------------------------------------------------
// Main update loop
//-------------------------------------------------------------------------------
void
Game::UpdateObjects( float dt )
{
    // update player
    mPlayer->Update( dt );
    
}   // End of Game::Update()


//-------------------------------------------------------------------------------
// @ Game::Render()
//-------------------------------------------------------------------------------
// Render stuff
//-------------------------------------------------------------------------------
void 
Game::Render()                                  // Here's Where We Do All The Drawing
{   
    // look from (-10, 2, 10) at the origin of the world 
    ::IvSetDefaultViewer( -10.0, 2.0, 10.0 );
    
    // draw the main object
    mPlayer->Render();

    // draw axes
    ::IvDrawAxes();
    
}

