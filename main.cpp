#include <windows.h>
#include <stdio.h>
#include <iostream>


class Prep;

class Pole
{
private:

    HWND diskr = GetForegroundWindow();
    HDC hdc = GetDC(diskr);
    COLORREF phon;

public:
    void Getphon(Pole &pole)
    {
        pole.phon = GetPixel (pole.hdc, 907, 129);
    }

    friend Prep;
};

class Dino
{
    public:
    void jump()
    {
        keybd_event(VK_UP, 0, 0, 0); // зажать клавишу
        Sleep(100);
        keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0); // отпустить клавишу

    }

    void slide()
    {
        keybd_event(VK_DOWN, 0, 0, 0); // зажать клавишу
        Sleep(200);
        keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0); // отпустить клавишу
    }
};

class Prep
{

    private:

    COLORREF kaktus;
    COLORREF ptuca;

     public:

    bool Kaktus(Pole &pole)
    {
        kaktus = GetPixel (pole.hdc, 504, 240);


     if(kaktus!=pole.phon)
         return true;
     else
         return false;
    }

    bool Ptuca(Pole &pole)
    {
        ptuca = GetPixel (pole.hdc, 504, 202);

        if(ptuca!=pole.phon)
            return true;
        else
            return false;
    }


};


int main()
{
    Sleep(3000);
    Pole pole;
    Dino gadzilla;
    Prep prep;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
         pole.Getphon(pole);

        if(prep.Kaktus(pole))
            gadzilla.jump();

        if(prep.Ptuca(pole))
            gadzilla.slide();
    }


    return 0;
}
