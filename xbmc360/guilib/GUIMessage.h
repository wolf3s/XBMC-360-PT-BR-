#ifndef GUILIB_MESSAGE_H
#define GUILIB_MESSAGE_H

#include "..\utils\Stdafx.h"
#include "..\utils\StdString.h"
#include <string>

#define GUI_MSG_WINDOW_INIT     1   // initialize window
#define GUI_MSG_WINDOW_DEINIT   2   // deinit window

#define GUI_MSG_SETFOCUS        3   // set focus to control param1=up/down/left/right
#define GUI_MSG_LOSTFOCUS       4   // control lost focus
#define GUI_MSG_CLICKED         5   // control has been clicked
#define GUI_MSG_LABEL_ADD       12   // add label control (for controls supporting more then 1 label)
#define GUI_MSG_LABEL_SET		13  // set the label of a control
#define GUI_MSG_ITEM_SELECTED   15  // ask control 2 return the selected item
#define GUI_MSG_EXECUTE			20  // user has clicked on a button with <execute> tag

#define GUI_MSG_USER         1000

//Send messgae macros

#define SET_CONTROL_LABEL(dwControlID,label) \
{ \
	CGUIMessage msg(GUI_MSG_LABEL_SET, GetID(), dwControlID); \
	msg.SetLabel(label); \
	OnMessage(msg); \
}

class CGUIMessage
{
public:
	CGUIMessage(int dwMsg, int senderID, int controlID, int param1 = 0, int param2 = 0);
	CGUIMessage(int dwMsg, int senderID, int controlID, int param1, int param2, void* lpVoid);

	int GetControlId() const ;
	int GetMessage() const;
	int GetSenderId() const;

	void SetLabel(const std::string& strLabel);
	const std::string& GetLabel() const;

	void SetStringParam(const std::string& strParam);
	const std::string& GetStringParam() const;

	void SetParam1(int iParam1);
	void SetParam2(int iParam2);
	int GetParam1() const;
	int GetParam2() const;
	void* GetLPVOID() const;
private:
	std::string m_strLabel;
	std::string m_strParam;
	int m_senderID;
	int m_controlID;
	int m_message;
	void* m_lpVoid;
	int m_param1;
	int m_param2;
};

#endif//GUILIB_MESSAGE_H