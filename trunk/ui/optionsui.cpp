#include <GLICT/globals.h>
#include <GLICT/types.h>
#include <GLICT/window.h>
#include <GLICT/panel.h>
#include <GLICT/button.h>
#include <GLICT/textbox.h>

#include "../options.h"
#include "options.h"
#include "gamemode.h"


void winOptions_t::initiateAll(glictContainer* desktop)
{
	/* ******************* OPTIONS ************************* */
	desktop->AddObject(&window);
	btnGeneral.SetOnClick(winOptions_t::winOptions_btnGeneral_OnClick);
	btnConsole.SetOnClick(winOptions_t::winOptions_btnConsole_OnClick);
	btnGraphics.SetOnClick(winOptions_t::winOptions_btnGraphics_OnClick);
	btnNetwork.SetOnClick(winOptions_t::winOptions_btnNetwork_OnClick);
	btnMotd.SetOnClick(winOptions_t::winOptions_btnMotd_OnClick);
	btnOk.SetOnClick(winOptions_t::winOptions_btnOk_OnClick);

	/* ***************** OPTIONS/GENERAL ******************** */
	desktop->AddObject(&winOptionsGeneral.window);
	winOptionsGeneral.btnOk.SetOnClick(winOptions_t::winOptionsGeneral_btnOk_OnClick);
	winOptionsGeneral.btnCancel.SetOnClick(winOptions_t::winOptionsGeneral_btnCancel_OnClick);
	winOptionsGeneral.btnHelp.SetOnClick(winOptions_t::btnHelp_OnClick);
	winOptionsGeneral.btnHelp.SetCustomData(new std::string(
		"Classic Control is ...\n"
		"\n"
		"Auto-chase Off turns off automatic chase of any\n"
		"monster you attack.\n"
		"\n"
		"Show hints allows occasional popups with some help\n"
		"during gameplay.\n"
		"\n"
		"Show names determines if there will be floating names\n"
		"above creatures.\n"
		"\n"
		"Show text effects allows you to turn on and off the\n"
		"so-called \"animated text\" effects."
		));

	/* ***************** OPTIONS/CONSOLE ******************** */
	desktop->AddObject(&winOptionsConsole.window);
	winOptionsConsole.btnOk.SetOnClick(winOptions_t::winOptionsConsole_btnOk_OnClick);
	winOptionsConsole.btnCancel.SetOnClick(winOptions_t::winOptionsConsole_btnCancel_OnClick);
	winOptionsConsole.btnHelp.SetOnClick(winOptions_t::btnHelp_OnClick);
	winOptionsConsole.btnHelp.SetCustomData(new std::string(
		"Help not done."
		));

	/* ***************** OPTIONS/GRAPHICS ******************** */
	desktop->AddObject(&winOptionsGraphics.window);
	winOptionsGraphics.btnOk.SetOnClick(winOptions_t::winOptionsGraphics_btnOk_OnClick);
	winOptionsGraphics.btnCancel.SetOnClick(winOptions_t::winOptionsGraphics_btnCancel_OnClick);
	winOptionsGraphics.btnHelp.SetOnClick(winOptions_t::btnHelp_OnClick);
	winOptionsGraphics.btnHelp.SetCustomData(new std::string(

		"Fullscreen decides whether or not the client will\n"
		"be taking the entire screen.\n"
		"\n"
		"Available resolutions shows detected resolutions on\n"
		"your computer that the client can use while in fullscreen."
		));
	winOptionsGraphics.btnAdvancedSettings.SetOnClick(winOptions_t::winOptionsGraphics_btnAdvanced_OnClick);

	/* ************ OPTIONS/ADVANCED GRAPHICS *************** */
	desktop->AddObject(&winOptionsGraphicsAdvanced.window);
	winOptionsGraphicsAdvanced.btnOk.SetOnClick(winOptions_t::winOptionsGraphicsAdvanced_btnOk_OnClick);
	winOptionsGraphicsAdvanced.btnCancel.SetOnClick(winOptions_t::winOptionsGraphicsAdvanced_btnCancel_OnClick);
	winOptionsGraphicsAdvanced.btnHelp.SetOnClick(winOptions_t::btnHelp_OnClick);
	winOptionsGraphicsAdvanced.btnHelp.SetCustomData(new std::string(
		// TODO (nfries88)
		"TODO"
		));

	/* ***************** OPTIONS/NETWORK ******************** */
	desktop->AddObject(&winOptionsNetwork.window);
	winOptionsNetwork.btnOk.SetOnClick(winOptions_t::winOptionsNetwork_btnOk_OnClick);
	winOptionsNetwork.btnCancel.SetOnClick(winOptions_t::winOptionsNetwork_btnCancel_OnClick);
	winOptionsNetwork.btnHelp.SetOnClick(winOptions_t::btnHelp_OnClick);
	winOptionsNetwork.btnHelp.SetCustomData(new std::string(
		"Server name is the IP address or hostname of the\n"
		"login server.\n"
		"\n"
		"Port is the TCP port of the login server.\n"
		"\n"
		"You can also choose if you'd like to access OpenTibia\n"
		"servers, or a proprietary server. To access OpenTibia\n"
		"servers, turn on the OT Encryption Key option."
		));
}

void winOptions_t::btnHelp_OnClick(glictPos* relmousepos, glictContainer* callerclass) {
	std::string *helptext = (std::string*)callerclass->GetCustomData();
	g_game->msgBox(helptext->c_str(), "Help", callerclass);
}

void winOptions_t::winOptions_btnGeneral_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(false);
	winOptions->winOptionsGeneral.Init();
	winOptions->winOptionsGeneral.window.SetVisible(true);
	winOptions->winOptionsGeneral.window.Focus(NULL);
}

void winOptions_t::winOptions_btnConsole_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(false);
	winOptions->winOptionsConsole.Init();
	winOptions->winOptionsConsole.window.SetVisible(true);
	winOptions->winOptionsConsole.window.Focus(NULL);
}

void winOptions_t::winOptions_btnGraphics_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(false);
	winOptions->winOptionsGraphics.Init();
	winOptions->winOptionsGraphics.window.SetVisible(true);
	winOptions->winOptionsGraphics.window.Focus(NULL);
}

void winOptions_t::winOptions_btnNetwork_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(false);
	winOptions->winOptionsNetwork.Init();
	winOptions->winOptionsNetwork.window.SetVisible(true);
	winOptions->winOptionsNetwork.window.Focus(NULL);
}

void winOptions_t::winOptions_btnMotd_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(false);
	g_game->msgBox(options.motdtext.c_str(), "Message of the Day", &winOptions->window);
}

void winOptions_t::winOptions_btnOk_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(false);
}

/* *********GENERAL********** */
void winOptions_t::winOptionsGeneral_btnOk_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(true);
	winOptions->window.Focus(NULL);
	winOptions->winOptionsGeneral.Store();
	winOptions->winOptionsGeneral.window.SetVisible(false);
}

void winOptions_t::winOptionsGeneral_btnCancel_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(true);
	winOptions->window.Focus(NULL);
	winOptions->winOptionsGeneral.window.SetVisible(false);
}

/* *********CONSOLE********** */
void winOptions_t::winOptionsConsole_btnOk_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(true);
	winOptions->window.Focus(NULL);
	winOptions->winOptionsConsole.Store();
	winOptions->winOptionsConsole.window.SetVisible(false);
}

void winOptions_t::winOptionsConsole_btnCancel_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(true);
	winOptions->window.Focus(NULL);
	winOptions->winOptionsConsole.window.SetVisible(false);
}

/* *********GRAPHICS********** */
void winOptions_t::winOptionsGraphics_btnOk_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(true);
	winOptions->window.Focus(NULL);
	winOptions->winOptionsGraphics.Store();
	winOptions->winOptionsGraphics.window.SetVisible(false);
}

void winOptions_t::winOptionsGraphics_btnCancel_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(true);
	winOptions->window.Focus(NULL);
	winOptions->winOptionsGraphics.window.SetVisible(false);
}

void winOptions_t::winOptionsGraphics_btnAdvanced_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->winOptionsGraphics.window.SetVisible(false);
	winOptions->winOptionsGraphicsAdvanced.Init();
	winOptions->winOptionsGraphicsAdvanced.window.SetVisible(true);
	winOptions->winOptionsGraphicsAdvanced.window.Focus(NULL);
}

/* *********ADVANCED GRAPHICS********** */
void winOptions_t::winOptionsGraphicsAdvanced_btnOk_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->winOptionsGraphics.window.SetVisible(true);
	winOptions->winOptionsGraphics.window.Focus(NULL);
	winOptions->winOptionsGraphicsAdvanced.Store();
	#if 0
	if (e != options.engine || w != options.w || h != options.h || bpp != options.bpp || fs != options.fullscreen) {
		switch(options.engine) {
			case ENGINE_OPENGL:
				g_engine = new EngineGL;
				break;
			/*
			case ENGINE_DIRECTX:
				g_engine = new EngineDX;
				break;
			*/
			default:
				DEBUGPRINT(DEBUGPRINT_LEVEL_OBLIGATORY, DEBUGPRINT_WARNING, "Unknown engine was selected. Falling back to SDL.");
				options.engine = ENGINE_SDL;
			case ENGINE_SDL:
				g_engine = new EngineSDL;
				break;
		}

		if(!g_engine->isSupported()){
			DEBUGPRINT(DEBUGPRINT_LEVEL_OBLIGATORY, DEBUGPRINT_WARNING, "The selected graphics engine is not supported. Falling back to SDL.");
			delete g_engine;
			options.engine = ENGINE_SDL;
			g_engine = new EngineSDL;
		}
	}
	#else
    if (winOptions->winOptionsGraphicsAdvanced.activeEngine != winOptions->winOptionsGraphicsAdvanced.activeEngineOriginal)
        g_game->msgBox("Restart is required to apply engine change.", "Engine change");
	#endif
	winOptions->winOptionsGraphicsAdvanced.window.SetVisible(false);

}

void winOptions_t::winOptionsGraphicsAdvanced_btnCancel_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->winOptionsGraphics.window.SetVisible(true);
	winOptions->winOptionsGraphics.window.Focus(NULL);
	winOptions->winOptionsGraphicsAdvanced.window.SetVisible(false);
}

/* *********NETWORK********** */
void winOptions_t::winOptionsNetwork_btnOk_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(true);
	winOptions->window.Focus(NULL);
	winOptions->winOptionsNetwork.Store();
	winOptions->winOptionsNetwork.window.SetVisible(false);
}

void winOptions_t::winOptionsNetwork_btnCancel_OnClick(glictPos* relmousepos, glictContainer* callerclass)
{
	winOptions_t* winOptions = g_game->getOptionsWindow();
	winOptions->window.SetVisible(true);
	winOptions->window.Focus(NULL);
	winOptions->winOptionsNetwork.window.SetVisible(false);
}