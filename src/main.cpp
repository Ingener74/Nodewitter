
#include <iostream>
#include <time.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>
#include <hge.h>
#include <hgegui.h>

#include "WidgetContainer.h"
#include "Image.h"
#include "Button.h"

static const int WINDOW_WIDTH = 1024;
static const int WINDOW_HEIGHT = 800;

HGE *hge = 0;

hgeGUI* gui = 0;
HTEXTURE cursorTexture = 0;
hgeSprite* cursorSprite = 0;

bool FrameFunc()
{
    float dt = hge->Timer_GetDelta();

    if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;

    gui->Update(dt);

    return false;
}

bool RenderFunc()
{
    hge->Gfx_BeginScene();

    hge->Gfx_Clear(0);

    gui->Render();

    hge->Gfx_EndScene();

    return false;
}

Widget* comicBook = 0;
void image1MouseEnter(Widget*) {
    if (comicBook)
        comicBook->Hide();
}
void image1MouseLeave(Widget*) {
    if (comicBook)
        comicBook->Show();
}
void image1MouseLDown(Widget*) {
    if (comicBook)
        comicBook->Hide();
}
void image1MouseRDown(Widget*) {
    if (comicBook)
        comicBook->Show();
}

Widget* but = NULL;
void buttonOnDown(Widget*) {
    // but->SetPos(rand() % (WINDOW_WIDTH - 150), rand() % (WINDOW_HEIGHT - 48));
    comicBook->SetPos(rand() % (WINDOW_WIDTH - 200), rand() % (WINDOW_HEIGHT - 200));
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    srand(static_cast<unsigned int>(time(NULL)));
    hge = hgeCreate(HGE_VERSION);

    hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
    hge->System_SetState(HGE_RENDERFUNC, RenderFunc);

    hge->System_SetState(HGE_TITLE, "Awesome HGE Widget Application");

    hge->System_SetState(HGE_WINDOWED, true);
    hge->System_SetState(HGE_SCREENWIDTH, WINDOW_WIDTH);
    hge->System_SetState(HGE_SCREENHEIGHT, WINDOW_HEIGHT);
    hge->System_SetState(HGE_SCREENBPP, 32);

    hge->System_SetState(HGE_USESOUND, false);

    if (hge->System_Initiate())
    {
        gui = new hgeGUI();

        WidgetContainer container(gui);
        


        container.AddWidget(0, boost::make_shared<Image>(hge, "chessBoard", "res/Chess_Board.png",
                                                         rand() % (WINDOW_WIDTH - 340), rand() % (WINDOW_HEIGHT - 340), 340.f, 340.f));
        if (Widget* chessBoard = container.GetWidget("chessBoard")) {
            chessBoard->SetEventHandler(Widget::MouseEnter, image1MouseEnter);
            chessBoard->SetEventHandler(Widget::MouseLeave, image1MouseLeave);
            chessBoard->SetEventHandler(Widget::MouseLDown, image1MouseLDown);
            chessBoard->SetEventHandler(Widget::MouseRDown, image1MouseRDown);
        }

        container.AddWidget(0, boost::make_shared<Image>(hge, "comicBook", "res/Simple_Comic.png",
                                                         rand() % (WINDOW_WIDTH - 200), rand() % (WINDOW_HEIGHT - 200), 200.f, 200.f));
        if (Widget* comicBookWidget = container.GetWidget("comicBook")) {
            comicBook = comicBookWidget;
        }

        container.AddWidget(1, boost::make_shared<Button>(hge, gui, "res/font1.fnt", "Push Me",
                                                          "mainButton", "res/btn-test-0.png", "res/btn-test-1.png",
                                                          rand() % (WINDOW_WIDTH - 150), rand() % (WINDOW_HEIGHT - 48), 150.f, 48.f));
        if (Widget* button = container.GetWidget("mainButton")) {
            button->SetEventHandler(Widget::MouseLDown, buttonOnDown);
            but = button;
        }

        gui->AddCtrl(&container);

        cursorTexture = hge->Texture_Load("res/cursor.png");
        cursorSprite = new hgeSprite(cursorTexture, 0, 0, 32, 32);

        gui->SetNavMode(HGEGUI_CYCLED | HGEGUI_UPDOWN);
        gui->SetCursor(cursorSprite);
        gui->Enter();

        hge->System_Start();

        hge->Texture_Free(cursorTexture);
        delete cursorSprite;
    }
    else
    {
        MessageBox(NULL, reinterpret_cast<LPCWSTR>(hge->System_GetErrorMessage()), L"Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
    }

    hge->System_Shutdown();

    hge->Release();

    return 0;
}
