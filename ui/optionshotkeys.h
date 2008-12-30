//////////////////////////////////////////////////////////////////////
// Yet Another Tibia Client
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#ifndef __UI_OPTIONSHOTKEYS_H
#define __UI_OPTIONSHOTKEYS_H

#include "util.h"
#include "checkbox.h"
class winOptionsHotkeys_t {
public:


  glictWindow window;

  glictPanel lblHotkeys; // 18 33 268 43
  glictList lstHotkeys; // 18 47 268 152

  glictList lblText;   // 18 166 268 175
  glictTextbox txtText; // 18 180 268 195

  // 18 209 268 230
  uiCheckbox chkSendAuto;

  // Item Hotkeys
  glictPanel lblObjText;
  glictPanel pnlObjView;
  glictButton btnSelectObj;
  glictButton btnClearObj;
  glictButton btnUseSelf;
  glictButton btnUseTarget;
  glictButton btnUseCrosshair;

  // Hotkey Object
  glictPanel pnlSeparator;// 12 366 275 368


  //glictButton btnHelp;// 72 200, 40 17
  glictButton btnOk; // 178 376
  glictButton btnCancel; // 230 376


  ClientVersion_t currentversion;


  winOptionsHotkeys_t() {

    window.SetVisible(false);
    window.SetHeight(404);
    window.SetWidth(286);
    window.SetCaption("Hotkey Options");
    window.SetBGColor(.4, .4, .4, 1.);

    window.AddObject(&lblHotkeys);
    lblHotkeys.SetCaption("Available hotkeys:");
    lblHotkeys.SetPos(18, 33);
    lblHotkeys.SetWidth(268-18);
    lblHotkeys.SetHeight(43-33);
    lblHotkeys.SetBGActiveness(false);
    lblHotkeys.SetFont("aafont");

    window.AddObject(&lstHotkeys);
    lstHotkeys.SetPos(18, 47);
    lstHotkeys.SetWidth(268-18);
    lstHotkeys.SetHeight(152-47);
    lstHotkeys.SetBGColor(.2, .2, .2, 1.);
    lstHotkeys.SetFont("aafont");

    window.AddObject(&lblText);
    lblText.SetCaption("Edit hotkey text:");
    lblText.SetPos(18, 166);
    lblText.SetWidth(268-18);
    lblText.SetHeight(195-180);
    lblText.SetBGActiveness(false);
    lblText.SetFont("aafont");

    window.AddObject(&txtText);
    txtText.SetPos(18, 180);
    txtText.SetWidth(268-18);
    txtText.SetHeight(195-180);
    txtText.SetFont("aafont");

    // 18 209 268 230
    window.AddObject(&chkSendAuto.pnlPanel);
    chkSendAuto.SetPos(18,209);
    chkSendAuto.SetWidth(268-18);
    chkSendAuto.SetHeight(230-209);
    chkSendAuto.SetCaption("Send automatically");

	// Item Hotkeys
	window.AddObject(&lblObjText);
	lblObjText.SetPos(18, 244);
	lblObjText.SetHeight(10);
	lblObjText.SetWidth(120);
	lblObjText.SetCaption("Edit Hotkey Object: ");
	lblObjText.SetBGActiveness(false);
	lblObjText.SetFont("aafont");
	// Display Items Here
	window.AddObject(&pnlObjView);
	pnlObjView.SetPos(18, 258);
	pnlObjView.SetHeight(53);
	pnlObjView.SetWidth(53);
	pnlObjView.SetCustomData(this);
	pnlObjView.SetOnPaint(&winOptionsHotkeys_t::drawObject);
	//pnlObjView.SetBGActiveness(false);
	pnlObjView.SetBGColor(.1,.1,.1,1);
	pnlObjView.SetSkin(&g_skin.inv);

	window.AddObject(&btnSelectObj);
	btnSelectObj.SetPos(82, 258);
	btnSelectObj.SetHeight(20);
	btnSelectObj.SetWidth(86);
	btnSelectObj.SetCaption("Select Object");
	btnSelectObj.SetOnClick(&winOptionsHotkeys_t::onSelectObj);
	btnSelectObj.SetFont("minifont", 8);
	window.AddObject(&btnClearObj);
	btnClearObj.SetPos(82, 290);
	btnClearObj.SetHeight(20);
	btnClearObj.SetWidth(86);
	btnClearObj.SetCaption("Clear Object");
	btnClearObj.SetOnClick(&winOptionsHotkeys_t::onClearObj);
	btnClearObj.SetFont("minifont", 8);

	window.AddObject(&btnUseSelf);
	btnUseSelf.SetPos(181, 257);
	btnUseSelf.SetHeight(20);
	btnUseSelf.SetWidth(86);
	btnUseSelf.SetCaption("Use on yourself");
	btnUseSelf.SetOnClick(&winOptionsHotkeys_t::onObjUse_Self);
	btnUseSelf.SetFont("minifont", 8);
	window.AddObject(&btnUseTarget);
	btnUseTarget.SetPos(181, 290);
	btnUseTarget.SetHeight(20);
	btnUseTarget.SetWidth(86);
	btnUseTarget.SetCaption("Use on target");
	btnUseTarget.SetOnClick(&winOptionsHotkeys_t::onObjUse_Target);
	btnUseTarget.SetFont("minifont", 8);
	window.AddObject(&btnUseCrosshair);
	btnUseCrosshair.SetPos(181, 324);
	btnUseCrosshair.SetHeight(20);
	btnUseCrosshair.SetWidth(86);
	btnUseCrosshair.SetCaption("Use on crosshair");
	btnUseCrosshair.SetOnClick(&winOptionsHotkeys_t::onObjUse_Crosshair);
	btnUseCrosshair.SetFont("minifont", 8);

    window.AddObject(&pnlSeparator);
    pnlSeparator.SetPos(12, 366);
    pnlSeparator.SetWidth(275-12);
    pnlSeparator.SetHeight(368-366);
    pnlSeparator.SetBGColor(.2,.2,.2,1.);
    pnlSeparator.SetSkin(&g_skin.chk);

    window.AddObject(&btnOk);
    btnOk.SetPos(178, 376);
    btnOk.SetWidth(43);
    btnOk.SetHeight(19);
    btnOk.SetCaption("Ok");
    btnOk.SetFont("minifont",8);

    window.AddObject(&btnCancel);
    btnCancel.SetPos(230, 376);
    btnCancel.SetWidth(43);
    btnCancel.SetHeight(19);
    btnCancel.SetCaption("Cancel");
    btnCancel.SetFont("minifont",8);
  }

  void Init() {
    chkSendAuto.SetValue(0);
  }

  void Store() {
  }


  static void drawObject(glictRect *real, glictRect *clipped, glictContainer *caller);
  static void onSelectObj(glictPos* pos, glictContainer *caller);
  static void onClearObj(glictPos* pos, glictContainer *caller);
  static void onObjUse_Self(glictPos* pos, glictContainer *caller);
  static void onObjUse_Target(glictPos* pos, glictContainer *caller);
  static void onObjUse_Crosshair(glictPos* pos, glictContainer *caller);
};

#endif

